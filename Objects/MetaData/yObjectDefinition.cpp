#include "yObjectDefinition.h"
#include "Macros/yMacros.h"

yObjectDefinition::yObjectDefinition() {
    mDefinition.mPhysicsMetaData = nullptr;
    mDefinition.mSoundMetaData = nullptr;
    mDefinition.mCurveMetaData = nullptr;
}

void yObjectDefinition::setDefinition( Definition& definition ) {
    yAssert( mDefinition.mObjectName == "", ("trying to reset the object definition is not allow, object: " + mDefinition.mObjectName).c_str() );
    mDefinition.mObjectName = definition.mObjectName;
    mDefinition.mBlendFileName = definition.mBlendFileName;
    mDefinition.mLayerBit = definition.mLayerBit;
    mDefinition.mPhysicsMetaData = definition.mPhysicsMetaData;
    mDefinition.mSoundMetaData = definition.mSoundMetaData;
    mDefinition.mCurveMetaData = definition.mCurveMetaData;
    mDefinition.mActuatorProperties = definition.mActuatorProperties;
    mDefinition.mHalfBoundingBox = definition.mHalfBoundingBox;
}

yObjectDefinition::Definition yObjectDefinition::getDefinition() {
    yAssert( mDefinition.mObjectName != "", "definition has no been set" );
    return mDefinition;
}

void yObjectDefinition::addDefinitionSubObject( yObjectDefinition::DefinitionSubObject& definition ) {
    mDefinitionSubObjects.push_back(definition);
}

void yObjectDefinition::addDefinitionSubObject( std::string subObjectName, std::string subObjectBlendFile, yObjectType::Type type ) {
    yObjectDefinition::DefinitionSubObject def;
    def.mSubObjectName = subObjectName;
    def.mSubObjectBlendFile = subObjectBlendFile;
    def.mType = type;
    addDefinitionSubObject(def);
}

Ogre::FastArray< yObjectDefinition::DefinitionSubObject >& yObjectDefinition::getDefinitionSubObject() {
    return mDefinitionSubObjects;
}

void yObjectDefinition::setDefinitionChildObject( Ogre::FastArray< DefinitionChildObject >& definition ) {
    mDefinitionChildObjects = definition;
}

void yObjectDefinition::addDefinitionChildObject( yObjectDefinition::DefinitionChildObject& definition ) {
    mDefinitionChildObjects.push_back(definition);
}

void yObjectDefinition::addDefinitionChildObject( std::string childObjectName, std::string childObjectBlendFile, yObjectType::Type type, int layerBit ) {
    yObjectDefinition::DefinitionChildObject def;
    def.mChildObjectName = childObjectName;
    def.mChildObjectBlendFile = childObjectBlendFile;
    def.mType = type;
    def.mLayerBit = layerBit;
    addDefinitionChildObject(def);
}

Ogre::FastArray< yObjectDefinition::DefinitionChildObject >& yObjectDefinition::getDefinitionChildObject() {
    return mDefinitionChildObjects;
}
