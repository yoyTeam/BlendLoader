#include "yParticleMetaData.h"
#include "BlenderSerialize/Serialize/BlenderSerialize/blend263/Blender.h"
#include "BlenderSerialize/BlenderDefines.h"
#include "Macros/yMacros.h"
#include "Constants/yConstantsThreads.h"

#include "Math/Simple/OgreAabb.h"

yParticleMetaData::yParticleMetaData() {
}

bool yParticleMetaData::parser( Blender::Object* bObject, Ogre::Aabb aabb ) {

    bool isParticle = false;

    //Other Modifiers
    for( Blender::ModifierData* modifierData = (Blender::ModifierData*)bObject->modifiers.first; modifierData; modifierData = modifierData->next ) {

        //Particle Modifier
        if( modifierData->type == 19 && (modifierData->mode & MOD_MASK_INV) ) {
            size_t i = mParticleData.size();
            mParticleData.resize( i + 1 );
            mParticleData[i].mHalfBoundingSize = aabb.getSize() * 0.5f;
            mParticleData[i].mIterationInterval = 0.033;
            mParticleData[i].mKeepParticleInLocalSpace = false;
            mParticleData[i].mGravityAffector = false;
            mParticleData[i].mGravityFactor = 1;
            mParticleData[i].mHasAvefac = false;

            Blender::ParticleSystemModifierData *particleMod = (Blender::ParticleSystemModifierData*)modifierData;
            Blender::ParticleSystem *bParticlesSystem = particleMod->psys;
            Blender::ParticleSettings *bParticleSettings = bParticlesSystem->part;

            yAssert( bParticlesSystem && bParticleSettings, "particle data corrupt" );

            //Particles
            if( bParticlesSystem->flag & 1 ) {

                mParticleData[i].mParticlesCount = bParticleSettings->totpart * 100;
                mParticleData[i].mWidth = bParticleSettings->size * bParticleSettings->bb_size[0];
                mParticleData[i].mHeight = bParticleSettings->size * bParticleSettings->bb_size[1];
                float lifeTime = bParticleSettings->lifetime/yConstantsThreads::ANIMATION_FRAME_RATE;
                mParticleData[i].mMaxTimeToLive = lifeTime;
                mParticleData[i].mMinTimeToLive = lifeTime - lifeTime * bParticleSettings->randlife;
                mParticleData[i].mDuration = (bParticleSettings->end - bParticleSettings->sta) / yConstantsThreads::ANIMATION_FRAME_RATE;
                mParticleData[i].mRate = bParticleSettings->totpart;
                mParticleData[i].mDirection = yUtils::convertToYup( Ogre::Vector3(bParticleSettings->ob_vel[0],bParticleSettings->ob_vel[1],bParticleSettings->ob_vel[2]) );

                if( !mParticleData[i].mDirection.length() ){
                    mParticleData[i].mAngle = Ogre::Radian(Ogre::Degree(360).valueRadians());
                    mParticleData[i].mMinVelocity = bParticleSettings->normfac;
                }
                else{
                    mParticleData[i].mAngle = Ogre::Radian(Ogre::Degree(bParticleSettings->randfac).valueRadians());
                    mParticleData[i].mMinVelocity = mParticleData[i].mDirection.length();
                }

                Blender::MTex* bTex = bParticleSettings->mtex[0];
                if( bTex ) {
                    Blender::ColorBand *ramp = bTex->tex->coba;
                    if( ramp ) {
                        for( size_t j = 0; j < ramp->tot; ++j ) {
                            Blender::CBData colorData = ramp->data[j];
                            mParticleData[i].mRampPos.push_back( colorData.pos );
                            mParticleData[i].mRampColor.push_back( Ogre::ColourValue( colorData.r, colorData.g, colorData.b, colorData.a ) );
                        }
                    }
                }

                mParticleData[i].mGravityAffector = bParticleSettings->effector_weights->global_gravity;
                if( mParticleData[i].mGravityAffector ){
                    mParticleData[i].mGravityFactor = bParticleSettings->effector_weights->global_gravity;
                }

                mParticleData[i].mMass = bParticleSettings->mass;
                mParticleData[i].mHasAvefac = bParticleSettings->avefac;
                mParticleData[i].mAvefac = Ogre::Radian(bParticleSettings->avefac);
                mParticleData[i].mRandRotFac = bParticleSettings->randrotfac;

                isParticle = true;
            }
        }
    }

    return isParticle;
}



const yParticleMetaData::ParticleData& yParticleMetaData::getParticleData( size_t index ) {
    yAssert( index < mParticleData.size(), "invalid index" );
    return mParticleData[index];
}

size_t yParticleMetaData::getParticleDataSize() {
    return mParticleData.size();
}
