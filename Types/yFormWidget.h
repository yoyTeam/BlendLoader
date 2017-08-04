#ifndef YFORMWIDGET_H
#define YFORMWIDGET_H

#include <QString>
#include "Constants/yConstantsForm.h"

class yFormWidget
{

public:
    virtual void init() {}
    virtual void setIcons() = 0;
    virtual void setScaleFactor( float scale ) = 0;
    virtual void notifyClassChanged( QString currentClassName, int currentClassID ) { (void) currentClassName; (void) currentClassID; }
    virtual void notifyUserChanged( QString currentUserName, yConstantsForm::UserType currentUserType ) { (void) currentUserName; (void) currentUserType; }
    virtual void notifyStudentChanged( QString currentStudentName, int currentStudentRut ) { (void) currentStudentName; (void) currentStudentRut; }

};

#endif // YFORMWIDGET_H
