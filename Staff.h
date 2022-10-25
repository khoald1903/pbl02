#include <bits/stdc++.h>
using namespace std;
class Staff
{
private:
    string Address;
    float Salary;
    string Name;
    string Phonenumber;
    string Sex;
    string ID;
    string Pass;
    int Age;

public:
    
    Staff();
    ~Staff();
    Staff(string ID, string Name, string Sex, int Age, string Phonenumber, string Address, float Salary, string Pass);
    void SetID(string ID);
    string GetID();
    void SetName(string Name);
    string GetName();
    void SetPhone(string Phonenumber);
    string GetPhone();
    void SetSex(string Sex);
    string GetSex();
    void SetAge(int Age);
    int GetAge();
    void SetAddress(string Address);
    string GetAddress();
    void SetSalary(float Salary);
    float GetSalary();
    void SetPass(string Pass);
    string GetPass();
    friend ostream &operator<<(ostream &, Staff);
    //friend istream &operator>>(istream &, Staff &);
    void Show();

};