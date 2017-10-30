#include "yNavMesh.h"
#include "Recast.h"
#include "DetourNavMeshQuery.h"
#include "DetourNavMeshBuilder.h"

#include "Utils/yCurve.h"
#include "Types/yMeshDataHelpers.h"
#include <iostream>
#include <cstring>
#include "Objects/yObject.h"
#include "Objects/Types/yObjectNavMesh.h"
#include "Utils/yUtils.h"

/**
 * Class used for free memory after a finished method
 */
class yNavMeshContainer{
public:
    rcHeightfield *heightfield;
    rcCompactHeightfield *compactHeightField;
    rcContourSet *contourSet;
    rcPolyMesh *polyMesh;
    dtNavMeshQuery *navquery;

    yNavMeshContainer(){
        this->heightfield = nullptr;
        this->compactHeightField = nullptr;
        this->contourSet = nullptr;
        this->polyMesh = nullptr;
        this->navquery = nullptr;
    }
    ~yNavMeshContainer(){
        if(this->heightfield) rcFreeHeightField(this->heightfield);
        if(this->compactHeightField) rcFreeCompactHeightfield(this->compactHeightField);
        if(this->contourSet) rcFreeContourSet(this->contourSet);
        if(this->polyMesh) rcFreePolyMesh(this->polyMesh);
        if(this->navquery) dtFreeNavMeshQuery(this->navquery);
    }
};


yNavMesh::yNavMesh() {
    mNavMesh = nullptr;
}

yNavMesh::~yNavMesh(){
    if( mNavMesh ) {
        dtFreeNavMesh(this->mNavMesh);
    }
}

bool yNavMesh::buildNavMesh( yVertexTriangleBuffer* vertexTriangleBuffer,
                             float walkableAngle, int walkableHeight, int walkableClimb, int walkableRadius ) {

    mTriCount = vertexTriangleBuffer->triangles.size();

    //float verts[vertexTriangleBuffer->vertexs.size()*3]; //not win compatible
    float* verts = new float[vertexTriangleBuffer->vertexs.size()*3];
    size_t k = 0;
    for( size_t i = 0; i < vertexTriangleBuffer->vertexs.size(); ++i ) {
        Ogre::Vector3 position = vertexTriangleBuffer->vertexs[i].co;
        verts[k] = position.x;
        verts[k+1] = position.y;
        verts[k+2] = position.z;
        k += 3;
    }

    //int tris[triCount*3]; //not win compatible
    int* tris = new int[mTriCount*3];
    k = 0;
    for( size_t i = 0; i < mTriCount; ++i ) {
        tris[k] = vertexTriangleBuffer->triangles[i].index[0];
        tris[k+1] = vertexTriangleBuffer->triangles[i].index[1];
        tris[k+2] = vertexTriangleBuffer->triangles[i].index[2];
        k += 3;
    }

    bool retVal = _buildNavMesh(verts, vertexTriangleBuffer->vertexs.size(), tris, mTriCount,
                 walkableAngle, walkableHeight, walkableClimb, walkableRadius);

    delete[] verts;
    delete[] tris;

    return retVal;
}


