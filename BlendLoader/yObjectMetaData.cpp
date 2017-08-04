#include "yObjectMetaData.h"
#include "BlendLoader/yAnimationMetaData.h"
#include "BlendLoader/yMeshMetaData.h"
#include "BlendLoader/yPhysicsMetaData.h"
#include "BlendLoader/yLightMetaData.h"
#include "BlendLoader/yCameraMetaData.h"
#include "BlendLoader/yCurveMetaData.h"
#include "Macros/yMacros.h"

yObjectMetaData::yObjectMetaData() {
    mAnimationMetaData = nullptr;
    mMeshMetaData = nullptr;
    mPhysicsMetaData = nullptr;
    mLightMetaData = nullptr;
    mCameraMetaData = nullptr;
    mSoundMetaData = nullptr;
    mMaterialMetaData = nullptr;
    mCurveMetaData = nullptr;
    mParticleMetaData = nullptr;
    mParent = nullptr;
    mType = yObjectType::NONE;
    mLayerBit = 0;
}

void yObjectMetaData::addAnimationMetaData( yAnimationMetaData* data ) {
    yAssert( data, "animation data can't be null" );
    yAssert( !mAnimationMetaData, "mesh overwrite is not allowed" );
    mAnimationMetaData = data;
}

void yObjectMetaData::addMeshMetaData( yMeshMetaData* data ) {
    yAssert( data, "mesh data can't be null" );
    yAssert( !mMeshMetaData, "mesh overwrite is not allowed" );
    mMeshMetaData = data;
}

void yObjectMetaData::addPhysicsMetaData( yPhysicsMetaData* data ) {
    yAssert( data, "physics data can't be null" );
    yAssert( !mPhysicsMetaData, "physics overwrite is not allowed" );
    mPhysicsMetaData = data;
}

void yObjectMetaData::addLightMetaData( yLightMetaData* data ) {
    yAssert( data, "light data can't be null" );
    yAssert( !mLightMetaData, "light overwrite is not allowed" );
    mLightMetaData = data;
}

void yObjectMetaData::addCameraMetaData( yCameraMetaData* data ) {
    yAssert( data, "Camera data can't be null" );
    yAssert( !mCameraMetaData, "Camera overwrite is not allowed" );
    mCameraMetaData = data;
}

void yObjectMetaData::addSoundMetaData( ySoundMetaData* data ) {
    yAssert( data, "Sound data can't be null" );
    yAssert( !mSoundMetaData, "Sound overwrite is not allowed" );
    mSoundMetaData = data;
}

void yObjectMetaData::addCurveMetaData( yCurveMetaData* data ) {
    yAssert( data, "Curve data can't be null" );
    yAssert( !mCurveMetaData, "Curve overwrite is not allowed" );
    mCurveMetaData = data;
}

void yObjectMetaData::addMaterialMetaData( yMaterialMetaData* data ) {
    yAssert( data, "Material data can't be null" );
    yAssert( !mMaterialMetaData, "Material overwrite is not allowed" );
    mMaterialMetaData = data;
}

void yObjectMetaData::addParticleMetaData( yParticleMetaData* data ) {
    yAssert( data, "Particle data can't be null" );
    yAssert( !mParticleMetaData, "Particle overwrite is not allowed" );
    mParticleMetaData = data;
}

void yObjectMetaData::setNames(std::string objectName, std::string blendFile) {
    yAssert( objectName != "", "object name cant be empty!");
    yAssert( mObjectName == "", ("name overwrite is not allowed. Original object: " + mObjectName + ", new object: " + objectName).c_str() );
    mObjectName = objectName;
    mBlendFile = blendFile;
}

void yObjectMetaData::setLayer( int layer ) {
    yAssert( layer != 0, "layer must be different to 0" );
    yAssert( mLayerBit == 0, "layer overwrite is not allowed" );
    yAssert( layer != yUtils::layerToLayerBit(19), "layer 19 is reserved to test in blender" );
    mLayerBit = layer;
}

void yObjectMetaData::setTransform( Ogre::Vector3 position, Ogre::Quaternion orientation, Ogre::Vector3 scale ) {
    /** @todo when transform generation is well defined, add an assert to not modify values **/
    mPosition = position;
    mOrientation = orientation;
    mScale = scale;
}

void yObjectMetaData::setAabb( Ogre::Aabb box ) {
    mAabb = box;
}

void yObjectMetaData::setActuatorProperties( std::map<std::string, std::string> data ) {
    mActuatorProperties = data;
}

void yObjectMetaData::addSubObject( yObjectMetaData* object ) {
    yAssert( object, "you can't add a null object meta data" );
    mSubObjects.push_back(object);
}

void yObjectMetaData::setObjectType( yObjectType::Type type ) {
    yAssert( mType == yObjectType::NONE || mType == type, ( "overwrite type is not allow, check the parser! Object: " + mObjectName ).c_str() );
    mType = type;
}

yAnimationMetaData* yObjectMetaData::getAnimationMetaData() {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    return mAnimationMetaData;
}

yMeshMetaData* yObjectMetaData::getMeshMetaDataPtr() {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    return mMeshMetaData;
}

yPhysicsMetaData* yObjectMetaData::getPhysicsMetaData() {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    return mPhysicsMetaData;
}

yLightMetaData* yObjectMetaData::getLightMetaData() {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    return mLightMetaData;
}

yCameraMetaData* yObjectMetaData::getCameraMetaData() {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    return mCameraMetaData;
}

yMaterialMetaData* yObjectMetaData::getMaterialMetaData() {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    return mMaterialMetaData;
}

ySoundMetaData* yObjectMetaData::getSoundMetaData() {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    return mSoundMetaData;
}

yCurveMetaData* yObjectMetaData::getCurveMetaData() {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    return mCurveMetaData;
}

yParticleMetaData* yObjectMetaData::getParticleMetaData() {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    return mParticleMetaData;
}

std::string yObjectMetaData::getObjectName() {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    return mObjectName;
}

std::string yObjectMetaData::getBlendFileName() {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    return mBlendFile;
}

int yObjectMetaData::getLayerBit() {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    yAssert( mLayerBit != 0, "object has not layer, probably data not loaded?");
    return mLayerBit;
}

void yObjectMetaData::getTransform( Ogre::Vector3& position, Ogre::Quaternion& orientation, Ogre::Vector3& scale ) {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    position = mPosition;
    orientation = mOrientation;
    scale = mScale;
}

Ogre::Aabb yObjectMetaData::getAabb() {
    return mAabb;
}

std::map<std::string, std::string> yObjectMetaData::getActuatorProperties() {
    return mActuatorProperties;
}

Ogre::Vector3 yObjectMetaData::getHalfBoundingBox() {
    return mAabb.getSize() * 0.5;
}

Ogre::FastArray<yObjectMetaData*>& yObjectMetaData::getSubObjects() {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    return mSubObjects;
}

yObjectType::Type yObjectMetaData::getObjectType() {
    yAssert( mObjectName != "", "object has not name, probably data not loaded?");
    //yAssert( mType != yObjectType::NONE, "type has not been set");
    return mType;
}

void yObjectMetaData::setParent( yObjectMetaData* object ) {
    yAssert( object, "you can't set a null parent" );
    mParent = object;
}

yObjectMetaData* yObjectMetaData::getParent() {
    return mParent;
}

void yObjectMetaData::addChildObjects( yObjectMetaData* object ) {
    yAssert( object, "you can't set a null child" );
    mChildObjects.push_back(object);
}

Ogre::FastArray<yObjectMetaData*>& yObjectMetaData::getChildsObjects() {
    return mChildObjects;
}
