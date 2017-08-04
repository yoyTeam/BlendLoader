#ifndef YPHYSICSMETADATA_H
#define YPHYSICSMETADATA_H

#include "Math/Simple/OgreAabb.h"
#include "Types/yTriangleMeshData.h"
#include "Types/yConstraintData.h"

namespace Blender {
    struct Object;
}

class btCollisionShape;
class btVector3;

class yPhysicsMetaData
{
public:

    yPhysicsMetaData();
    bool parser( Blender::Object* bObject, Ogre::Aabb aabb );

    btCollisionShape* createCollisionShape();

    bool isStatic();
    bool isKinematic();
    bool isCompound();
    bool isNoSleeping();

    float getMass();
    float getDampingLinear();
    float getDampingAngular();

    float getFriction();

    short getColGroup();
    short getColMask();

    int getCollisionFlag();

    Ogre::FastArray<Constraint::ConstraintData>& getConstraintsData();

private:
    void parseConstraints( Blender::Object* bObject );

    bool mIsStatic;
    bool mIsKinematic;
    bool mIsCompound;
    bool mIsNoSleeping;
    float mMass;
    float mDampingLinear;
    float mDampingAngular;
    float mFriction;
    short mColGroup;
    short mColMask;
    int mCollisionFlag;
    Ogre::FastArray<Constraint::ConstraintData> mConstraints;

    //data to build mesh
    int mType;
    btScalar mBoundingRadius;
    btVector3 mHalfExtends;
    Ogre::FastArray<yTriangleData> mTriangleData;
    Ogre::FastArray<yTriangleMeshData> mTriangleBvhData;
    float mColShapeMargin;
    bool mUseBvh;
    bool mIsPlane;
};

#endif // YPHYSICSMETADATA_H
