#ifndef YPARTICLEMETADATA_H
#define YPARTICLEMETADATA_H

#include "OgreVector3.h"
#include "OgreColourValue.h"

namespace Blender {
    struct Object;
}

class yParticleMetaData
{
public:
    struct ParticleData {
        int mParticlesCount;
        float mWidth;
        float mHeight;
        int mIterationInterval;
        bool mKeepParticleInLocalSpace;
        float mMaxTimeToLive;
        float mMinTimeToLive;
        float mDuration;
        float mRate;
        Ogre::Vector3 mDirection;
        float mMinVelocity;
        Ogre::Radian mAngle;
        Ogre::Vector3 mHalfBoundingSize;

        Ogre::FastArray<Ogre::ColourValue> mRampColor;
        Ogre::FastArray<float> mRampPos;

        bool mGravityAffector;
        float mGravityFactor;
        float mMass;
        bool mHasAvefac;
        Ogre::Radian mAvefac;
        float mRandRotFac;
    };

    yParticleMetaData();
    bool parser( Blender::Object* bObject, Ogre::Aabb aabb );
    const ParticleData& getParticleData( size_t index );
    size_t getParticleDataSize();

private:
    Ogre::FastArray<ParticleData> mParticleData;

};

#endif // YPARTICLEMETADATA_H
