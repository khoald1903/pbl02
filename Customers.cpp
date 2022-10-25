#include "Customers.h"

void Customers::Set_Name()
{
    cout << "Moi nhap ten: ";
    getline(cin, this->Name);
}

void Customers::Set_Address()
{
    cout << "Moi nhap dia chi: ";
    getline(cin, this->Address);
}

void Customers::Set_Sex()
{
    cout << "Moi nhap gioi tinh: ";
    getline(cin, this->Sex);
}

void Customers::Set_PhoneNumber()
{
    cout << "Moi nhap so dien thoai: ";
    cin >> this->PhoneNumber;
}