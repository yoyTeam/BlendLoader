#ifndef YOBJECTDEFINITIONGRAPHICS_H
#define YOBJECTDEFINITIONGRAPHICS_H

#include <string>
class yAnimationMetaData;
class yMeshMetaData;
class yLightMetaData;
class yCameraMetaData;
class yMaterialMetaData;
class yParticleMetaData;
class yTerraMetaData;
class yOceanMetaData;

class yObjectDefinitionGraphics
{
public:
    struct Definition {
        yAnimationMetaData* mAnimationMetaData;
        yMeshMetaData* mMeshMetaData;
        yLightMetaData* mLightMetaData;
        yCameraMetaData* mCameraMetaData;
        yMaterialMetaData* mMaterialMetaData;
        yParticleMetaData* mParticleMetaData;
        yTerraMetaData* mTerraMetaData;
        yOceanMetaData* mOceanMetaData;
        bool mIsUniqueMaterial;
    };

    yObjectDefinitionGraphics();
    void setDefinition(Definition &definition );
    Definition getDefinition();
    void mustBeUniqueMaterial();

private:
    Definition mDefinition;
};

#endif // YOBJECTDEFINITIONGRAPHICS_H
