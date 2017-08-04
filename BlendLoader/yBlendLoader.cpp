#include "yBlendLoader.h"
#include "yBlendMetaData.h"
#include "yObjectMetaData.h"
#include "yMeshMetaData.h"
#include "yLightMetaData.h"
#include "Objects/yObjectManagerMetaData.h"
#include "ySceneMetaData.h"
#include "yCameraMetaData.h"
#include "yPhysicsMetaData.h"
#include "ySoundMetaData.h"
#include "yMaterialMetaData.h"
#include "yCurveMetaData.h"
#include "yAnimationMetaData.h"
#include "yParticleMetaData.h"

#include "BlenderSerialize/Serialize/BlenderSerialize/blend263/Blender.h"
#include "BlenderSerialize/Serialize/BlenderSerialize/bBlenderFile.h"
#include "BlenderSerialize/Serialize/BlenderSerialize/bMain.h"
#include "BlenderSerialize/BlenderDefines.h"
#include "Constants/yConstantsBlend.h"

#include <QString>
#include <QDir>

#include <iostream>
#include "Macros/yMacros.h"


#define GET_NAME(x) ((x) && (x)->id.name[0] != '0' ? (x)->id.name + 2 : "")

yBlendLoader::yBlendLoader( yObjectManagerMetaData* manager )
{
    yAssert( manager, "manager can't be null" );
    mManagerMetaData = manager;
}

void yBlendLoader::loadFile( std::string blendFileName, yBlendMetaData* storeData ) {

    // Parse blendFile
    bParse::bBlenderFile *blendFile = new bParse::bBlenderFile(blendFileName.c_str());
    if( blendFile->ok() ) {
        blendFile->parse(false);

        Blender::FileGlobal *bFile = (Blender::FileGlobal*)blendFile->getFileGlobal();
        Blender::Scene *bScene = bFile->curscene;

        // for every Object in the blendFile
        for (Blender::Base *base = (Blender::Base*)bScene->base.first; base; base = base->next)
        {
            Blender::Object *bObject = base->object;

            // Last Layer is reserved for testing inside Blender
            if( !bObject || bObject->lay == yUtils::layerToLayerBit(19) || !isCompatibleObject(bObject) ) {
                continue;
            }

            generateObject( storeData, bObject, blendFileName );
        }

        // for every Group in the blendfile
        bParse::bListBasePtr *iter = blendFile->getMain()->getGroup();
        for(int i=0; i<iter->size(); i++) {
            // save groups to let the user create it
            Blender::Group *bGroup = (Blender::Group*)iter->at(i);
            generateGroup( storeData, bGroup, blendFileName );
        }

        // finally, store scene info (only if the blendfile is the main blendfile)
        if( yUtils::normalizeBlendPath(blendFileName) == yUtils::normalizeBlendPath(yConstantsBlend::MAIN_BLENDFILE) ) {
            storeData->setSceneInfo( parseSceneInfo( bScene, blendFile ) );
        }
    }
    else {
        std::cout << yWarning << "Unable to open file: '" << blendFileName << "'. Not found" << std::endl;
    }

    // clean memory
    delete blendFile;
}

bool yBlendLoader::isCompatibleObject( Blender::Object* bObject ) {
    return ( bObject->type == OB_MESH || bObject->type == OB_EMPTY || bObject->type == OB_CAMERA || bObject->type == OB_LAMP || bObject->type == OB_CURVE || bObject->type == OB_FONT );
}

yObjectMetaData* yBlendLoader::generateGroup( yBlendMetaData* storeData, Blender::Group* bGroup, std::string blendFileName ) {

    // get group name
    std::string groupName = GET_NAME(bGroup);

    // always create
    yObjectMetaData* newObject = storeData->getGroupMetaData( groupName );
    if( newObject ) return newObject;

    // ok, really is not created... create it!
    newObject = new yObjectMetaData();

    // set the group in center
    Ogre::Vector3 p(0,0,0);
    Ogre::Quaternion q(1,0,0,0);
    Ogre::Vector3 s(1,1,1);
    newObject->setTransform( p, q ,s );

    // set names and layer
    newObject->setNames( groupName, blendFileName );
    newObject->setLayer( bGroup->layer & ~yUtils::layerToLayerBit(19) );
    newObject->setObjectType( yObjectType::GROUP );

    //Now generate every Object from that Group
    for (Blender::GroupObject *bGroupObject = (Blender::GroupObject*)bGroup->gobject.first; bGroupObject; bGroupObject = bGroupObject->next)
    {
        Blender::Object *bSubObject = bGroupObject->ob;

        // maybe an empty group?
        if( !bSubObject ) {
            continue;
        }

        // Last Layer is reserved for testing inside Blender
        if( bSubObject->lay == yUtils::layerToLayerBit(19) ) {
            continue;
        }

        // generate and add subObjects of this group
        if( isCompatibleObject(bSubObject) ){
            std::string motive = "The group " + groupName + " has the object " + GET_NAME(bSubObject) + " that no exist in the blend file " + blendFileName;
            yAssert( storeData->getObjectMetaData( GET_NAME(bSubObject) ), motive.c_str() );
            yObjectMetaData* subObject = generateObject( storeData, bSubObject, blendFileName);
            newObject->addSubObject( subObject );
        }
    }

    storeData->addGroup(newObject);
    return newObject;
}

