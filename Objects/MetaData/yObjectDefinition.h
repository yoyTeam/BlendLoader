#ifndef YOBJECTDEFINITION_H
#define YOBJECTDEFINITION_H

#include <string>
#include <map>
#include "Objects/Types/yObjectType.h"
#include "assert.h"
#include "OgreFastArray.h"
#include "OgreVector3.h"

class yPhysicsMetaData;
class ySoundMetaData;
class yMaterialMetaData;
class yCurveMetaData;

class yObjectDefinition
{
public:
    struct Definition {
        std::string mObjectName;
        std::string mBlendFileName;
        int mLayerBit;
        Ogre::Vector3 mHalfBoundingBox;
        yPhysicsMetaData* mPhysicsMetaData;
        ySoundMetaData* mSoundMetaData;
        yCurveMetaData* mCurveMetaData;
        std::map< std::string, std::string > mActuatorProperties;
    };

    struct DefinitionSubObject {
        std::string mSubObjectName;
        std::string mSubObjectBlendFile;
        yObjectType::Type mType;
    };

    struct DefinitionChildObject {
        std::string mChildObjectName;
        std::string mChildObjectBlendFile;
        yObjectType::Type mType;
        int mLayerBit;
    };

    yObjectDefinition();
    void setDefinition( Definition& definition );
    Definition getDefinition();
    void addDefinitionSubObject( DefinitionSubObject& definition );
    void addDefinitionSubObject( std::string subObjectName, std::string subObjectBlendFile, yObjectType::Type type );
    Ogre::FastArray<DefinitionSubObject>& getDefinitionSubObject();

    void setDefinitionChildObject( Ogre::FastArray< DefinitionChildObject >& definition );
    void addDefinitionChildObject( yObjectDefinition::DefinitionChildObject& definition );
    void addDefinitionChildObject( std::string childObjectName, std::string childObjectBlendFile, yObjectType::Type type, int layerBit );
    Ogre::FastArray< yObjectDefinition::DefinitionChildObject >& getDefinitionChildObject();

private:
    Definition mDefinition;
    Ogre::FastArray< DefinitionSubObject > mDefinitionSubObjects;
    Ogre::FastArray< DefinitionChildObject > mDefinitionChildObjects;
};

#endif // YOBJECTDEFINITION_H
