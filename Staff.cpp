#include "Staff.h"

Staff::Staff()
{

}

long long Staff::GetSalary()
{
    return this->Salary;
}

Staff::Staff(string id, string pass, string name, string addr, string sex, string phonenb, long long salary)
{
    this->ID = id;
    this->Pass = pass;
    this->Name = name;
    this->Address = addr;
    this->Sex = sex;
    this->PhoneNumber = phonenb;
    this->Salary = salary;
}

void Staff::SetSalary(long long salary)
{
    this->Salary = salary;
}


void Staff::Show()
{
    cout << "\t\t" << setw(10) << this->ID
         << "\t"
         << setw(20) << this->Name
         << "\t\t"
         << setw(3) << this->Sex
         << "\t"
         << setw(10) << this->PhoneNumber
         << setw(20) << this->Address
         << "\t\t" << setw(10) << this->Pass
         << "\t" << setw(15) << this->Salary << endl;
    // cout << "-----------------";
    // cout << "\nAdd Order Details\n";
    // cout << "-----------------\n\n";

    // cout << str1;
    // cout << " ID "
    //      << "\t   COMPUTER TYPE"
    //      << "\t COMPUTER SPECS"
    //      << "   \t\t COMPUTER NAME"
    //      << "    \t\tCOMPUTER PRICE (RS.)" << endl;
    //cout << str1;
}
Staff::~Staff()
{
    
}

