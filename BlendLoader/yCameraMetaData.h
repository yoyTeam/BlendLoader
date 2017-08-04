#ifndef YCAMERAMETADATA_H
#define YCAMERAMETADATA_H

#include "OgreMath.h"

namespace Blender {
    struct Object;
}

class yCameraMetaData
{
public:
    yCameraMetaData();
    bool parser( Blender::Object* bObjCamera );
    float getFarClipDistance();
    Ogre::Radian getFov();

private:
    float mFarClipDistance;
    Ogre::Radian mFov;
};

#endif // YCAMERAMETADATA_H
