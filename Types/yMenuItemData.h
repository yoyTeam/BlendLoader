#ifndef YMENUITEMDATA_H
#define YMENUITEMDATA_H

#include <string>
#include "OgrePixelFormat.h"

class yTexture;
class yVideo;


struct yMenuItemData{
    enum SPECIAL_FUNCTIONS { NONE, SIMROOM, NO_SIMROOM, MULTIPLAYER };
    std::string mTitle;
    std::string mSubTitle;
    std::string mIconPath;
    yTexture* mInfoTexture;
    yVideo* mInfoVideo;
    std::string mInfoText;
    std::string mNextStateName;
    Ogre::FastArray<int> mNextStateFlags;
    SPECIAL_FUNCTIONS mSpecialFunction;
};

#endif // YMENUITEMDATA_H
