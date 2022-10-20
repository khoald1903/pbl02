#include <iostream>
#include <string.h>
using namespace std;
class Users
{
    private:
        string User;
        string Pass;
        string TypeUser;
    public:
        Users();
        ~Users();
        Users(string User, string Pass);
        string Status;
        string Get_status();
        string Get_user();
        string Get_pass();
        void Set_status(string status);
        void Set_user(string user);
        void Set_pass(string pass);

};