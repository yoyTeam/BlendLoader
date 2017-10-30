#ifndef YNAVMESHMANAGER_H
#define YNAVMESHMANAGER_H

#include <assert.h>
#include "OgreFastArray.h"
#include "OgreVector3.h"

class yObject;
class yObjectNavMesh;
class yObjectInstance;
class yCurve;

class yNavMeshManager
{
    friend class yEngineServices;

public:
    yNavMeshManager();
    void travelTo( yObject* object, yObject* navMesh, Ogre::Vector3 targetWorldPos, float speed );

private:
    void update();
    void notifyObjectCreated( yObjectInstance* object );
    void notifyObjectAdded( yObjectInstance* object );
    void notifyObjectRemoved( yObjectInstance* object );
    void notifyObjectDestroyed( yObjectInstance* object );

    struct ActiveFollowPath {
        yObject* mObject;
        yCurve* mPath;
        float mSpeed;
        float mCurrentPathPos;
    };

    Ogre::FastArray< ActiveFollowPath > mActivePaths;
};

#endif // YNAVMESHMANAGER_H
