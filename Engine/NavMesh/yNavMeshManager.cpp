#include "yNavMeshManager.h"
#include "Objects/yObject.h"
#include "Objects/Types/yObjectNavMesh.h"
#include "Objects/yObjectInstance.h"
#include "BlendLoader/yMeshMetaData.h"
#include "Utils/yCurve.h"

yNavMeshManager::yNavMeshManager() {

}

void yNavMeshManager::notifyObjectCreated( yObjectInstance* object ) {
    if( object->getObject()->getObjectType() == yObjectType::NAVMESH ) {
        //is a nav mesh, build it
        yObjectNavMesh* objectNav = static_cast<yObjectNavMesh*>(object->getObject());
        object->getObjectDefinitionGraphics().mMeshMetaData->poblateNavMesh( objectNav->getNavMesh() );
    }
}

void yNavMeshManager::update() {
    for( size_t i = mActivePaths.size() - 1; i < mActivePaths.size(); --i ) {
        mActivePaths[i].mCurrentPathPos += yConstantsThreads::TICK_RATE * mActivePaths[i].mSpeed;
        if( mActivePaths[i].mCurrentPathPos >= 1.0 ) {
            //we are done with the path, remove it
            delete mActivePaths[i].mPath;
            mActivePaths[i].mObject = mActivePaths[ mActivePaths.size() - 1 ].mObject;
            mActivePaths[i].mSpeed = mActivePaths[ mActivePaths.size() - 1 ].mSpeed;
            mActivePaths[i].mPath = mActivePaths[ mActivePaths.size() - 1 ].mPath;
            mActivePaths[i].mCurrentPathPos = mActivePaths[ mActivePaths.size() - 1 ].mCurrentPathPos;
            mActivePaths.pop_back();
        }
        else {
            yAssert( mActivePaths[i].mObject, "object null" );
            Ogre::Vector3 prevPos = mActivePaths[i].mObject->getWorldPosition();
            Ogre::Vector3 newPos = mActivePaths[i].mPath->getLocalPoint( mActivePaths[i].mCurrentPathPos ); //actually is in world coordinates because nav
                                                                                                            //mesh give us the path in world coordinates
            mActivePaths[i].mObject->setWorldPosition( newPos );

            //lets smooth the rotation a little
            Ogre::Quaternion currentOrientation = mActivePaths[i].mObject->getWorldOrientation();

            Ogre::Vector3 prevDirection = -currentOrientation.zAxis();
            Ogre::Vector3 currentDirection = newPos - prevPos;

            Ogre::Vector3 distance = currentDirection.normalisedCopy() - prevDirection.normalisedCopy();
            Ogre::Vector3 delta = Ogre::Math::lerp( prevDirection.normalisedCopy(), currentDirection.normalisedCopy(), distance.length() * 0.05 );

            mActivePaths[i].mObject->setWorldOrientation( yUtils::calculateDirection( mActivePaths[i].mObject, delta, Ogre::Vector3::NEGATIVE_UNIT_Z, true ) );
            //node->setDirection( delta, Ogre::Node::TS_WORLD );
            //node->setFixedYawAxis( true, Ogre::Vector3::UNIT_Y );
        }
    }
}

void yNavMeshManager::notifyObjectAdded( yObjectInstance* object ) {

}

void yNavMeshManager::notifyObjectRemoved( yObjectInstance* object ) {
    yObject* obj = object->getObject();

    //if the object is in an active path, remove it
    for( size_t i = mActivePaths.size() - 1; i < mActivePaths.size(); --i ) {
        if( mActivePaths[i].mObject == obj ) {
            delete mActivePaths[i].mPath;
            mActivePaths[i].mObject = mActivePaths[ mActivePaths.size() - 1 ].mObject;
            mActivePaths[i].mSpeed = mActivePaths[ mActivePaths.size() - 1 ].mSpeed;
            mActivePaths[i].mPath = mActivePaths[ mActivePaths.size() - 1 ].mPath;
            mActivePaths[i].mCurrentPathPos = mActivePaths[ mActivePaths.size() - 1 ].mCurrentPathPos;
            mActivePaths.pop_back();
        }
    }
}

void yNavMeshManager::notifyObjectDestroyed( yObjectInstance* object ) {
    yObject* obj = object->getObject();

    //if the object is in an active path, remove it
    for( size_t i = mActivePaths.size() - 1; i < mActivePaths.size(); --i ) {
        if( mActivePaths[i].mObject == obj ) {
            delete mActivePaths[i].mPath;
            mActivePaths[i].mObject = mActivePaths[ mActivePaths.size() - 1 ].mObject;
            mActivePaths[i].mSpeed = mActivePaths[ mActivePaths.size() - 1 ].mSpeed;
            mActivePaths[i].mPath = mActivePaths[ mActivePaths.size() - 1 ].mPath;
            mActivePaths[i].mCurrentPathPos = mActivePaths[ mActivePaths.size() - 1 ].mCurrentPathPos;
            mActivePaths.pop_back();
        }
    }
}

void yNavMeshManager::travelTo( yObject* object, yObject* navMesh, Ogre::Vector3 targetWorldPos, float speed ) {
    yAssert( object, "null object" );
    yAssert( navMesh, "null nav mesh" );
    yAssert( navMesh->getObjectType() == yObjectType::NAVMESH, "nav mesh is not a nav mesh object type" );

    ActiveFollowPath followPath;
    followPath.mObject = object;
    followPath.mSpeed = speed;
    followPath.mCurrentPathPos = 0;
    followPath.mPath = new yCurve();
    yObjectNavMesh* objectNavMesh = static_cast<yObjectNavMesh*>(navMesh);
    objectNavMesh->findPath( *followPath.mPath, followPath.mObject->getWorldPosition(), targetWorldPos );
    mActivePaths.push_back(followPath);
}
