#ifndef HA_CONTROLLER_H
#define HA_CONTROLLER_H
#include <string>
#include <string.h>
#include <stdbool.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <errno.h>
#include <exception>
#include <exception.h>

// #include "types.h"
#include "md5.h"
#include "database.h"

class Controller {
    friend class Console;
private:
    Database database;
    User current_user;
    // Config config;
public:
    Controller();
    bool verifyUser(std::string username, std::string passwd);
    void saveUser(User usr);
};

#endif // HA_CONTROLLER_H
