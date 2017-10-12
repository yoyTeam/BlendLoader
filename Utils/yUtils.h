#ifndef YUTILS_H
#define YUTILS_H

#include <string>
#include "btBulletDynamicsCommon.h"
#include "OgreVector3.h"

#define GET_NAME(x) ((x) && (x)->id.name[0] != '0' ? (x)->id.name + 2 : "")

class yObject;

namespace yUtils {

    /**
     * @brief removePreNumbers remove numbers before the text.
     * Useful with names get with typeid
     * @param name name to process
     * @return the name without numbers in the begin
     */
    std::string removePreNumbers( std::string name );

    /**
     * @brief convertToYup Convert vectors from Z-Up to Y-Up space
     * @param vector vector in Z-Up space
     * @return vectpr in Y-Up space
     */
    Ogre::Vector3 convertToYup( Ogre::Vector3 vector );

    /**
     * @brief normalizeBlendPath make an absolute path using a full path and
     * a relative path
     * @param path the relative path. The base path will be the execution application path
     * @return the absolute path
     */
    std::string normalizeBlendPath( std::string path );

    /**
     * @brief normalizeBlendPath make an absolute path using a full path and
     * a relative path
     * @param parentPath the full base path
     * @param localPath the relative path respect #parentPath
     * @return the absolute path
     */
    std::string normalizeBlendPath( std::string parentPath, std::string localPath );

    /**
     * @brief getFileName get the file name from a path
     * @param path the path to extract the file
     * @return the file name
     */
    std::string getFileName( std::string path );

    /**
     * @brief getFileNameNoExtension get the file name from a path and remove extension
     * @param path the path to extract the file
     * @return the file name without extension
     */
    std::string getFileNameNoExtension( std::string path );

    std::string getDateInStandardString();

    /**
     * @brief layerToLayerBit convert a layer to layerbit
     * @param layer The layer to convert. For example, in blender,
     * will be values between 0 and 19
     * @return The layerbit.
     */
    int layerToLayerBit( int layer );

    /**
     * @brief ogreToBullet convert a ogre vector to bullet format
     * @param vector ogre vector
     * @return vector converted to bullet
     */
    btVector3 ogreToBullet(const Ogre::Vector3 vector);

    /**
     * @brief ogreToBullet convert a ogre quaternion to bullet format
     * @param quaternion quaternion to convert
     * @return quaternion converted to bullet
     */
    btQuaternion ogreToBullet(const Ogre::Quaternion quaternion);

    /**
     * @brief ogreToBullet generate a bullet transform with a ogre vector and quaternion
     * @param vector ogre vector
     * @param quaternion ogre quaternion
     * @return bullet transform
     */
    btTransform ogreToBullet(const Ogre::Vector3 vector, const Ogre::Quaternion quaternion);

    /**
     * @brief bulletToOgre convert a bullet vector to ogre format
     * @param vector vector to convert
     * @return vector converted to ogre
     */
    Ogre::Vector3 bulletToOgre(const btVector3 vector);

    /**
     * @brief bulletToOgre convert a bullet quaternion to ogre format
     * @param quaternion quaternion to convert
     * @return quaternion converted to ogre
     */
    Ogre::Quaternion bulletToOgre(const btQuaternion quaternion);

    namespace bt {
        const btVector3 V3_ZERO = btVector3(0, 0, 0);
        const btVector3 V3_UNIT_X = btVector3(1, 0, 0);
        const btVector3 V3_UNIT_Y = btVector3(0, 1, 0);
        const btVector3 V3_UNIT_Z = btVector3(0, 0, 1);

        const btQuaternion Q_X_AXIS_ZERO = btQuaternion(V3_UNIT_X, 0);
        const btQuaternion Q_Y_AXIS_ZERO = btQuaternion(V3_UNIT_Y, 0);
        const btQuaternion Q_Z_AXIS_ZERO = btQuaternion(V3_UNIT_Z, 0);

        namespace math {
            /** @brief Function that get the angle of vector with respect to X axis.
             * @param[in] vector that will be used.
             * @return angle calculated.
             */
            btScalar angleX(const btVector3 vector);
            /** @brief Function that get the angle of vector with respect to Y axis.
             * @param[in] vector that will be used.
             * @return angle calculated.
             */
            btScalar angleY(const btVector3 vector);
            /** @brief Function that get the angle of vector with respect to Z axis.
             * @param[in] vector that will be used.
             * @return angle calculated.
             */
            btScalar angleZ(const btVector3 vector);

            /** @brief rotate a vector.
             * @param[in] vector Vector to rotate.
             * @param[in] axis The axis to rotate about.
             * @param[in] angle The angle to rotate by.
             * @param[in] origin Offset of rotation.
             * @return rotated vector
             */
            btVector3 rotate(const btVector3 vector, const btVector3 axis, const btScalar angle,
                             const btVector3 origin = btVector3(0, 0, 0));

