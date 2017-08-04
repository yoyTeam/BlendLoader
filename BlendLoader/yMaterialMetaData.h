#ifndef YMATERIALMETADATA_H
#define YMATERIALMETADATA_H

#include <string>
#include <assert.h>
#include "OgreFastArray.h"
#include "Types/yMaterialData.h"

namespace Blender {
    struct Object;
    struct Material;
    struct Mesh;
}

class yMaterialMetaData
{
public:
    yMaterialMetaData();
    bool parser(Blender::Object* bObject, std::string blendFile , size_t materialCount);
    size_t getMaterialCount();
    yMaterialData getMaterialData( size_t index );

private:
    void parseMaterial( Blender::Material *bMaterial );
    std::string mBlendFile;
    Blender::Mesh* mBMesh;
    Ogre::FastArray< yMaterialData > mMaterialDefinition;

};

#endif // YMATERIALMETADATA_H
