#include "yPhysicsMetaData.h"
#include "BlenderSerialize/Serialize/BlenderSerialize/blend263/Blender.h"
#include "BlenderSerialize/BlenderDefines.h"
#include "BulletCollision/Gimpact/btGImpactShape.h"
#include "btBulletDynamicsCommon.h"
#include "Macros/yMacros.h"

#include "OgreColourValue.h"

yPhysicsMetaData::yPhysicsMetaData() {
    mIsStatic = true;
    mIsKinematic = true;
    mMass = 1;
    mDampingLinear = 1;
    mDampingAngular = 1;
    mFriction = 0.5;
    mCollisionFlag = 0;
    mIsNoSleeping = false;
    mColGroup = 0;
    mColMask = 0;
    mIsCompound = false;
    mIsPlane = false;
}

bool yPhysicsMetaData::parser( Blender::Object* bObject, Ogre::Aabb aabb ) {

    yAssert( bObject, "bObject null" );
    bool isPhysics = false;

    //Generate Physics Meta data
    if( bObject->type == OB_MESH && ( bObject->body_type == OB_BODY_TYPE_RIGID || bObject->body_type == OB_BODY_TYPE_STATIC || bObject->body_type == OB_BODY_TYPE_CHARACTER ) ) {

        Ogre::Vector3 halfBoundingSize = aabb.getSize() * 0.5f;
        mType = bObject->collision_boundtype;

        if( bObject->collision_boundtype == OB_BOUND_SPHERE ){
            btScalar boundingRadius = std::max( std::max( halfBoundingSize.x, halfBoundingSize.y ), halfBoundingSize.z );
            mBoundingRadius = boundingRadius;
        }
        else if( bObject->collision_boundtype == OB_BOUND_CONE ){
            /** @todo we need a way to detect cone orientation, so we can
             * easily set it like coneShapeX for example **/
            mBoundingRadius = std::max( halfBoundingSize.x, halfBoundingSize.z );
            mHalfExtends = btVector3( mBoundingRadius, halfBoundingSize.y, mBoundingRadius );
        }
        else if( bObject->collision_boundtype == OB_BOUND_CYLINDER ){
            /** @todo we need a way to detect cylinder orientation, so we can
             * easily set it like CylinderShapeX for example **/
            btScalar radius = std::max( halfBoundingSize.x, halfBoundingSize.z );
            btVector3 halfExtends = btVector3( radius, halfBoundingSize.y, radius );
            mHalfExtends = halfExtends;
        }
        else if( bObject->collision_boundtype == OB_BOUND_CONVEX_HULL || bObject->collision_boundtype == OB_BOUND_TRIANGLE_MESH ){

            Blender::Mesh *bMesh = (Blender::Mesh*)bObject->data;
            mUseBvh = ( 1.99 < bObject->obstacleRad && bObject->obstacleRad < 2.01 ) ? true : false; // == 2, but let some error just in case (float precision)

            //First generate a trimesh
            //Using blender's mesh data, similar to generateMesh method
            Blender::MPoly* mpoly = bMesh->mpoly;
            Blender::MLoop* mloop = bMesh->mloop;
            Blender::MLoopCol* mloopCol = bMesh->mloopcol;
            for( size_t fi = 0; fi < bMesh->totpoly; ++fi ) {
                const Blender::MPoly& curpoly = mpoly[fi];
                const Blender::MLoop& v0 = mloop[curpoly.loopstart];
                const Blender::MLoop& v1 = mloop[curpoly.loopstart+1];
                const Blender::MLoop& v2 = mloop[curpoly.loopstart+2];

                Ogre::FastArray<Ogre::ColourValue> vertexCol;
                vertexCol.resize(4);
                if( mloopCol != 0 && mUseBvh ) {
                    for(unsigned int i=0; i<4; i++){
                        vertexCol[i] = Ogre::ColourValue( static_cast<unsigned char>(mloopCol[curpoly.loopstart+i].r)/static_cast<float>(UCHAR_MAX),
                                static_cast<unsigned char>(mloopCol[curpoly.loopstart+i].g)/static_cast<float>(UCHAR_MAX),
                                static_cast<unsigned char>(mloopCol[curpoly.loopstart+i].b)/static_cast<float>(UCHAR_MAX) );
                    }
                }

                Ogre::Vector3 vertex0 = yUtils::convertToYup( Ogre::Vector3(bMesh->mvert[v0.v].co[0],bMesh->mvert[v0.v].co[1],bMesh->mvert[v0.v].co[2]) );
                btVector3 vtx0(vertex0.x,vertex0.y,vertex0.z);

                Ogre::Vector3 vertex1 = yUtils::convertToYup( Ogre::Vector3(bMesh->mvert[v1.v].co[0],bMesh->mvert[v1.v].co[1],bMesh->mvert[v1.v].co[2]) );
                btVector3 vtx1(vertex1.x,vertex1.y,vertex1.z);

                Ogre::Vector3 vertex2 = yUtils::convertToYup( Ogre::Vector3(bMesh->mvert[v2.v].co[0],bMesh->mvert[v2.v].co[1],bMesh->mvert[v2.v].co[2]) );
                btVector3 vtx2(vertex2.x,vertex2.y,vertex2.z);

                yTriangleData data;
                data.v0Pos = vtx0;
                data.v1Pos = vtx1;
                data.v2Pos = vtx2;
                mTriangleData.push_back( data );

                if( mUseBvh ) {
                    yTriangleMeshData meshData;
                    meshData.v0Pos = vertex0;
                    meshData.v1Pos = vertex1;
                    meshData.v2Pos = vertex2;
                    meshData.v0Coeff = vertexCol[0].r;
                    meshData.v1Coeff = vertexCol[1].r;
                    meshData.v2Coeff = vertexCol[2].r;
                    mTriangleBvhData.push_back( meshData );
                }

                const bool isQuad = curpoly.totloop==4;
                if( isQuad ) {
                    const Blender::MLoop& v3 = mloop[curpoly.loopstart+3];

                    Ogre::Vector3 vertex3 = yUtils::convertToYup( Ogre::Vector3(bMesh->mvert[v3.v].co[0],bMesh->mvert[v3.v].co[1],bMesh->mvert[v3.v].co[2]) );
                    btVector3 vtx3(vertex3.x,vertex3.y,vertex3.z);

                    yTriangleData data;
                    data.v0Pos = vtx0;
                    data.v1Pos = vtx3;
                    data.v2Pos = vtx2;
                    mTriangleData.push_back( data );

                    if( mUseBvh ) {
                        yTriangleMeshData meshData;
                        meshData.v0Pos = vertex0;
                        meshData.v1Pos = vertex3;
                        meshData.v2Pos = vertex2;
                        meshData.v0Coeff = vertexCol[0].r;
                        meshData.v1Coeff = vertexCol[3].r;
                        meshData.v2Coeff = vertexCol[2].r;
                        mTriangleBvhData.push_back( meshData );
                    }
                }
            }
        }
        //In any Other case, make it Box
        else{
            if( halfBoundingSize.y == 0 ) {
                mHalfExtends = btVector3(0, 1, 0);
                mIsPlane = true;
            }
            else {
                mHalfExtends = btVector3( Ogre::Math::Abs(halfBoundingSize.x), Ogre::Math::Abs(halfBoundingSize.y), Ogre::Math::Abs(halfBoundingSize.z) );
            }
        }

        //Shape is ready, set some properties
        mColShapeMargin = bObject->margin;

        //dynamic or static
        if( bObject->body_type == OB_BODY_TYPE_RIGID ) { //updated often and affected by forces
            mMass = bObject->mass;
            mIsStatic = false;
            mIsKinematic = false;
        }
        else if( bObject->body_type == OB_BODY_TYPE_CHARACTER ) {
            mMass = 0;
            mIsStatic = false;
            mIsKinematic = true;
        }
        else {
            mMass = 0;
            mIsStatic = true;
            mIsKinematic = false;
        }

        //damping
        mDampingLinear = bObject->damping;
        mDampingAngular = bObject->rdamping;

        //Friction comes from the material
        Blender::Mesh *bMesh = (Blender::Mesh*)bObject->data;
        if( bMesh->mat && bMesh->mat[0] ) {
            mFriction = bMesh->mat[0]->friction;
        }

        //flags
        if( bObject->body_type == OB_BODY_TYPE_STATIC ) {
            mCollisionFlag = btCollisionObject::CF_STATIC_OBJECT;
        }
        else if( bObject->body_type == OB_BODY_TYPE_CHARACTER ) {
            mCollisionFlag = btCollisionObject::CF_KINEMATIC_OBJECT;
        }

        if( bObject->gameflag & OB_GHOST ) {
            mCollisionFlag = mCollisionFlag | btCollisionObject::CF_NO_CONTACT_RESPONSE;
        }

        //No sleeping
        if( bObject->gameflag & OB_COLLISION_RESPONSE ) {
            mIsNoSleeping = true;
        }
        else {
            mIsNoSleeping = false;
        }

        //collision mask
        mColGroup = bObject->col_group;
        mColMask = bObject->col_mask;

        //Set the compound flag for later
        if( bObject->gameflag & OB_CHILD ) {
            mIsCompound = true;
        }
        else {
            mIsCompound = false;
        }

        parseConstraints( bObject );

        //signal that is a physics object
        isPhysics = true;
    }

    return isPhysics;
}

