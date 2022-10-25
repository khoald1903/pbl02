#include "Product.h"

Product::Product()
{
}

Product::~Product()
{
}

void Product::SetID(string id)
{
    this->ID = id;
}

void Product::SetName(string name)
{
    this->Name = name;
}

void Product::SetSize(int size)
{
    this->Size = size;
}

void Product::SetManufacturer(string manufacturer)
{
    this->Manufacturer = manufacturer;
}

void Product::SetPrice(float price)
{
    this->Price = price;
}

void Product::SetType(string type)
{
    this->Type = type;
}

string Product::GetID()
{
    return this->ID;
}

string Product::GetName()
{
    return this->Name;
}

int Product::GetSize()
{
    return this->Size;
}

float Product::GetPrice()
{
    return this->Price;
}

string Product::GetManufacturer()
{
    return this->Manufacturer;
}

string Product::GetType()
{
    return this->Type;
}

ostream &operator<<(ostream &out, Product product)
{
    out << product.ID << "  " << product.Name << "  " << product.Manufacturer
        << "  " << product.Size << "  " << product.Type << "  " << product.Price << endl;
    return out;
}

istream &operator>>(istream &in, Product product)
{
    cout << "Moi nhap ID: "; 
    cin >> product.ID;
    cout << "Moi nhap ten: ";
    cin >> product.Name;
    cout << "Moi nhap nha san xuat: ";
    cin >> product.Manufacturer;
    cout << "Moi nhap loai giay: ";
    cin >> product.Type;
    cout << "Moi nhap size: ";
    cin >> product.Size;
    cout << "Moi nhap gia: ";
    cin >> product.Price;
    return in;
}