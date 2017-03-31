#include "database.h"
using std::cout;
using std::endl;

Database::Database()
{
    connect();
}

Database::~Database()
{
    this->conn->close();
}

void Database::connect()
{
    driver = get_driver_instance();
    try
    {
        conn = driver->connect("tcp://127.0.0.1:3306", MYSQL_USERNAME, MYSQL_PASSWORD);
        conn->setSchema(MYSQL_DATABASE);
        cout << "\t\t\t\t[ OK ]" << endl;
    }
    catch(sql::SQLException &e)
    {
#ifdef DEBUG
        cout << endl << "MySQLErrorcode: " << e.getErrorCode() << "\nMySQLState: " << e.getSQLState() << endl;
#else
        cout << "\t\t\t\t[ FAILED ]" << endl;
#endif
    }
}

bool Database::insert(string sql)
{
    try
    {
        // connect();
        stmt = conn->createStatement();
        stmt->executeQuery(sql);
        delete stmt;
    }
    catch(sql::SQLException &e)
    {
#ifdef DEBUG
    cout << endl << "MySQLErrorcode: " << e.getErrorCode() << "\nMySQLState: " << e.getSQLState() << endl;
#else
    cout << "\t\t\t\t[ FAILED ]" << endl;
#endif
    }
}

User Database::verifyUser(string username, string password)
{
    try
    {
        pstmt = conn->prepareStatement("SELECT * FROM user WHERE username LIKE ? AND password LIKE ?");
        pstmt->setString(1, username);
        pstmt->setString(2, password);
        sql::ResultSet *rs;
        rs = pstmt->executeQuery();
        if(rs->rowsCount() > 0)
        {
            User user(rs->getString("username"), rs->getString("password"), rs->getString("name"), rs->getString("prename"), rs->getInt("id"));
            return user;
        }
        else
        {
        //    User user;
            // return user;
        }
    }
    catch(sql::SQLException &e)
    {
        cout << endl << "MySQLErrorcode: " << e.getErrorCode() << "\nMySQLState: " << e.getSQLState() << endl;
    }
}
