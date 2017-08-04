#ifndef YTEXTUREDATA_H
#define YTEXTUREDATA_H

#include <string>
#include "OgrePixelFormat.h"
#include "OgreTexture.h"

struct yTextureData{
    std::string mName;
    std::string mFileName;
    int mWidth;
    int mHeight;
    Ogre::PixelFormat mFormat;
    Ogre::TextureUsage mUsage;
};

#endif // YTEXTUREDATA_H
