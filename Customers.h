#include "Admin.h"
#include "Bill.h"

class Customers : public Users
{
    private:
        ManagerProduct cart;
        string Phonenumber;
        string Sex;
        string Address;
    public:
        Bill Buy(ManagerProduct, int);
        int SumPrice();
        void DeleteAll();
        Customers();
        ~Customers();

        friend ostream& operator<<(ostream&, Customers);
};
