#include "Customers.h"

class Staff : public Users
{
    private:
        long long Salary;
    public:
        long long GetSalary();
        void SetSalary(long long salary);
        void Show();
        void Update();
        Staff();
        Staff(string id, string pass, string name, string addr, string sex, string phonenb, long long salary);
        ~Staff();
};
