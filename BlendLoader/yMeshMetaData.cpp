#include "yMeshMetaData.h"
#include "BlenderSerialize/Serialize/BlenderSerialize/blend263/Blender.h"
#include "BlenderSerialize/BlenderDefines.h"
#include "Macros/yMacros.h"

#include "OgreMesh.h"
#include "OgreMesh2.h"
#include "OgreMeshManager.h"
#include "OgreMeshManager2.h"
#include "OgreSubMesh.h"
#include "OgreSubMesh2.h"
#include "OgreRoot.h"
#include "OgreOldSkeletonInstance.h"
#include "OgreOldSkeletonManager.h"
#include "OgreHardwareBufferManager.h"
#include "OgreVector2.h"
#include "OgreLodConfig.h"
#include "OgreMeshLodGenerator.h"
#include "OgrePixelCountLodStrategy.h"

#include "Types/yMeshDataHelpers.h"
#include "Engine/NavMesh/yNavMesh.h"
#include "iostream"

yMeshMetaData::yMeshMetaData() {
    mMesh.setNull();
    mIsStatic = false;
    mNeedGeneration = true;
    mBoneControlled = false;
    mIsNavMesh = false;
}

bool yMeshMetaData::parser(std::string blendFileName, Blender::Object* bObject , std::string skeletonName, bool isBoneControlled ) {

    yAssert( bObject, "bObject null" );
    bool isMesh = false;
    mBlendFileName = blendFileName;
    mType = bObject->type;
    mBoneControlled = isBoneControlled;
    mSkeletonName = skeletonName;

    //check if we need to generate the mesh (maybe is used only like collision shape)
    mIsVisible = !(bObject->restrictflag & OB_RESTRICT_RENDER);
    bool omitMesh = !mIsVisible && ( bObject->body_type == OB_BODY_TYPE_STATIC || bObject->body_type == OB_BODY_TYPE_RIGID || bObject->body_type == OB_BODY_TYPE_CHARACTER );

    if( !omitMesh ) {
        if( mType == OB_MESH ) {
            Blender::Mesh *data = (Blender::Mesh*)bObject->data;
            mName = GET_NAME(data);
            mNameMeshFinal = blendFileName + "_" + mName;
            mMesh = Ogre::MeshManager::getSingleton().getByName( mNameMeshFinal );

            if( mMesh.isNull() ){
                for( Blender::LodLevel *lodLevel = (Blender::LodLevel*)bObject->lodlevels.first; lodLevel; lodLevel = lodLevel->next )
                {
                    if( !lodLevel->distance ) continue;
                    yLodInfo lodInfo;
                    lodInfo.distance = lodLevel->distance;
                    lodInfo.bMesh = NULL;
                    if( lodLevel->source ) lodInfo.bMesh = (Blender::Mesh*)lodLevel->source->data;
                    mLodInfos.push_back(lodInfo);
                }
                mVertexTriangleBufferCombo = fillTriangleBuffers( data, !skeletonName.empty() );
                mNeedGeneration = true;
            }

            //check if is a navmesh
            mIsNavMesh = ( bObject->body_type == OB_BODY_TYPE_NAVMESH );
            isMesh = true;
        }
        else if( mType == OB_FONT ) {
            Blender::Curve* bCurve = static_cast<Blender::Curve*>(bObject->data);
            Blender::Text* bText = static_cast<Blender::Text*>(bObject->data);
            mName = GET_NAME(bText);
            mNameMeshFinal = blendFileName + "_PlaneTextMesh_" + mName;

            mVertexTriangleBufferCombo = fillTriangleBuffersForTextPlane( bCurve );
            mNeedGeneration = true;
            isMesh = true;
        }
    }

    if( isMesh ) {
        if( (bObject->body_type == OB_BODY_TYPE_STATIC || bObject->body_type == OB_BODY_TYPE_OCCLUDER) && bObject->type != OB_CAMERA ) { //Force Cameras to be dynamic
            mIsStatic = true;
        }
        else {
            mIsStatic = false;
        }
    }

    return isMesh;
}

void yMeshMetaData::poblateNavMesh( yNavMesh& navMesh ) {
    yVertexTriangleBuffer* vertexTriangleBuffer = mVertexTriangleBufferCombo.vertexTriangleBuffers[0];
    bool valid = navMesh.buildNavMesh( vertexTriangleBuffer );
    yAssert( valid, "Fail building the nav mesh" );
}

Ogre::MeshPtr& yMeshMetaData::generate() {

    if( mNeedGeneration ) {
        yAssert( mVertexTriangleBufferCombo.vertexTriangleBuffers.size() != 0, "vertex buffer is empty, call parser before generate" );

        Ogre::v1::MeshPtr v1Mesh;
        v1Mesh.setNull();
        v1Mesh = Ogre::v1::MeshManager::getSingleton().getByName( mNameMeshFinal + "_V1" );
        if( v1Mesh.isNull() ) {
            v1Mesh = generateMesh( mVertexTriangleBufferCombo, mLodInfos );
        }
        mMesh = convertMeshToV2( v1Mesh );

        //If is BoneControlled aka RagDoll, set bounds to infinite, so it wont dissapear when moved away from its original position
        if( mType == OB_MESH && mBoneControlled ) {
            mMesh->_setBounds(Ogre::Aabb::BOX_INFINITE);
        }

        mNeedGeneration = false;
    }

    yAssert( !mMesh.isNull(), "something go wrong with the mesh generation" );
    return mMesh;
}

inline Ogre::Vector3 yMeshMetaData::calcNormal(yTempFace *tri)
{
    Ogre::Vector3 n = (tri->vertex[1].co - tri->vertex[2].co).crossProduct(tri->vertex[2].co - tri->vertex[0].co).normalisedCopy();
    return n;
}

