#include "Customers.h"

Customers::Customers()
{
}
Customers::~Customers()
{
}

ostream &operator<<(ostream &out, Customers customer)
{
    cout << customer.ID << "\t" << customer.Name << "\t" << customer.Sex << "\t" << customer.PhoneNumber << "\t" << customer.Address << endl;
    return out;
}

void Customers::Set_Name(string name)
{
    this->Name = name;
}

void Customers::Set_Address(string address)
{
    this->Address = address;
}

void Customers::Set_Sex(string sex)
{
    this->Sex = sex;
}

void Customers::Set_PhoneNumber(string phonenb)
{
    this->PhoneNumber = phonenb;
}

string Customers::GetID()
{
    return this->ID;
}

string Customers::GetPass()
{
    return this->Pass;
}

void Customers::SetID(string id)
{
    this->ID = id;
}

void Customers::SetPass(string pass)
{
    this->Pass = pass;
}

string Customers::Get_Address()
{
    return this->Address;
}

string Customers::Get_PhoneNumber()
{
    return this->PhoneNumber;
}

string Customers::Get_Name()
{
    return this->Name;
}

string Customers::Get_Sex()
{
    return this->Sex;
}

void Customers::AddCart(ManagerProduct Products)
{   
    int n = 0;
    while(n != -1)
    {
        cout << "Moi nhap STT san pham can mua hoac bam -1 de thoat:";
        cin >> n;
        cart.AddLast(Products.Getindex(n));
    }
}   

double Customers::SumPrice()
{
    double sum = 0;
    for(int i = 0; i< cart.GetSize(); i++)
    {
        sum+= cart.Getindex(i).GetPrice();
    }
    return sum;
}