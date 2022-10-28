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
void Bill::SetSumPrice(int SumPrice)
{
    this->SumPrice = SumPrice;
}
int Bill::GetSumPrice()
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
    cout << "\t+---------------------------------------------------------------------" << endl;
    cout << "\t\t\tMa hoa don: " << this->IDB << '\n';
    cout << "\t\t\tNgay Thang Nam thanh toan: " << this->Day << "/" << this->Month << "/" << this->Year << '\n';
    cout << "\t\t\tMa khach hang: " << this->IDC << '\n';
    cout << "\t\t\tTen khach hang: " << this->NameCustomer << '\n';
    cout << "\t\t\tTong tien: " << this->SumPrice << '\n';
    cout << "\t+---------------------------------------------------------------------" << endl;
    //fo.close();
}