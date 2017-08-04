#include "ySceneMetaData.h"
#include "Macros/yMacros.h"

ySceneMetaData::ySceneMetaData() {
    mAmbientLightHemisphereUpper = Ogre::ColourValue();
    mAmbientLightHemisphereLower = Ogre::ColourValue(0,0,0);
    mAmbientLightHemisphereDirection = Ogre::Vector3::UNIT_X;
    mFogMode = Ogre::FOG_NONE;
    mFogColor = Ogre::ColourValue();
    mFogDensity = 0;
    mFogLinearStart = 0;
    mFogLinearEnd = 999;
    mShadowFarDistance = 0;

    mAmbientSet = false;
    mFogSet = false;
    mShadowSet = false;
}

void ySceneMetaData::setAmbientLightProperties( Ogre::ColourValue hemisphereUpper, Ogre::ColourValue hemisphereLower, Ogre::Vector3 hemisphereDirection ) {
    mAmbientLightHemisphereUpper = hemisphereUpper;
    mAmbientLightHemisphereLower = hemisphereLower;
    mAmbientLightHemisphereDirection = hemisphereDirection;
    mAmbientSet = true;
}

void ySceneMetaData::setFogProperties( Ogre::FogMode mode, Ogre::ColourValue color, float density, float linearStart, float linearEnd ) {
    mFogMode = mode;
    mFogColor = color;
    mFogDensity = density;
    mFogLinearStart = linearStart;
    mFogLinearEnd = linearEnd;
    mFogSet = true;
}

void ySceneMetaData::setShadowParams( float distance, float bias, float pssmLambda, int pssmSplits ) {
    mShadowFarDistance = distance;
    mShadowBias = bias;
    mPssmLambda = pssmLambda;
    mPssmSplitsCount = pssmSplits;
    mShadowSet = true;
}

void ySceneMetaData::getAmbientLightProperties( Ogre::ColourValue& hemisphereUpper, Ogre::ColourValue& hemisphereLower, Ogre::Vector3& hemisphereDirection ) {
    yAssert( mAmbientSet, "request ambient data no setted" );
    hemisphereUpper = mAmbientLightHemisphereUpper;
    hemisphereLower = mAmbientLightHemisphereLower;
    hemisphereDirection = mAmbientLightHemisphereDirection;
}

void ySceneMetaData::getFogProperties( Ogre::FogMode& mode, Ogre::ColourValue& color, float& density, float& linearStart, float& linearEnd ) {
    yAssert( mFogSet, "request fog data no setted" );
    mode = mFogMode;
    color = mFogColor;
    density = mFogDensity;
    linearStart = mFogLinearStart;
    linearEnd = mFogLinearEnd;
}

float ySceneMetaData::getShadowFarDistance() {
    yAssert( mShadowSet, "request data no setted" );
    return mShadowFarDistance;
}

float ySceneMetaData::getPssmLambda(){
    yAssert( mShadowSet, "request data no setted" );
    return mPssmLambda;
}

int ySceneMetaData::getPssmSplitsCount(){
    yAssert( mShadowSet, "request data no setted" );
    return mPssmSplitsCount;
}