//Generate the Ogre Mesh and assign the Skeleton and VertexBoneAssignments if theres any
yMeshMetaData::yVertexTriangleBufferCombo yMeshMetaData::fillTriangleBuffers(Blender::Mesh* bMesh, bool hasSkeleton)
{
    Blender::MVert *mvert = bMesh->mvert;
    Blender::MPoly *mpoly = bMesh->mpoly;
    Blender::MLoop *mloop = bMesh->mloop;
    Blender::MLoopCol *mloopCol = bMesh->mloopcol;
    Blender::MLoopUV *muvs[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    Blender::MVert vpak[4];
    Ogre::Vector2 cnor[4];
    int index[4];
    Ogre::ColourValue vertexCol[4];

    yTriangleIndex ipak;

    //uvs
    int uvSetCount = 0;
    bool useWind = false;
    Blender::CustomDataLayer *layers = (Blender::CustomDataLayer*)bMesh->ldata.layers;
    if (layers)
    {
        for (int i=0; i<bMesh->ldata.totlayer; i++)
        {
            if( layers[i].type == CD_MLOOPUV && uvSetCount < 8 )
            {
                Blender::MLoopUV *mtf = (Blender::MLoopUV*)layers[i].data;
                if(mtf)
                    muvs[uvSetCount++] = mtf;
            }
            else if(layers[i].type == CD_MLOOPCOL && std::string(layers[i].name)=="wind")
            {
                useWind = true;
            }
        }
    }



    const int maxSubMesh = 16;
    bool subMeshReady[maxSubMesh];
    for(unsigned int i=0; i<maxSubMesh; i++){
        subMeshReady[i] = false;
    }

    yVertexTriangleBufferCombo triangleBufferCombo;

//    for(unsigned int i=0; i<maxSubMesh; i++){
//        triangleBufferCombo.vertexTriangleBuffers[i] = nullptr;
//        triangleBufferCombo.vertexTriangleBuffersShadow[i] = nullptr;
//    }





//EDGE SPLIT ATTEMPT
//    std::map<int, int> sharpVertex;
//    //get sharp edges
//    for (int fi = 0; fi < bMesh->totpoly; fi++)
//    {
//        const Blender::MPoly& curpoly = mpoly[fi];

//        //skip if face is not a triangle || quad
//        if (curpoly.totloop<3)
//            continue;

//        if (curpoly.totloop>4){
//            std::cout<<"Ngon detected in Mesh: "<<GET_NAME(bMesh)<<std::endl;
//            continue;
//        }

//        const bool isQuad = curpoly.totloop==4;

//        const Blender::MLoop& e0 = mloop[curpoly.loopstart];
//        const Blender::MLoop& e1 = mloop[curpoly.loopstart+1];
//        const Blender::MLoop& e2 = mloop[curpoly.loopstart+2];

//        if (isQuad)
//        {
//            const Blender::MLoop& e3 = mloop[curpoly.loopstart+3];
//        }

//        else{

//            if(medge[e0.e].flag & ME_SHARP){
//                std::cout<<"YES "<<medge[e0.e].v1<<" - "<<medge[e0.e].v2<<std::endl;
//                sharpVertex[medge[e0.e].v1] = 1;
//                sharpVertex[medge[e0.e].v2] = 1;
//            }
//            if(medge[e1.e].flag & ME_SHARP){
//                std::cout<<"YES "<<medge[e1.e].v1<<" - "<<medge[e1.e].v2<<std::endl;
//                sharpVertex[medge[e1.e].v1] = 1;
//                sharpVertex[medge[e1.e].v2] = 1;
//            }
//            if(medge[e2.e].flag & ME_SHARP){
//                std::cout<<"YES "<<medge[e2.e].v1<<" - "<<medge[e2.e].v2<<std::endl;
//                sharpVertex[medge[e2.e].v1] = 1;
//                sharpVertex[medge[e2.e].v2] = 1;
//            }

////            for(int v=0; v<3; v++){
////                if(isVertexSharp[v]>1){
////                    tempFace.vertex[v].no = faceNormal;
////                }
////            }
//        }
//    }




    //For Bone deformations mesh has to have only vertexGroups assigned to bones, other vertexGroups may cause crash
    Blender::MDeformVert *dvert = bMesh->dvert;
    short *clnors;
    bool useCustomNormals = false;

    Blender::CustomDataLayer* cdlayers = (Blender::CustomDataLayer*)bMesh->ldata.layers;

    for( int i = 0; i < bMesh->ldata.totlayer; i++ ){
        if( cdlayers[i].type==41 ){
            clnors = (short *)(cdlayers[i].data);
            useCustomNormals = true;
        }
    }

    bool useVertexColor = false;
    if( mloopCol != 0 && useWind ) useVertexColor = true; //Only for wind for now

    //get vertex/indexs and reorder
    for (int fi = 0; fi < bMesh->totpoly; fi++)
    {
        const Blender::MPoly& curpoly = mpoly[fi];

        int matIndex = curpoly.mat_nr;

        if( matIndex >= maxSubMesh ){
            std::cout << yWarning << "mesh '" << mName << "' has more than " << maxSubMesh << " materials assigned" << std::endl;
        }

        if( !subMeshReady[matIndex] ){
            triangleBufferCombo.vertexTriangleBuffers.resize( std::max( (int)triangleBufferCombo.vertexTriangleBuffers.size(), matIndex+1 ) );
            triangleBufferCombo.vertexTriangleBuffers[matIndex] = new yVertexTriangleBuffer();
            triangleBufferCombo.vertexTriangleBuffers[matIndex]->uvSetCount = uvSetCount;
            triangleBufferCombo.vertexTriangleBuffers[matIndex]->subMeshIndexer->indexMapping.resize(bMesh->totvert);

            triangleBufferCombo.vertexTriangleBuffersShadow.resize( std::max( (int)triangleBufferCombo.vertexTriangleBuffersShadow.size(), matIndex+1 ) );
            triangleBufferCombo.vertexTriangleBuffersShadow[matIndex] = new yVertexTriangleBuffer();
            triangleBufferCombo.vertexTriangleBuffersShadow[matIndex]->uvSetCount = uvSetCount;
            triangleBufferCombo.vertexTriangleBuffersShadow[matIndex]->subMeshIndexer->indexMapping.resize(bMesh->totvert);

            subMeshReady[matIndex] = true;
        }
        yVertexTriangleBuffer* currentBuffer = triangleBufferCombo.vertexTriangleBuffers[matIndex];
        yVertexTriangleBuffer* currentBufferShadow = triangleBufferCombo.vertexTriangleBuffersShadow[matIndex];


        //skip if face is not a triangle || quad
        if (curpoly.totloop<3)
            continue;

        if (curpoly.totloop>4){
            std::cout<<yWarning<<"Ngon detected in Mesh '"<<mName<<"' of file '"<<mBlendFileName<<"'"<<std::endl;
            continue;
        }

        const bool isQuad = curpoly.totloop==4;

        yTempFace tempFace;
        yTempFace tempFaceQuad[2];

        const Blender::MLoop& v0 = mloop[curpoly.loopstart];
        const Blender::MLoop& v1 = mloop[curpoly.loopstart+1];
        const Blender::MLoop& v2 = mloop[curpoly.loopstart+2];

        vpak[0] = mvert[v0.v];
        vpak[1] = mvert[v1.v];
        vpak[2] = mvert[v2.v];

        if( useCustomNormals ){
            cnor[0] = Ogre::Vector2( clnors[v0.v], clnors[v0.v+1] );
            cnor[1] = Ogre::Vector2( clnors[v1.v], clnors[v1.v+1] );
            cnor[2] = Ogre::Vector2( clnors[v2.v], clnors[v2.v+1] );
        }
        else{
            cnor[0] = Ogre::Vector2( 0, 0 );
            cnor[1] = Ogre::Vector2( 0, 0 );
            cnor[2] = Ogre::Vector2( 0, 0 );
        }

        index[0] = v0.v;
        index[1] = v1.v;
        index[2] = v2.v;


        if( useVertexColor ) {
            currentBuffer->hasVertexColors = true;

            for(unsigned int i=0; i<3; i++){
                vertexCol[i] = Ogre::ColourValue( static_cast<unsigned char>(mloopCol[curpoly.loopstart+i].r)/static_cast<float>(UCHAR_MAX),
                        static_cast<unsigned char>(mloopCol[curpoly.loopstart+i].g)/static_cast<float>(UCHAR_MAX),
                        static_cast<unsigned char>(mloopCol[curpoly.loopstart+i].b)/static_cast<float>(UCHAR_MAX) );
            }
        }

        int currentOrder[3];

        Ogre::Vector3 faceNormal;

        if (isQuad)
        {
            const Blender::MLoop& v3 = mloop[curpoly.loopstart+3];
            vpak[3] = mvert[v3.v];
            if( useCustomNormals ){
                cnor[3] = Ogre::Vector2( clnors[v3.v], clnors[v3.v+1] );
            }
            else{
                cnor[3] = Ogre::Vector2( 0, 0 );
            }
            index[3] = v3.v;

            if( useVertexColor ) {
                currentBuffer->hasVertexColors = true;
                vertexCol[3] = Ogre::ColourValue( static_cast<unsigned char>(mloopCol[curpoly.loopstart+3].r)/static_cast<float>(UCHAR_MAX),
                        static_cast<unsigned char>(mloopCol[curpoly.loopstart+3].g)/static_cast<float>(UCHAR_MAX),
                        static_cast<unsigned char>(mloopCol[curpoly.loopstart+3].b)/static_cast<float>(UCHAR_MAX) );
            }

            Ogre::Vector3 epsilon0, epsilon1;

            epsilon0 = (Ogre::Vector3(vpak[0].co[0],vpak[0].co[1],vpak[0].co[2]) - Ogre::Vector3(vpak[1].co[0],vpak[1].co[1],vpak[1].co[2]));
            epsilon1 = (Ogre::Vector3(vpak[2].co[0],vpak[2].co[1],vpak[2].co[2]) - Ogre::Vector3(vpak[3].co[0],vpak[3].co[1],vpak[3].co[2]));

            bool nearFlag = epsilon0.squaredLength() < epsilon1.squaredLength();

            for(int tri=0; tri<2; tri++){
                if(tri==0 && nearFlag){
                    currentOrder[0] = 0;
                    currentOrder[1] = 1;
                    currentOrder[2] = 2;
                }
                else if(tri==1 && nearFlag){
                    currentOrder[0] = 2;
                    currentOrder[1] = 3;
                    currentOrder[2] = 0;
                }
                if(tri==0 && !nearFlag){
                    currentOrder[0] = 0;
                    currentOrder[1] = 1;
                    currentOrder[2] = 3;
                }
                else if(tri==1 && !nearFlag){
                    currentOrder[0] = 3;
                    currentOrder[1] = 1;
                    currentOrder[2] = 2;
                }

                ipak.index[0] = index[currentOrder[0]];
                ipak.index[1] = index[currentOrder[1]];
                ipak.index[2] = index[currentOrder[2]];

                for(int i=0; i<3; i++){
                    int k=currentOrder[i];

                    //Coordinates
                    tempFaceQuad[tri].vertex[i].co.x = vpak[k].co[0];
                    tempFaceQuad[tri].vertex[i].co.y = vpak[k].co[1];
                    tempFaceQuad[tri].vertex[i].co.z = vpak[k].co[2];
                    tempFaceQuad[tri].vertex[i].co = yUtils::convertToYup(tempFaceQuad[tri].vertex[i].co);
                    //Normals
                    tempFaceQuad[tri].vertex[i].no.x = vpak[k].no[0]/32767.f;
                    tempFaceQuad[tri].vertex[i].no.y = vpak[k].no[1]/32767.f;
                    tempFaceQuad[tri].vertex[i].no.z = vpak[k].no[2]/32767.f;
                    tempFaceQuad[tri].vertex[i].no = yUtils::convertToYup(tempFaceQuad[tri].vertex[i].no);
                    //Colors
                    tempFaceQuad[tri].vertex[i].col = vertexCol[k];

                    //uvs
                    for(int j=0; j<uvSetCount; j++){
                        const Blender::MLoopUV& uv1 = muvs[j][curpoly.loopstart+k];
                        tempFaceQuad[tri].vertex[i].uv[j].x = uv1.uv[0];
                        tempFaceQuad[tri].vertex[i].uv[j].y = uv1.uv[1];
                    }

                    tempFaceQuad[tri].vertex[i].vba = ipak.index[i];
                }



                tempFaceQuad[tri].triangleIndex = ipak;
            }

            faceNormal = calcNormal(&tempFaceQuad[0]);
            Ogre::Vector3 faceNormal2 = calcNormal(&tempFaceQuad[1]);

            faceNormal = (faceNormal+faceNormal2)/2.0;

            if (!(curpoly.flag & ME_SMOOTH)){
                tempFaceQuad[0].vertex[0].no = tempFaceQuad[0].vertex[1].no = tempFaceQuad[0].vertex[2].no = faceNormal;
                tempFaceQuad[1].vertex[0].no = tempFaceQuad[1].vertex[1].no = tempFaceQuad[1].vertex[2].no = faceNormal;
            }

            for(int tri=0; tri<2; tri++){
                yTriangleIndex tempTriangleIndex = currentBuffer->addTriangle(tempFaceQuad[tri]);


                //Get vertexBoneAssigments
                if(hasSkeleton && dvert){
                    for (int n = 0; n < bMesh->totvert; n++){
                        for(int v=0; v<3; v++){
                            if(tempFaceQuad[tri].vertex[v].vba==n){
                                const Blender::MDeformVert& dv = dvert[n];
                                for (int w = 0; w < dv.totweight; w++){
                                    Ogre::v1::VertexBoneAssignment vba;
                                    vba.boneIndex = dv.dw[w].def_nr;
                                    vba.weight = dv.dw[w].weight;
                                    vba.vertexIndex = tempTriangleIndex.index[v];
                                    currentBuffer->vbas.push_back(vba);
                                    currentBufferShadow->vbas.push_back(vba);
                                }//for (int w = 0; w < dv.totweight; w++)
                            }//if(tempFaceQuad[tri].vertex[v].vba==n)
                        }//for(int v=0; v<3; v++)
                    }//for (int n = 0; n < bMesh->totvert; n++)

                    currentBufferShadow->addTriangle(tempFaceQuad[tri], false);
                }//if(hasSkeleton && dvert)
                else{
                    currentBufferShadow->addTriangle(tempFaceQuad[tri], true);
                }
            }

        }

        else{
            ipak.index[0] = v0.v;
            ipak.index[1] = v1.v;
            ipak.index[2] = v2.v;

            for(int i=0; i<3; i++){

                //Coordinates
                tempFace.vertex[i].co.x = vpak[i].co[0];
                tempFace.vertex[i].co.y = vpak[i].co[1];
                tempFace.vertex[i].co.z = vpak[i].co[2];
                tempFace.vertex[i].co = yUtils::convertToYup(tempFace.vertex[i].co);
                //Normals
                tempFace.vertex[i].no.x = vpak[i].no[0]/32767.f;
                tempFace.vertex[i].no.y = vpak[i].no[1]/32767.f;
                tempFace.vertex[i].no.z = vpak[i].no[2]/32767.f;
                tempFace.vertex[i].no = yUtils::convertToYup(tempFace.vertex[i].no);
                //Colors
                tempFace.vertex[i].col = vertexCol[i];

                //uvs
                for(int j=0; j<uvSetCount; j++){
                    const Blender::MLoopUV& uv1 = muvs[j][curpoly.loopstart+i];
                    tempFace.vertex[i].uv[j].x = uv1.uv[0];
                    tempFace.vertex[i].uv[j].y = uv1.uv[1];
                }

                tempFace.vertex[i].vba = ipak.index[i];
            }

            faceNormal = calcNormal(&tempFace);

            if (!(curpoly.flag & ME_SMOOTH)){
                tempFace.vertex[0].no = tempFace.vertex[1].no = tempFace.vertex[2].no = faceNormal;
            }

            tempFace.triangleIndex = ipak;
            yTriangleIndex tempTriangleIndex = currentBuffer->addTriangle(tempFace);

            //Get vertexBoneAssigments
            if(hasSkeleton && dvert){
                for (int n = 0; n < bMesh->totvert; n++){
                    for(int v=0; v<3; v++){
                        if(tempFace.vertex[v].vba==n){
                            const Blender::MDeformVert& dv = dvert[n];
                            for (int w = 0; w < dv.totweight; w++){
                                Ogre::v1::VertexBoneAssignment vba;
                                vba.boneIndex = dv.dw[w].def_nr;
                                vba.weight = dv.dw[w].weight;
                                vba.vertexIndex = tempTriangleIndex.index[v];
                                currentBuffer->vbas.push_back(vba);
                                currentBufferShadow->vbas.push_back(vba);
                            }//for (int w = 0; w < dv.totweight; w++)
                        }//if(tempFace.vertex[v].vba==n)
                    }//for(int v=0; v<3; v++)
                }//for (int n = 0; n < bMesh->totvert; n++)

                currentBufferShadow->addTriangle(tempFace, false);
            }//if(hasSkeleton && dvert)
            else{
                currentBufferShadow->addTriangle(tempFace, true);
            }
        }
    }

    return triangleBufferCombo;
}

yMeshMetaData::yVertexTriangleBufferCombo yMeshMetaData::fillTriangleBuffersForTextPlane(Blender::Curve* bCurve) {

    float height = bCurve->lines*bCurve->linedist;
    float top = 1 + bCurve->yof - 0.1;
    float bottom = -(height - top)*1.05;
    float width = ( (float)bCurve->len / (float)bCurve->lines )*0.75*bCurve->spacing;
    float xOffset = bCurve->yof;
    if( bCurve->spacemode == CU_MIDDLE ) xOffset -= width/2.0;
    else if( bCurve->spacemode == CU_RIGHT ) xOffset -= width;
    float left = 0 + xOffset;
    float right = width + xOffset;

    yVertexTriangleBufferCombo triangleBufferCombo;
    yVertexTriangleBuffer* triangleBuffer = new yVertexTriangleBuffer();
    triangleBuffer->subMeshIndexer->indexMapping.resize(4);
    triangleBuffer->uvSetCount = 1;

    for(unsigned int f=0; f<2; f++){

        yTempFace tempFace;
        yTriangleIndex ipak;

        ipak.index[0] = f+0;
        ipak.index[1] = f*2+1;
        ipak.index[2] = 2;

        for(unsigned int i=0; i<3; i++){

            int x = (!f)*(i==1)+f*(i!=2);
            int y = (!f)*(i==2)+f*(i!=0);

            //Coordinates
            if( !x ) tempFace.vertex[i].co.x = left;
            else  tempFace.vertex[i].co.x = right;
            if( !y ) tempFace.vertex[i].co.y = bottom;
            else  tempFace.vertex[i].co.y = top;

            tempFace.vertex[i].co.x *= bCurve->fsize;
            tempFace.vertex[i].co.y *= bCurve->fsize;
            tempFace.vertex[i].co.z = 0;
            tempFace.vertex[i].co = yUtils::convertToYup(tempFace.vertex[i].co);

            //Normals
            tempFace.vertex[i].no.x = 0;
            tempFace.vertex[i].no.y = 0;
            tempFace.vertex[i].no.z = 1;
            tempFace.vertex[i].no = yUtils::convertToYup(tempFace.vertex[i].no);

            //uvs
            tempFace.vertex[i].uv[0].x = x;
            tempFace.vertex[i].uv[0].y = y;
        }

        tempFace.triangleIndex = ipak;

        triangleBuffer->addTriangle( tempFace );
    }

    triangleBufferCombo.vertexTriangleBuffersShadow.push_back( triangleBuffer );
    triangleBufferCombo.vertexTriangleBuffers.push_back( triangleBuffer );

    return triangleBufferCombo;
}

//Generate the Ogre Mesh and assign the Skeleton and VertexBoneAssignments if theres any
Ogre::v1::MeshPtr yMeshMetaData::generateMesh(yVertexTriangleBufferCombo triangleBufferCombo, Ogre::FastArray<yLodInfo> lodInfos)
{
    if( false ) {//Direct v2 mesh format, not used because we can't calc tangents

        Ogre::Vector3 minBB(Ogre::Vector3::UNIT_SCALE*FLT_MAX);
        Ogre::Vector3 maxBB(Ogre::Vector3::UNIT_SCALE*-FLT_MAX);

        Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().createManual(mNameMeshFinal, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);


        for(unsigned int sm=0; sm<triangleBufferCombo.vertexTriangleBuffers.size(); sm++){

            yVertexTriangleBuffer* currentBuffer = triangleBufferCombo.vertexTriangleBuffers[sm];
            yVertexTriangleBuffer* currentBufferShadow = triangleBufferCombo.vertexTriangleBuffersShadow[sm];

            if( !currentBuffer ) continue;
            if( !currentBuffer->vertexs.size() ){
                std::cout<<yWarning<<"Mesh '"<<mNameMeshFinal<<"' in file '"<<mBlendFileName<<"' has 0 vertex, probably crash"<<std::endl;
                continue;
            }

            // Create the submesh
            Ogre::SubMesh* subMesh = mesh->createSubMesh();
            subMesh->setMaterialName("DebugMat");

            Ogre::RenderSystem* renderSystem = Ogre::Root::getSingleton().getRenderSystem();
            Ogre::VaoManager* vaoManager = renderSystem->getVaoManager();

            {
                Ogre::VertexElement2Vec vertexElements;
                vertexElements.push_back(Ogre::VertexElement2(Ogre::VET_FLOAT3, Ogre::VES_POSITION));
                vertexElements.push_back(Ogre::VertexElement2(Ogre::VET_FLOAT3, Ogre::VES_NORMAL));

                //uvs
                for(int i=0; i<currentBuffer->uvSetCount; i++){
                    vertexElements.push_back(Ogre::VertexElement2(Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES));
                }

                size_t vertexCount = currentBuffer->vertexs.size();

                size_t vertexSize = vaoManager->calculateVertexSize(vertexElements);

                Ogre::Real* vertexData = static_cast<Ogre::Real*>( OGRE_MALLOC_SIMD( vertexSize * vertexCount, Ogre::MEMCATEGORY_GEOMETRY ) );
                Ogre::Real* pVertex = reinterpret_cast<Ogre::Real*>(vertexData);


                for(size_t i=0; i<vertexCount; i++)
                {
                    //Position
                    Ogre::Vector3 pos = currentBuffer->vertexs[i].co;
                    *pVertex++ = pos.x;
                    *pVertex++ = pos.y;
                    *pVertex++ = pos.z;

                    Ogre::Vector3 norm =currentBuffer->vertexs[i].no.normalisedCopy();
                    //Normals
                    *pVertex++ = norm.x;
                    *pVertex++ = norm.y;
                    *pVertex++ = norm.z;

                    //uvs
                    for(int j=0; j<currentBuffer->uvSetCount; j++){
                        *pVertex++ = currentBuffer->vertexs[i].uv[j].x;
                        *pVertex++ = 1.0-currentBuffer->vertexs[i].uv[j].y;
                    }

                    //Calc Bounds
                    minBB.makeFloor(pos);
                    maxBB.makeCeil(pos);

                }

                Ogre::VertexBufferPackedVec vertexBuffers;

                Ogre::VertexBufferPacked *pVertexBuffer = vaoManager->createVertexBuffer( vertexElements, vertexCount, Ogre::BT_IMMUTABLE, vertexData, true );
                vertexBuffers.push_back(pVertexBuffer);




                static const unsigned short index16BitClamp = (0xFFFF) - 1;

                //Indices

                size_t iBufSize = currentBuffer->triangles.size() * 3;

                Ogre::IndexBufferPacked::IndexType buff_type = ( currentBuffer->maxIndex > index16BitClamp) ?
                            Ogre::IndexBufferPacked::IT_32BIT : Ogre::IndexBufferPacked::IT_16BIT;

                Ogre::IndexBufferPacked *indexBuffer = 0;


                //Build index items
                bool using32 = buff_type == Ogre::IndexBufferPacked::IT_32BIT;

                if (!using32){
                    Ogre::uint16 *indices16 = reinterpret_cast<Ogre::uint16*>( OGRE_MALLOC_SIMD( sizeof(Ogre::uint16) * iBufSize, Ogre::MEMCATEGORY_GEOMETRY ) );

                    std::vector<Ogre::uint16> castedIndices(currentBuffer->indices.begin(), currentBuffer->indices.end());

                    memcpy( indices16, &castedIndices[0], sizeof(Ogre::uint16)*castedIndices.size() );

                    indexBuffer = vaoManager->createIndexBuffer( Ogre::IndexBufferPacked::IT_16BIT, iBufSize, Ogre::BT_IMMUTABLE, indices16, true );
                }
                else{
                    Ogre::uint32 *indices32 = reinterpret_cast<Ogre::uint32*>( OGRE_MALLOC_SIMD( sizeof(Ogre::uint32) * iBufSize, Ogre::MEMCATEGORY_GEOMETRY ) );

                    memcpy( indices32, &currentBuffer->indices[0], sizeof(Ogre::uint32)*currentBuffer->indices.size() );

                    indexBuffer = vaoManager->createIndexBuffer( Ogre::IndexBufferPacked::IT_32BIT, iBufSize, Ogre::BT_IMMUTABLE, indices32, true );
                }


                Ogre::VertexArrayObject *vao = vaoManager->createVertexArrayObject(
                            vertexBuffers, indexBuffer, Ogre::OperationType::OT_TRIANGLE_LIST );

                subMesh->mVao[0].push_back( vao );
                subMesh->mVao[1].push_back( vao );
            }

            //SHADOW
            if(false){
                Ogre::VertexElement2Vec vertexElements;
                vertexElements.push_back(Ogre::VertexElement2(Ogre::VET_FLOAT3, Ogre::VES_POSITION));

                size_t vertexCount = currentBufferShadow->vertexs.size();

                size_t vertexSize = vaoManager->calculateVertexSize(vertexElements);

                Ogre::Real* vertexData = static_cast<Ogre::Real*>( OGRE_MALLOC_SIMD( vertexSize * vertexCount, Ogre::MEMCATEGORY_GEOMETRY ) );
                Ogre::Real* pVertex = reinterpret_cast<Ogre::Real*>(vertexData);


                for(size_t i=0; i<vertexCount; i++)
                {
                    Ogre::Vector3 pos = yUtils::convertToYup(Ogre::Vector3(currentBufferShadow->vertexs[i].co[0],currentBufferShadow->vertexs[i].co[1],currentBufferShadow->vertexs[i].co[2]));
                    //transform to Y-up
                    *pVertex++ = pos.x;
                    *pVertex++ = pos.y;
                    *pVertex++ = pos.z;

                }

                Ogre::VertexBufferPackedVec vertexBuffers;

                Ogre::VertexBufferPacked *pVertexBuffer = vaoManager->createVertexBuffer( vertexElements, vertexCount, Ogre::BT_IMMUTABLE, vertexData, true );
                vertexBuffers.push_back(pVertexBuffer);




                static const unsigned short index16BitClamp = (0xFFFF) - 1;

                //Indices

                size_t iBufSize = currentBufferShadow->triangles.size() * 3;

                Ogre::IndexBufferPacked::IndexType buff_type = ( currentBufferShadow->maxIndex > index16BitClamp) ?
                            Ogre::IndexBufferPacked::IT_32BIT : Ogre::IndexBufferPacked::IT_16BIT;

                Ogre::IndexBufferPacked *indexBuffer = 0;


                //Build index items
                bool using32 = buff_type == Ogre::IndexBufferPacked::IT_32BIT;

                if (!using32){
                    Ogre::uint16 *indices16 = reinterpret_cast<Ogre::uint16*>( OGRE_MALLOC_SIMD( sizeof(Ogre::uint16) * iBufSize, Ogre::MEMCATEGORY_GEOMETRY ) );

                    std::vector<Ogre::uint16> castedIndices(currentBufferShadow->indices.begin(), currentBufferShadow->indices.end());

                    memcpy( indices16, &castedIndices[0], sizeof(Ogre::uint16)*castedIndices.size() );

                    indexBuffer = vaoManager->createIndexBuffer( Ogre::IndexBufferPacked::IT_16BIT, iBufSize, Ogre::BT_IMMUTABLE, indices16, true );
                }
                else{
                    Ogre::uint32 *indices32 = reinterpret_cast<Ogre::uint32*>( OGRE_MALLOC_SIMD( sizeof(Ogre::uint32) * iBufSize, Ogre::MEMCATEGORY_GEOMETRY ) );

                    memcpy( indices32, &currentBufferShadow->indices[0], sizeof(Ogre::uint32)*currentBufferShadow->indices.size() );

                    indexBuffer = vaoManager->createIndexBuffer( Ogre::IndexBufferPacked::IT_32BIT, iBufSize, Ogre::BT_IMMUTABLE, indices32, true );
                }


                Ogre::VertexArrayObject *vao = vaoManager->createVertexArrayObject(
                            vertexBuffers, indexBuffer, Ogre::OperationType::OT_TRIANGLE_LIST );

                subMesh->mVao[1].push_back( vao );
            }




            if(mSkeletonName!=""){
                Ogre::v1::SkeletonPtr skeleton = Ogre::v1::OldSkeletonManager::getSingletonPtr()->getByName(mSkeletonName,Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
                for(int i=0; i<currentBuffer->vbas.size(); ++i){
                    if( skeleton->getBone(currentBuffer->vbas[i].boneIndex) ) subMesh->addBoneAssignment( currentBuffer->vbas[i] );
                }
            }

        }

        Ogre::Aabb bounds;
        bounds.merge(minBB);
        bounds.merge(maxBB);
        mesh->_setBounds(bounds,false);
        mesh->_setBoundingSphereRadius(bounds.getRadius());


        mesh->arrangeEfficient( false, false, true );

        if(mSkeletonName!=""){
            Ogre::v1::SkeletonPtr skeleton = Ogre::v1::OldSkeletonManager::getSingletonPtr()->getByName(mSkeletonName,Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

            mesh->_notifySkeleton(skeleton);
            skeleton->unload();
        }

    }
    else{
        Ogre::Vector3 minBB(Ogre::Vector3::UNIT_SCALE*FLT_MAX);
        Ogre::Vector3 maxBB(Ogre::Vector3::UNIT_SCALE*-FLT_MAX);

        Ogre::v1::MeshPtr newMesh = Ogre::v1::MeshManager::getSingleton().createManual(mNameMeshFinal+"_V1", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

        newMesh->setVertexBufferPolicy(Ogre::v1::HardwareBuffer::HBU_STATIC);
        newMesh->setIndexBufferPolicy(Ogre::v1::HardwareBuffer::HBU_STATIC);

        newMesh->msOptimizeForShadowMapping = true;

        for(unsigned int sm=0; sm<triangleBufferCombo.vertexTriangleBuffers.size(); sm++){

            yVertexTriangleBuffer* currentBuffer = triangleBufferCombo.vertexTriangleBuffers[sm];
            yVertexTriangleBuffer* currentBufferShadow = triangleBufferCombo.vertexTriangleBuffersShadow[sm];

            if( !currentBuffer ) continue;
            if( !currentBuffer->vertexs.size() ){
                std::cout<<yWarning<<"Mesh '"<<mNameMeshFinal<<"' in file '"<<mBlendFileName<<"' has 0 vertex, probably crash"<<std::endl;
                continue;
            }


            static const unsigned short index16BitClamp = (0xFFFF) - 1;

            Ogre::v1::SubMesh *newSubMesh = newMesh->createSubMesh();
            newSubMesh->setMaterialName("DebugMat"); //just to avoid missing material warning

            newSubMesh->useSharedVertices = false;
            newSubMesh->operationType = Ogre::OperationType::OT_TRIANGLE_LIST;

            Ogre::v1::HardwareVertexBufferSharedPtr vertexBuffer;
            //MAIN BUFFER
            {
                size_t vertexCount = currentBuffer->vertexs.size();
                size_t iBufSize = currentBuffer->triangles.size() * 3;

                newSubMesh->vertexData[0] = OGRE_NEW Ogre::v1::VertexData();
                newSubMesh->vertexData[0]->vertexCount = currentBuffer->vertexs.size();

                size_t offs = 0;

                Ogre::v1::VertexDeclaration *decl = newSubMesh->vertexData[0]->vertexDeclaration;
                //position
                decl->addElement(0, offs, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
                offs += Ogre::v1::VertexElement::getTypeSize(Ogre::VET_FLOAT3);

                //normals
                decl->addElement(0, offs, Ogre::VET_FLOAT3, Ogre::VES_NORMAL);
                offs += Ogre::v1::VertexElement::getTypeSize(Ogre::VET_FLOAT3);

                //colors
                if(currentBuffer->hasVertexColors){
                    decl->addElement(0, offs, Ogre::VET_FLOAT3, Ogre::VES_DIFFUSE);
                    offs += Ogre::v1::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
                }

                //uvs
                for(int i=0; i<currentBuffer->uvSetCount; i++){
                    decl->addElement(0, offs, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES, i);
                    offs += Ogre::v1::VertexElement::getTypeSize(Ogre::VET_FLOAT2);
                }

                vertexBuffer = Ogre::v1::HardwareBufferManager::getSingleton().createVertexBuffer(
                            offs, vertexCount, Ogre::v1::HardwareBuffer::HBU_STATIC);

                Ogre::v1::VertexBufferBinding *bind = newSubMesh->vertexData[0]->vertexBufferBinding;
                bind->setBinding(0, vertexBuffer);



                //Index buffer
                Ogre::v1::HardwareIndexBuffer::IndexType buff_type = (currentBuffer->maxIndex > index16BitClamp) ?
                            Ogre::v1::HardwareIndexBuffer::IT_32BIT : Ogre::v1::HardwareIndexBuffer::IT_16BIT;

                Ogre::v1::HardwareIndexBufferSharedPtr indexBuffer = Ogre::v1::HardwareBufferManager::getSingleton().createIndexBuffer(buff_type,
                                                                                                                                       iBufSize,
                                                                                                                                       Ogre::v1::HardwareBuffer::HBU_STATIC);
                newSubMesh->indexData[0] = OGRE_NEW Ogre::v1::IndexData();
                newSubMesh->indexData[0]->indexCount = iBufSize;
                newSubMesh->indexData[0]->indexBuffer = indexBuffer;



                //Build index items
                bool using32 = buff_type == Ogre::v1::HardwareIndexBuffer::IT_32BIT;

                unsigned int *indices32 = 0;
                unsigned short *indices16 = 0;

                if (!using32)
                    indices16 = static_cast<unsigned short*>(indexBuffer->lock(Ogre::v1::HardwareBuffer::HBL_WRITE_ONLY));
                else
                    indices32 = static_cast<unsigned int*>(indexBuffer->lock(Ogre::v1::HardwareBuffer::HBL_WRITE_ONLY));

                for (unsigned int cur = 0; cur < currentBuffer->triangles.size(); ++cur)
                {
                    const yTriangleIndex& currentTriangle = currentBuffer->triangles[cur];
                    for(unsigned int i=0; i<3; i++){
                        if(using32)
                            *indices32++ = (unsigned int)currentTriangle.index[i];
                        else
                            *indices16++ = (unsigned short)currentTriangle.index[i];
                    }
                }

                indexBuffer->unlock();

                //Build vertex buffer
                float *bufferArray = static_cast<float*>(vertexBuffer->lock(Ogre::v1::HardwareBuffer::HBL_WRITE_ONLY));
                for(int i=0; i<currentBuffer->vertexs.size(); ++i)
                {
                    //Position
                    Ogre::Vector3 pos = currentBuffer->vertexs[i].co;
                    *bufferArray++ = pos.x;
                    *bufferArray++ = pos.y;
                    *bufferArray++ = pos.z;

                    //Normals
                    Ogre::Vector3 norm = currentBuffer->vertexs[i].no;//.normalisedCopy();
                    *bufferArray++ = norm.x;
                    *bufferArray++ = norm.y;
                    *bufferArray++ = norm.z;

                    //Colors
                    if(currentBuffer->hasVertexColors){
                        *bufferArray++ = currentBuffer->vertexs[i].col.r;
                        *bufferArray++ = currentBuffer->vertexs[i].col.g;
                        *bufferArray++ = currentBuffer->vertexs[i].col.b;
                    }

                    //uvs
                    for(int j=0; j<currentBuffer->uvSetCount; ++j){
                        *bufferArray++ = currentBuffer->vertexs[i].uv[j].x;
                        *bufferArray++ = 1.0-currentBuffer->vertexs[i].uv[j].y;
                    }

                    //Calc Bounds
                    minBB.makeFloor(pos);
                    maxBB.makeCeil(pos);

                }
                vertexBuffer->unlock();

            }
            //END MAIN BUFFER

            newSubMesh->indexData[1] = newSubMesh->indexData[0];
            newSubMesh->vertexData[1] = newSubMesh->vertexData[0];


            //SHADOW BUFFER
            Ogre::v1::HardwareVertexBufferSharedPtr vertexBufferShad;
            {
                size_t vertexCount = currentBufferShadow->vertexs.size();  //currentBufferShadow
                size_t iBufSize = currentBufferShadow->triangles.size() * 3;

                newSubMesh->vertexData[1] = OGRE_NEW Ogre::v1::VertexData();
                newSubMesh->vertexData[1]->vertexCount = currentBufferShadow->vertexs.size();

                size_t offs = 0;

                Ogre::v1::VertexDeclaration *decl = newSubMesh->vertexData[1]->vertexDeclaration;

                //position
                decl->addElement(0, offs, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
                offs += Ogre::v1::VertexElement::getTypeSize(Ogre::VET_FLOAT3);

                //colors
                if(currentBuffer->hasVertexColors){
                    decl->addElement(0, offs, Ogre::VET_FLOAT3, Ogre::VES_DIFFUSE);
                    offs += Ogre::v1::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
                }

                vertexBufferShad = Ogre::v1::HardwareBufferManager::getSingleton().createVertexBuffer(
                            offs, vertexCount, Ogre::v1::HardwareBuffer::HBU_STATIC);

                Ogre::v1::VertexBufferBinding *bind = newSubMesh->vertexData[1]->vertexBufferBinding;
                bind->setBinding(0, vertexBufferShad);


                //END SHADOW BUFFER

                //Index buffer
                Ogre::v1::HardwareIndexBuffer::IndexType buff_type = (currentBufferShadow->maxIndex > index16BitClamp) ?
                            Ogre::v1::HardwareIndexBuffer::IT_32BIT : Ogre::v1::HardwareIndexBuffer::IT_16BIT;

                Ogre::v1::HardwareIndexBufferSharedPtr indexBuffer = Ogre::v1::HardwareBufferManager::getSingleton().createIndexBuffer(buff_type,
                                                                                                                                       iBufSize,
                                                                                                                                       Ogre::v1::HardwareBuffer::HBU_STATIC);
                newSubMesh->indexData[1] = OGRE_NEW Ogre::v1::IndexData();
                newSubMesh->indexData[1]->indexCount = iBufSize;
                newSubMesh->indexData[1]->indexBuffer = indexBuffer;


                //Build index items
                bool using32 = buff_type == Ogre::v1::HardwareIndexBuffer::IT_32BIT;

                unsigned int *indices32 = 0;
                unsigned short *indices16 = 0;

                if (!using32)
                    indices16 = static_cast<unsigned short*>(indexBuffer->lock(Ogre::v1::HardwareBuffer::HBL_WRITE_ONLY));
                else
                    indices32 = static_cast<unsigned int*>(indexBuffer->lock(Ogre::v1::HardwareBuffer::HBL_WRITE_ONLY));

                for (unsigned int cur = 0; cur < currentBufferShadow->triangles.size(); ++cur)
                {
                    const yTriangleIndex& currentTriangle = currentBufferShadow->triangles[cur];
                    for(unsigned int i=0; i<3; i++){
                        if(using32)
                            *indices32++ = (unsigned int)currentTriangle.index[i];
                        else
                            *indices16++ = (unsigned short)currentTriangle.index[i];
                    }
                }

                indexBuffer->unlock();

                float *bufferArrayShad = static_cast<float*>(vertexBufferShad->lock(Ogre::v1::HardwareBuffer::HBL_WRITE_ONLY));
                for(int i=0; i<currentBufferShadow->vertexs.size(); ++i)
                {
                    //Position
                    Ogre::Vector3 pos = currentBufferShadow->vertexs[i].co;
                    *bufferArrayShad++ = pos.x;
                    *bufferArrayShad++ = pos.y;
                    *bufferArrayShad++ = pos.z;

                    //Colors
                    if(currentBuffer->hasVertexColors){
                        *bufferArrayShad++ = currentBuffer->vertexs[i].col.r;
                        *bufferArrayShad++ = currentBuffer->vertexs[i].col.g;
                        *bufferArrayShad++ = currentBuffer->vertexs[i].col.b;
                    }
                }
                vertexBufferShad->unlock();

            }
            //END SHADOW BUFFER


            if(mSkeletonName!=""){
                Ogre::v1::SkeletonPtr skeleton = Ogre::v1::OldSkeletonManager::getSingletonPtr()->getByName(mSkeletonName,Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
                for(int i=0; i<currentBuffer->vbas.size(); i++){
                    if( skeleton->getBone(currentBuffer->vbas[i].boneIndex) ) newSubMesh->addBoneAssignment( currentBuffer->vbas[i] );
                }
            }

        }

        if(mSkeletonName!=""){
            Ogre::v1::SkeletonPtr skeleton = Ogre::v1::OldSkeletonManager::getSingletonPtr()->getByName(mSkeletonName,Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
            newMesh->_notifySkeleton(skeleton);
            skeleton->unload();
        }

        if( !(minBB.x <= maxBB.x && minBB.y <= maxBB.y && minBB.z <= maxBB.z) ){
            newMesh.getPointer()->unload();
            newMesh.setNull();
            return newMesh;
        }
        newMesh->_setBounds(Ogre::AxisAlignedBox(minBB,maxBB),false);


//        Ogre::LodConfig config(newMesh);
//        //config.strategy = Ogre::PixelCountLodStrategy::getSingletonPtr();
//        for(int i=0; i<lodInfos.size(); i++){
//            std::string meshName = GET_NAME(lodInfos.at(i).bMesh);
//            Ogre::v1::MeshPtr lodMesh = generateMesh( meshName, fillTriangleBuffers( lodInfos.at(i).bMesh, !skeletonName.empty(), blendFile ), blendFile, skeletonName, std::vector<yLodInfo>() );
//            config.createManualLodLevel( lodInfos.at(i).distance, lodMesh->getName() );
//        }
//        Ogre::MeshLodGenerator::getSingleton().generateLodLevels(config);

        bool generateLod = true;
        if( lodInfos.size() && !lodInfos[0].bMesh ) generateLod = false;


        newMesh->msOptimizeForShadowMapping = false;

        if( generateLod ){
            //QTime timer;
            //timer.start();
            //Ogre::MeshLodGenerator::getSingleton().generateAutoconfiguredLodLevels( newMesh );
            Ogre::LodConfig config;


            config.mesh = newMesh;
            config.strategy = Ogre::PixelCountLodStrategy::getSingletonPtr();
            Ogre::LodLevel lodLevel;
            lodLevel.reductionMethod = Ogre::LodLevel::VRM_COLLAPSE_COST;
            Ogre::Real radius = newMesh->getBoundingSphereRadius();

            for(int i = 2; i < 6; i++)
            {
                Ogre::Real i4 = (Ogre::Real) (i * i * i * i);
                Ogre::Real i5 = i4 * (Ogre::Real) i;
                lodLevel.distance = 3388608.f / i4;
                lodLevel.reductionValue = radius / 100000.f * i5;
                config.levels.push_back(lodLevel);
            }

            Ogre::MeshLodGenerator::getSingleton().generateLodLevels( config );
            //std::cout<<newMesh->getNumLodLevels()<<"  - "<<newMesh->getName()<<" LODTIME "<<timer.elapsed()<<std::endl;
        }

        newMesh->load();


        //newMesh->msOptimizeForShadowMapping = false;

        //    if(meshName=="./media/Main.blend_Cube"){
        //        Ogre::v1::MeshSerializer* mSerializer = new Ogre::v1::MeshSerializer();
        //        mSerializer->exportMesh(newMesh.getPointer(),"CubeYoy.mesh",Ogre::v1::MESH_VERSION_1_8);
        //        delete mSerializer;
        //    }

        return newMesh;
    }
}

Ogre::MeshPtr yMeshMetaData::convertMeshToV2( Ogre::v1::MeshPtr mesh, bool unload ){

    Ogre::MeshPtr newMeshV2;
    if( mesh.isNull() ){
        newMeshV2.setNull();
        return newMeshV2;
    }

    newMeshV2 = Ogre::MeshManager::getSingleton().getByName( mesh->getName().substr(0, mesh->getName().size()-3 ) );
    if( newMeshV2.isNull() )
        newMeshV2 = Ogre::MeshManager::getSingleton().createManual( mesh->getName().substr(0, mesh->getName().size()-3 ), Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME );
    else return newMeshV2;

    //Import the v1 mesh to v2
    newMeshV2->importV1( mesh.get(), mesh->getBoundingSphereRadius()<10, true, true );

    if(unload){
        mesh->unload();
        mesh.setNull();
    }

    return newMeshV2;
}

bool yMeshMetaData::isStatic() {
    return mIsStatic;
}

bool yMeshMetaData::isNavMesh() {
    return mIsNavMesh;
}

bool yMeshMetaData::isVisible() {
    return mIsVisible;
}

int yMeshMetaData::getNumSubMeshes(){
    return mVertexTriangleBufferCombo.vertexTriangleBuffers.size();
}
