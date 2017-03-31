#ifndef WEBCONNCET_H
#define WEBCONNCET_H
#include <string>
#include <vector>
#include <curl/curl.h>
#include <stdio.h>

using std::string;
using std::vector;

class webconncet
{
private:
    string url;
    string google_url;
    vector<string> raw_result;
public:
    webconncet();
    bool search(string query);
    vector<string> getRaw();
};

#endif // WEBCONNCET_H
