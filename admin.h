#include <iostream>
#include <string.h>
using namespace std;

class admin
{
    private:
        string user;
        string pass;
    public:
        void show();
        admin(string user, string pass);
        admin();
        void setuser(string user)
        {
            this->user = user;
        }
        void setpass(string pass)
        {
            this->pass = pass;
        }
        string getUser()
        {
            return user;
        }
        string getPass()
        {
            return pass;
        }
};