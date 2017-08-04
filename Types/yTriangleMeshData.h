#ifndef YTRIANGLEMESHDATA_H
#define YTRIANGLEMESHDATA_H

#include "OgreVector3.h"
#include "btBulletCollisionCommon.h"

struct yTriangleMeshData {
    //position vertexs (local space)
    Ogre::Vector3 v0Pos;
    Ogre::Vector3 v1Pos;
    Ogre::Vector3 v2Pos;

    //by the moment, we only store the friction coeff
    float v0Coeff;
    float v1Coeff;
    float v2Coeff;
};

struct yTriangleData {
    //position vertexs (local space)
    btVector3 v0Pos;
    btVector3 v1Pos;
    btVector3 v2Pos;
};

#endif // YTRIANGLEMESHDATA_H