yObjectMetaData* yBlendLoader::generateObject( yBlendMetaData* storeData, Blender::Object* bObject, std::string blendFileName ) {

    // get object name
    std::string objectName = GET_NAME(bObject);

    // check if the object exist in other blendfile (if so, we don't need create it)
    yObjectMetaData* newObject = mManagerMetaData->getObjectMetaData( objectName, blendFileName );
    if( newObject ) return newObject;

    // the object does not exist in other blendfile.
    // Maybe is in this blendfile, check if already we create it in the load process
    newObject = storeData->getObjectMetaData( objectName );
    if( newObject ) return newObject;

    // ok, really is not created... create it!
    newObject = new yObjectMetaData();

    // check parent, retrieve or create it
    yObjectMetaData* parentObject = nullptr;
    if( bObject->parent && isCompatibleObject( bObject->parent ) ){

        //Generate or retrieve the parent Object
        parentObject = generateObject( storeData, bObject->parent, blendFileName );
        yAssert( parentObject,
                  std::string( "Warning: Object '" + objectName + "' is looking for a parent named '" +
                               GET_NAME(bObject->parent) + "', but it could not be created (Maybe is in layer 20?)").c_str() );
        newObject->setParent( parentObject );
        parentObject->addChildObjects( newObject );
    }

    // set names and layer
    newObject->setNames( objectName, blendFileName );
    newObject->setLayer( bObject->lay );

    // parse spatial information
    Ogre::Vector3 p; Ogre::Quaternion q; Ogre::Vector3 s;
    parseSpatialTransform( bObject, parentObject, p, q, s );
    newObject->setTransform( p, q ,s );

    // parse aabb
    newObject->setAabb( parseAabb( bObject ) );

    // parse animation
    std::string skelName = "";
    yAnimationMetaData* animation = parseAnimation( bObject, blendFileName );
    if( animation ) {
        newObject->addAnimationMetaData( animation );
        if( animation->getAnimationSkeleton() ) {
            skelName = animation->getAnimationSkeleton()->mSkeletonName;
        }
    }

    // parse particle
    yParticleMetaData* particle = parseParticle( bObject, newObject->getAabb() );
    if( particle ) {
        newObject->addParticleMetaData( particle );
    }

    // parse mesh
    yMeshMetaData* mesh = parseMesh( bObject, blendFileName, skelName, false );
    if( mesh ) {
        if( mesh->isNavMesh() ) {
            newObject->setObjectType( yObjectType::NAVMESH );
        }
        else {
            newObject->setObjectType( yObjectType::BASIC );
        }
        newObject->addMeshMetaData( mesh );

        // parse materials
        yMaterialMetaData* material = parseMaterial( bObject, blendFileName, mesh->getNumSubMeshes() );
        if( material ) {
            newObject->addMaterialMetaData( material );
        }
    }

    // parse physics
    yPhysicsMetaData* physics = parsePhysics( bObject, newObject->getAabb() );
    if( physics ) {
        newObject->setObjectType( yObjectType::BASIC );
        newObject->addPhysicsMetaData( physics );
    }

    // parse light
    yLightMetaData* light = parseLight( bObject );
    if( light ) {
        newObject->setObjectType( yObjectType::LIGHT );
        newObject->addLightMetaData( light );
    }

    // parse camera
    yCameraMetaData* camera = parseCamera( bObject );
    if( camera ) {
        newObject->setObjectType( yObjectType::CAMERA );
        newObject->addCameraMetaData( camera );
    }

    // parse sound
    ySoundMetaData* sound = parseSound( bObject, blendFileName );
    if( sound ) {
        newObject->addSoundMetaData( sound );
    }

    // parse actuator properties
    newObject->setActuatorProperties( parseActuatorProperties(bObject) );

    // parse yCurve
    yCurveMetaData* curve = parseCurve( bObject );
    if( curve ) {
        newObject->setObjectType( yObjectType::CURVE );
        newObject->addCurveMetaData( curve );
    }

    // generate subobjects
    Blender::Group *bDupliGroup = bObject->dup_group;
    if( bDupliGroup ) {
        newObject->setObjectType( yObjectType::GROUP );

        //two cases, the group definition is in another file or is in the same file
        if( bDupliGroup->id.lib ) {
            //other file, load
            std::string path = yUtils::normalizeBlendPath( blendFileName, std::string(bDupliGroup->id.lib->name) );
            mManagerMetaData->loadBlendFile(path);

            std::string groupName = GET_NAME(bDupliGroup);
            yObjectMetaData* group = mManagerMetaData->getGroupMetaData( groupName, path );
            yAssert( group, ("group not found in the target blend file, group: " + groupName + ", blendfile: " + blendFileName).c_str() );

            Ogre::FastArray<yObjectMetaData*>& subObjects = group->getSubObjects();
            for( size_t i = 0; i < subObjects.size(); ++i ) {
                yObjectMetaData* subObject = mManagerMetaData->getObjectMetaData( subObjects[i]->getObjectName(),
                                                                                  subObjects[i]->getBlendFileName() );
                newObject->addSubObject( subObject );
            }
        }
        else {
            //same file, just loop the group
            for (Blender::GroupObject *bGroupObject = (Blender::GroupObject*)bDupliGroup->gobject.first; bGroupObject; bGroupObject = bGroupObject->next)
            {
                Blender::Object *bSubObject = bGroupObject->ob;
                if( !bSubObject ) {
                    continue;
                }

                // Last Layer is reserved for testing inside Blender
                if( bSubObject->lay == yUtils::layerToLayerBit(19) ) {
                    continue;
                }

                if( isCompatibleObject(bSubObject) ) {
                    //Generate the subObject
                    yObjectMetaData* subObject = generateObject( storeData, bSubObject, blendFileName);
                    newObject->addSubObject( subObject );
                }
            }
        }
    }

    storeData->addObject(newObject);
    return newObject;
}

