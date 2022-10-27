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
        string Manufacturer;

    public: 
        void SetID(string id);
        void SetName(string name);
        void SetSize(int size);
        void SetManufacturer(string producer);
        void SetPrice(double price);
        void SetType(string type);

        string GetID();
        string GetName();
        int GetSize();
        string GetManufacturer();
        float GetPrice();
        string GetType();

        Product();
        ~Product();

        friend ostream& operator<<(ostream& out, Product product);
        friend istream& operator>>(istream& in, Product &product);
};