#include "yAnimationMetaData.h"
#include "BlenderSerialize/Serialize/BlenderSerialize/blend263/Blender.h"
#include "BlenderSerialize/BlenderDefines.h"
#include "Macros/yMacros.h"
#include "Constants/yConstantsThreads.h"

#include "OgreMatrix4.h"

yAnimationMetaData::yAnimationMetaData() {
    mAnimationSkeleton = nullptr;
}

bool yAnimationMetaData::parser( Blender::Object* bObject, std::string blendFileName ) {

    yAssert( bObject, "blender object can't be null" );
    mBlendFile = blendFileName;

    //animation
    Blender::AnimData* bAnimationData = nullptr;

    //Look for it the Modifiers
    for( Blender::ModifierData* modifierData = (Blender::ModifierData*)bObject->modifiers.first; modifierData; modifierData = modifierData->next ) {
        //Modifier type Armature
        if( modifierData->type == 8 && ( modifierData->mode & MOD_MASK_INV ) ) {
            Blender::ArmatureModifierData* armatureMod = (Blender::ArmatureModifierData*)modifierData;
            yAssert( armatureMod, "modifier is an armature, but armature is null" );

            Data* data = new Data();

            //Generate the skeleton usign the skeleton blender object that the modifier uses
            if( generateSkeleton(armatureMod->object, data) ) {
                data->mSkeletonName = mBlendFile + "_" + GET_NAME(armatureMod->object);
                //If "Bone Envelopes" is enabled make the object Bone Controlled aka Ragdoll
                if( armatureMod->deformflag == 3 ) {
                    data->mIsBoneControlled = true;
                }
                else {
                    data->mIsBoneControlled = false;
                }
                data->mIsAutoPlay = false;
                data->mSetInitialTimeRandom = false;

                //we only need the first one find it
                bAnimationData = armatureMod->object->adt;
                mAnimationSkeleton = data;
                break;
            }
            else {
                delete data;
                data = nullptr;
            }
        }
    }

    //Skeleton animation
    if( bAnimationData ) {
        Blender::NlaTrack* nlaTrack = (Blender::NlaTrack*)bAnimationData->nla_tracks.first;

        while( nlaTrack && ( nlaTrack->flag | 4) ){
            Blender::NlaStrip* nlaStrip = (Blender::NlaStrip*)nlaTrack->strips.first;
            while( nlaStrip ) {
                Blender::bAction* bAction = nlaStrip->act;
                if( bAction ) {
                    convertAnimation( bAction, *mAnimationSkeleton );
                    mAnimationSkeleton->mAnimationName = mBlendFile + "_" + GET_NAME(bAction);
                    mAnimationSkeleton->mAnimationAliasName = GET_NAME(bAction);
                }
                nlaStrip = nlaStrip->next;
            }
            nlaTrack = nlaTrack->next;
        }
    }

    //Object animation
    Blender::AnimData* bAnimationObjectData = bObject->adt;
    if( bAnimationObjectData ){
        Blender::NlaTrack *nlaTrack = (Blender::NlaTrack*)bAnimationObjectData->nla_tracks.first;

        /** @todo check (nlaTrack->flag | 4) **/
        while( nlaTrack && (nlaTrack->flag | 4) ) {
            Blender::NlaStrip* nlaStrip = (Blender::NlaStrip*)nlaTrack->strips.first;
            while( nlaStrip ) {
                Blender::bAction* bAction = nlaStrip->act;
                if( bAction ) {
                    Data* data = new Data();
                    convertAnimation( bAction, *data );
                    data->mIsAutoPlay = false;
                    data->mSetInitialTimeRandom = false;
                    data->mAnimationName = mBlendFile + "_" + GET_NAME(bAction);
                    data->mAnimationAliasName = GET_NAME(bAction);
                    mAnimationObject.addData( mBlendFile + "_" + GET_NAME(bAction), data );
                }
                nlaStrip = nlaStrip->next;
            }
            nlaTrack = nlaTrack->next;
        }
    }

    //check actuators, maybe we must auto play
    for( Blender::bActuator *bActuator = (Blender::bActuator*)bObject->actuators.first; bActuator; bActuator = bActuator->next ) {
        //Play the animation thats on an action actuator
        if( bActuator->type == ACT_ACTION ) {
            Blender::bActionActuator *bActionActuator = (Blender::bActionActuator*)bActuator->data;
            if( bActionActuator->act ) {
                Data* data = nullptr;
                if( mAnimationSkeleton->mAnimationAliasName == GET_NAME(bActionActuator->act) ) {
                    data = mAnimationSkeleton;
                }
                else {
                    for( size_t i = 0; i < mAnimationObject.size(); ++i ) {
                        if( mAnimationObject[i]->mAnimationAliasName == GET_NAME(bActionActuator->act) ) {
                            data = mAnimationObject[i];
                            break;
                        }
                    }
                }

                if( data ) {
                    if( bActionActuator->flag & 16 ){
                        data->mSetInitialTimeRandom = true;
                    }
                    data->mIsAutoPlay = true;
                }
            }
        }
    }

    return mAnimationSkeleton || mAnimationObject.size();
}

