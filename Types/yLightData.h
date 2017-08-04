#ifndef YLIGHTDATA_H
#define YLIGHTDATA_H

#include <string>
#include "OgreColourValue.h"
#include "OgreLight.h"

struct yLightData{
    Ogre::ColourValue mColor;
    float mEnergy;
    Ogre::Light::LightTypes mType;
    bool mNightOnly;
};

#endif // YLIGHTDATA_H
