#ifndef YCONSTRAINTDATA_H
#define YCONSTRAINTDATA_H

#include <assert.h>
#include "OgreFastArray.h"
#include <string>
#include "btBulletDynamicsCommon.h"

namespace Constraint {
    enum ConstraintType {
        BALL,
        GENERIC6DOF,
        HINGE
    };

    struct ConstraintData {
        std::string mTargetObjectName;
        bool mDisableCollisionBetweenLinkedBodies;
        btVector3 mPivot;
        btVector3 mAxisInA;
        int mConstraintType;
        Ogre::FastArray<float> mMinLimit;
        Ogre::FastArray<float> mMaxLimit;
    };
}

#endif // YCONSTRAINTDATA_H
