#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class Product
{
    private:
        string ID;
        string Name;
        int Size;
        double Price;
        string Type;
        int Amount;
        string Manufacturer;

    public: 
        friend class Bill;
        void SetID(string);
        void SetName(string);
        void SetSize(int);
        void SetManufacturer(string);
        void SetPrice(double);
        void SetType(string);
        void SetAmount(int);

        string GetID();
        string GetName();
        int GetSize();
        string GetManufacturer();
        float GetPrice();
        string GetType();
        int GetAmount();

        Product();
        ~Product();

        friend ostream& operator<<(ostream&, Product);
        friend istream& operator>>(istream&, Product&);
};