#ifndef YMATERIALDATA_H
#define YMATERIALDATA_H

#include "OgreColourValue.h"
#include "OgreHlmsSamplerblock.h"

class yTexture;

namespace yTransparencyMode {
    enum TransparencyMode{
        NONE,
        TRANSPARENT_,
        FADE,
        CLIP
    };
}

namespace yBlendMode {
    enum BlendMode
    {
        /// Regular alpha blending
        NORMAL_NON_PREMUL,
        /// Premultiplied alpha blending
        NORMAL_PREMUL,
        ADD,
        SUBTRACT,
        MULTIPLY,
        MULTIPLY2X,
        SCREEN,
        OVERLAY,
        LIGHTEN,
        DARKEN,
        GRAIN_EXTRACT,
        GRAIN_MERGE,
        DIFFERENCE_,
        NUM_BLEND_MODES
    };
}

struct yMaterialTextureData{
    bool mUsed;
    std::string mPath;
    yTexture* mTexture;
    Ogre::HlmsSamplerblock mSamplerBlock;
    int mUVIndex;
    float mBlend;
};

namespace yMaterialTextureType {
    enum MaterialTextureType
    {
        ALBEDO_TEXTURE,
        DETAIL_TEXTURE_0,
        DETAIL_TEXTURE_1,
        DETAIL_TEXTURE_2,
        DETAIL_TEXTURE_3,
        NORMAL_TEXTURE,
        REFLECTIVITY_TEXTURE
    };
}
namespace yMaterialParameter {
    enum MaterialParameter
    {
        ALBEDO,
        ROUGHNESS,
        METALNESS,
        EMIT,
        TRANSPARENCY_MODE,
        CULLING_MODE,
        DEPTH_BIAS,
        BLINK,
        CAST_SHADOW,
        ALBEDO_TEXTURE,
        ALBEDO_TEXTURE_SAMPLERBLOCK,
        ALBEDO_TEXTURE_UV,
        DETAIL_TEXTURE_0,
        DETAIL_TEXTURE_1,
        DETAIL_TEXTURE_2,
        DETAIL_TEXTURE_3,
        DETAIL_TEXTURE_0_SAMPLERBLOCK,
        DETAIL_TEXTURE_1_SAMPLERBLOCK,
        DETAIL_TEXTURE_2_SAMPLERBLOCK,
        DETAIL_TEXTURE_3_SAMPLERBLOCK,
        DETAIL_TEXTURE_0_UV,
        DETAIL_TEXTURE_1_UV,
        DETAIL_TEXTURE_2_UV,
        DETAIL_TEXTURE_3_UV,
        DETAIL_BLEND_MODE_0,
        DETAIL_BLEND_MODE_1,
        DETAIL_BLEND_MODE_2,
        DETAIL_BLEND_MODE_3,
        DETAIL_BLEND_0,
        DETAIL_BLEND_1,
        DETAIL_BLEND_2,
        DETAIL_BLEND_3,
        NORMAL_TEXTURE,
        NORMAL_TEXTURE_SAMPLERBLOCK,
        NORMAL_TEXTURE_UV,
        REFLECTIVITY_TEXTURE,
        REFLECTIVITY_TEXTURE_SAMPLERBLOCK,
        REFLECTIVITY_TEXTURE_UV,
        DETAIL_BLEND_TEXTURE,
        DETAIL_BLEND_TEXTURE_SAMPLERBLOCK,
        DETAIL_BLEND_TEXTURE_UV
    };
}

struct yMaterialData{
    std::string mName;
    Ogre::ColourValue mAlbedo;
    float mRoughness;
    float mMetalness;
    float mEmit;
    yTransparencyMode::TransparencyMode mTransparencyMode;
    Ogre::CullingMode mCullingMode;
    float mDepthBias;
    bool mBlink;
    bool mNightEmit;
    bool mCastShadow;
    yMaterialTextureData mAlbedoTexture;
    yMaterialTextureData mDetailTexture[4];
    yBlendMode::BlendMode mDetailBlendMode[4];
    yMaterialTextureData mNormalTexture;
    yMaterialTextureData mReflectivityTexture;
    bool mUseReflectivityRoughness;
    bool mUseReflectivityMetalness;
    bool mUseReflectivityAO;
    yMaterialTextureData mDetailBlendTexture;
};


#endif // YMATERIALDATA_H
