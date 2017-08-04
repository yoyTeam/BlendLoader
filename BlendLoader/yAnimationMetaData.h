#ifndef YANIMATIONMETADATA_H
#define YANIMATIONMETADATA_H

#include "Types/yTransform.h"
#include "Types/yAnimationData.h"
#include "Types/yFastArray.h"

namespace Blender {
    struct Object;
    struct Bone;
    struct bAction;
    struct BezTriple;
}

class yAnimationMetaData
{
public:

    struct BoneData {
        int mParentIndex;  //-1 is no parent
        std::string mName;
        yTransform mTransf;
    };

    struct Data {
        yAnimationData mAnimation;
        float mLength;
        Ogre::FastArray< BoneData > mBoneData;
        std::string mSkeletonName;
        bool mIsBoneControlled;
        std::string mAnimationName;
        std::string mAnimationAliasName;
        bool mIsAutoPlay;
        bool mSetInitialTimeRandom;
    };

    yAnimationMetaData();
    bool parser( Blender::Object* bObject, std::string blendFileName );
    Data* getAnimationSkeleton();
    yFastArray<Data*>& getAnimationObject();

private:

    bool generateSkeleton( Blender::Object *bObject, Data* data );
    void buildBoneTree( Blender::Bone* cur, Blender::Bone* prev, Data* data, int parentIndex = -1 );
    void getActionStartEnd( Blender::bAction* bAction, float& start, float& end );
    void getSplineStartEnd( Blender::BezTriple* bez, int totvert, float& start, float& end );
    yBezierSpline convertSpline( Blender::BezTriple* bez, int mode, int totvert, float xoffset );
    void convertAnimation( Blender::bAction* bAction, Data& newAnimation );
    Ogre::Matrix4 getFromFloatNorm(const float m[][4]);

    std::string mBlendFile;
    Data* mAnimationSkeleton;
    yFastArray<Data*> mAnimationObject;
};

#endif // YANIMATIONMETADATA_H
