#ifndef YANIMATIONDATA_H
#define YANIMATIONDATA_H

#include "assert.h"
#include "OgreFastArray.h"
#include <map>

struct yBezierVertex {
    float h1[2];
    float cp[2];
    float h2[2];
};

class yBezierSpline
{
public:

    enum BezierInterpolation
    {
        BEZ_LINEAR,
        BEZ_CONSTANT,
        BEZ_CUBIC,
    };

protected:
    Ogre::FastArray<yBezierVertex>  m_verts;
    int                             m_code;
    BezierInterpolation             m_interpMethod;


    int solveRoots(const double& x,
                   const double p0,
                   const double p1,
                   const double p2,
                   const double p3,
                   double& s) const;

    float interpolate(const double& t,
                         const double& p0,
                         const double& p1,
                         const double& p2,
                         const double& p3) const;


    void updateHandles(float* p0, float* p1, float* p2, float* p3) const;


public:
    yBezierSpline() : m_interpMethod(BEZ_LINEAR) {}
    ~yBezierSpline() {}

    // interpolate across this spline
    // delta is the normalized time
    // time is the current frame number
    float interpolate( float delta, float time ) const;

    void addVertex(yBezierVertex v) {
        m_verts.push_back(v);
    }

    Ogre::FastArray<yBezierVertex> getVerts(void) const {
        return m_verts;
    }

    int getNumVerts(void) const {
        return (int)m_verts.size();
    }


    void setInterpolationMethod(BezierInterpolation meth) {
        m_interpMethod = meth;
    }

    BezierInterpolation getInterpolationMethod(void) const {
        return m_interpMethod;
    }
};

struct yAnimationTransforms {
    yBezierSpline animationSplines[13];
};

class yAnimationData
{
public:

    enum ANIMATION_CHANNEL { SC_ROT_QUAT_W, SC_ROT_QUAT_X, SC_ROT_QUAT_Y, SC_ROT_QUAT_Z,
                     SC_ROT_EULER_X, SC_ROT_EULER_Y, SC_ROT_EULER_Z,
                     SC_LOC_X, SC_LOC_Y, SC_LOC_Z,
                     SC_SCL_X, SC_SCL_Y, SC_SCL_Z };

    yAnimationData(){}
    void addSpline( std::string object, int channelType, yBezierSpline spline ) {
        animationTransforms[object].animationSplines[channelType] = spline;
    }

    std::map<std::string,yAnimationTransforms> animationTransforms;
};

#endif // YANIMATIONDATA_H