void yPhysicsMetaData::parseConstraints( Blender::Object* bObject ) {

    //Look for Constraints
    for( Blender::bConstraint* bConstraint = (Blender::bConstraint*)bObject->constraints.first; bConstraint; bConstraint = bConstraint->next ) {

        Constraint::ConstraintData constraintData;

        //Omit if its Disabled
        if( bConstraint->flag & 512 ) {
            continue;
        }

        //Generate RigidBody Constraints
        if( bConstraint->type == CONSTRAINT_TYPE_RIGIDBODYJOINT ) {

            //Get the blender Constraint
            Blender::bRigidBodyJointConstraint *jointConstraint = (Blender::bRigidBodyJointConstraint*)bConstraint->data;
            if( !jointConstraint->tar ) {
                continue;
            }

            //Get the target Object
            constraintData.mTargetObjectName = GET_NAME(jointConstraint->tar);

            //Check if linked Collision is disbled
            constraintData.mDisableCollisionBetweenLinkedBodies = (jointConstraint->flag & CONSTRAINT_DISABLE_LINKED_COLLISION);

            //pivot
            Ogre::Vector3 pivot( yUtils::convertToYup(Ogre::Vector3(jointConstraint->pivX,jointConstraint->pivY,jointConstraint->pivZ)) );
            constraintData.mPivot = yUtils::ogreToBullet(pivot);

            //localConstraintFrameBasis
            const float radsPerDeg = 0.01745329251994329508888888888889f; // 6.283185307179586232f / 360.f;
            btMatrix3x3 localCFrame;
            Ogre::Vector3 axis( yUtils::convertToYup(Ogre::Vector3(jointConstraint->axX,jointConstraint->axY,jointConstraint->axZ)));
            localCFrame.setEulerZYX(radsPerDeg*axis.x,radsPerDeg*axis.y,radsPerDeg*axis.z);
            constraintData.mAxisInA = localCFrame.getColumn(0);

            //constraint type
            if( jointConstraint->type == CONSTRAINT_RB_BALL ) {
                constraintData.mConstraintType = Constraint::BALL;
            }
            else if( jointConstraint->type == CONSTRAINT_RB_GENERIC6DOF ) {
                constraintData.mConstraintType = Constraint::GENERIC6DOF;
            }
            else if( jointConstraint->type == CONSTRAINT_RB_HINGE ) {
                constraintData.mConstraintType = Constraint::HINGE;
            }
            else {
                //constraint no supported, just not add and continue
                continue;
            }

            //minLimit > maxLimit means free(disabled limit) for this degree of freedom
            constraintData.mMinLimit.resize(6, 1);
            constraintData.mMaxLimit.resize(6, -1);

            //check limits setted
            int dofbit = 1;
            for( int dofIndex = 0; dofIndex < 6; ++dofIndex ) {
                int dof = dofIndex;
                if( dof == 1 ) {
                    dof = 2;
                }
                else if(dof==2) {
                    dof = 1;
                }
                else if(dof==4) {
                    dof = 5;
                }
                else if(dof==5) {
                    dof = 4;
                }

                if( jointConstraint->flag & dofbit ) {
                    constraintData.mMinLimit[dof] = jointConstraint->minLimit[dofIndex];
                    constraintData.mMaxLimit[dof] = jointConstraint->maxLimit[dofIndex];
                }
                dofbit<<=1;
            }

            mConstraints.push_back(constraintData);
        }
    }

}

