#ifndef YLICENSEDATA_H
#define YLICENSEDATA_H

#include <assert.h>
#include <string>
#include "OgreFastArray.h"

namespace yLicenseData {
    struct Data {
        int hoursAvailableTotal;
        int minsAvailableTotal;
        int secsAvailableTotal;
        Ogre::FastArray<int> id;
        Ogre::FastArray<int> hoursLimit;
        Ogre::FastArray<int> hoursUsed;
        Ogre::FastArray<int> minsUsed;
        Ogre::FastArray<int> secsUsed;
        Ogre::FastArray<int> daysUsed;
        Ogre::FastArray<std::string> keyLicense;
        bool firstUseToday;
    };

    struct Date {
        size_t day;
        size_t month;
        size_t year;
    };
}

#endif // YLICENSEDATA_H