void yBlendLoader::parseSpatialTransform( Blender::Object* bObject, yObjectMetaData* parentObject, Ogre::Vector3& position, Ogre::Quaternion& orientation, Ogre::Vector3& scale ) {
    //get matrix in Z up coordinates (blender world space)
    Ogre::Matrix4 objectMat(
                bObject->obmat[0][0], bObject->obmat[1][0], bObject->obmat[2][0], bObject->obmat[3][0],
                bObject->obmat[0][1], bObject->obmat[1][1], bObject->obmat[2][1], bObject->obmat[3][1],
                bObject->obmat[0][2], bObject->obmat[1][2], bObject->obmat[2][2], bObject->obmat[3][2],
                bObject->obmat[0][3], bObject->obmat[1][3], bObject->obmat[2][3], bObject->obmat[3][3]
                );

    //convert orientation to our space.
    //we are in Y-up (Y space) and the original space is in Z-up (Z space),
    //so if we want apply the rotation A used in Z space in
    //the Y space (rotation A'), we need convert the rotation from Z space to Y space.
    //if the matrix to convert from space Z to Y is M, then the rotation in Y space is:
    //A' = M.inverse * A * M;

    //transformation matrix/quaternion
    Ogre::Quaternion M = Ogre::Quaternion::IDENTITY;

    //to go from Z to Y, we need rotate Z space respect X -90° and then respect Y 180°
    Ogre::Quaternion bufferTransf;
    bufferTransf.FromAngleAxis( Ogre::Degree(-90), Ogre::Vector3::UNIT_X );
    M = bufferTransf * M;
    bufferTransf.FromAngleAxis( Ogre::Degree(180), Ogre::Vector3::UNIT_Y );
    M = bufferTransf * M;
    Ogre::Matrix4 oriM;
    oriM.makeTransform( Ogre::Vector3(0,0,0), Ogre::Vector3(1,1,1), M );

    //child matrix (if has not parent, will be the final converted matrix)
    Ogre::Matrix4 childMat;

    //final matrix transformation (Y space)
    childMat = oriM.inverse() * objectMat * oriM;

    //parent matrix
    Ogre::Matrix4 parentMat = Ogre::Matrix4::IDENTITY;

    //If the Object has a Parent, get the global parent
    //transformation to make the current transformation local
    yObjectMetaData* parent = parentObject;
    while( parent ){

        Ogre::Vector3 p;
        Ogre::Quaternion q;
        Ogre::Vector3 s;
        parent->getTransform( p, q, s );
        Ogre::Matrix4 parentMatBuf = Ogre::Matrix4::IDENTITY;

        //fill parent matrix
        parentMatBuf.makeTransform( p, s, q );

        //convert space. Left operand is the space
        //where we go, right operand is the space where we are
        parentMat = parentMatBuf * parentMat;

        //update parent
        parent = parent->getParent();
    }

    //final transformation, make it local
    Ogre::Matrix4 finalMat = parentMat.inverse() * childMat;

    //final transformation
    Ogre::Vector3 p,s; Ogre::Quaternion q;
    /** @todo understand why finalMat.decomposition requires be a affine matrix
     * (assert is trigger by ogre there, so we copy the method here for the moment )
     * **/
    Ogre::Matrix3 m3x3;
    finalMat.extract3x3Matrix(m3x3);

    Ogre::Matrix3 matQ;
    Ogre::Vector3 vecU;
    m3x3.QDUDecomposition( matQ, s, vecU );

    q = Ogre::Quaternion( matQ );
    p = Ogre::Vector3( finalMat[0][3], finalMat[1][3], finalMat[2][3] );

    //when is a camera or light object, the direction in blender is different
    //to the rest of the world, so we need to offset a little more to be
    //consistent with the blender view
    if( bObject->type == OB_CAMERA || bObject->type == OB_LAMP ) {
        //the transform to apply is basically rotate the object to be like Z up space,
        //but their coordinates still remains in Y up space
        Ogre::Quaternion M = Ogre::Quaternion::IDENTITY;
        Ogre::Quaternion bufferTransf;
        bufferTransf.FromAngleAxis( Ogre::Degree(90), Ogre::Vector3::UNIT_X );
        M = bufferTransf * M;
        bufferTransf.FromAngleAxis( Ogre::Degree(180), Ogre::Vector3::UNIT_Z );
        M = bufferTransf * M;
        q = q * M;
    }

    //set values
    position = p;
    orientation = q;
    scale = s;
}

