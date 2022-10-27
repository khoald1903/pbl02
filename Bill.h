#include <bits/stdc++.h>
using namespace std;
class Date
{
public:
    int Day;
    int Month;
    int Year;

public:
    Date() : Day(Day), Month(Month), Year(Year)
    {
    }
    ~Date()
    {
    }
};

class Bill : public Date
{
    Date d;
    string IDB;
    string IDC;
    string NameCustomer;
    string Phonenb;
    double SumPrice;

    

    public:
    Bill();
    ~Bill();
    Bill(Date d, string IDB, string IDC, string NameCustomer, float SumPrice);
    // Bill(const Bill &);
    void SetDay(int Day);
    int GetDay();
    void SetMonth(int Month);
    int GetMonth();
    void SetYear(int Year);
    int GetYear();

    void SetIDB(string IDB);
    string GetIDB();
    void SetIDC(string IDC);
    string GetIDC();
    void SetPhoneNB(string nb);
    string GetPhoneNB();
    
    void SetNameCustomer(string NameCustomer);
    string GetNameCustomer();
    void SetSumPrice(double SumPrice);
    double GetSumPrice();
    void Show();
};