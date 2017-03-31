#include "controller.h"

Controller::Controller()
{
    std::cout << "Starting Controller Service\t\t\t[ OK ]" << std::endl;
    std::cout << "Starting MySQL Service";
    this->database = Database();
//    this->current_user = User;
}

void Controller::saveUser(User user)
{
    this->database.insert(user.toInsertString());
}

bool Controller::verifyUser(std::string username, std::string passwd)
{
    try
    {
        username = "root";
        passwd = "root";
        std::cout << "Starting DB Connection to verify user=" << username << " with password=" << passwd;
        this->current_user = database.verifyUser(username, passwd);
        std::cout << "\t\t\t\t[ DONE ]" << std::endl;
        if(!current_user.isNull())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(std::exception &e)
    {
        std::cout << "Standard exception: " << e.what() << std::endl;
        return false;
    }
}
