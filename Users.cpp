#include "Users.h"

Users::Users()
{

}

Users::~Users()
{

}

void Users::SetName(string name)
{
    this->Name = name;
}

void Users::SetAddress(string address)
{
    this->Address = address;
}

void Users::SetSex(string sex)
{
    this->Sex = sex;
}

void Users::SetPhoneNumber(string phonenb)
{
    this->PhoneNumber = phonenb;
}

string Users::GetID()
{
    return this->ID;
}

string Users::GetPass()
{
    return this->Pass;
}

void Users::SetID(string id)
{
    this->ID = id;
}

void Users::SetPass(string pass)
{
    this->Pass = pass;
}

string Users::GetAddress()
{
    return this->Address;
}

string Users::GetPhoneNumber()
{
    return this->PhoneNumber;
}

string Users::GetName()
{
    return this->Name;
}

string Users::GetSex()
{
    return this->Sex;
}