Ogre::Aabb yBlendLoader::parseAabb( Blender::Object* bObject ) {
    Ogre::Aabb aabb;
    Blender::Mesh* bMesh = (Blender::Mesh*)bObject->data;

    if( bMesh && bObject->type == OB_MESH ) {
        Ogre::Vector3 minBB(Ogre::Vector3::UNIT_SCALE*FLT_MAX);
        Ogre::Vector3 maxBB(Ogre::Vector3::UNIT_SCALE*-FLT_MAX);

        //Using blender's mesh data, similar to generateMesh method
        Blender::MPoly *mpoly = bMesh->mpoly;
        Blender::MLoop *mloop = bMesh->mloop;
        for (int fi = 0; fi < bMesh->totpoly; fi++)
        {
            const Blender::MPoly& curpoly = mpoly[fi];
            const bool isQuad = (curpoly.totloop == 4);
            for( size_t i = 0; i < 3 + isQuad; ++i ){
                Ogre::Vector3 vertex = yUtils::convertToYup( Ogre::Vector3(bMesh->mvert[mloop[curpoly.loopstart+i].v].co[0],bMesh->mvert[mloop[curpoly.loopstart+i].v].co[1],bMesh->mvert[mloop[curpoly.loopstart+i].v].co[2]) );

                minBB.makeFloor(vertex);
                maxBB.makeCeil(vertex);
            }
        }

        aabb.merge(minBB);
        aabb.merge(maxBB);
    }

    return aabb;
}

std::map<std::string, std::string> yBlendLoader::parseActuatorProperties( Blender::Object* bObject ) {
    std::map<std::string, std::string> data;
    for( Blender::bActuator *bActuator = (Blender::bActuator*)bObject->actuators.first; bActuator; bActuator = bActuator->next ) {
        if( bActuator->type == ACT_PROPERTY ) {
            Blender::bPropertyActuator *bPropActuator = (Blender::bPropertyActuator*)bActuator->data;
            data[std::string(bActuator->name)] = std::string(bPropActuator->value);
        }
    }
    return data;
}

