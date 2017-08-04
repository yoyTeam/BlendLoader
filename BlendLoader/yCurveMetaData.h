#ifndef YCURVEMETADATA_H
#define YCURVEMETADATA_H

#include "assert.h"
#include "OgreFastArray.h"
#include "OgreVector3.h"

namespace Blender {
    struct Object;
}

class yCurveMetaData
{
public:
    yCurveMetaData();
    bool parser( Blender::Object* bObject );
    bool getIsCyclic();
    bool getIsConstant();
    Ogre::FastArray< Ogre::FastArray<Ogre::Vector3> >& getBezTriples();

private:
    bool mIsCyclic;
    bool mIsConstant;
    Ogre::FastArray< Ogre::FastArray<Ogre::Vector3> > mBezTriples;
};

#endif // YCURVEMETADATA_H
