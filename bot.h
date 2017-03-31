#ifndef BOT_H
#define BOT_H
#include <vector>
#include <string>
#include "user.h"

using std::vector;
using std::string;

class Bot
{
private:
    bool speech;
    vector<string> talk;
    User user;
    User bot;
public:
    Bot();
    void init();
    void talkLoop();
};

#endif // BOT_H
