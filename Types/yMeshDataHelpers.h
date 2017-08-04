#ifndef YMESHDATAHELPERS_H
#define YMESHDATAHELPERS_H

#include "OgreVector3.h"
#include "OgreColourValue.h"
#include "OgreVector2.h"
#include "OgreVertexBoneAssignment.h"

//Mesh Generator stuffs
struct yTriangleIndex {
    unsigned int index[3];
};

class yVertex
{
public:
    yVertex()
    {
        co = no = Ogre::Vector3(0, 0, 0);
        vba  = -1;
        for (int _i = 0; _i < 8; _i++)
            uv[_i] = Ogre::Vector2(0, 0);
    }

    yVertex(const yVertex& o) { *this = o; }
    yVertex& operator = (const yVertex& o)
    {
        co      = o.co;
        no      = o.no;
        col      = o.col;
        vba     = o.vba;
        for (int _i = 0; _i < 8; _i++)
            uv[_i] = o.uv[_i];
        return *this;
    }

    Ogre::Vector3   co; // vertex coordinates
    Ogre::Vector3   no; // normals
    Ogre::ColourValue   col; // normals
    Ogre::Vector2   uv[8]; // texture coordinates
    int             vba; // Vertex bone assignment
};

class ySubMeshIndexer;

struct yTempFace
{
    yVertex vertex[3];
    yTriangleIndex triangleIndex;
};

class yVertexTriangleBuffer {

public:

    yVertexTriangleBuffer();
    ~yVertexTriangleBuffer();

    yTriangleIndex addTriangle(yTempFace tempFace, bool isForShadow=false);

    Ogre::FastArray<Ogre::v1::VertexBoneAssignment> vbas;

    Ogre::FastArray< yTriangleIndex > triangles;
    Ogre::FastArray< yVertex > vertexs;

    Ogre::FastArray< Ogre::uint32 > indices;

    int maxIndex;

    int uvSetCount;
    bool hasVertexColors;
    ySubMeshIndexer* subMeshIndexer;

};

class ySubMeshIndexer
{

public:

    ySubMeshIndexer(){newIndexCount=0;}

    int newIndexCount;

    struct IndexMapping
    {
        Ogre::FastArray<int> mapedIndexes;
        Ogre::FastArray<yVertex> mappedVertexes;
    };

    Ogre::FastArray<yVertex> prevVertexes;

    Ogre::FastArray<IndexMapping> indexMapping;

    unsigned int getVertexIndex(yVertexTriangleBuffer* sub, unsigned int index, yVertex& ref, bool isForShadow=false)
    {
//        if(isForShadow){
//            for(unsigned int i=0; i<prevVertexes.size(); i++){
//                yVertex currentVertex = prevVertexes.at(i);
//                if( vertEq(sub, currentVertex, ref, true) ){
//                    return i;
//                }
//            }

//            prevVertexes.push_back(ref);
//            sub->vertexs.push_back(ref);

//            newIndexCount++;
//            sub->maxIndex = newIndexCount-1;

//            return newIndexCount-1;
//        }

        //else
        for(unsigned int i=0; i<indexMapping[index].mappedVertexes.size(); i++){
            yVertex currentVertex = indexMapping[index].mappedVertexes[i];
            if( vertEq(sub, currentVertex, ref, isForShadow) ){
                return indexMapping[index].mapedIndexes[i];
            }
        }

        indexMapping[index].mapedIndexes.push_back( newIndexCount );
        indexMapping[index].mappedVertexes.push_back( ref );
        sub->vertexs.push_back(ref);

        newIndexCount++;
        sub->maxIndex = newIndexCount-1;

        return newIndexCount-1;
    }

    bool vertEq(yVertexTriangleBuffer* sub, yVertex& a, yVertex& b, bool isForShadow )
    {
        float margin = 1e-10f;
        //if(isForShadow) margin = 0.1;

        if ( std::abs((a.co - b.co).squaredLength()) > margin ){
            return false;
        }
        if(isForShadow){
            return true;
        }

        if ( std::abs((a.no - b.no).squaredLength()) > margin ){
            return false;
        }

        bool result = true;

        for (int i = 0; i < sub->uvSetCount; i++)
        {
            result = std::abs((a.uv[i] - b.uv[i]).squaredLength()) < margin;
            if (!result){
                break;
            }
        }

        return result;
    }
};

#endif // YMESHDATAHELPERS_H
