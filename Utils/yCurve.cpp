#include "yCurve.h"
#include "BlendLoader/yCurveMetaData.h"
#include "Macros/yMacros.h"

yCurve::yCurve() {
    mLength = 0;
    mIsCyclic = false;
    mIsConstant = false;
}

yCurve::yCurve( yCurveMetaData* curveData ) {
    yAssert( curveData, ( "trying to set a curve with null" ) );

    mLength = 0;
    mBezTriples = curveData->getBezTriples();
    mIsCyclic = curveData->getIsCyclic();
    mIsConstant = curveData->getIsConstant();
    generateBezierPoints();
}

void yCurve::generateBezierPoints( float t, bool constant ) {

    yAssert( t > 0, "steps 't' must be greater than 0" );
    mCurvePoints.clear();

    size_t triCount = mBezTriples.size();

    for( size_t i = 0; i < triCount - 1; ++i ) {
        Ogre::FastArray<Ogre::Vector3>& bezFirst = mBezTriples[i];
        Ogre::FastArray<Ogre::Vector3>& bezSecond = mBezTriples[i + 1];

        makeBezier( t, bezFirst, bezSecond );
    }

    if( mIsCyclic ) {
        yAssert( triCount > 0, "no bezier triples" );
        Ogre::FastArray<Ogre::Vector3>& bezFirst = mBezTriples[triCount - 1];
        Ogre::FastArray<Ogre::Vector3>& bezSecond = mBezTriples[0];

        makeBezier( t, bezFirst, bezSecond );
    }

    if( constant ) {
        makeConstant();
    }

    mLength = 0;
    for( size_t i = 0; i < mCurvePoints.size() - 1; ++i ) {
        mLength += mCurvePoints[i].distance( mCurvePoints[i+1] );
    }

}

void yCurve::makeBezier( float t, Ogre::FastArray<Ogre::Vector3>& first, Ogre::FastArray<Ogre::Vector3>& second ) {

    yAssert( t > 0, "steps 't' must be greater than 0" );
    Ogre::Vector3& pt0 = first[1];
    Ogre::Vector3& pt1 = first[2];
    Ogre::Vector3& pt2 = second[0];
    Ogre::Vector3& pt3 = second[1];

    for( float tt = 0.f; tt < 1.f; tt += t ) {
        float yt = 1 - tt;
        float t1 = yt * yt;
        float t2 = 3 * yt * tt;
        Ogre::Vector3 pt = pt0 * t1 * yt + pt1 * t2 * yt + pt2 * t2 * tt + pt3 * tt * tt * tt;
        mCurvePoints.push_back(pt);
    }
}

void yCurve::makeConstant() {

    Ogre::FastArray<Ogre::Vector3> constantPoints;
    float step = 0.003f;
    float i = 0.0f;

    constantPoints.push_back( getLocalPoint(i) );
    while( i <= 1.0f ) {
        Ogre::Vector3 currentPoint = getLocalPoint(i);
        Ogre::Vector3 nextPoint = getLocalPoint( i + step );

        Ogre::Vector3 newPoint = nextPoint - currentPoint;
        newPoint = newPoint.normalisedCopy() * step;

        newPoint += currentPoint;

        i += step * ( currentPoint.distance( newPoint ) / currentPoint.distance( nextPoint ) );

        constantPoints.push_back( newPoint );
    }

    mCurvePoints = constantPoints;
}

void yCurve::addPoints( Ogre::FastArray<Ogre::Vector3> points ) {
    for( size_t i = 0; i < points.size(); ++i ) {
        if( mCurvePoints.size() ) {
            mLength += mCurvePoints[ mCurvePoints.size() - 1 ].distance( points[i] );
        }
        mCurvePoints.push_back( points[i] );
    }
}

Ogre::Vector3 yCurve::getLocalPoint( float nr ) {
    /// TODO: i think that if we pass nr=1.0 it isn´t the last last point of curve.

    Ogre::Vector3 point;

    if( mCurvePoints.size() != 0 ) {
        if( nr > 1.0 ) {
            point = mCurvePoints[mCurvePoints.size()-1];
        }
        else if( nr < 0.0 ){
            point = mCurvePoints[0];
        }
        else {
            int pointIndex = nr * ( mCurvePoints.size() - 1 );
            int nextPointIndex = pointIndex;
            if( pointIndex + 1 < mCurvePoints.size() ) {
                nextPointIndex = pointIndex + 1;
            }
            float interpolationValue = nr * ( mCurvePoints.size() - 1 ) - pointIndex;

            point = Ogre::Math::lerp( mCurvePoints[pointIndex], mCurvePoints[nextPointIndex], interpolationValue );

        }
    }

    return point;
}

float yCurve::getLength() {
    return mLength;
}