bool yNavMesh::_buildNavMesh(const float *verts, const size_t nverts, const int *tris, const size_t ntris,
                             float walkableAngle, int walkableHeight, int walkableClimb, int walkableRadius){

    yNavMeshContainer container;

    /******************************
     * ~ * ~ --- RECAST --- ~ * ~ *
     ******************************/

    /* source of recast steps: http://masagroup.github.io/recastdetour/group__recast.html */

    /* recast step 1: Prepare the input triangle mesh */

    rcConfig config;
    memset(&config, 0, sizeof(config));

    float m_cellSize = 0.03f;
    float m_cellHeight = 0.05f;
    float m_agentHeight = 2.0f;
    float m_agentRadius = 0.1f;
    float m_agentMaxClimb = 0.2f;
    float m_agentMaxSlope = 45.0f;
    int m_regionMinSize = 8;
    int m_regionMergeSize = 20;
    float m_edgeMaxLen = 12.0f;
    float m_edgeMaxError = 1.3f;
    float m_vertsPerPoly = 6.0f;
    float m_detailSampleDist = 6.0f;
    float m_detailSampleMaxError = 1.0f;

    config.cs = m_cellSize;
    config.ch = m_cellHeight;
    config.walkableSlopeAngle = m_agentMaxSlope;
    config.walkableHeight = (int)ceilf(m_agentHeight / config.ch);
    config.walkableClimb = (int)floorf(m_agentMaxClimb / config.ch);
    config.walkableRadius = (int)ceilf(m_agentRadius / config.cs);
    config.maxEdgeLen = (int)(m_edgeMaxLen / m_cellSize);
    config.maxSimplificationError = m_edgeMaxError;
    config.minRegionArea = (int)rcSqr(m_regionMinSize);      // Note: area = size*size
    config.mergeRegionArea = (int)rcSqr(m_regionMergeSize);  // Note: area = size*size
    config.maxVertsPerPoly = (int)m_vertsPerPoly;
    config.detailSampleDist = m_detailSampleDist < 0.9f ? 0 : m_cellSize * m_detailSampleDist;
    config.detailSampleMaxError = m_cellHeight * m_detailSampleMaxError;

    rcCalcBounds(verts, nverts, config.bmin, config.bmax);
    rcCalcGridSize(config.bmin, config.bmax, config.cs, &config.width, &config.height);



    /* recast step 2: Build a rcHeightfield */

    rcContext ctx(false);

    container.heightfield = rcAllocHeightfield();
    if(!container.heightfield)
        return false;

    if(!rcCreateHeightfield(&ctx, *container.heightfield, config.width, config.height,
                        config.bmin, config.bmax, config.cs, config.ch))
        return false;

    //unsigned char areas[triCount]; // must be greater or equal to triangles.
    unsigned char* areas = new unsigned char[mTriCount]; // must be greater or equal to triangles.
    std::memset(areas, RC_NULL_AREA, sizeof(areas));
    rcMarkWalkableTriangles(&ctx, config.walkableSlopeAngle, verts, nverts, tris, ntris, areas);

    if(!rcRasterizeTriangles(&ctx, verts, nverts, tris, areas, ntris, *container.heightfield))
        return false;

    rcFilterLowHangingWalkableObstacles(&ctx, config.walkableClimb, *container.heightfield);
    rcFilterLedgeSpans(&ctx, config.walkableHeight, config.walkableClimb, *container.heightfield);
    rcFilterWalkableLowHeightSpans(&ctx, config.walkableHeight, *container.heightfield);

    /* recast step 3: Build a rcCompactHeightfield */

    container.compactHeightField = rcAllocCompactHeightfield();

    if(!container.compactHeightField)
        return false;

    if(!rcBuildCompactHeightfield(&ctx, config.walkableHeight, config.walkableClimb, *container.heightfield, *container.compactHeightField))
        return false;
    if(!rcErodeWalkableArea(&ctx, config.walkableRadius, *container.compactHeightField))
        return false;

    // next we have 3 algorithms for compact height field. Only one of then must be used.

    // Watershed partitioning
//    rcBuildDistanceField(&ctx, *container.compactHeightField);
//    rcBuildRegions(&ctx, *container.compactHeightField, config.borderSize, config.minRegionArea, config.mergeRegionArea);

    // Monotone partioning
    if(!rcBuildDistanceField(&ctx, *container.compactHeightField))
        return false;
    if(!rcBuildRegionsMonotone(&ctx, *container.compactHeightField, config.borderSize, config.minRegionArea, config.mergeRegionArea))
        return false;

    // Layer partitoining
//    rcBuildLayerRegions(&ctx, *container.compactHeightField, config.borderSize, config.minRegionArea);

    /* recast step 4: Build a rcContourSet */

    container.contourSet = rcAllocContourSet();
    if(!container.contourSet)
        return false;

    if(!rcBuildContours(&ctx, *container.compactHeightField, config.maxSimplificationError, config.maxEdgeLen, *container.contourSet))
        return false;

    /* recast step 5: Build a rcPolyMesh */

    container.polyMesh = rcAllocPolyMesh();
    if(!container.polyMesh)
        return false;

    if(!rcBuildPolyMesh(&ctx, *container.contourSet, config.maxVertsPerPoly, *container.polyMesh))
        return false;

    /******************************
     * ~ * ~ --- DETOUR --- ~ * ~ *
     ******************************/

    /* nav mesh data */

    //unsigned short navMeshDataFlags[triCount]; // must be greater or equal to triangles.
    unsigned short* navMeshDataFlags = new unsigned short[mTriCount]; // must be greater or equal to triangles.
    // Update poly flags from areas.
    for(int i=0; i<ntris; i++)
    {
        if(areas[i] == RC_WALKABLE_AREA)
            areas[i] = SAMPLE_POLYAREA_GROUND;

        if(areas[i] == SAMPLE_POLYAREA_GROUND ||
                areas[i] == SAMPLE_POLYAREA_GRASS ||
                areas[i] == SAMPLE_POLYAREA_ROAD){
            navMeshDataFlags[i] = SAMPLE_POLYFLAGS_WALK;
        }
        else if(areas[i] == SAMPLE_POLYAREA_WATER){
            navMeshDataFlags[i] = SAMPLE_POLYFLAGS_SWIM;
        }
        else if(areas[i] == SAMPLE_POLYAREA_DOOR){
            navMeshDataFlags[i] = SAMPLE_POLYFLAGS_WALK | SAMPLE_POLYFLAGS_DOOR;
        }
    }

    dtNavMeshCreateParams navMeshCreateParams;
    memset(&navMeshCreateParams, 0, sizeof(navMeshCreateParams));
    navMeshCreateParams.verts = container.polyMesh->verts;
    navMeshCreateParams.vertCount = container.polyMesh->nverts;
    navMeshCreateParams.polys = container.polyMesh->polys;
    navMeshCreateParams.polyFlags = navMeshDataFlags;
    navMeshCreateParams.polyAreas = areas;
    navMeshCreateParams.polyCount = container.polyMesh->npolys;
    navMeshCreateParams.nvp = config.maxVertsPerPoly;
    rcVcopy(navMeshCreateParams.bmin, config.bmin);
    rcVcopy(navMeshCreateParams.bmax, config.bmax);
    navMeshCreateParams.walkableHeight = config.walkableHeight;
    navMeshCreateParams.walkableRadius = config.walkableRadius;
    navMeshCreateParams.walkableClimb = config.walkableClimb;
    navMeshCreateParams.cs = config.cs;
    navMeshCreateParams.ch = config.ch;
    navMeshCreateParams.buildBvTree = true;

    unsigned char *navData;
    int navDataSize;
    if(!dtCreateNavMeshData(&navMeshCreateParams, &navData, &navDataSize))
        return false;

    /* nav mesh */

    this->mNavMesh = dtAllocNavMesh();
    if(!this->mNavMesh)
        return false;

    if(!dtStatusSucceed(this->mNavMesh->init(navData, navDataSize, DT_TILE_FREE_DATA)))
        return false;


    return true;
}


