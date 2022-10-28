#include "Bill.h"

Bill::Bill()
{
    this->Day = this->Month = this->Year = 0;
    this->IDB = this->IDC = "";
    this->NameCustomer = "";
    this->SumPrice = 0;
}
Bill::Bill(Date d, string IDB, string IDC, string NameCustomer, float SumPrice)
    : IDB(IDB), IDC(IDC), NameCustomer(NameCustomer), SumPrice(SumPrice)
{
}
/*Bill::Bill(const Bill &) : IDB(IDB), IDC(IDC), NameCustomer(NameCustomer), SumPrice(SumPrice)
{
}*/
Bill::~Bill()
{
}
void Bill::SetDay(int Day)
{
    this->Day = Day;
}
int Bill::GetDay()
{
    return this->Day;
}
void Bill::SetMonth(int Month)
{
    this->Month = Month;
}
int Bill::GetMonth()
{
    return this->Month;
}
void Bill::SetYear(int Year)
{
    this->Year = Year;
}
int Bill::GetYear()
{
    return this->Year;
}
void Bill::SetIDB(string IDB)
{
    this->IDB = IDB;
}
string Bill::GetIDB()
{
    return this->IDB;
}
void Bill::SetIDC(string IDC)
{
    this->IDC = IDC;
}
string Bill::GetIDC()
{
    return this->IDC;
}
void Bill::SetNameCustomer(string NameCustomer)
{
    this->NameCustomer = NameCustomer;
}
string Bill::GetNameCustomer()
{
    return this->NameCustomer;
}
void Bill::SetSumPrice(double SumPrice)
{
    this->SumPrice = SumPrice;
}
double Bill::GetSumPrice()
{
    return this->SumPrice;
}

string Bill::GetPhoneNB()
{
    return this->Phonenb;
}

void Bill::SetPhoneNB(string nb)
{
    this->Phonenb = nb;
}

void Bill::Show()
{
    cout << "Ma hoa don: " << this->IDB << '\n';
    cout << "Ngay Thang Nam thanh toan: " << this->Day << "/" << this->Month << "/" << this->Year << '\n';
    cout << "Ma khach hang: " << this->IDC << '\n';
    cout << "Ten khach hang: " << this->NameCustomer << '\n';
    cout << "Tong tien: " << this->SumPrice << '\n';
    
}