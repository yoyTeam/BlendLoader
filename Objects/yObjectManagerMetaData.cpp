#include "yObjectManagerMetaData.h"
#include "Macros/yMacros.h"
#include "BlendLoader/yBlendLoader.h"
#include "BlendLoader/yBlendMetaData.h"
#include "BlendLoader/yObjectMetaData.h"

yObjectManagerMetaData::yObjectManagerMetaData()
{
    mBlendLoader = new yBlendLoader( this );
    /** @todo create custom memory pool to not reserve useless memory **/
    //mBlendMetaData.reserve(100);
}

bool yObjectManagerMetaData::loadBlendFile( std::string blendFileName ) {
    yAssert( blendFileName != "", "can't load blend file with empty name");
    blendFileName = yUtils::normalizeBlendPath(blendFileName);

    bool fileLoaded = false;
    if( !mBlendMetaData.getData(blendFileName) ) {

        //file not found, load!
        yBlendMetaData* data = new yBlendMetaData();
        data->setBlendFileName( blendFileName );

        //save the empty container
        mBlendMetaData.addData(blendFileName, data);

        //actually load the file (and fill the container)
        mBlendLoader->loadFile( blendFileName, data );

        fileLoaded = true;
    }

    return fileLoaded;
}

yObjectMetaData* yObjectManagerMetaData::getObjectMetaData( std::string objectName, std::string blendFileName ) {
    blendFileName = yUtils::normalizeBlendPath(blendFileName);
    yBlendMetaData* data = mBlendMetaData.getData( blendFileName );
    return ( !data ) ? nullptr : data->getObjectMetaData( objectName );
}

yObjectMetaData* yObjectManagerMetaData::getGroupMetaData( std::string groupName, std::string blendFileName ) {
    blendFileName = yUtils::normalizeBlendPath(blendFileName);
    yBlendMetaData* data = mBlendMetaData.getData( blendFileName );
    return ( !data ) ? nullptr : data->getGroupMetaData( groupName );
}

void yObjectManagerMetaData::getObjectsMetaData( int layer, std::string blendFileName,
                                                 Ogre::FastArray<std::string>& objectsName,
                                                 Ogre::FastArray<yObjectType::Type>& objectsType,
                                                 Ogre::FastArray<bool>& objectsHasParent ) {
    blendFileName = yUtils::normalizeBlendPath(blendFileName);
    yBlendMetaData* data = mBlendMetaData.getData( blendFileName );
    yAssert( data, ("blender: " + blendFileName + " not found").c_str() );
    data->getObjectNames( layer, objectsName, objectsType, objectsHasParent );
}

bool yObjectManagerMetaData::findObjectMetaData( std::string blendFileName,
                                                 std::string objectName,
                                                 yObjectType::Type& objectType,
                                                 bool& objectHasParent,
                                                 int& layerBit ) {
    blendFileName = yUtils::normalizeBlendPath(blendFileName);
    yBlendMetaData* data = mBlendMetaData.getData( blendFileName );
    yAssert( data, ("blender: " + blendFileName + " not found").c_str() );
    return data->findObjectNames( objectName, objectType, objectHasParent, layerBit );
}

ySceneMetaData* yObjectManagerMetaData::getSceneMetaData( std::string blendFileName ) {
    blendFileName = yUtils::normalizeBlendPath( blendFileName );
    yBlendMetaData* data = mBlendMetaData.getData( blendFileName );
    yAssert( data, ("blender: " + blendFileName + " not found").c_str() );
    return data->getSceneMetaData();
}
