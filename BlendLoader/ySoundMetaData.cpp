#include "ySoundMetaData.h"
#include "BlenderSerialize/Serialize/BlenderSerialize/blend263/Blender.h"
#include "BlenderSerialize/BlenderDefines.h"
#include "Macros/yMacros.h"
#include "Utils/yUtils.h"

ySoundMetaData::ySoundMetaData() {

}

bool ySoundMetaData::parser( Blender::Object* bObject, std::string blendFile ) {

    yAssert( bObject, "bObject null" );
    bool found = false;

    for( Blender::bActuator *bActuator = (Blender::bActuator*)bObject->actuators.first; bActuator; bActuator = bActuator->next ) {
        //The sound is obtained from a Sound Actuator logic brick
        if( bActuator->type == ACT_SOUND ) {
            found = true;
            Blender::bSoundActuator *bSoundActuator = (Blender::bSoundActuator*)bActuator->data;
            mPaths.push_back( yUtils::normalizeBlendPath( blendFile, std::string( bSoundActuator->sound->name ) ) );
            mLoop.push_back( bSoundActuator->type == ACT_SND_LOOP_END_SOUND || bSoundActuator->type == ACT_SND_LOOP_STOP_SOUND );
            mReferenceDistance.push_back( bSoundActuator->sound3D.reference_distance );
            mActuatorName.push_back( std::string(bActuator->name) );
        }
    }

    return found;
}

size_t ySoundMetaData::getSoundCount() {
    return mPaths.size();
}

std::string ySoundMetaData::getPath( size_t index ) {
    yAssert( index < mPaths.size(), "invalid index" );
    return mPaths[index];
}

bool ySoundMetaData::getIsLoop( size_t index ) {
    yAssert( index < mLoop.size(), "invalid index" );
    return mLoop[index];
}

float ySoundMetaData::getReferenceDistance( size_t index ) {
    yAssert( index < mReferenceDistance.size(), "invalid index" );
    return mReferenceDistance[index];
}

std::string ySoundMetaData::getActuatorName( size_t index ) {
    yAssert( index < mActuatorName.size(), "invalid index" );
    return mActuatorName[index];
}
