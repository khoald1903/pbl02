#include "Product.h"

class ManagerProduct
{
    private:
        Product *p;
        int size;
    public:
        ManagerProduct();
        ~ManagerProduct();

        int GetSize();
        void AddIndexK(Product product, int k);
        void AddLast(Product product);

        void DeleteIndexK(int k);
        bool Update(string id);
        Product Getindex(int i);
        void SortASC(int left, int right, bool Func(string, string));

        Product &operator[](int i);
        friend ostream &operator<<(ostream &out, ManagerProduct product);
};