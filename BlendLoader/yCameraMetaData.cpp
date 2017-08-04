#include "yCameraMetaData.h"
#include "BlenderSerialize/Serialize/BlenderSerialize/blend263/Blender.h"
#include "BlenderSerialize/BlenderDefines.h"
#include "Macros/yMacros.h"

yCameraMetaData::yCameraMetaData() {
}

bool yCameraMetaData::parser( Blender::Object* bObjCamera ) {

    yAssert( bObjCamera, "bObject null" );

    if( bObjCamera->type != OB_CAMERA ) {
        return false;
    }

    Blender::Camera* bCamera = static_cast<Blender::Camera*>( bObjCamera->data );
    mFarClipDistance = bCamera->clipend;

    //Obtain the Fov from the blender main Camera (is not working perfect but good enough)
    float forceAspectRatio = 16.0f / 9.0f;
    float mFovNoAspectRatio = 360.0f * Ogre::Math::ATan(16.0f / bCamera->lens).valueRadians() / Ogre::Math::PI;
    mFov = 2 * Ogre::Math::ATan(Ogre::Math::Tan(mFovNoAspectRatio * Ogre::Math::PI / 360.0) / forceAspectRatio ).valueRadians();

    return true;
}

float yCameraMetaData::getFarClipDistance() {
    return mFarClipDistance;
}

Ogre::Radian yCameraMetaData::getFov() {
    return mFov;
}
