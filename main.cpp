#include <iostream>
#include "console.h"
#include "controller.h"
#include "util.h"
#include "md5.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        cout << "No parameter starting programm as Terminal programm" << endl;
        Controller contr;
        Console console(contr);
    }
    else
    {
        cout << "Parameter found starting analyze Parameter" << endl;
        for(int i = 0; i < argc; i++)
        {
            cout << "line[" << i << "]" << argv[i] << endl;
        }
    }
    return 0;
}
