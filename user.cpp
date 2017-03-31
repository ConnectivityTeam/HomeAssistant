#include "user.h"

User::User() : User("", "", "", "", 0)
{

}

User::User(std::string username, std::string password, std::string name, std::string prename, int uid)
{
    this->username = username;
    this->password = password;
    this->name = name;
    this->prename = prename;
    this->uid = uid;
}

User::~User()
{
    this->username.clear();
    this->password.clear();
    this->name.clear();
    this->prename.clear();
    this->uid = 0;
}

bool User::isNull()
{
    if(username == "" && password == "" && name == "" && prename == "" && uid == 0)
        return true;
    else
        return false;
}

void User::setPassword(std::string password)
{
    this->password = md5(password);
}

std::string User::getUsername()
{
    return this->username;
}

std::string User::getPrename()
{
    return this->prename;
}

std::string User::getName()
{
    return this->name;
}

int User::getUid()
{
    return this->uid;
}

std::string User::toInsertString()
{
    std::stringstream ss;
    ss << "INSERT INTO user (username, password, name, prename) VALUES ('" << this->username << "', '" << md5(this->password) << "', '" << this->name << "', '" << this->prename << "')";
    return ss.str();
}

std::string User::toString()
{
    std::stringstream ss;
    ss << "Username=" << username << ", Password=" << password << ", Name=" << name << ", Prename=" << prename << ", Uid" << uid;
    return ss.str();
}
