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

void Product::SetPrice(int price)
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

int Product::GetPrice()
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
    out << "\t" << setw(10) << product.ID << "\t" << setw(20) << product.Name << "\t" << setw(20) << product.Manufacturer
        << "\t\t" << setw(2) << product.Size << "\t" << setw(15) << product.Type << "\t" << setw(20) << setprecision(3) << fixed << product.Price << endl;
    return out;
}

istream &operator>>(istream &in, Product &product)
{
    fflush(stdin);
    cout << "Moi nhap ID: "; 
    cin >> product.ID;
    fflush(stdin);
    cout << "Moi nhap ten: ";
    getline(cin, product.Name);
    fflush(stdin);
    cout << "Moi nhap nha san xuat: ";
    getline(cin, product.Manufacturer);
    fflush(stdin);
    cout << "Moi nhap loai giay: ";
    getline(cin, product.Type);
    fflush(stdin);
    cout << "Moi nhap size: ";
    cin >> product.Size;
    fflush(stdin);
    cout << "Moi nhap gia: ";
    cin >> product.Price;
    return in;
}