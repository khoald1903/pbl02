#include "Users.h"

Users::Users(){}
Users::Users(string User, string Pass)
{
    this->User = User;
    this->Pass = Pass;
}

string Users::Get_status()
{
    return Status;
}

string Users::Get_user()
{
    return User;
}

string Users::Get_pass()
{
    return Pass;
}

void Users::Set_status(string status)
{
    this->Status = status;
}

void Users::Set_pass(string pass)
{
    this->Pass = pass;
}

void Users::Set_user(string user)
{
    this->User = user;
}

Users::~Users(){}