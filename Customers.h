#include "Users.h"

class Customers
{
    private:
        int PhoneNumber;
        string Address;
        string Name;
        string Sex;

    public:
        Customers();
        ~Customers();
        void Set_PhoneNumber();
        void Set_Address();
        void Set_Name();
        void Set_Sex();
        int Get_PhoneNumber();
        string Get_Address();

};


