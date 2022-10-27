#include <iostream>
#include "ManagerProduct.h"
#include "Bill.h"

using namespace std;

class Customers
{

private:
    ManagerProduct cart;
    string PhoneNumber;
    string Address;
    string Name;
    string Sex;
    string ID;
    string Pass;

    int cnt;

public:

    Customers();
    ~Customers();

    string GetID();
    string GetPass();

    void SetID(string id);
    void SetPass(string pass);
    void Set_PhoneNumber(string);
    void Set_Address(string);
    void Set_Name(string);
    void Set_Sex(string);
    
    string Get_PhoneNumber();
    string Get_Address();
    string Get_Sex();
    string Get_Name();


    void ShowItems();
    Bill Buy(ManagerProduct Products);

    double SumPrice();
    string ToString(int);
    friend ostream& operator<<(ostream& out, Customers customer);
};
