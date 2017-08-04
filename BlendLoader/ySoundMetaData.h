#ifndef YSOUNDMETADATA_H
#define YSOUNDMETADATA_H

#include <string>
#include <assert.h>
#include "OgreFastArray.h"

namespace Blender {
    struct Object;
}

class ySoundMetaData
{
public:
    ySoundMetaData();
    bool parser( Blender::Object* bObject, std::string blendFile );
    size_t getSoundCount();
    std::string getPath( size_t index );
    bool getIsLoop( size_t index );
    float getReferenceDistance( size_t index );
    std::string getActuatorName( size_t index );

private:
    Ogre::FastArray< std::string > mPaths;
    Ogre::FastArray< bool > mLoop;
    Ogre::FastArray< float > mReferenceDistance;
    Ogre::FastArray< std::string > mActuatorName;
};

#endif // YSOUNDMETADATA_H
