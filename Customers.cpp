#include "Customers.h"
ManagerProduct cart;
Customers::Customers()
{
    cnt = 0;
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

string Customers::ToString(int a)
{
    string temp = "";
    while(a > 0)
    {
        char r = a%10 - '0';
        temp+=r;
        a/=10;
    }
    string temp2 ="";
    for(int i = temp.size() - 1; i>=0; i--) temp2+=temp[i];
    return temp2;
}

void Customers::ShowItems(){
    for(int i = 0; i < cart.GetSize(); i++)
    {
        cout << setw(20) << cart.Getindex(i).GetName() << "\t" << setw(15) << cart.Getindex(i).GetPrice() << endl;
    }
}


Bill Customers::Buy(ManagerProduct Products)
{   
    cart.SetSize(0);
    time_t hientai = time(0);
    tm *dt = localtime(&hientai);

    Bill temp;
    temp.SetDay(dt->tm_mday);
    temp.SetMonth(dt->tm_mon + 1);
    temp.SetYear(dt->tm_year + 1900);
    temp.SetNameCustomer(this->Name);
    temp.SetIDC(this->ID);
    temp.SetPhoneNB(this->PhoneNumber);
    temp.SetIDB(this->Name + to_string(++cnt));
    int n = 0;
    while(true)
    {
        cout << "Moi nhap STT san pham can mua hoac bam -1 de thanh toan:";
        cin >> n;
        if(n == -1) break;
        cart.AddLast(Products.Getindex(n));
    }
    temp.SetSumPrice(SumPrice());
    delete[] dt;
    return temp;
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