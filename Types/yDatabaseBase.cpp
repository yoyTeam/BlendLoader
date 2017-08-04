#include "yDatabaseBase.h"
#include "Utils/yUtils.h"
#include "Macros/yMacros.h"

yDatabaseBase::yDatabaseBase( std::string path, std::string uniqueName ) {
    std::string connectionName = uniqueName;

    if( yUtils::isLogicThread() ) {
        connectionName += "_logic";
        mCreatedInLogic = true;
    }
    else {
        connectionName += "_graphics";
        mCreatedInLogic = false;
    }

    mDatabase = QSqlDatabase::addDatabase("QSQLITE", QString(connectionName.c_str()));
    mDatabase.setDatabaseName(QString(yUtils::normalizeBlendPath(path).c_str()));
    mDatabase.open();
}

yDatabaseBase::~yDatabaseBase() {
    //mDatabase.close();
    //QSqlDatabase::removeDatabase(mDatabase.connectionName());
}

QSqlQuery yDatabaseBase::exec( QString query ) {
    //database are thread safe except if the exec is done in other thread respect the connection created
    yAssert( (mCreatedInLogic && yUtils::isLogicThread()) || (!mCreatedInLogic && yUtils::isGraphicsThread()), "connection created in other thread" );
    return mDatabase.exec(query);
}

QSqlQuery yDatabaseBase::createQueryContainer() {
    //database are thread safe except if the exec is done in other thread respect the connection created
    yAssert( (mCreatedInLogic && yUtils::isLogicThread()) || (!mCreatedInLogic && yUtils::isGraphicsThread()), "connection created in other thread" );
    return QSqlQuery(mDatabase);
}
