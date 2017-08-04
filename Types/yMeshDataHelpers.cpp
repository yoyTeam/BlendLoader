#include "yMeshDataHelpers.h"

yVertexTriangleBuffer::yVertexTriangleBuffer() { subMeshIndexer = new ySubMeshIndexer(); hasVertexColors = false; }
yVertexTriangleBuffer::~yVertexTriangleBuffer() { delete subMeshIndexer; }

yTriangleIndex yVertexTriangleBuffer::addTriangle( yTempFace tempFace, bool isForShadow ) {
    yTriangleIndex tri;

    for(int i=0; i<3; i++){
        tri.index[i] = subMeshIndexer->getVertexIndex(this, tempFace.triangleIndex.index[i], tempFace.vertex[i], isForShadow);
        indices.push_back( tri.index[i] );
    }

    triangles.push_back(tri);

    return tri;
}
