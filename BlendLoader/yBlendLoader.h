#ifndef YBLENDLOADER_H
#define YBLENDLOADER_H

#include <string>
#include "Math/Simple/OgreAabb.h"

namespace Blender {
    struct Object;
    struct Group;
    struct Scene;
    struct Material;
    struct Mesh;
}

namespace bParse {
    class bBlenderFile;
}

namespace Ogre {
    class Vector3;
    class Quaternion;
}

class yBlendMetaData;
class yMeshMetaData;
class yLightMetaData;
class yObjectMetaData;
class yObjectManagerMetaData;
class ySceneMetaData;
class yCameraMetaData;
class yPhysicsMetaData;
class ySoundMetaData;
class yMaterialMetaData;
class yCurveMetaData;
class yAnimationMetaData;
class yParticleMetaData;

class yBlendLoader
{
public:
    yBlendLoader(yObjectManagerMetaData* manager);
    void loadFile(std::string blendFileName, yBlendMetaData* storeData );

private:
    bool isCompatibleObject( Blender::Object* bObject );
    yObjectMetaData* generateGroup( yBlendMetaData* storeData, Blender::Group* bGroup, std::string blendFileName );
    yObjectMetaData* generateObject( yBlendMetaData* storeData, Blender::Object* bObject, std::string blendFileName );
    void parseSpatialTransform(Blender::Object* bObject, yObjectMetaData *parentObject, Ogre::Vector3& position, Ogre::Quaternion& orientation, Ogre::Vector3& scale );
    yMeshMetaData* parseMesh( Blender::Object* bObject , std::string blendFileName, std::string skeletonName, bool isBoneControlled );
    Ogre::Aabb parseAabb( Blender::Object* bObject );
    std::map<std::string, std::string> parseActuatorProperties( Blender::Object* bObject );
    yLightMetaData* parseLight( Blender::Object* bObject );
    yCameraMetaData* parseCamera( Blender::Object* bObject );
    ySoundMetaData* parseSound( Blender::Object* bObject, std::string blendFileName );
    yCurveMetaData* parseCurve( Blender::Object* bObject );
    yMaterialMetaData* parseMaterial(Blender::Object *bObject, std::string blendFileName, int materialCount);
    ySceneMetaData* parseSceneInfo( Blender::Scene* bScene, bParse::bBlenderFile* blendFile );
    yPhysicsMetaData* parsePhysics( Blender::Object* bObject, Ogre::Aabb aabb );
    yAnimationMetaData* parseAnimation( Blender::Object* bObject, std::string blendFileName );
    yParticleMetaData* parseParticle( Blender::Object* bObject, Ogre::Aabb aabb );

    yObjectManagerMetaData* mManagerMetaData;
};

#endif // YBLENDLOADER_H
