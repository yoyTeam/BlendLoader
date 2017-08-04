#include "yLightMetaData.h"
#include "BlenderSerialize/Serialize/BlenderSerialize/blend263/Blender.h"
#include "BlenderSerialize/BlenderDefines.h"
#include "Macros/yMacros.h"

#include "OgreSceneManager.h"

yLightMetaData::yLightMetaData()
{
    mName = "";
    mCastShadow = false;
}

//Generate a light with blender's parameters
bool yLightMetaData::parser( std::string name, Blender::Object* bObject ) {

    yAssert( bObject, "bObject null" );

    if( bObject->type != OB_LAMP ) {
        return false;
    }

    // get light meta data
    Blender::Lamp* light = ( Blender::Lamp* )bObject->data;

    // set name
    mName = name;

    // Set them to Black if they are disabled, otherwise create the colors
    mColor = ( light->mode & LA_NO_DIFF ) ? Ogre::ColourValue::Black : mColor = Ogre::ColourValue( light->r, light->g, light->b );
    mEnergy = light->energy;    

    mNightOnly = ( light->mode & 4 ); //thisLayerOnly in blender is nightonly

    // Set some general light parameters
    mCastShadow = (light->mode & LA_SHAD_RAY) || ( light->type == LA_SPOT && (light->mode & LA_SHAD_BUF) );
    //if( light->type == LA_SPOT && yGraphicsSystem::getSingleton().getQualityLevel() == yGraphicsSystem::LOW_QUALITY ){
//    if( light->type == LA_SPOT ) {
//        mCastShadow = false;
//    }

    mAttenuationRange = 10000.0f;
    mAttenuationConstant = 1.0f;
    mAttenuationLinear = light->att1/light->dist;
    mAttenuationQuadratic = light->att2/(light->dist * light->dist);
    mAttenuationRadius = light->dist;
    mAttenuationLumThreshold = 0.99f;

    //Set particular parametes depending of light Type
    if( light->type == LA_SUN ) {
        mType = Ogre::Light::LT_DIRECTIONAL;
    }
    else if( light->type == LA_SPOT ) {
        mType = Ogre::Light::LT_SPOTLIGHT;
        float spotSize = Ogre::Radian(light->spotsize).valueDegrees();
        mSpotLightOuterAngleDegree = spotSize > 128 ? 128 : spotSize;
        mSpotLightInnerAngleDegree = (1-light->spotblend)*spotSize;
        mSpotLightClipDistance =  light->dist;
    }
    else {
        mType = Ogre::Light::LT_POINT;
    }

    return true;
}

Ogre::Light* yLightMetaData::generate( Ogre::SceneManager* manager ) {

    Ogre::Light* light = nullptr;

    //Create the Ogre Light, we always generate a new light when is request
    size_t index = mLight.size();
    mLight.push_back( manager->createLight() );
    yAssert( index == mLight.size() - 1, "someone create a light when we was creating one" );
    light = mLight[index];

    //Set some general light parameters
    light->setName(mName);
    light->setDiffuseColour(mColor);
    light->setSpecularColour(mColor);
    light->setCastShadows(mCastShadow);
    light->setPowerScale(mEnergy*50);
    light->setAttenuation( mAttenuationRange, mAttenuationConstant, mAttenuationLinear, mAttenuationQuadratic );
    light->setAttenuationBasedOnRadius( mAttenuationRadius, mAttenuationLumThreshold );
    light->setType( mType );

    if( mType == Ogre::Light::LT_SPOTLIGHT ) {
        light->setSpotlightOuterAngle( Ogre::Radian( Ogre::Degree( mSpotLightOuterAngleDegree ).valueRadians() ) );
        light->setSpotlightInnerAngle( Ogre::Radian( Ogre::Degree( mSpotLightInnerAngleDegree ).valueRadians() ) );
        light->setShadowFarClipDistance( mSpotLightClipDistance );
    }

    return light;
}