bool yNavMesh::findPath( yCurve& curve, yObjectNavMesh* navMeshContainer, const float *startPos, const float *endPos ) {

    //float pathFound[triCount*3];
    float* pathFound = new float[mTriCount*3];

    /// the size of path found
    int pathFoundSize;
    mPath.clear();

    /* nav mesh query */

    yNavMeshContainer container;
    container.navquery = dtAllocNavMeshQuery();
    if(!container.navquery)
        return false;

    // TODO: find a good number parameter (2048)
    if(!dtStatusSucceed(container.navquery->init(this->mNavMesh, 2048)))
        return false;

    dtQueryFilter queryFilter = dtQueryFilter();
//    queryFilter.setIncludeFlags(0xffff);
//    queryFilter.setExcludeFlags(0);

    float ext[] = {0, 0, 0};
    dtPolyRef sref, eref;
    float spoint[3], epoint[3];
    if(!dtStatusSucceed(container.navquery->findNearestPoly(startPos, ext, &queryFilter, &sref, spoint)))
        return false;
    if(!dtStatusSucceed(container.navquery->findNearestPoly(endPos, ext, &queryFilter, &eref, epoint)))
        return false;

    /* query */

    //dtPolyRef polys[triCount];
    dtPolyRef* polys = new dtPolyRef[mTriCount];
    int npolys;
    if(!dtStatusSucceed(container.navquery->findPath(sref, eref, spoint, epoint, &queryFilter, polys, &npolys, mTriCount)))
        return false;

    if(!dtStatusSucceed(container.navquery->findStraightPath(startPos, endPos, polys, npolys, pathFound, nullptr, nullptr,
                                                             &pathFoundSize, mTriCount*3, DT_STRAIGHTPATH_ALL_CROSSINGS)))
        return false;


    int k = 0;
    for( int i = 0; i < pathFoundSize; ++i ) {
        Ogre::Vector3 newPoint = Ogre::Vector3( pathFound[k], pathFound[k+1], pathFound[k+2] );
        if( navMeshContainer ) {
            //convert local to world position if container is given
            newPoint = yUtils::convertLocalToWorldPosition(*navMeshContainer, newPoint );
        }
        mPath.push_back( newPoint );
        k += 3;        
    }
    curve.addPoints( mPath );
    curve.makeConstant();

    return true;
}

Ogre::FastArray<Ogre::Vector3> yNavMesh::getPath() {
    return mPath;
}
