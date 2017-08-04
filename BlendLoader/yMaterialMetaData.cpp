#include "yMaterialMetaData.h"
#include "BlenderSerialize/Serialize/BlenderSerialize/blend263/Blender.h"
#include "BlenderSerialize/BlenderDefines.h"
#include "Macros/yMacros.h"
#include "Utils/yUtils.h"
#include "OgreTextureManager.h"

yMaterialMetaData::yMaterialMetaData() {

}

bool yMaterialMetaData::parser( Blender::Object *bObject, std::string blendFile, size_t materialCount ) {

    yAssert( bObject, "bObject null" );

    if( bObject->type != OB_MESH )  return false;

    mBMesh = (Blender::Mesh*)bObject->data;

    yAssert( mBMesh, "bMesh null" );

    Blender::Material **bMaterials = mBMesh->mat;

    if( !bMaterials ) return false;

    mBlendFile = blendFile;
    for( size_t i = 0; i < materialCount; ++i ) {

        Blender::Material *bMaterial = (Blender::Material*)bMaterials[i];

        if( !bMaterial ) continue;

        parseMaterial( bMaterial );
    }

    return true;

}

void yMaterialMetaData::parseMaterial( Blender::Material *bMaterial ) {

    yAssert( bMaterial, "material null" );
    yMaterialData materialDefinition;

    //BASIC PROPERTIES
    materialDefinition.mName = GET_NAME( bMaterial ) + mBlendFile;
    materialDefinition.mAlbedo = Ogre::ColourValue( bMaterial->r,bMaterial->g,bMaterial->b,bMaterial->alpha );
    materialDefinition.mRoughness = (float)(bMaterial->har-1)/510.0;
    materialDefinition.mMetalness = bMaterial->spec * ( 0.21*bMaterial->specr + 0.72*bMaterial->specg + 0.07*bMaterial->specb);
    materialDefinition.mEmit = bMaterial->emitt;

    //EMPTY TEXTURES
    materialDefinition.mAlbedoTexture.mUsed = false;
    for( size_t j = 0; j < 4; ++j ) {
        materialDefinition.mDetailTexture[j].mUsed = false;
    }
    materialDefinition.mNormalTexture.mUsed = false;
    materialDefinition.mReflectivityTexture.mUsed = false;
    materialDefinition.mDetailBlendTexture.mUsed = false;

    //USAGE OF REFLECTIVITY TEXTURE
    materialDefinition.mUseReflectivityRoughness = false;
    materialDefinition.mUseReflectivityMetalness = false;
    materialDefinition.mUseReflectivityAO = false;


    //TRANSPARENCY
    if( bMaterial->game.alpha_blend & GEMAT_CLIP ) {
        materialDefinition.mTransparencyMode = yTransparencyMode::CLIP;
    }
    else if( bMaterial->game.alpha_blend & GEMAT_ALPHA ) {
        if( bMaterial->mode & MA_ZTRA ){
            materialDefinition.mTransparencyMode = yTransparencyMode::FADE;
        }
        else{
            materialDefinition.mTransparencyMode = yTransparencyMode::TRANSPARENT_;
        }
    }
    else{
        materialDefinition.mTransparencyMode = yTransparencyMode::NONE;
    }

    //CULLING MODE
    if( !(bMaterial->game.flag & GEMAT_BACKCULL) ) {
        materialDefinition.mCullingMode = Ogre::CULL_NONE;
    }
    else{
        materialDefinition.mCullingMode = Ogre::CULL_CLOCKWISE;
    }

    //DEPTH BIAS
    materialDefinition.mDepthBias = bMaterial->zoffs;

    //BLINK EFFECT
    materialDefinition.mBlink = bMaterial->mode & MA_TANGENT_V;

    //EMIT AT NIGHT
    materialDefinition.mNightEmit = bMaterial->game.face_orientation & GEMAT_HALO;

    //CAST SHADOW
    materialDefinition.mCastShadow = bMaterial->mode & MA_SHADBUF;

    //TEXTURES
    int albedoCount = 0;
    for( size_t i = 0; i < MAX_MTEX; ++i ) {
        Blender::MTex* bTexture = bMaterial->mtex[i];

        if( bTexture && bTexture->tex->type == TEX_IMAGE ) {

            std::string fullPath = "";
            if( bTexture->tex->ima ) {

                fullPath = yUtils::normalizeBlendPath( mBlendFile, std::string(bTexture->tex->ima->name) );

                //SAMPLERBLOCK
                Ogre::HlmsSamplerblock samplerblock;
                samplerblock.mU = Ogre::TAM_CLAMP;
                samplerblock.mV = Ogre::TAM_CLAMP;
                samplerblock.mMaxAnisotropy = 8;
                samplerblock.mMagFilter = Ogre::FO_ANISOTROPIC;

                if( bTexture->tex->extend == TEX_REPEAT ) {
                    if( bTexture->tex->xrepeat ) {
                        samplerblock.mU = Ogre::TAM_WRAP;
                    }
                    if( bTexture->tex->yrepeat ) {
                        samplerblock.mV = Ogre::TAM_WRAP;
                    }
                }
                else if( bTexture->tex->extend == TEX_CHECKER ) {
                    samplerblock.mU = Ogre::TAM_WRAP;
                    samplerblock.mV = Ogre::TAM_WRAP;
                }
                else if( bTexture->tex->extend == TEX_CLIPCUBE ) {
                    samplerblock.mU = Ogre::TAM_BORDER;
                    samplerblock.mV = Ogre::TAM_BORDER;
                    samplerblock.mBorderColour = Ogre::ColourValue(1,1,1,0);
                }

                //UV INDEX
                int uvIndex = 0;
                bool noUV = true;
                //find uv index
                if( bTexture->texco == TEXCO_UV ) {

                    //find uv index
                    Blender::CustomData *data = &mBMesh->pdata;
                    if(data) {
                        Blender::CustomDataLayer *cd = (Blender::CustomDataLayer*)data->layers;
                        if(cd) {
                            for( size_t i = 0; i < data->totlayer; ++i ) {
                                if( cd[i].type == CD_MTFACE || cd[i].type == CD_MTEXPOLY) {
                                    if( std::string(cd[i].name) == std::string(bTexture->uvname) ) {
                                        noUV = false;
                                        break;
                                    }
                                    ++uvIndex;
                                }
                            }
                        }
                    }

                    if( noUV ) {
                        uvIndex = 0;
                    }
                }

                //FILL DATA
                yMaterialTextureData texture;
                texture.mPath = fullPath;
                texture.mSamplerBlock = samplerblock;
                texture.mUVIndex = uvIndex;

                if( bTexture->mapto & MAP_COL ) {
                    texture.mUsed = true;
                    if( albedoCount > 4 ) continue; //if theres more than 4, just skip it
                    else if( !albedoCount ) {
                        materialDefinition.mAlbedoTexture = texture;
                    }
                    else{
                        texture.mBlend = bTexture->colfac;
                        materialDefinition.mDetailTexture[albedoCount-1] = texture;

                        yBlendMode::BlendMode blendMode = yBlendMode::NORMAL_NON_PREMUL;
                        if( bTexture->blendtype == MTEX_ADD ) blendMode = yBlendMode::ADD;
                        else if( bTexture->blendtype == MTEX_MUL ) blendMode = yBlendMode::MULTIPLY;
                        else if( bTexture->blendtype == MTEX_SUB ) blendMode = yBlendMode::SUBTRACT;
                        else if( bTexture->blendtype == MTEX_SCREEN ) blendMode = yBlendMode::SCREEN;
                        else if( bTexture->blendtype == MTEX_OVERLAY ) blendMode = yBlendMode::OVERLAY;
                        else if( bTexture->blendtype == MTEX_LIGHT ) blendMode = yBlendMode::LIGHTEN;
                        else if( bTexture->blendtype == MTEX_DARK ) blendMode = yBlendMode::DARKEN;
                        else if( bTexture->blendtype == MTEX_DIFF ) blendMode = yBlendMode::DIFFERENCE_;

                        materialDefinition.mDetailBlendMode[albedoCount-1] = blendMode;

                    }
                    materialDefinition.mAlbedo = Ogre::ColourValue::White;
                    albedoCount++;
                }
                if( bTexture->mapto & MAP_NORM ) {
                    texture.mUsed = true;
                    materialDefinition.mNormalTexture = texture;
                }
                if( bTexture->mapto & MAP_HAR ) {
                    texture.mUsed = true;
                    materialDefinition.mReflectivityTexture = texture;
                    materialDefinition.mRoughness = 1.0;
                    materialDefinition.mUseReflectivityRoughness = true;
                }
                if( (bTexture->mapto & MAP_COLSPEC) || (bTexture->mapto & MAP_SPEC) ) {
                    texture.mUsed = true;
                    materialDefinition.mReflectivityTexture = texture;
                    materialDefinition.mMetalness = 1.0;
                    materialDefinition.mUseReflectivityMetalness = true;
                }
                if( bTexture->mapto & MAP_AMB ) {
                    texture.mUsed = true;
                    materialDefinition.mReflectivityTexture = texture;
                    materialDefinition.mUseReflectivityAO = true;
                }
                if( bTexture->texflag & MTEX_STENCIL ) {
                    texture.mUsed = true;
                    materialDefinition.mDetailBlendTexture = texture;
                }

            }
            else{
                if( bTexture->mapto & MAP_COL ) {
                    albedoCount++;
                }
            }
        }

    }

    mMaterialDefinition.push_back( materialDefinition );

}

yMaterialData yMaterialMetaData::getMaterialData( size_t index ) {
    yAssert( index < mMaterialDefinition.size(), "invalid index" );
    return mMaterialDefinition[index];
}

size_t yMaterialMetaData::getMaterialCount() {
    return mMaterialDefinition.size();
}
