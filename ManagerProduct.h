#include "Element.cpp"
#include "Product.h"
class ManagerProduct
{
private:
    Element<Product> products;

public:
    ManagerProduct();
    void Add(); //nhập dữ liệu từ bạn phím rồi add vào

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
    void ShowFile();
    void ReSetAmount(string id, int amount);
    void Show();
    void Show2();
    
    ~ManagerProduct();
};