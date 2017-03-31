#include "console.h"

using namespace std;

Console::Console(Controller controller) : controller(controller)
{
    cout << "Starting Console init Serivce";
    this->exit = false;
    this->logedin = false;
    cout << "\t\t\t[ OK ]" << endl;
    loop();
}

void Console::loop()
{
    while(!exit)
    {
        if(login())
        {
            logedin = true;
            terminal();
        }
        else
        {
            cout << "username, password missmatch error" << endl;
        }
    }
    cout << "Stopping Controller Service\t\t\t[ OK ]" << endl;
    cout << "Stopping Terminal Service\t\t\t[ OK ]" << endl;
}

bool Console::login()
{
    if(controller.current_user.isNull())
        cout << "NullUser exists" << endl;
    string username, password;
    cout << "Username: ";
    cin >> username;
    password = getpass("Password: ", true);
    return controller.verifyUser(username, password);
}

void Console::terminal()
{
    string buf;
    while(logedin)
    {
        cout << controller.current_user.getUsername() << "$ ";
        cin >> buf;
        commands.push_back(buf);
        interpret(buf);
    }
}

void Console::interpret(string buffer)
{
    if(buffer == "quit")
    {
        buffer = "";
        logedin = false;
        exit = true;
    }
    else if(buffer == "loggout")
    {
        buffer = "";
        logedin = false;
    }
    else if(buffer == "speech=enable")
    {
        buffer = "";
        speech = true;
    }
    else if(buffer == "speech=disable")
    {
        buffer = "";
        speech = false;
    }
    else if(buffer == "user")
    {
        buffer = "";
        //cout << "username=" << user.username << "\npassword" << user.password << "\nname=" << user.name << "\nprename=" << user.prename << endl;
    }
    else
    {
        buffer = "";
        output("Undefined Command " + buffer);
    }
}

void Console::output(string buffer)
{
    if(speech)
    {
//        speak(buffer);
    }
    else
    {
        cout << buffer << endl;
    }
}

int Console::getch()
{
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}

string Console::getpass(const char *prompt, bool show_asterisk=true)
{
  const char BACKSPACE=127;
  const char RETURN=10;

  string password;
  unsigned char ch=0;

  cout <<prompt<<endl;

  while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                 cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else
         {
             password+=ch;
             if(show_asterisk)
                 cout <<'*';
         }
    }
  cout <<endl;
  return password;
}

