#pragma once
#include <bits/stdc++.h>
#include "ManagerProduct.h"
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
    int SumPrice;

    ManagerProduct list;

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
    void SetSumPrice(int SumPrice);
    int GetSumPrice();
    void Add(Product);
    void Show();

    friend ostream &operator<<(ostream &out, Bill x);
};