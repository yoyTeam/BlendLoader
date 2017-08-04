#ifndef YMESHMETADATA_H
#define YMESHMETADATA_H

#include <string>
#include "OgreMesh.h"

namespace Blender {
    struct Mesh;
    struct Object;
    struct Curve;
}

class yVertexTriangleBuffer;
class yNavMesh;
class yObject;
struct yTempFace;

class yMeshMetaData
{
public:
    yMeshMetaData();
    bool parser(std::string blendFileName, Blender::Object* bObject, std::string skeletonName = "", bool isBoneControlled = false );
    Ogre::MeshPtr& generate();
    bool isStatic();
    bool isNavMesh();
    bool isVisible();
    int getNumSubMeshes();
    void poblateNavMesh( yNavMesh& navMesh );

private:

    struct yVertexTriangleBufferCombo {
        Ogre::FastArray<yVertexTriangleBuffer*> vertexTriangleBuffers;
        Ogre::FastArray<yVertexTriangleBuffer*> vertexTriangleBuffersShadow;
    };

    struct yLodInfo {
        float distance;
        Blender::Mesh* bMesh;
    };

    inline Ogre::Vector3 calcNormal(yTempFace *tri);
    yVertexTriangleBufferCombo fillTriangleBuffers(Blender::Mesh* bMesh, bool hasSkeleton);
    yVertexTriangleBufferCombo fillTriangleBuffersForTextPlane(Blender::Curve* bCurve);
    Ogre::v1::MeshPtr generateMesh( yVertexTriangleBufferCombo triangleBufferCombo, Ogre::FastArray<yLodInfo> mLodInfos );
    Ogre::MeshPtr convertMeshToV2( Ogre::v1::MeshPtr mMesh, bool unload = true );

    std::string mName;
    std::string mSkeletonName;
    std::string mBlendFileName;
    std::string mNameMeshFinal;
    Ogre::MeshPtr mMesh;
    yVertexTriangleBufferCombo mVertexTriangleBufferCombo;
    Ogre::FastArray<yLodInfo> mLodInfos;
    int mType;
    bool mNeedGeneration;
    bool mBoneControlled;
    bool mIsStatic;
    bool mIsNavMesh;
    bool mIsVisible;
};

#endif // YMESHMETADATA_H
