#ifndef YFASTARRAY_H
#define YFASTARRAY_H

#include "Macros/yMacros.h"
#include "OgreFastArray.h"
#include <map>

/**
 * @brief The yFastArray class
 * This class let store something in adjacent memory
 * with the benefit of log N search. However, use
 * more memory, because use an array and a map to
 * store the data
 * @todo By the moment only let store pointers, so we
 * have a false adjacent memory!!. This must be fixed
 */
template <typename T> class yFastArray
{
public:
    /**
     * @brief yFastArray constructor.
     * Remember call reserve() to increase the memory size
     */
    yFastArray() { mMemoryReserved = 0; }

    /**
     * @brief reserve reserve memory, so data is adjacent
     * @param sizeToReserve the size of the memory
     */
    void reserve( int sizeToReserve ) {
        yAssert( sizeToReserve >= 0, "you can't reserve negative space" );
        mMemoryReserved = sizeToReserve;
        mData.reserve(sizeToReserve);
    }

    /**
     * @brief addData add some data to this class
     * @param id the id of the data. Must be unique
     * in this instance
     * @param data the data to store
     */
    void addData( std::string id, T data ) {
        yAssert( !getData(id), ("id: " + id + " already exist").c_str() );
        size_t indexToSave = mData.size();

        /** @todo check if this assert is neccessary **/
        //yAssert( indexToSave <= mMemoryReserved && "Potential memory error!, resize the vector could invalidate any pointer" );
        mData.push_back( data );
        yAssert( indexToSave == mData.size() - 1, "Someone use our slot memory (maybe call from different trheads at the same time?)" );

        mDataListIndex[id] = indexToSave;
    }

    /**
     * @brief getData get some data by their id
     * @param id the id of the data.
     * @return the data, or null if not found
     */
    T getData( std::string id ) {
        auto search = mDataListIndex.find(id);

        if( search != mDataListIndex.end() ) {
            size_t index = search->second;
            return mData[index];
        }

        return nullptr;
    }

    /**
     * @brief getName get the name of an index
     * @param index the index to search
     * @return the name, or empty if index not found
     */
    std::string getName( size_t index ) {
        std::string name = "";
        for( auto const &data : mDataListIndex ) {
            if( data.second == index ) {
                name = data.first;
                break;
            }
        }
        return name;
    }

    /**
     * @brief operator[] overload operator to get data by index.
     * Useful to get all the data iterating by a loop
     * @param index the index. Must be lower than size()
     * @return the data in the index asked
     */
    T operator[]( size_t index ) {
        yAssert( index < mData.size(), "invalid index" );
        return mData[index];
    }

    /**
     * @brief size get the total elements stored
     * @return the total elements stored
     */
    size_t size() {
        return mData.size();
    }

    /**
     * @brief erase remove an object by their index
     * @note this is a slow operation, because we must reorder the internal
     * structures. If the order in the array is not important, use #eraseNoReorder
     * @param index index to erase
     */
    void erase( size_t index ) {
        yAssert( index < mData.size(), "invalid index" );
        mData.erase( &mData[index] );
        for( auto it = mDataListIndex.begin(); it != mDataListIndex.end() ; ) {
          if( it->second == index ) {
            it = mDataListIndex.erase(it);
          }
          else {
              if( it->second > index ) {
                it->second = it->second - 1;
              }
              ++it;
          }
        }
    }

    /**
     * @brief eraseNoReorder remove an object by their index
     * @note this is faster than #erase, but not preserve the array order
     * @param index index to erase
     */
    void eraseNoReorder( size_t index ) {
        yAssert( index < mData.size(), "invalid index" );
        size_t lastPos = mData.size() - 1;
        mData[index] = mData[ lastPos ];
        mData.pop_back();

        //update map
        int ready = 0;
        for( auto it = mDataListIndex.begin(); it != mDataListIndex.end() ; ) {
          if( it->second == index ) {
            it = mDataListIndex.erase(it);
            ++ready;
          }
          else {
              if( it->second == lastPos ) {
                it->second = index;
                ++ready;
              }
              ++it;
          }
          if( ready == 2 ) {
              break;
          }
        }
    }

private:
    Ogre::FastArray< T > mData; ///< the data store
    std::unordered_map< std::string, size_t > mDataListIndex; ///< this container is just to fast find objects in #mData
    size_t mMemoryReserved; ///< how much memory is reserved
};

#endif // YFASTARRAY_H