            /** @brief set the distance of a vector.
             * @param[in] vector Vector to modify length.
             * @param[in] distance Dessired distance of vector.
             * @param[in] origin Origin of vector given.
             * @return vector with the distance.
             */
            btVector3 setDistance(const btVector3 vector, const btScalar distance,
                                  const btVector3 origin = btVector3(0, 0, 0));
        }
    }

    /**
     * @brief isLogicThread check if the caller is in the logic thread
     * @return true if caller in logic thread, false otherwise
     */
    bool isLogicThread();

    /**
     * @brief isGraphicsThread check if the caller is in the graphics thread
     * @return true if caller in graphics thread, false otherwise
     */
    bool isGraphicsThread();

    /**
     * @brief convertLocalToWorldPosition convert a local object position to world position
     * @param obj the object reference
     * @param localPos the position respect the object
     * @return the world position
     */
    Ogre::Vector3 convertLocalToWorldPosition( yObject& obj, Ogre::Vector3 localPos );

    /**
     * @brief convertWorldToLocalPosition convert a world position to local object position
     * @param obj the object reference
     * @param worldPos the world position
     * @return the local position respect object
     */
    Ogre::Vector3 convertWorldToLocalPosition( yObject& obj, Ogre::Vector3 worldPos );

    /**
     * @brief convertLocalToWorldOrientation convert a local object orientation to world orientation
     * @param obj the object reference
     * @param localOri the orientation respect the object
     * @return the world orientation
     */
    Ogre::Quaternion convertLocalToWorldOrientation( yObject& obj, Ogre::Quaternion localOri );

    /**
     * @brief convertWorldToLocalOrientation convert a world orientation to local object orientation
     * @param obj the object reference
     * @param worldOri the world orientation
     * @return the local orientation respect object
     */
    Ogre::Quaternion convertWorldToLocalOrientation( yObject& obj, Ogre::Quaternion worldOri );

    /**
     * @brief getNumericSubFix convert a number to format .xxx ( 1 -> .001, 10 -> .010, 100 -> .100 )
     * @param number the number
     * @return the number in the format .xxx
     */
    std::string getNumericSubFix( size_t number );

    /**
     * @brief getRandomValue generates an uniform random value in range [0,1] with 3 decimals
     * @return the generated random value
     */
    float getRandomValue();

    /**
     * @brief split split a string using a char delimit
     * @param s the string to parse
     * @param delim the delimit character to split the string
     * @param elems the elements splited
     * @return the elements splited
     */
    Ogre::FastArray<std::string>& split( const std::string& s, char delim, Ogre::FastArray<std::string>& elems );

    /**
     * @brief formatTime Convert a time in a right format.
     * For example, if you have 5 hour, 87 min and 110 sec,
     * the output will be 6 hour, 28min and 50sec
     * @param hour the hours
     * @param min the minutes
     * @param sec the seconds
     */
    void formatTime( int& hour, int& min, int& sec );

    /**
     * @brief checkFileExist check if a file exist
     * @param fullPath the full path, that is, directory path + filename.
     * Can be a relative path to current work directory
     * @return true if the file exist, false otherwise
     */
    bool checkFileExist( std::string fullPath );

    /**
     * @brief calculateDirection calculate the orientation need by an object to point
     * to a position
     * @param object the object do you want to calculate the orientation
     * @param vec the position to point
     * @param localDirectionVector The vector which normally describes the natural
     * direction of the node, usually -Z
     * @param yawFixed true if must be yaw fixed
     * @param yawFixedAxis the vector axis used for yaw fixed
     * @return The orientation to point to the position
     */
    Ogre::Quaternion calculateDirection(yObject* object, const Ogre::Vector3& vec, const Ogre::Vector3& localDirectionVector = Ogre::Vector3::NEGATIVE_UNIT_Z, bool yawFixed = false, Ogre::Vector3 yawFixedAxis = Ogre::Vector3::UNIT_Y);

    /**
     * @brief isUserWatching check if the point is inside the watching user zone
     * @param pos the world position of the point
     * @return true if watching, false otherwise
     */
    bool isUserWatching( Ogre::Vector3 pos );

    /**
     * @brief getConfigFileSetting get a config from the config file
     * @param keyValue the value to search
     * @param result the result of the search
     * @return true if the key was found, false otherwise
     */
    bool getConfigFileSetting( Ogre::String keyValue, Ogre::String& result );

    /**
     * @brief quaternionAngle calculate the minimum degrees between the two quaternions
     * @param a first quaternion
     * @param b second quaternion
     * @return minimum degrees between the two quaternions
     */
    Ogre::Real quaternionAngle( Ogre::Quaternion a, Ogre::Quaternion b );
}

#endif // YUTILS_H
