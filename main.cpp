#include <iostream>
#include <stdlib.h>
#include "Customers.h"
using namespace std;
ManagerProduct products;
Element<Bill> ListBill;
Element<Customers> ListCustomer;
Element<Admin> ListAdmin;
Customers x;

bool CheckAdmin(string id, string pass)
{
    for (int i = 0; i < ::ListAdmin.GetSize(); i++)
    {
        if (::ListAdmin.GetIndex(i).GetID().compare(id) == 0)
        {
            if (::ListAdmin.GetIndex(i).GetPass().compare(pass) == 0)
                return true;
        }
    }
    return false;
}

bool CheckCustomers(string id, string pass)
{
    for (int i = 0; i < ::ListCustomer.GetSize(); i++)
    {
        if (ListCustomer.GetIndex(i).GetID().compare(id) == 0)
        {
            if (ListCustomer.GetIndex(i).GetPass().compare(pass) == 0)
                return true;
        }
    }
    return false;
}

bool Login(int flag)
{
    string user;
    string pass;
    fflush(stdin);
    cout << "Moi nhap user: ";
    getline(cin, user);
    cout << "Moi nhap mat khau: ";
    getline(cin, pass);

    if (flag == 1)
    {
        if (CheckAdmin(user, pass) == true)
        {
            return true;
        }
    }
    else if (flag == 2)
    {
        if (CheckCustomers(user, pass) == true)
        {
            return true;
        }
    }
    return false;
}

ostream &operator<<(ostream &out, Bill x)
{
    x.list.Show();
    out << x.GetSumPrice() << endl;
    return out;
}
ostream &operator<<(ostream &out, Customers c)
{
    cout << "ID"<< "\t"<< "Ten"
         << "\t"
         << "Gioi tinh"
         << "\t"
         << "SDT"
         << "\t"
         << "Dia chi" << endl;
}
void MenuLogin()
{
    cout << "\t\t+========================     Dang nhap     =========================+" << endl;
    cout << "\t\t|                                                                    |" << endl;
    cout << "\t\t|                      1.  Quan tri vien                             |" << endl;
    cout << "\t\t|                      2.  Khach hang                                |" << endl;
    cout << "\t\t|                      3.  Chua co tai khoan                         |" << endl;
    cout << "\t\t|                      4.  Thoat                                     |" << endl;
    cout << "\t\t+====================================================================+" << endl;
}

void MenuAdmin()
{
    cout << "\t\t+========================     Admin         =========================+" << endl;
    cout << "\t\t|                                                                    |" << endl;
    cout << "\t\t|                      1.  Quan li san pham                          |" << endl;
    cout << "\t\t|                      2.  Quan li khach hang                        |" << endl;
    cout << "\t\t|                      3.  Quan li hoa don                           |" << endl;
    cout << "\t\t|                      4.  Quay lai                                  |" << endl;
    cout << "\t\t|                      5.  Thoat                                     |" << endl;
    cout << "\t\t+====================================================================+" << endl;
}

void MenuCustomer()
{
    cout << "\t\t+=======================     Khach hang    ==========================+" << endl;
    cout << "\t\t|                                                                    |" << endl;
    cout << "\t\t|                      1.  Mua hang                                  |" << endl;
    cout << "\t\t|                      2.  Hoa don                                   |" << endl;
    cout << "\t\t|                      3.  Quay lai                                  |" << endl;
    cout << "\t\t|                      4.  Thoat                                     |" << endl;
    cout << "\t\t+====================================================================+" << endl;
}

void MenuManagerProducts()
{
    cout << "\t\t+======================== Quan li san pham  =========================+" << endl;
    cout << "\t\t|                                                                    |" << endl;
    cout << "\t\t|                      1.  Danh sach san pham                        |" << endl;
    cout << "\t\t|                      2.  Them san pham                             |" << endl;
    cout << "\t\t|                      3.  Xoa san pham                              |" << endl;
    cout << "\t\t|                      4.  Doanh thu                                 |" << endl;
    cout << "\t\t|                      5.  Sap xep san pham                          |" << endl;
    cout << "\t\t|                      6.  Tim kiem san pham                         |" << endl;
    cout << "\t\t|                      7.  Cap nhat san pham                         |" << endl;
    cout << "\t\t|                      8.  Quay lai                                  |" << endl;
    cout << "\t\t|                      9.  Thoat                                     |" << endl;
    cout << "\t\t+====================================================================+" << endl;
}