yMeshMetaData* yBlendLoader::parseMesh( Blender::Object* bObject, std::string blendFileName, std::string skeletonName, bool isBoneControlled ) {
    yMeshMetaData* mesh = new yMeshMetaData();
    if( !mesh->parser( blendFileName, bObject, skeletonName, isBoneControlled ) ) {
        delete mesh;
        mesh = nullptr;
    }
    return mesh;
}

yLightMetaData* yBlendLoader::parseLight( Blender::Object* bObject ) {
    yLightMetaData* light = new yLightMetaData();
    std::string name = GET_NAME(bObject);
    if( !light->parser( name, bObject ) ) {
        delete light;
        light = nullptr;
    }
    return light;
}

yCameraMetaData* yBlendLoader::parseCamera( Blender::Object* bObject ) {
    yCameraMetaData* camera = new yCameraMetaData();
    if( !camera->parser( bObject ) ) {
        delete camera;
        camera = nullptr;
    }
    return camera;
}

ySoundMetaData* yBlendLoader::parseSound( Blender::Object* bObject, std::string blendFileName ) {
    ySoundMetaData* sound = new ySoundMetaData();
    if( !sound->parser( bObject, blendFileName ) ) {
        delete sound;
        sound = nullptr;
    }
    return sound;
}

yCurveMetaData* yBlendLoader::parseCurve( Blender::Object* bObject ) {
    yCurveMetaData* curve = new yCurveMetaData();
    if( !curve->parser( bObject ) ) {
        delete curve;
        curve = nullptr;
    }
    return curve;
}

yMaterialMetaData* yBlendLoader::parseMaterial( Blender::Object* bObject, std::string blendFileName, int materialCount ) {
    yMaterialMetaData* material = new yMaterialMetaData();
    if( !material->parser( bObject, blendFileName, materialCount ) ) {
        delete material;
        material = nullptr;
    }
    return material;
}

ySceneMetaData* yBlendLoader::parseSceneInfo( Blender::Scene* bScene, bParse::bBlenderFile* blendFile ) {

    ySceneMetaData* data = new ySceneMetaData();

    Blender::World* bWorld = bScene->world;
    data->setAmbientLightProperties( Ogre::ColourValue( bWorld->ambr, bWorld->ambg, bWorld->ambb ),
                                     Ogre::ColourValue( bWorld->zenr, bWorld->zeng, bWorld->zenb ),
                                     Ogre::Vector3::UNIT_Y );

    if( bWorld->mode & WO_MIST ) {
        data->setFogProperties( Ogre::FOG_LINEAR,
                                Ogre::ColourValue( bWorld->horr, bWorld->horg, bWorld->horb ),
                                0,
                                bWorld->miststa,
                                bWorld->miststa + bWorld->mistdist );
    }


    bParse::bListBasePtr *iter = blendFile->getMain()->getLamp();
    for(int i=0; i<iter->size(); i++)
    {
        Blender::Lamp *bLight = (Blender::Lamp*)iter->at(i);

        //only use the data of the first one find it
        if( std::string(GET_NAME(bLight)) == "Lamp" || std::string(GET_NAME(bLight)) == "Sun" ){

            float distance = bLight->clipend;
            float bias = bLight->bleedbias;
            float pssmLambda = bLight->bias;
            int pssmSplits = std::max( 2, std::min( 4, (int)bLight->shadow_frustum_size ) );

            data->setShadowParams( distance, bias, pssmLambda, pssmSplits );
            break;
        }
    }

    return data;
}

yPhysicsMetaData* yBlendLoader::parsePhysics( Blender::Object* bObject, Ogre::Aabb aabb ) {
    yPhysicsMetaData* physics = new yPhysicsMetaData();
    if( !physics->parser( bObject, aabb ) ) {
        delete physics;
        physics = nullptr;
    }
    return physics;
}

yAnimationMetaData* yBlendLoader::parseAnimation( Blender::Object* bObject, std::string blendFileName ) {
    yAnimationMetaData* animation = new yAnimationMetaData();
    if( !animation->parser( bObject, blendFileName ) ) {
        delete animation;
        animation = nullptr;
    }
    return animation;
}

yParticleMetaData* yBlendLoader::parseParticle( Blender::Object* bObject, Ogre::Aabb aabb ) {
    yParticleMetaData* particle = new yParticleMetaData();
    if( !particle->parser( bObject, aabb ) ) {
        delete particle;
        particle = nullptr;
    }
    return particle;
}
