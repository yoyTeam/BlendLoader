#include "yUtils.h"
#include <string>
#include "OgreStringConverter.h"
#include <QString>
#include <QDir>
#include <QDate>
#include <iostream>
#include "Engine/yEngine.h"
#include "Objects/yObject.h"
#include "Objects/yObjectInstance.h"
#include <random>

#include "Engine/yEngineServices.h"
#include "Engine/yEngineGraphicsData.h"

namespace yUtils {

    //remove numbers before the text
    std::string removePreNumbers( std::string name ){
        std::string cleanName = name;
        for( size_t j = 0; j < cleanName.size(); j++ ) {
            if( !Ogre::StringConverter::isNumber(cleanName.substr(j,1)) ) {
                cleanName = cleanName.substr(j);
                break;
            }
        }
        return cleanName;
    }

    //Convert blender's Z-Up to Ogre's Y-Up
    Ogre::Vector3 convertToYup( Ogre::Vector3 vector ){
        Ogre::Vector3 convertedVector = Ogre::Vector3(-vector.x, vector.z, vector.y);
        return convertedVector;
    }

    //normalize path
    std::string normalizeBlendPath( std::string path ) {
        QString qPath = QString::fromStdString(path);

        qPath.replace("\\","/");
        qPath.replace("//","");

        return QDir( qPath ).absolutePath().toStdString();
    }

    //normalize local path
    std::string normalizeBlendPath( std::string parentPath, std::string localPath ) {
        QString qRelativePath = QString::fromStdString(localPath);
        QString qParentPath = QString::fromStdString(parentPath);

        qRelativePath.replace("\\","/");
        qRelativePath.replace("//","");
        qParentPath.replace("\\","/");

        //remove file name
        QDir parent(qParentPath); parent.cdUp();
        qParentPath = parent.absolutePath();
        qParentPath.append("/");

        //make path
        std::string finalPath = qParentPath.toStdString() + qRelativePath.toStdString();

        //make absolute
        return normalizeBlendPath(finalPath);
    }

    //get the file name from a path
    std::string getFileName( std::string path ) {
        size_t found = path.find_last_of("/\\");
        std::string nameWithNoPath = path.substr(found+1);
        return nameWithNoPath;
    }

    //get the file name from a path and remove extension
    std::string getFileNameNoExtension( std::string path ) {
        std::string filename = getFileName(path);
        size_t lastdot = filename.find_last_of(".");
        if( lastdot == std::string::npos ) {
            return filename;
        }
        else {
            return filename.substr(0, lastdot);
        }
    }

    std::string getDateInStandardString(){
        QDateTime current = QDateTime::currentDateTime();
        return current.toString( "yyyy-MM-dd_hh-mm-ss" ).toStdString();
    }

    //layerbit
    int layerToLayerBit( int layer ) {
        return std::pow(2,layer);
    }

    btVector3 ogreToBullet(const Ogre::Vector3 vector){
        return btVector3(vector.x, vector.y, vector.z);
    }

    btQuaternion ogreToBullet(const Ogre::Quaternion quaternion){
        return btQuaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
    }

