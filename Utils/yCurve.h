#ifndef YCURVE_H
#define YCURVE_H

#include "OgreVector3.h"
class yCurveMetaData;

class yCurve
{
public:
    /**
     * @brief yCurve Manual curve builder. Later you must add
     * the points with #addPoints. Also, you can call #makeConstant
     */
    yCurve();

    /**
     * @brief yCurve Automatic curve builder. It will build the curve
     * with the meta data given
     * @param curveData the meta data
     */
    yCurve( yCurveMetaData* curveData );

    /**
     * @brief setCurveData set the data to generate the curve.
     * By default it call generateBezierPoints() after extract
     * data from metadata
     * @param curveData the metadata to instance the curve
     */
    void setCurveData( yCurveMetaData* curveData );

    /**
     * @brief generateBezierPoints generate all the points of the curve, so
     * can be use later with getLocalPoint() and getWorldPoint()
     * @param t steps between points, lower values means more points are generated.
     * Must be greater than 0
     * @param constant if you want a constant distance between points, set this flag
     * true; otherwise you will get the separation like in the blend file
     */
    void generateBezierPoints( float t = 0.001, bool constant = true );

    /**
     * @brief getLocalPoint get a point local position from path
     * @param nr Porcentage of path desired (between 0 and 1)
     * @return point of path.
     */
    Ogre::Vector3 getLocalPoint( float nr );

    /**
     * @brief getLength get the curve length
     * @return the total length of the curve
     */
    float getLength();

    /**
     * @brief makeConstant convert the points of the current curve so
     * they are separate by a constant distance
     */
    void makeConstant();

    /**
     * @brief addPoints manually add the points to the curve. Generally
     * you want do this when build the yCurve without the meta data
     * @param points the points
     */
    void addPoints( Ogre::FastArray<Ogre::Vector3> points );

private:
    /**
     * @brief makeBezier generate points between two points
     * @param t steps between points, lower values means more points are generated.
     * Must be greater than 0
     * @param first start point
     * @param second end point
     */
    void makeBezier( float t, Ogre::FastArray<Ogre::Vector3>& first, Ogre::FastArray<Ogre::Vector3>& second );

    Ogre::FastArray< Ogre::FastArray <Ogre::Vector3> > mBezTriples; ///< the curve meta data (we store so the user can generate the curve with another step)
    Ogre::FastArray<Ogre::Vector3> mCurvePoints; ///< the real curve points
    bool mIsCyclic; ///< the curve is cyclic
    bool mIsConstant;  ///< the curve must have constant separation
    float mLength;  ///< the length of the curve
};

#endif // YCURVE_H
