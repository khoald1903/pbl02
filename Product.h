#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class Product
{
private:
    string ID;
    string Name;
    string Type;
    string Manufacturer;
    int Size;
    int Price;
    int Amount;
    int ImportPrice;

public:
    friend class Bill;
    void SetID(string);
    void SetName(string);
    void SetSize(int);
    void SetManufacturer(string);
    void SetPrice(long long);
    void SetType(string);
    void SetAmount(int);
    void SetImportPrice(long long);

    string GetID();
    string GetName();
    int GetSize();
    string GetManufacturer();
    long long GetPrice();
    string GetType();
    int GetAmount();
    long long GetImportPrice();

    Product();
    ~Product();

    friend ostream &operator<<(ostream &, Product);
    friend istream &operator>>(istream &, Product &);
};