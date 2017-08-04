#ifndef YREPORTDATA_H
#define YREPORTDATA_H

#include <assert.h>
#include "OgreFastArray.h"
#include <QString>
#include "Constants/yConstantsReports.h"

class yReportParameter
{
public:
    yReportParameter(){
        mName = "";
        mValueNumeric = -1; // -1 to not show value in report.
        mValueString = "";
        mPercent = -1;
        mFinalResult = "";
    }

    //TITLE
    std::string mName; //eg: path, time, pendulum

    //BOTH IN SAME LINE
    float mValueNumeric; //eg: 85, 320, 124
    std::string mValueString; //For units or Others. eg: degrees, seconds, cm 02m:34s

    //BOTH IN SAME LINE
    int mPercent; //eg: 0, 50, 100
    std::string mFinalResult; //eg: excelent, good, fail

    //FOR GRAPHS
    //Ogre::FastArray<Ogre::Vector3> history;
};

class yReportParameterTime : public yReportParameter
{
public:
    void setTime( int ms ){
        int seconds = ms / 1000;
        int minutes = (seconds / 60) % 60;
        seconds = seconds % 60;
        if( minutes ) {
            mValueString = QString("%1m:%2s").arg(minutes, 2, 10, QLatin1Char('0')).arg(seconds, 2, 10, QLatin1Char('0')).toStdString();
        }
        else {
            mValueString = QString("%2s").arg(seconds, 2, 10, QLatin1Char('0')).toStdString();
        }
    }
};

struct yReportData {
    Ogre::FastArray< yReportParameter > mParameters; ///< the report parameters
    std::string mReportName = yConstantsReports::reportNoName; ///< the report name do you want associate. If the name is -1, one will be generate and save in this var
    std::string mInstructorName; ///< the instructor name who evaluate the exercise
    std::string mStudentFullName; ///< the student names and last names, separate by spaces
    int mStudentRut; ///< the student rut who complete the exercise
    int mClassID; ///< the class id where the exercise was done

    // you must fill this in engine thread
    std::string mExerciseName; ///< the exercise name
    std::string mExerciseLevelName; ///< the exercise level name
    std::string mSimulatorName; ///< the simulator name
};

#endif // YREPORTDATA_H
