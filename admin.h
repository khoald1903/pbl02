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
};