//Generate Skeleton, Root bones and child tree
bool yAnimationMetaData::generateSkeleton( Blender::Object *bObject, Data* data ) {

    yAssert( bObject, "object null" );
    Blender::bArmature *bArmature = static_cast<Blender::bArmature*>( bObject->data );
    if( bArmature ) {
        Blender::Bone *bBone = static_cast<Blender::Bone*>(bArmature->bonebase.first);
        while( bBone ) {
            // only process root bones
            if( !bBone->parent ) {
                buildBoneTree( bBone, nullptr, data );
            }
            bBone = bBone->next;
        }
    }

    return data->mBoneData.size();
}

void yAnimationMetaData::buildBoneTree( Blender::Bone* cur, Blender::Bone* prev, Data* data, int parentIndex ) {

    Ogre::Matrix4 parBind = Ogre::Matrix4::IDENTITY;
    if( prev && parentIndex != -1 ) {
        parBind = getFromFloatNorm(prev->arm_mat).inverse();
    }

    Ogre::Matrix4 bind = parBind * getFromFloatNorm( cur->arm_mat );

    Ogre::Quaternion rot;
    Ogre::Vector3 loc, scl;
    // extract translation and rotation
    loc = bind.getTrans();
    rot = bind.extractQuaternion();
    // extract scale
    Ogre::Matrix4 invRot(rot.Inverse());
    Ogre::Matrix4 T = invRot * bind;
    scl = Ogre::Vector3(T[0][0], T[1][1], T[2][2]);

    if( loc.isNaN() ) {
        loc = Ogre::Vector3::ZERO;
    }
    if( rot.isNaN() ) {
        rot = Ogre::Quaternion::IDENTITY;
        scl = Ogre::Vector3::UNIT_SCALE;
    }
    if( scl.isNaN() ) {
        scl = Ogre::Vector3::UNIT_SCALE;
    }

    // create the bone data
    BoneData boneData;
    boneData.mParentIndex = parentIndex;
    boneData.mName = cur->name;
    boneData.mTransf.position = yUtils::convertToYup(loc);
    boneData.mTransf.orientation = Ogre::Quaternion(rot.w,-rot.x,rot.z,rot.y);
    boneData.mTransf.scale = scl;
    data->mBoneData.push_back(boneData);
    int myIndex = (int)data->mBoneData.size() - 1;

    Blender::Bone* chi = static_cast<Blender::Bone*>(cur->childbase.first);
    while( chi ) {
        // recurse
        //only we need to rectify the root bone respect object, so pass identity transform to the other bones
        buildBoneTree( chi, cur, data, myIndex );
        chi = chi->next;
    }
}

Ogre::Matrix4 yAnimationMetaData::getFromFloatNorm(const float m[][4]) {
    Ogre::Vector3 loc, scale;
    Ogre::Quaternion quat;

    // convert a Blender4x4 matrix to Ogre4x4
    Ogre::Matrix4 btomat = Ogre::Matrix4(
                m[0][0], m[1][0], m[2][0], m[3][0],
                m[0][1], m[1][1], m[2][1], m[3][1],
                m[0][2], m[1][2], m[2][2], m[3][2],
                m[0][3], m[1][3], m[2][3], m[3][3]
            );

    // extract translation
    loc = btomat.getTrans();

    // extract rotation
    Ogre::Matrix3 matr;
    btomat.extract3x3Matrix(matr);
    matr.Orthonormalize();

    Ogre::Quaternion rot(matr);
    if( rot.Norm() != 1.0f ) {
        rot.normalise();
    }
    quat = rot;

    // extract scale
    Ogre::Matrix4 invRot(rot.Inverse());
    btomat = invRot * btomat;
    scale = Ogre::Vector3(btomat[0][0], btomat[1][1], btomat[2][2]);

    Ogre::Matrix4 ret;
    ret.makeTransform(loc, scale, quat);
    return ret;
}


