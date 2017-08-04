#ifndef YDATABASEBASE_H
#define YDATABASEBASE_H

#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>

/**
 * @brief The yDatabaseBase class
 * Base class to open a QSQLite database and manipulate it.
 * Internally generate the connections to be access by the graphics
 * and the logic thread
 */
class yDatabaseBase
{
public:

    /**
     * @brief yDatabaseBase Constructor. Needs the path where the database
     * will be and a unique name
     * @param path The path where the database will be
     * @param uniqueName the unique connection name
     */
    yDatabaseBase( std::string path, std::string uniqueName );
    virtual ~yDatabaseBase();

    /**
     * @brief exec Exec a query in the database
     * @param query The query to be executed
     * @return The query answer
     */
    QSqlQuery exec( QString query );

    /**
     * @brief createQueryContainer create a QSqlQuery container,
     * so can be filled with a query and be executed directly there.
     * You can have several instance simultaneously
     * @return the query container
     */
    QSqlQuery createQueryContainer();

private:
    QSqlDatabase mDatabase; ///< the database
    bool mCreatedInLogic; ///< the creation thread
};

#endif // YDATABASEBASE_H