void ProductManagerFeature()
{
    int x;
    while (true)
    {
        MenuManagerProducts();
        cin >> x;

        if (x == 1)
        {
            system("cls");
            products.Show();
        }
        else if (x == 2)
        {
            products.Add();
            system("cls");
        }
        else if (x == 3)
        {
            fflush(stdin);
            string id;
            cout << "Moi nhap ID:";
            cin >> id;
            products.DeleteID(id);
        }
        else if (x == 4)
        {
            //doanh thu
        }
        else if (x == 5)
        {
            products.SortASC();
        }
        else if (x == 6)
        {
            fflush(stdin);
            string id;
            cout << "Moi nhap id can tim: ";
            cin >> id;
            Product x = products.Search(id);
            if(x.GetID().compare("NULL") == 0)
            {
                cout << "Tim that bai" << endl;
            }
            else
            {
                cout << "Tim thanh cong" << endl;
            }
        }
        else if (x == 7)
        {
            fflush(stdin);
            string id;
            cout << "Moi nhap id san pham can cap nhat: ";
            cin >> id;
            bool flag = products.Update(id);
            if(flag)
            {
                cout << "Cap nhat thanh cong!" << endl;
            }
            else 
            {
                cout << "Khong tim thay ID san pham can cap nhat!" << endl;
            }
        }
        else if (x == 8)
        {
            system("cls");
            break;
        }
        else if(x == 9)
            exit(1);
    }
}

void AdminFeatures()
{
    int menuAdmin;
    while (true)
    {
        MenuAdmin();
        cin >> menuAdmin;
        system("cls");
        if (menuAdmin == 1)
        {
            ProductManagerFeature(); 
        }
        else if (menuAdmin == 2)  
        {
            //quản lí khách hàng
            // show list khách hàng
            cout << "ID"
                 << "\t"
                 << "Ten"
                 << "\t"
                 << "Gioi tinh"
                 << "\t"
                 << "SDT"
                 << "\t"
                 << "Dia chi" << endl;

            for (int i = 0; i < ListCustomer.GetSize(); i++)
            {
                //cout << ListCustomer.GetIndex(i);
            }
        }
        else if (menuAdmin == 3)
        {
            //quản lí hoá đơn
        }
        else if (menuAdmin == 4)
        {
            break;
        }
        else
            exit(1);
    }
}


void CustomersFeatures()
{
    int menuCustomers;
    while (true)
    {
        MenuCustomer();
        cin >> menuCustomers;
        system("cls");
        if (menuCustomers == 1)
        {
            ListBill.Add(x.Buy(products, ListBill.GetSize()));
        }
        else if (menuCustomers == 2)
        {
            //xuất ra các hoá đơn dựa trên id
            ListBill.Show();
        }
        else if (menuCustomers == 3)
        {
            break;
        }
        else
            exit(1);
    }
}

void Handle()
{
    cout << "\t\t+==========     Chuong trinh quan li shop ban giay         ==========+" << endl;
    int menu;
    while(true)
    {
        MenuLogin();
        cin >> menu;
        system("cls");
        if(menu == 1)
        {
            while (true)
            {
                if (Login(1) == 0)
                {
                    cout << "Tai khoan hoac mat khau sai! Ban co muon nhap lai khong Y/N\n";
                    char var;
                    cin >> var;
                    if (var == 'Y' || var == 'y')
                        continue;
                    else
                        exit(1);
                }
                else
                {
                    cout << "Dang nhap thanh cong!" << endl;
                    break;
                }
            }
            AdminFeatures();
        }
        else if(menu == 2)
        {
            if (Login(2) == 0)
            {
                cout << "Tai khoan hoac mat khau sai! Ban co muon nhap lai khong Y/N\n";
                char var;
                cin >> var;
                if (var == 'Y' || var == 'y')
                    continue;
                else
                    exit(1);
            }
            else
            {
                cout << "Dang nhap thanh cong!" << endl;
                break;
            }
            CustomersFeatures();
        }
        else if(menu == 3)
        {
            //đăng ký
        }
        else
        {
            exit(1);
        }
    }
}

int main()
{
    Handle();
    return 0;
}
