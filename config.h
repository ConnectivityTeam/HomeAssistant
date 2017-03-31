#ifndef CONFIG_H
#define CONFIG_H
#include <string>
using std::string;
class Config
{
private:
    string mysql_username;
    string mysql_password;
    bool bot_on_init;
    bool skip_login;
    string username;
    string password;
    string logpath;
    bool speech;
public:
    Config();
};

#endif // CONFIG_H
