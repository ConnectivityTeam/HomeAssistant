#ifndef HA_CONSOLE_H
#define HA_CONSOLE_H
#include "controller.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "controller.h"

class Console
{
public:
    Console(Controller);
private:
    bool exit;
    bool logedin;
    bool speech;
    Controller controller;
    std::vector<std::string> commands;
    // t_user user;
    bool login();
    void logout();
    void loop();
    void terminal();
    void output(std::string);
    void interpret(std::string);
    int getch();
    string getpass(const char *__prompt, bool show_asterisk);
};

#endif // CONSOLE_H