    btTransform ogreToBullet(const Ogre::Vector3 vector, const Ogre::Quaternion quaternion){
        return btTransform(
                    btQuaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w),
                    btVector3(vector.x, vector.y, vector.z));
    }

    Ogre::Vector3 bulletToOgre(const btVector3 vector){
        return Ogre::Vector3(vector.x(), vector.y(), vector.z());
    }

    Ogre::Quaternion bulletToOgre(const btQuaternion quaternion){
        return Ogre::Quaternion(quaternion.w(), quaternion.x(), quaternion.y(), quaternion.z());
    }

    namespace bt {
        namespace math {
            // source: https://ingenieriaensistemasuat.wordpress.com/2011/04/25/cosenos-directores-de-un-vector-problema-resuelto/
            btScalar angleX(const btVector3 vector){
                return btAcos(vector.x() / vector.norm());
            }
            btScalar angleY(const btVector3 vector){
                return btAcos(vector.y() / vector.norm());
            }
            btScalar angleZ(const btVector3 vector){
                return btAcos(vector.z() / vector.norm());
            }

            btVector3 rotate(const btVector3 vector, const btVector3 axis, const btScalar angle, const btVector3 origin){
                return (vector - origin).rotate(axis, angle) + origin;
            }

            btVector3 setDistance(const btVector3 vector, const btScalar distance, const btVector3 origin){
                btVector3 new_vector = vector - origin;
                return new_vector * (distance / new_vector.length()) + origin;
            }
        }
    }

    bool isLogicThread() {
        return yEngine::checkThread() == yEngine::ThreadLogic;
    }

    bool isGraphicsThread() {
        return yEngine::checkThread() == yEngine::ThreadGraphic;
    }

    Ogre::Vector3 convertLocalToWorldPosition( yObject& obj, Ogre::Vector3 localPos ) {
        //return obj.getWorldOrientation() * ( localPos * obj.getScale() ) + obj.getWorldPosition();
        return obj.getWorldOrientation() * localPos + obj.getWorldPosition();
    }

    Ogre::Vector3 convertWorldToLocalPosition( yObject& obj, Ogre::Vector3 worldPos ) {
        //return obj.getWorldOrientation().Inverse() * ( worldPos - obj.getWorldPosition() ) / obj.getScale();
        return obj.getWorldOrientation().Inverse() * ( worldPos - obj.getWorldPosition() );
    }

    Ogre::Quaternion convertLocalToWorldOrientation( yObject& obj, Ogre::Quaternion localOri ) {
        return obj.getWorldOrientation() * localOri;
    }

    Ogre::Quaternion convertWorldToLocalOrientation( yObject& obj, Ogre::Quaternion worldOri ) {
        return obj.getWorldOrientation().Inverse() * worldOri;
    }

    std::string getNumericSubFix( size_t number ) {
        std::string subFix;
        if( number < 10 ) {
            subFix = ".00" + std::to_string(number);
        }
        else if( number < 100 ) {
            subFix = ".0" + std::to_string(number);
        }
        else  {
            subFix = "." + std::to_string(number);
        }
        return subFix;
    }

    float getRandomValue() {

        const int range_from  = 0;
        const int range_to    = 1000;
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>  distr(range_from, range_to);

        int randInt = distr(generator);

        return (float)randInt/1000.0f;
    }

    Ogre::FastArray<std::string>& split( const std::string& s, char delim, Ogre::FastArray<std::string>& elems ) {
        std::stringstream ss(s);
        std::string item;
        while( std::getline(ss, item, delim) ) {
            elems.push_back(item);
        }
        return elems;
    }

    void formatTime( int& hour, int& min, int& sec ) {
        min += sec / 60;
        sec = sec % 60;

        hour += min / 60;
        min = min % 60;
    }

    bool checkFileExist( std::string fullPath ) {
        QDir file;
        file.setPath( QString::fromStdString(fullPath) );
        file.cdUp();
        return file.exists( QString::fromStdString(yUtils::getFileName(fullPath)) );
    }

    Ogre::Quaternion calculateDirection( yObject* object, const Ogre::Vector3& vec, const Ogre::Vector3& localDirectionVector, bool yawFixed, Ogre::Vector3 yawFixedAxis ) {
        // Do nothing if given a zero vector
        if( vec == Ogre::Vector3::ZERO ) return Ogre::Quaternion();

        // The direction we want the local direction point to
        Ogre::Vector3 targetDir = vec.normalisedCopy();

        // Calculate target orientation relative to world space
        Ogre::Quaternion targetOrientation;
        if( yawFixed ) {
            // Calculate the quaternion for rotate local Z to target direction
            Ogre::Vector3 xVec = yawFixedAxis.crossProduct( targetDir );
            xVec.normalise();
            Ogre::Vector3 yVec = targetDir.crossProduct(xVec);
            yVec.normalise();
            Ogre::Quaternion unitZToTarget = Ogre::Quaternion(xVec, yVec, targetDir);

            if( localDirectionVector == Ogre::Vector3::NEGATIVE_UNIT_Z ) {
                // Specail case for avoid calculate 180 degree turn
                targetOrientation =
                    Ogre::Quaternion(-unitZToTarget.y, -unitZToTarget.z, unitZToTarget.w, unitZToTarget.x);
            }
            else {
                // Calculate the quaternion for rotate local direction to target direction
                Ogre::Quaternion localToUnitZ = localDirectionVector.getRotationTo(Ogre::Vector3::UNIT_Z);
                targetOrientation = unitZToTarget * localToUnitZ;
            }
        }
        else {
            const Ogre::Quaternion& currentOrient = object->getWorldOrientation();

            // Get current local direction relative to world space
            Ogre::Vector3 currentDir = currentOrient * localDirectionVector;

            if( (currentDir+targetDir).squaredLength() < 0.00005f ) {
                // Oops, a 180 degree turn (infinite possible rotation axes)
                // Default to yaw i.e. use current UP
                targetOrientation =
                    Ogre::Quaternion(-currentOrient.y, -currentOrient.z, currentOrient.w, currentOrient.x);
            }
            else {
                // Derive shortest arc to new direction
                Ogre::Quaternion rotQuat = currentDir.getRotationTo(targetDir);
                targetOrientation = rotQuat * currentOrient;
            }
        }

        // Set target orientation, transformed to parent space
        if( object->getObjectInstanceContainer().getParentObjectInstance() ) {
            targetOrientation = object->getObjectInstanceContainer().getParentObjectInstance()->getObject()->getWorldOrientation().UnitInverse() * targetOrientation;
        }

        return targetOrientation;
    }

    bool isUserWatching( Ogre::Vector3 pos ) {
        bool watching = false;
        if( yUtils::isLogicThread() ) {
            Ogre::Vector3 camDir = -yEngineServices::getEngineGraphicsData().getCameraWorldOrientation().zAxis();
            Ogre::Radian angle = camDir.angleBetween( pos - yEngineServices::getEngineGraphicsData().getCameraWorldPosition() );
            if( angle.valueRadians() <= 1.0 ) {
                watching = true;
            }
        }
        else {
            yAssert( true, "implementation in graphics thread is pending in this method");
        }
        return watching;
    }

    bool getConfigFileSetting( Ogre::String keyValue, Ogre::String& result ) {
        result = yEngine::getConfigFile().getSetting( keyValue );
        return result != Ogre::BLANKSTRING;
    }

    Ogre::Real quaternionAngle( Ogre::Quaternion a, Ogre::Quaternion b ) {
        Ogre::Radian angleInRadian(acosf( ( b * a.Inverse() ).w ) * 2.0f);
        return  angleInRadian.valueDegrees(); // To degrees!;
    }
}
