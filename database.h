#ifndef DATABASE_H
#define DATABASE_H
#define DEBUG

/*
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <mysql_error.h>
*/
#include "user.h"
#include <string>
#include "mysql_connection.h"
#include <mysql_driver.h>
#include <cppconn/connection.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#ifdef DEBUG
#define MYSQL_USERNAME "root"
#define MYSQL_PASSWORD "Peuplingues62"
#define MYSQL_DATABASE "ki_database"
#else
#include <fstream>
#endif

using std::string;

class Database
{
private:
    sql::Driver *driver;
    sql::Statement *stmt;
    sql::Connection *conn;
    sql::PreparedStatement *pstmt;
public:
    Database();
    ~Database();
    void connect();
    User verifyUser(string username, string password);
    bool insert(string sql);
    bool drop(string sql);
};

#endif // DATABASE_H
