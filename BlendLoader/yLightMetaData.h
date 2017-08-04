#ifndef YLIGHTMETADATA_H
#define YLIGHTMETADATA_H

#include <string>
#include "OgreColourValue.h"
#include "OgreLight.h"

namespace Blender {
    struct Object;
}

namespace Ogre {
    class Light;
    class SceneManager;
}

class yLightMetaData
{
    friend class yLightManager;
public:
    yLightMetaData();
    bool parser( std::string name, Blender::Object* bObject );
    Ogre::Light* generate( Ogre::SceneManager* manager );

private:
    std::string mName;
    Ogre::ColourValue mColor;
    float mEnergy;
    bool mCastShadow;
    Ogre::FastArray<Ogre::Light*> mLight;
    Ogre::Light::LightTypes mType;
    bool mNightOnly;
    float mAttenuationRange;
    float mAttenuationConstant;
    float mAttenuationLinear;
    float mAttenuationQuadratic;
    float mAttenuationRadius;
    float mAttenuationLumThreshold;
    float mSpotLightInnerAngleDegree;
    float mSpotLightOuterAngleDegree;
    float mSpotLightClipDistance;

};

#endif // YLIGHTMETADATA_H
