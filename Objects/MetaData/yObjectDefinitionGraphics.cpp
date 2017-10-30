#include "yObjectDefinitionGraphics.h"
#include "Macros/yMacros.h"

yObjectDefinitionGraphics::yObjectDefinitionGraphics() {
    mDefinition.mMeshMetaData = nullptr;
    mDefinition.mAnimationMetaData = nullptr;
    mDefinition.mLightMetaData = nullptr;
    mDefinition.mCameraMetaData = nullptr;
    mDefinition.mMaterialMetaData = nullptr;
    mDefinition.mParticleMetaData = nullptr;
    mDefinition.mTerraMetaData = nullptr;
    mDefinition.mOceanMetaData = nullptr;
    mDefinition.mIsUniqueMaterial = false;
}

void yObjectDefinitionGraphics::setDefinition( Definition& definition ) {
    yAssert( !mDefinition.mMeshMetaData, "trying to reset the object definition is not allow" );
    mDefinition.mAnimationMetaData = definition.mAnimationMetaData;
    mDefinition.mMeshMetaData = definition.mMeshMetaData;
    mDefinition.mLightMetaData = definition.mLightMetaData;
    mDefinition.mCameraMetaData = definition.mCameraMetaData;
    mDefinition.mMaterialMetaData = definition.mMaterialMetaData;
    mDefinition.mParticleMetaData = definition.mParticleMetaData;
    mDefinition.mTerraMetaData = definition.mTerraMetaData;
    mDefinition.mOceanMetaData = definition.mOceanMetaData;
    mDefinition.mIsUniqueMaterial = definition.mIsUniqueMaterial;
}

yObjectDefinitionGraphics::Definition yObjectDefinitionGraphics::getDefinition() {
    return mDefinition;
}

void yObjectDefinitionGraphics::mustBeUniqueMaterial() {
    mDefinition.mIsUniqueMaterial = true;
}
