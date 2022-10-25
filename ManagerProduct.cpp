#include "ManagerProduct.h"

ManagerProduct::ManagerProduct()
{
    p = NULL;
    size = 0;
}

ManagerProduct::~ManagerProduct()
{
    delete[] p;
}

Product& ManagerProduct::operator[](int i)
{
    static Product a;
    return (i>=0) && (i < size) ? *(p+i) : a;
}

int ManagerProduct::GetSize()
{
    return this->size;
}

Product ManagerProduct::Getindex(int i)
{
    return p[i];
}

ostream &operator<<(ostream &out, ManagerProduct product)
{
    for (int i = 0; i < product.size; i++)
    {
        cout << i+1 << " " << product.p[i];
    }

    return out;
}

void ManagerProduct::AddIndexK(Product product, int k)
{
    Product *temp = new Product[size + 1];
    for (int i = 0; i < k; i++)
    {
        temp[i] = p[i];
    }
    temp[k] = product;
    size++;
    for (int i = k + 1; i < size; i++)
    {
        temp[i] = p[i - 1];
    }
    delete[] p;
    p = temp;
    temp = new Product;
    delete temp;
}

void ManagerProduct::AddLast(Product product)
{
    AddIndexK(product, size);
}

void ManagerProduct::DeleteIndexK(int k)
{
    Product *temp = new Product[size - 1];
    for (int i = 0; i < k; i++)
    {
        temp[i] = p[i];
    }
    for (int i = k + 1; i < size; i++)
    {
        temp[i - 1] = p[i];
    }
    size--;
    delete[] p;
    p = temp;
    temp = new Product;
    delete temp;
}

bool ManagerProduct::Update(string id)
{
    bool flag = false;
    string name, manufacturer, type;
    int size;
    float price;
    for (int i = 0; i < size; i++)
    {
        if(this->p[i].GetID().compare(id) == 0)
        {
            flag = true;
            fflush(stdin);
            cout << "Moi nhap ten moi: ";
            cin >> name;
            cout << "Moi nhap nha san xuat: ";
            cin >> manufacturer;
            cout << "Moi nhap loai giay: "; 
            cin >> type;
            cout << "Moi nhap size: "; 
            cin >> size;
            cout << "Moi nhap gia: "; 
            cin >>price;
        }
    }
    return flag; 
}
