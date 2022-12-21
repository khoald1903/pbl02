#include "Admin.h"
#include "Bill.h"

class Customers : public Users
{
    private:
        ManagerProduct cart;

    public:
        Bill Buy(ManagerProduct, int);
        Customers(string id, string pass, string name, string addr, string sex, string phonenb);
        int SumPrice();
        void DeleteAll();
        void Show();
        Customers();
        ~Customers();

        //friend ostream& operator<<(ostream&, Customers);
};
