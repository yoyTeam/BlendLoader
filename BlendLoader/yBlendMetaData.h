#ifndef YBLENDMETADATA_H
#define YBLENDMETADATA_H

#include <assert.h>
#include "Objects/Types/yObjectType.h"
#include "Types/yFastArray.h"

class yObjectMetaData;
class yObjectInstance;
class ySceneMetaData;

class yBlendMetaData
{
public:
    yBlendMetaData();
    void addGroup( yObjectMetaData* group );
    void addObject( yObjectMetaData* object );
    void fillObjectInstance( yObjectInstance &objectInstance, std::string objectName, yObjectType::Type type );
    void fillGroupInstance( yObjectInstance& objectInstance, std::string objectName );
    yObjectMetaData* getObjectMetaData( std::string objectName );
    void getObjectNames( int layer, Ogre::FastArray<std::string>& objectsName, Ogre::FastArray<yObjectType::Type>& objectsType , Ogre::FastArray<bool>& objectsHasParent );
    bool findObjectNames( std::string objectName, yObjectType::Type& objectType, bool& objectHasParent, int& layerBit );
    yObjectMetaData* getGroupMetaData( std::string groupName );
    void setBlendFileName( std::string blendFile );
    void setSceneInfo( ySceneMetaData* scene );
    ySceneMetaData* getSceneMetaData();

private:
    void fillObjectData( yObjectInstance& objectInstance, yObjectMetaData& objectData );

    yFastArray< yObjectMetaData* > mObjects;
    yFastArray< yObjectMetaData* > mGroups;
    std::string mBlendFileName;
    ySceneMetaData* mScene;
};

#endif // YBLENDMETADATA_H
