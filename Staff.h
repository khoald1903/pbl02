#include "Users.h"

class Staff : public Users
{
    private:
        string Phonenumber;
        string Sex;
        string Address;
    public:
        Staff();
        ~Staff();
};