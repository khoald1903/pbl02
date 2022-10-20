#include "admin.h"

admin::admin(){}
admin::admin(string user, string pass)
{
    this->user = user;
    this->pass = pass;
}

void admin::show()
{
    cout << user << "    " << pass;
}