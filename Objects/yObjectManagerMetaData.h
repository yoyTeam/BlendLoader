#ifndef YOBJECTMANAGERMETADATA_H
#define YOBJECTMANAGERMETADATA_H

#include <string>
#include <vector>
#include "Objects/Types/yObjectType.h"
#include "Types/yFastArray.h"

class yBlendLoader;
class yBlendMetaData;
class yMeshMetaData;
class yObjectMetaData;
class ySceneMetaData;

/**
 * @brief The yObjectManagerMetaData class
 * This class is responsible to manage the objects metadata,
 * that is, get it from blend files, store it and ask the
 * right metadata to fill the object being created.
 */
class yObjectManagerMetaData
{
public:

    yObjectManagerMetaData();

    /**
     * @brief loadBlendFile load a blend file, parse it, and
     * store their metadata to future use
     * @param blendFileName the path to the blendfile
     * @return true if the file was loaded, false if not loaded beacuse it was already loaded before
     */
    bool loadBlendFile( std::string blendFileName );

    /**
     * @brief getObjectMetaData get an object meta data, usually
     * called by #yBlendLoader to re-use data
     * @param objectName name of the object to get
     * @param blendFileName the blendfile where the object is
     * @return the object meta data or null if not found
     */
    yObjectMetaData* getObjectMetaData( std::string objectName, std::string blendFileName );

    /**
     * @brief getGroupMetaData get an group meta data, usually
     * called by #yBlendLoader to re-use data
     * @param groupName name of the group to get
     * @param blendFileName the blendfile where the group is
     * @return the group meta data or null if not found
     */
    yObjectMetaData* getGroupMetaData( std::string groupName, std::string blendFileName );

    /**
     * @brief getObjectsMetaData get information about objects
     * in a specific layer. Use the #objectsName and #objectsType
     * to get the result
     * @param layer the layer (no layerBit!) of the blendfile
     * @param blendFileName the blendfile name
     * @param objectsName the objects name found
     * @param objectsType the objects type found. It use the same index respect
     * to #objectsName
     * @param objectHasParent the objects parents (true if it has a parent, false otherwise)
     * It use the same index request respect to #objectsName
     */
    void getObjectsMetaData( int layer, std::string blendFileName , Ogre::FastArray<std::string>& objectsName, Ogre::FastArray<yObjectType::Type>& objectsType, Ogre::FastArray<bool>& objectsHasParent );

    /**
     * @brief findObjectMetaData find/get a specific object meta data
     * @param blendFileName the blendfile name
     * @param objectName the object to search
     * @param objectType the object type found
     * @param objectHasParent the object parent (true if it has a parent, false otherwise)
     * @param layerBit the object layer
     * @return true if find the object in the blendfile request, false otherwise
     */
    bool findObjectMetaData( std::string blendFileName, std::string objectName, yObjectType::Type& objectType, bool& objectHasParent, int& layerBit );

    /**
     * @brief getSceneMetaData get the scene meta data ( like fog, shadow, etc ) from the blendfile request
     * @param blendFileName the blendfile to extract the scene meta data
     * @return the scene meta data
     */
    ySceneMetaData* getSceneMetaData( std::string blendFileName );

private:
    yBlendLoader* mBlendLoader; ///< the blend loader parser
    yFastArray< yBlendMetaData* > mBlendMetaData; ///< the blend meta data, every position is a different blendfile
};

#endif // YOBJECTMANAGERMETADATA_H
