#include "yBlendMetaData.h"
#include "yObjectMetaData.h"
#include "Objects/yObjectInstance.h"
#include "Objects/yObject.h"
#include "ySceneMetaData.h"
#include "Macros/yMacros.h"
#include "iostream"

yBlendMetaData::yBlendMetaData()
{
    mBlendFileName = "";
    mScene = nullptr;

    /** @todo create custom memory pool to not reserve useless memory **/
    //mObjects.reserve(10000);
    //mGroups.reserve(1000);
}

void yBlendMetaData::setBlendFileName( std::string blendFile ) {
    mBlendFileName = blendFile;
}

void yBlendMetaData::addGroup( yObjectMetaData* group ) {
    yAssert( mBlendFileName != "", "you must tell me what blendfile I am before add objects" );

    // only save groups they are in the same blendfile that me
    if( group->getBlendFileName() == mBlendFileName ) {
        mGroups.addData(group->getObjectName(), group);
    }
}

void yBlendMetaData::addObject( yObjectMetaData* object ) {
    yAssert( mBlendFileName != "", "you must tell me what blendfile I am before add objects" );

    // only save objects they are in the same blendfile that me
    if( object->getBlendFileName() == mBlendFileName ) {
        mObjects.addData( object->getObjectName(), object );
    }
}

void yBlendMetaData::setSceneInfo( ySceneMetaData* scene ) {
    yAssert( scene, "you can't set a null scene info" );
    yAssert( !mScene, "rewrite scene info is not allowed" );
    mScene = scene;
}

void yBlendMetaData::fillObjectInstance(yObjectInstance& objectInstance, std::string objectName, yObjectType::Type type ) {

    yObjectMetaData* object = mObjects.getData( objectName );

    // fill
    yAssert( object, ("I don't have the object: " + objectName).c_str() );
    yAssert( object->getObjectType() == type, ("object type does not match. This is a error!. Object: " + objectName).c_str() );
    fillObjectData( objectInstance, *object );

    return;
}

void yBlendMetaData::fillGroupInstance( yObjectInstance& objectInstance, std::string objectName ) {

    yObjectMetaData* object = mGroups.getData( objectName );

    // fill
    yAssert( object, ("I don't have the group: " + objectName).c_str() );
    fillObjectData( objectInstance, *object );

    return;
}

void yBlendMetaData::fillObjectData( yObjectInstance& objectInstance, yObjectMetaData& objectData ) {

    // set object position
    yTransform transf;
    objectData.getTransform( transf.position, transf.orientation, transf.scale );
    objectInstance.getObject()->setInitialTransform(transf);

    // fill logic stuffs
    yObjectDefinition definitionEngine;
    Ogre::FastArray<yObjectMetaData*>& subObjects = objectData.getSubObjects();
    for( size_t i = 0; i < subObjects.size(); ++i ) {
        definitionEngine.addDefinitionSubObject( subObjects[i]->getObjectName(),
                                                 subObjects[i]->getBlendFileName(),
                                                 subObjects[i]->getObjectType() );
    }

    Ogre::FastArray<yObjectMetaData*>& childObjects = objectData.getChildsObjects();
    for( size_t i = 0; i < childObjects.size(); ++i ) {
        definitionEngine.addDefinitionChildObject( childObjects[i]->getObjectName(),
                                                   childObjects[i]->getBlendFileName(),
                                                   childObjects[i]->getObjectType(),
                                                   childObjects[i]->getLayerBit() );
    }

    yObjectDefinition::Definition definition;
    definition.mObjectName = objectData.getObjectName();
    definition.mLayerBit = objectData.getLayerBit();
    definition.mBlendFileName = objectData.getBlendFileName();
    definition.mPhysicsMetaData = objectData.getPhysicsMetaData();
    definition.mSoundMetaData = objectData.getSoundMetaData();
    definition.mCurveMetaData = objectData.getCurveMetaData();
    definition.mActuatorProperties = objectData.getActuatorProperties();
    definition.mHalfBoundingBox = objectData.getHalfBoundingBox();
    definitionEngine.setDefinition(definition);
    objectInstance.setObjectDefinition(definitionEngine);


    //fill graphics stuffs
    yObjectDefinitionGraphics::Definition definitionGraphics;
    definitionGraphics.mAnimationMetaData = objectData.getAnimationMetaData();
    definitionGraphics.mMeshMetaData = objectData.getMeshMetaDataPtr();
    definitionGraphics.mLightMetaData = objectData.getLightMetaData();
    definitionGraphics.mCameraMetaData = objectData.getCameraMetaData();
    definitionGraphics.mMaterialMetaData = objectData.getMaterialMetaData();
    definitionGraphics.mParticleMetaData = objectData.getParticleMetaData();
    objectInstance.setObjectDefinitionGraphics(definitionGraphics);
}

yObjectMetaData* yBlendMetaData::getObjectMetaData( std::string objectName ) {
    return mObjects.getData( objectName );
}

void yBlendMetaData::getObjectNames( int layer,
                                     Ogre::FastArray<std::string>& objectsName,
                                     Ogre::FastArray<yObjectType::Type>& objectsType,
                                     Ogre::FastArray<bool>& objectsHasParent ) {
    yAssert( 0 <= layer && layer < 20, "layer value must be between 0 and 20" );
    const int layerBit = yUtils::layerToLayerBit( layer );
    for( size_t i = 0; i < mObjects.size(); ++i ) {
        yObjectMetaData* object = mObjects[i];
        if( object->getLayerBit() & layerBit ) {
            objectsName.push_back( object->getObjectName() );
            objectsType.push_back( object->getObjectType() );
            objectsHasParent.push_back( object->getParent() );
        }
    }
}

bool yBlendMetaData::findObjectNames( std::string objectName,
                                      yObjectType::Type& objectType,
                                      bool& objectHasParent,
                                      int& layerBit ) {
    bool find = false;
    yObjectMetaData* data = mObjects.getData(objectName);
    if( data ) {
        objectType = data->getObjectType();
        objectHasParent = data->getParent();
        layerBit = data->getLayerBit();
        find = true;
    }
    return find;
}

yObjectMetaData* yBlendMetaData::getGroupMetaData( std::string groupName ) {
    return mGroups.getData( groupName );
}

ySceneMetaData* yBlendMetaData::getSceneMetaData() {
    return mScene;
}