void yAnimationMetaData::convertAnimation( Blender::bAction* bAction, Data& newAnimation ) {

    // min/max
    float start, end;
    getActionStartEnd(bAction, start, end);

    newAnimation.mLength = (float)(end-start) / yConstantsThreads::ANIMATION_FRAME_RATE;

    Blender::FCurve* bfc = (Blender::FCurve*)bAction->curves.first;

    while( bfc ) {

        if( bfc->flag & 16 ) { //muted
            bfc = bfc->next;
            continue;
        }

        std::string rnap(bfc->rna_path);
        std::string chan_name;
        std::string transform_name;

        // Pose action
        if( rnap.substr(0, 10) == "pose.bones" ) {
            size_t i = rnap.rfind('\"');
            chan_name = rnap.substr(12, i - 12);
            transform_name = rnap.substr(i + 3, rnap.length() - i + 3);
        }
        // Object action
        else {
            transform_name = rnap;
            chan_name = "MainObjectChannel";
        }

        if( bfc->bezt ) {
            int transformType = -1;
            if( transform_name == "rotation_quaternion" ) {
                if( bfc->array_index == 0 ) {
                    transformType = yAnimationData::SC_ROT_QUAT_W;
                }
                else if( bfc->array_index == 1 ) {
                    transformType = yAnimationData::SC_ROT_QUAT_X;
                }
                else if( bfc->array_index == 2 ) {
                    transformType = yAnimationData::SC_ROT_QUAT_Y;
                }
                else if( bfc->array_index == 3 ) {
                    transformType = yAnimationData::SC_ROT_QUAT_Z;
                }
            }
            else if (transform_name == "rotation_euler") {
                if( bfc->array_index == 0 ) {
                    transformType = yAnimationData::SC_ROT_EULER_X;
                }
                else if( bfc->array_index == 1 ) {
                    transformType = yAnimationData::SC_ROT_EULER_Y;
                }
                else if( bfc->array_index == 2) {
                    transformType = yAnimationData::SC_ROT_EULER_Z;
                }
            }
            else if( transform_name == "location" ) {
                if( bfc->array_index == 0 ) {
                    transformType = yAnimationData::SC_LOC_X;
                }
                else if( bfc->array_index == 1 ) {
                    transformType = yAnimationData::SC_LOC_Y;
                }
                else if( bfc->array_index == 2 ) {
                    transformType = yAnimationData::SC_LOC_Z;
                }
            }
            else if( transform_name == "scale" ) {
                if( bfc->array_index == 0 ) {
                    transformType = yAnimationData::SC_SCL_X;
                }
                else if( bfc->array_index == 1 ) {
                    transformType = yAnimationData::SC_SCL_Y;
                }
                else if( bfc->array_index == 2 ) {
                    transformType = yAnimationData::SC_SCL_Z;
                }
            }

            // ignore any other codes
            if( transformType != -1 && bfc->totvert > 0 ) {
                yBezierSpline newSpline = convertSpline( bfc->bezt, bfc->bezt->ipo, bfc->totvert, -start );
                if( newSpline.getNumVerts() ) {
                    newAnimation.mAnimation.addSpline( chan_name, transformType, newSpline );
                }
            }
        }

        if( !bfc->next || bfc->next->prev != bfc ) {
            break;
        }

        bfc = bfc->next;
    }

}

void yAnimationMetaData::getActionStartEnd( Blender::bAction* bAction, float& start, float& end ) {
    yAssert( bAction, "null action!" );

    start = FLT_MAX;
    end = -FLT_MAX;

    float tstart, tend;

    Blender::FCurve* bfc = (Blender::FCurve*)bAction->curves.first;
    while( bfc ) {
        getSplineStartEnd(bfc->bezt, bfc->totvert, tstart, tend);
        if( start > tstart ) {
            start = tstart;
        }

        if( end < tend ) {
            end = tend;
        }

        if( bfc->next == 0 || bfc->next->prev != bfc ) {
            break;
        }

        bfc = bfc->next;
    }
}

void yAnimationMetaData::getSplineStartEnd( Blender::BezTriple* bez, int totvert, float& start, float& end ) {
    start = FLT_MAX;
    end = -FLT_MAX;

    Blender::BezTriple* bezt = bez;
    for( int c = 0; c < totvert; ++c, ++bezt ) {
        if( start > bezt->vec[1][0] ) {
            start = bezt->vec[1][0];
        }

        if( end < bezt->vec[1][0] ) {
            end = bezt->vec[1][0];
        }
    }
}

yBezierSpline yAnimationMetaData::convertSpline( Blender::BezTriple* bez, int mode, int totvert, float xoffset ) {
    float xfactor = 1.0f/yConstantsThreads::ANIMATION_FRAME_RATE;
    float yoffset = 0.0f;
    float yfactor = 1.0f;

    yBezierSpline spline;

    switch (mode) {
    case 0://BEZT_IPO_CONST:
        spline.setInterpolationMethod(yBezierSpline::BEZ_CONSTANT);
        break;
    case 1://BEZT_IPO_LIN:
        spline.setInterpolationMethod(yBezierSpline::BEZ_LINEAR);
        break;
    default://BEZT_IPO_BEZ:
        spline.setInterpolationMethod(yBezierSpline::BEZ_CUBIC);
        break;
    }


    Blender::BezTriple* bezt = bez;
    for( int c = 0; c < totvert; c++, bezt++) {
        yAssert( bezt, "null entry converting spline" );
        yBezierVertex v;

        v.h1[0] = (bezt->vec[0][0] + xoffset) * xfactor;
        v.h1[1] = (bezt->vec[0][1] + yoffset) * yfactor;
        v.cp[0] = (bezt->vec[1][0] + xoffset) * xfactor;
        v.cp[1] = (bezt->vec[1][1] + yoffset) * yfactor;
        v.h2[0] = (bezt->vec[2][0] + xoffset) * xfactor;
        v.h2[1] = (bezt->vec[2][1] + yoffset) * yfactor;

        spline.addVertex(v);
    }

    return spline;

}

yAnimationMetaData::Data* yAnimationMetaData::getAnimationSkeleton() {
    return mAnimationSkeleton;
}

yFastArray<yAnimationMetaData::Data*>& yAnimationMetaData::getAnimationObject() {
    return mAnimationObject;
}
