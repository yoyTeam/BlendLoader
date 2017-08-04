#ifndef YSCENEMETADATA_H
#define YSCENEMETADATA_H

#include "OgreColourValue.h"
#include "OgreVector3.h"
#include "OgreCommon.h"

class ySceneMetaData
{
public:
    ySceneMetaData();

    void setAmbientLightProperties(Ogre::ColourValue hemisphereUpper, Ogre::ColourValue hemisphereLower, Ogre::Vector3 hemisphereDirection );
    void setFogProperties( Ogre::FogMode mode, Ogre::ColourValue color, float density, float linearStart, float linearEnd );
    void setShadowParams( float distance , float bias, float pssmLambda, int pssmSplits );

    void getAmbientLightProperties( Ogre::ColourValue& hemisphereUpper, Ogre::ColourValue& hemisphereLower, Ogre::Vector3& hemisphereDirection );
    void getFogProperties( Ogre::FogMode& mode, Ogre::ColourValue& color, float& density, float& linearStart, float& linearEnd );
    float getShadowFarDistance();
    float getPssmLambda();
    int getPssmSplitsCount();

    bool isAmbientSet()     { return mAmbientSet; }
    bool isFogSet()         { return mFogSet; }
    bool isShadowSet()      { return mShadowSet; }

private:
    Ogre::ColourValue mAmbientLightHemisphereUpper;
    Ogre::ColourValue mAmbientLightHemisphereLower;
    Ogre::Vector3 mAmbientLightHemisphereDirection;
    Ogre::FogMode mFogMode;
    Ogre::ColourValue mFogColor;
    float mFogDensity;
    float mFogLinearStart;
    float mFogLinearEnd;
    int mPssmSplitsCount;
    float mPssmLambda;
    float mShadowFarDistance;
    float mShadowBias;

    bool mAmbientSet;
    bool mFogSet;
    bool mShadowSet;
};

#endif // YSCENEMETADATA_H
