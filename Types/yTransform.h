#ifndef YTRANSFORM_H
#define YTRANSFORM_H

#include "OgreVector3.h"
typedef struct{
    Ogre::Vector3 position;
    Ogre::Quaternion orientation;
    Ogre::Vector3 scale;
    bool dirty; ///< useful to signal if this struct was changed
} yTransform;

#endif // YTRANSFORM_H
