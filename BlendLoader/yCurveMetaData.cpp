#include "yCurveMetaData.h"
#include "BlenderSerialize/Serialize/BlenderSerialize/blend263/Blender.h"
#include "BlenderSerialize/BlenderDefines.h"
#include "Macros/yMacros.h"

yCurveMetaData::yCurveMetaData() {

}

bool yCurveMetaData::parser( Blender::Object *bObject ){

    bool isCurve = false;

    if( bObject->type == OB_CURVE ) {
        Blender::Curve* bCurve = static_cast<Blender::Curve*>( bObject->data );
        yAssert( bCurve, ( "fail getting curve data. Object: " + std::string(GET_NAME(bObject)) ).c_str() );

        Blender::Nurb* bNurb = (Blender::Nurb*)bCurve->nurb.first;
        yAssert( bNurb, ( "fail getting Nurb data. Object: " + std::string(GET_NAME(bObject)) ).c_str() );

        if( bNurb->type == CU_BEZIER ) {

            //check if is a cyclic curve
            mIsCyclic = (bNurb->flagu & CU_CYCLIC) || (bNurb->flagv & CU_CYCLIC);

            //check constant
            mIsConstant = !(bCurve->flag & CU_STRETCH);

            //get the points
            for( size_t i = 0; i < bNurb->pntsu; ++i ) {
                const Blender::BezTriple& trp = bNurb->bezt[i];
                Ogre::FastArray<Ogre::Vector3> bezTriple;
                for( size_t j = 0; j < 3; ++j ) {
                    Ogre::Vector3 bt;
                    bt.x = trp.vec[j][0];
                    bt.y = trp.vec[j][1];
                    bt.z = trp.vec[j][2];
                    bt = yUtils::convertToYup( bt );
                    bezTriple.push_back( bt );
                }
                mBezTriples.push_back( bezTriple );
            }

            //if we have an empty curve just ignore it
            if( mBezTriples.size() > 0 ) {
                isCurve = true;
            }
        }
    }

    return isCurve;
}

bool yCurveMetaData::getIsCyclic() {
    return mIsCyclic;
}

bool yCurveMetaData::getIsConstant() {
    return mIsConstant;
}

Ogre::FastArray< Ogre::FastArray<Ogre::Vector3> >& yCurveMetaData::getBezTriples() {
    return mBezTriples;
}
