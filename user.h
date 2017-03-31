#ifndef USER_H
#define USER_H
#include "md5.h"
#include <string>
#include <sstream>

class User
{
private:
    std::string username;
    std::string password;
    std::string name;
    std::string prename;
    int uid;

    bool verifyUser(std::string username, std::string password);
    void saveUser();
    void deleteUser(int uid);
    void updateUser();
public:
    User();
    User(std::string username, std::string password, std::string name, std::string prename, int uid);
    ~User();
    std::string getUsername();
    std::string getName();
    std::string getPrename();
    int getUid();
    void setPassword(std::string password);
    std::string toString();
    std::string toInsertString();
    bool isNull();
};

#endif // USER_H
