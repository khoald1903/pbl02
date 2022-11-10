#include <iostream>
using namespace std;

class Users
{
        protected:
            string ID;
            string Pass;
            string Name;
            string Sex;
            string PhoneNumber;
            string Address;

        public:
            Users();
            ~Users();
            string GetID();
            string GetPass();

            void SetID(string id);
            void SetPass(string pass);
            void SetPhoneNumber(string);
            void SetAddress(string);
            void SetName(string);
            void SetSex(string);

            string GetPhoneNumber();
            string GetAddress();
            string GetSex();
            string GetName();
};