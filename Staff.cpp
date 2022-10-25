#include <bits/stdc++.h>
#include "Staff.h"
using namespace std;
Staff::Staff()
{
    this->ID =" "; 
    this->Name ="";
    this->Sex ="";
    this->Phonenumber = "";
     this->Address = "";
    this->Age = 0;
    this->Salary = 0;
    this->Pass = "";
}
Staff::Staff(string ID, string Name, string Sex, int Age, string Phonenumber, string Address, float Salary, string Pass)
    : ID(ID), Name(Name), Sex(Sex), Age(Age), Phonenumber(Phonenumber), Address(Address), Salary(Salary), Pass(Pass)
{
}

Staff::~Staff()
{
}
void Staff::SetID(string ID)
{
    this->ID = ID;
}
string Staff::GetID()
{
    return this->ID;
}
void Staff::SetName(string Name)
{
    this->Name = Name;
}
string Staff::GetName()
{
    return this->Name;
}
void Staff::SetPhone(string Phonenumber)
{
    this->Phonenumber = Phonenumber;
}
string Staff::GetPhone()
{
    return this->Phonenumber;
}
void Staff::SetSex(string Sex)
{
    this->Sex = Sex;
}
string Staff::GetSex()
{
    return this->Sex;
}
void Staff::SetAge(int Age)
{
    this->Age = Age;
}
int Staff::GetAge()
{
    return this->Age;
}
void Staff::SetAddress(string Address)
{
    this->Address = Address;
}
string Staff::GetAddress()
{
    return this->Address;
}
void Staff::SetSalary(float salary)
{
    this->Salary = Salary;
}
float Staff::GetSalary()
{
    return this->Salary;
}
void Staff::SetPass(string Pass)
{
    this->Pass = Pass;
}
string Staff::GetPass()
{
    return this->Pass;
}
void Staff::Show()
{
    cout << this->ID << " " << this->Pass << endl;
}