#include "Element.cpp"
#include "Product.h"
class ManagerProduct
{
private:
    Element<Product> products;

public:
    ManagerProduct();
    void Add(); 
    int GetSize();
    void AddIndexK(Product product, int k);
    void AddLast(Product product);

    void DeleteIndexK(int k);
    void DeleteID(string);
    void DeleteAll();

    bool Update(string id);

    Product Getindex(int i);

    void SortASC();
    Product Search(string ID);

    void ReSetAmount(string id, int amount);
    void Show();
    // void SetSize(int size);

    // Product &operator[](int i);
    // friend ostream &operator<<(ostream &out, ManagerProduct &product);
    ~ManagerProduct();
};