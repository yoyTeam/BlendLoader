#ifndef YOBJECTMETADATA_H
#define YOBJECTMETADATA_H

#include <string>
#include "OgreVector3.h"
#include "Objects/Types/yObjectType.h"
#include "Math/Simple/OgreAabb.h"

class yAnimationMetaData;
class yMeshMetaData;
class yLightMetaData;
class yCameraMetaData;
class yPhysicsMetaData;
class ySoundMetaData;
class yMaterialMetaData;
class yCurveMetaData;
class yParticleMetaData;

class yObjectMetaData
{
public:
    yObjectMetaData();
    void addAnimationMetaData( yAnimationMetaData* data );
    void addMeshMetaData( yMeshMetaData* data );
    void addPhysicsMetaData( yPhysicsMetaData* data );
    void addLightMetaData( yLightMetaData* data );
    void addCameraMetaData( yCameraMetaData* data );
    void addSoundMetaData( ySoundMetaData* data );
    void addCurveMetaData( yCurveMetaData* data );
    void addMaterialMetaData( yMaterialMetaData* data );
    void addParticleMetaData( yParticleMetaData* data );
    void setNames( std::string objectName, std::string blendFile );
    void setLayer( int layer );
    void setTransform( Ogre::Vector3 position, Ogre::Quaternion orientation, Ogre::Vector3 scale );
    void setAabb( Ogre::Aabb box );
    void setActuatorProperties( std::map<std::string, std::string> data );
    void addSubObject( yObjectMetaData* object );
    void setObjectType( yObjectType::Type type );
    void setParent( yObjectMetaData* object );
    void addChildObjects( yObjectMetaData* object );

    yAnimationMetaData* getAnimationMetaData();
    yMeshMetaData* getMeshMetaDataPtr();
    yPhysicsMetaData* getPhysicsMetaData();
    yLightMetaData* getLightMetaData();
    yCameraMetaData* getCameraMetaData();
    ySoundMetaData* getSoundMetaData();
    yCurveMetaData* getCurveMetaData();
    yParticleMetaData* getParticleMetaData();
    yMaterialMetaData* getMaterialMetaData();
    std::string getObjectName();
    std::string getBlendFileName();
    int getLayerBit();
    void getTransform( Ogre::Vector3& position, Ogre::Quaternion& orientation, Ogre::Vector3& scale );
    Ogre::Aabb getAabb();
    std::map<std::string, std::string> getActuatorProperties();
    Ogre::FastArray<yObjectMetaData*> &getSubObjects();
    yObjectType::Type getObjectType();
    yObjectMetaData* getParent();
    Ogre::FastArray<yObjectMetaData*>& getChildsObjects();
    Ogre::Vector3 getHalfBoundingBox();

private:
    yAnimationMetaData* mAnimationMetaData;
    yMeshMetaData* mMeshMetaData;
    yPhysicsMetaData* mPhysicsMetaData;
    yLightMetaData* mLightMetaData;
    yCameraMetaData* mCameraMetaData;
    ySoundMetaData* mSoundMetaData;
    yCurveMetaData* mCurveMetaData;
    yMaterialMetaData* mMaterialMetaData;
    yParticleMetaData* mParticleMetaData;
    std::string mObjectName;
    std::string mBlendFile;
    Ogre::Vector3 mPosition;
    Ogre::Quaternion mOrientation;
    Ogre::Vector3 mScale;
    yObjectType::Type mType;
    Ogre::FastArray< yObjectMetaData* > mSubObjects;
    int mLayerBit;
    yObjectMetaData* mParent;
    Ogre::FastArray< yObjectMetaData* > mChildObjects;
    Ogre::Aabb mAabb;
    std::map<std::string, std::string> mActuatorProperties;
};

#endif // YOBJECTMETADATA_H