btCollisionShape* yPhysicsMetaData::createCollisionShape() {

    btCollisionShape* colShape = nullptr;

    if( mType == OB_BOUND_SPHERE ){
        colShape = new btSphereShape( mBoundingRadius );
    }
    else if( mType == OB_BOUND_CONE ) {
        colShape = new btConeShape( mBoundingRadius, mHalfExtends.getY() );
    }
    else if( mType == OB_BOUND_CYLINDER ){
        colShape = new btCylinderShape( mHalfExtends );
    }
    else if( mType == OB_BOUND_CONVEX_HULL || mType == OB_BOUND_TRIANGLE_MESH ){

        btTriangleMesh* meshInterface = new btTriangleMesh();
        for( size_t i = 0; i < mTriangleData.size(); ++i ) {
            meshInterface->addTriangle(mTriangleData[i].v0Pos,mTriangleData[i].v1Pos,mTriangleData[i].v2Pos, mUseBvh);
        }

        if( mUseBvh ) {
            //we could use the meshInterface to create the btBvhTriangleMesh, however
            //we could want modify the shape run time, so we need to store the vertexs
            //and indexs arrays to easily modify it in the future
            unsigned char *gVertices;
            int totalVerts;
            int vertStride;
            PHY_ScalarType vertType;

            unsigned char *gIndices;
            int indexStride;
            int numFaces;
            PHY_ScalarType indexType;

            //get vertex and index arrays
            meshInterface->getLockedVertexIndexBase(&gVertices, totalVerts, vertType, vertStride,
                                                    &gIndices, indexStride, numFaces, indexType,
                                                    0 );

            //convert vertex unsigned char array to btVector3 array
            btVector3 *vertexs = new btVector3[totalVerts];
            for( size_t i = 0; i < totalVerts; i++ ) {
                float x, y, z;
                x = *(float *)(gVertices);
                y = *(float *)(gVertices + sizeof(float));
                z = *(float *)(gVertices + sizeof(float) * 2);
                gVertices += vertStride;
                vertexs[i] = btVector3(x,y,z);
            }

            //convert index unsigned char array to int array
            int *indexs = new int[numFaces*3];
            for( size_t i = 0; i < numFaces*3; i++ ) {
                int value = *(int *)(gIndices);
                gIndices += sizeof(int);
                indexs[i] = value;
            }

            //unlock
            meshInterface->unLockVertexBase(0);

            //create the triangle index array
            btTriangleIndexVertexArray* indexVertexArrays = new btTriangleIndexVertexArray(numFaces,
                                                                                           indexs,
                                                                                           indexStride,
                                                                                           totalVerts,
                                                                                           (btScalar*) &vertexs[0].x(),
                                                                                            vertStride );

            //set vertex and index arrays in yObject
//            mTriangleVertices = vertexs;
//            mTriangleTotalVert = totalVerts;
//            mTriangleIndexs = indexs;
//            mTriangleTotalIndexs = numFaces * 3;

            //create shape
            colShape = new btBvhTriangleMeshShape( indexVertexArrays, true );
        }
        else if( mType == OB_BOUND_CONVEX_HULL ){
            colShape = new btConvexTriangleMeshShape(meshInterface);
        }
        else {
            //Create a GImpactMeshShape
            btGImpactMeshShape* gimpact = new btGImpactMeshShape(meshInterface);
            gimpact->postUpdate();
            gimpact->updateBound();
            colShape = gimpact;
        }

    }
    //In any Other case, make it Box
    else{
        if( mIsPlane ) {
            colShape = new btStaticPlaneShape(mHalfExtends, 0); //floorPlane
        }
        else {
            colShape = new btBoxShape( mHalfExtends );
        }
    }
    colShape->setMargin( mColShapeMargin );

    return colShape;
}

bool yPhysicsMetaData::isStatic() {
    return mIsStatic;
}

bool yPhysicsMetaData::isKinematic() {
    return mIsKinematic;
}

bool yPhysicsMetaData::isCompound() {
    return mIsCompound;
}

bool yPhysicsMetaData::isNoSleeping() {
    return mIsNoSleeping;
}

float yPhysicsMetaData::getMass() {
    return mMass;
}

float yPhysicsMetaData::getDampingLinear() {
    return mDampingLinear;
}

float yPhysicsMetaData::getDampingAngular() {
    return mDampingAngular;
}

float yPhysicsMetaData::getFriction() {
    return mFriction;
}

short yPhysicsMetaData::getColGroup() {
    return mColGroup;
}

short yPhysicsMetaData::getColMask() {
    return mColMask;
}

int yPhysicsMetaData::getCollisionFlag() {
    return mCollisionFlag;
}

Ogre::FastArray<Constraint::ConstraintData>& yPhysicsMetaData::getConstraintsData() {
    return mConstraints;
}
