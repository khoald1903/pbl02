#include <iostream>
using namespace std;
class Customers
{
private:
    int PhoneNumber;
    string Address;
    string Name;
    string Sex;
    string ID;
    string Pass;

public:
    Customers();
    ~Customers();
    string GetID();
    string GetPass();
    void SetID(string id);
    void SetPass(string pass);
    void Set_PhoneNumber();
    void Set_Address();
    void Set_Name();
    void Set_Sex();
    int Get_PhoneNumber();
    string Get_Address();
};
