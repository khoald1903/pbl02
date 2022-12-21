#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "Staff.h"
#include "fstream"
#include <conio.h>
using namespace std;
ManagerProduct products;
Element<Bill> ListBills;
Element<Customers> ListCustomers;
Element<Admin> ListAdmins;
Element<Staff> ListStaffs;
fstream File;
string userCustomer;
Customers x;

void ShowCustomersToFile()
    {
        fstream fo;
        fo.open("customers.txt", ios::out);
        for (int i = 0; i < ListCustomers.GetSize(); i++)
        {
            fo << ListCustomers.GetIndex(i).GetID() << '|';
            fo << ListCustomers.GetIndex(i).GetPass() << '|';
            fo << ListCustomers.GetIndex(i).GetName() << '|';
            fo << ListCustomers.GetIndex(i).GetSex() << '|';
            fo << ListCustomers.GetIndex(i).GetPhoneNumber() << '|';
            fo << ListCustomers.GetIndex(i).GetAddress() << '|';
            if (i < ListCustomers.GetSize() - 1)
                fo << '\n';
        }
        fo.close();
    }
void ShowStaffsToFile()
    {
        fstream fo;
        fo.open("staff.txt", ios::out);
        for (int i = 0; i < ListStaffs.GetSize(); i++)
        {
            fo << ListStaffs.GetIndex(i).GetID() << '|';
            fo << ListStaffs.GetIndex(i).GetPass() << '|';
            fo << ListStaffs.GetIndex(i).GetName() << '|';
            fo << ListStaffs.GetIndex(i).GetSex() << '|';
            fo << ListStaffs.GetIndex(i).GetPhoneNumber() << '|';
            fo << ListStaffs.GetIndex(i).GetAddress() << '|';
            fo << ListStaffs.GetIndex(i).GetSalary() << '|';
            if (i < ListStaffs.GetSize() - 1)
                fo << '\n';
        }
        fo.close();
    }

void ShowBillToFile()
    {
        fstream fo;
        int size = ListBills.GetSize();
        fo.open("Bill.txt", ios::out);
        for (int i = 0; i < size; i++)
        {

            fo << "Ma hoa don: " << ListBills.GetIndex(i).GetIDB() << '\n';
            fo << "Ngay Thang Nam thanh toan: " << ListBills.GetIndex(i).GetDay() << "/" << ListBills.GetIndex(i).GetMonth() << "/" << ListBills.GetIndex(i).GetYear() << '\n';
            fo << "Ma khach hang: " << ListBills.GetIndex(i).GetIDC() << '\n';
            fo << "Ten khach hang: " << ListBills.GetIndex(i).GetNameCustomer() << '\n';
            fo << "Tong tien: " << ListBills.GetIndex(i).GetSumPrice() << '\n';
            fo << "[" << endl;
            int size2 = ListBills.GetIndex(i).list.GetSize();
            for (int j = 0; j < size2; j++)
            {
                fo << "." << ListBills.GetIndex(i).list.Getindex(j).GetID() << "|" << ListBills.GetIndex(i).list.Getindex(j).GetName() << "|" << ListBills.GetIndex(i).list.Getindex(j).GetSize() << "|" << ListBills.GetIndex(i).list.Getindex(j).GetPrice() << "|" << ListBills.GetIndex(i).list.Getindex(j).GetType() << "|" << ListBills.GetIndex(i).list.Getindex(j).GetAmount() << "|" << ListBills.GetIndex(i).list.Getindex(j).GetManufacturer() << '\n';
            }
            fo << "]";
            if (i < size - 1)
                fo << '\n';
        }
        fo.close();
    }

void BillsOfCustomer(Element<Bill> ListBills, string id)
    {
        int flag = 0;
        int size = ListBills.GetSize();
        for (int i = 0; i < size; i++)
        {
            if (ListBills.GetIndex(i).GetIDC().compare(id) == 0)
            {
                flag++;
                ListBills.GetIndex(i).Show();
            }
        }
        if (flag == 0)
        {
            cout << "\t\t\t\t\tChua co hoa don!" << endl;
        }
    }

void TinhDoanhthu()
    {
        cout << "\t\t\t\t\t  _____                    _       _   _           " << endl;
        cout << "\t\t\t\t\t |  __ \\                  | |     | | | |          " << endl;
        cout << "\t\t\t\t\t | |  | | ___   __ _ _ __ | |__   | |_| |__  _   _ " << endl;
        cout << "\t\t\t\t\t | |  | |/ _ \\ / _` | '_ \\| '_ \\  | __| '_ \\| | | |" << endl;
        cout << "\t\t\t\t\t | |__| | (_) | (_| | | | | | | | | |_| | | | |_| |" << endl;
        cout << "\t\t\t\t\t |_____/ \\___/ \\__,_|_| |_|_| |_|  \\__|_| |_|\\__,_|" << endl;
        int M, Y;
        cout << endl;
        cout << "\t\t\t\t\tNhap thang can tinh doanh thu: ";
        cin >> M;
        cout << endl;
        cout << "\t\t\t\t\tNhap nam can tinh doanh thu: ";
        cin >> Y;
        long long Tongdoanhthu = 0;
        int size = ListBills.GetSize();
        for (int i = 0; i < size; i++)
        {
            if (ListBills.GetIndex(i).GetMonth() == M && ListBills.GetIndex(i).GetYear() == Y)
                Tongdoanhthu += ListBills.GetIndex(i).GetSumPrice();
        }
        cout << "\t\t\t\t\tTong doanh thu cua thang " << M << " nam " << Y << " la " << Tongdoanhthu << endl;
    }
void TinhLoiNhuan()
    {
        cout << "\t\t\t\t  _           _         _                       " << endl;
        cout << "\t\t\t\t | |         (_)       | |                      " << endl;
        cout << "\t\t\t\t | |     ___  _   _ __ | |__  _   _  __ _ _ __  " << endl;
        cout << "\t\t\t\t | |    / _ \\| | | '_ \\| '_ \\| | | |/ _` | '_ \\ " << endl;
        cout << "\t\t\t\t | |___| (_) | | | | | | | | | |_| | (_| | | | |" << endl;
        cout << "\t\t\t\t |______\\___/|_| |_| |_|_| |_|\\__,_|\\__,_|_| |_|" << endl;
        int M, Y;
        cout << endl;
        cout << "\t\t\t\t\tNhap thang can tinh loi nhuan: ";
        cin >> M;
        cout << endl;
        cout << "\t\t\t\t\tNhap nam can tinh loi nhuan: ";
        cin >> Y;
        long long SumSalary = 0;
        int SizeStaff = ListStaffs.GetSize();
        for (int i = 0; i < SizeStaff; i++)
        {
            SumSalary += ListStaffs.GetIndex(i).GetSalary();
        }
        long long SumImportPrice = 0;
        long long SumBills = 0;
        int SizeBill = ListBills.GetSize();
        for (int i = 0; i < SizeBill; i++)
        {
            if (ListBills.GetIndex(i).GetMonth() == M && ListBills.GetIndex(i).GetYear() == Y)
            {
                SumBills += ListBills.GetIndex(i).GetSumPrice();
                for (int j = 0; j < ListBills.GetIndex(i).list.GetSize(); j++)
                {
                    for (int k = 0; k < products.GetSize(); k++)
                    {
                        if (ListBills.GetIndex(i).list.Getindex(j).GetID() == products.Getindex(k).GetID())
                        {
                            SumImportPrice += products.Getindex(k).GetImportPrice();
                            break;
                        }
                    }
                }
            }
        }
        long long SumProfit = SumBills - SumImportPrice - SumSalary;
        cout << "\t\t\t\t\tLoi nhuan cua thang " << M << " nam " << Y << " la " << SumProfit << '\n';
    }

    Staff GetStaff(string id, string pass, string name, string sex, string phonenb, string address, int salary)
    {
        Staff node;
        node.SetID(id);
        node.SetPass(pass);
        node.SetName(name);
        node.SetSex(sex);
        node.SetPhoneNumber(phonenb);
        node.SetAddress(address);
        node.SetSalary(salary);
        return node;
    }

    Admin GetAdmin(string user, string pass)
    {
        Admin node;
        node.SetID(user);
        node.SetPass(pass);
        return node;
    }

    Customers GetCustomers(string id, string pass, string name, string sex, string phonenb, string address)
    {
        Customers node;
        node.SetID(id);
        node.SetPass(pass);
        node.SetName(name);
        node.SetSex(sex);
        node.SetPhoneNumber(phonenb);
        node.SetAddress(address);
        return node;
    }

    bool CheckAdmin(string id, string pass)
    {
        for (int i = 0; i < ::ListAdmins.GetSize(); i++)
        {
            if (::ListAdmins.GetIndex(i).GetID().compare(id) == 0)
            {
                if (::ListAdmins.GetIndex(i).GetPass().compare(pass) == 0)
                    return true;
            }
        }
        return false;
    }

    bool CheckCustomers(string id, string pass)
    {
        for (int i = 0; i < ::ListCustomers.GetSize(); i++)
        {
            if (ListCustomers.GetIndex(i).GetID().compare(id) == 0)
            {
                if (ListCustomers.GetIndex(i).GetPass().compare(pass) == 0)
                    return true;
            }
        }
        return false;
    }

    bool CheckStaffs(string id, string pass)
    {
        for (int i = 0; i < ::ListStaffs.GetSize(); i++)
        {
            if (ListStaffs.GetIndex(i).GetID().compare(id) == 0)
            {
                if (ListStaffs.GetIndex(i).GetPass().compare(pass) == 0)
                    return true;
            }
        }
        return false;
    }

    bool Login(int flag)
    {
        fflush(stdin);
        string user;
        cout << "\t\t\t\t\tMoi nhap user: ";
        getline(cin, user);

        cout << "\t\t\t\t\tMoi nhap mat khau: ";
        char c = 0, x[20];
        int i = 0;
        while (true)
        {
            c = getch();
            if (c == 13)
            {
                break;
            }
            else if (c == 8)
            {
                i--;
                cout << "\b \b";
            }
            else
            {
                x[i++] = c;
                cout << "*";
            }
        }
        x[i] = '\0';
        string pass = string(x);
        cout << endl;
        if (flag == 1)
        {
            if (CheckAdmin(user, pass) == true)
            {
                return true;
            }
        }
        else if (flag == 2)
        {
            if (CheckStaffs(user, pass) == true)
            {
                return true;
            }
        }
        else if (flag == 3)
        {
            userCustomer = user;
            if (CheckCustomers(user, pass) == true)
            {
                return true;
            }
        }
        return false;
    }

    void MenuLogin()
    {
        cout << "\t\t\t\t"
             << "   _____ _                   ____                 _____ _          " << endl;
        cout << "\t\t\t\t"
             << "  / ____| |                 |  _ \\               / ____(_)            " << endl;
        cout << "\t\t\t\t"
             << " | (___ | |__   ___  _ __   | |_) | __ _ _ __   | |  __ _  __ _ _   _ " << endl;
        cout << "\t\t\t\t"
             << "  \\___ \\| '_ \\ / _ \\| '_ \\  |  _ < / _` | '_ \\  | | |_ | |/ _` | | | |" << endl;
        cout << "\t\t\t\t"
             << "  ____) | | | | (_) | |_) | | |_) | (_| | | | | | |__| | | (_| | |_| |" << endl;
        cout << "\t\t\t\t"
             << " |_____/|_| |_| ___/| .__/  |____/ \\__,_|_| |_|  \\_____|_|\\__,_|\\__, |" << endl;
        cout << "\t\t\t\t"
             << "                    | |                                          __/ |" << endl;
        cout << "\t\t\t\t"
             << "                    |_|                                         |___/ " << endl;
        cout << "\t\t\t\t+========================     Dang nhap     =========================+" << endl;
        cout << "\t\t\t\t|                                                                    |" << endl;
        cout << "\t\t\t\t|                      1.  Quan tri vien                             |" << endl;
        cout << "\t\t\t\t|                      2.  Nhan vien                                 |" << endl;
        cout << "\t\t\t\t|                      3.  Khach hang                                |" << endl;
        cout << "\t\t\t\t|                      4.  Thoat                                     |" << endl;
        cout << "\t\t\t\t+====================================================================+" << endl;
    }

    void MenuAdmin()
    {
        cout << "\t\t\t\t\t   ____                      _        _         _            " << endl;
        cout << "\t\t\t\t\t  / __ \\                    | |      (_)       (_)           " << endl;
        cout << "\t\t\t\t\t | |  | |_   _  __ _ _ __   | |_ _ __ _  __   ___  ___ _ __  " << endl;
        cout << "\t\t\t\t\t | |  | | | | |/ _` | '_ \\  | __| '__| | \\ \\ / / |/ _ \\ '_ \\ " << endl;
        cout << "\t\t\t\t\t | |__| | |_| | (_| | | | | | |_| |  | |  \\ V /| |  __/ | | |" << endl;
        cout << "\t\t\t\t\t  \\___\\_\\\\__,_|\\__,_|_| |_|  \\__|_|  |_|   \\_/ |_|\\___|_| |_|" << endl;
        cout << "\t\t\t\t+========================   Quan tri vien   =========================+" << endl;
        cout << "\t\t\t\t|                                                                    |" << endl;
        cout << "\t\t\t\t|                      1.  Quan li san pham                          |" << endl;
        cout << "\t\t\t\t|                      2.  Quan li khach hang                        |" << endl;
        cout << "\t\t\t\t|                      3.  Quan li hoa don                           |" << endl;
        cout << "\t\t\t\t|                      4.  Doanh thu                                 |" << endl;
        cout << "\t\t\t\t|                      5.  Loi nhuan                                 |" << endl;
        cout << "\t\t\t\t|                      6.  Quan li nhan vien                         |" << endl;
        cout << "\t\t\t\t|                      7.  Quay lai                                  |" << endl;
        cout << "\t\t\t\t|                      8.  Thoat                                     |" << endl;
        cout << "\t\t\t\t+====================================================================+" << endl;
    }

    void MenuStaffs()
    {
        cout << "\t\t\t\t\t _   _ _                         _            " << endl;
        cout << "\t\t\t\t\t| \\ | | |                       (_)           " << endl;
        cout << "\t\t\t\t\t|  \\| | |__   __ _ _ __   __   ___  ___ _ __  " << endl;
        cout << "\t\t\t\t\t| . ` | '_ \\ / _` | '_ \\  \\ \\ / / |/ _ \\ '_ \\ " << endl;
        cout << "\t\t\t\t\t| |\\  | | | | (_| | | | |  \\ V /| |  __/ | | |" << endl;
        cout << "\t\t\t\t\t|_| \\_|_| |_|\\__,_|_| |_|   \\_/ |_|\\___|_| |_|" << endl;
        cout << "\t\t\t\t+=======================     Nhan vien     ==========================+" << endl;
        cout << "\t\t\t\t|                                                                    |" << endl;
        cout << "\t\t\t\t|                      1.  Danh sach san pham                        |" << endl;
        cout << "\t\t\t\t|                      2.  Tim kiem san pham                         |" << endl;
        cout << "\t\t\t\t|                      3.  Sap xep san pham                          |" << endl;
        cout << "\t\t\t\t|                      4.  Quay lai                                  |" << endl;
        cout << "\t\t\t\t|                      5.  Thoat                                     |" << endl;
        cout << "\t\t\t\t+====================================================================+" << endl;
    }

    void MenuCustomer()
    {
        cout << "\t\t\t\t  _  ___                _       _                       " << endl;
        cout << "\t\t\t\t | |/ / |              | |     | |                      " << endl;
        cout << "\t\t\t\t | ' /| |__   __ _  ___| |__   | |__   __ _ _ __   __ _ " << endl;
        cout << "\t\t\t\t |  < | '_ \\ / _` |/ __| '_ \\  | '_ \\ / _` | '_ \\ / _` |" << endl;
        cout << "\t\t\t\t | . \\| | | | (_| | (__| | | | | | | | (_| | | | | (_| |" << endl;
        cout << "\t\t\t\t |_|\\_\\_| |_|\\__,_|\\___|_| |_| |_| |_|\\__,_|_| |_|\\__, |" << endl;
        cout << "\t\t\t\t                                                   __/ |" << endl;
        cout << "\t\t\t\t                                                  |___/ " << endl;
        cout << "\t\t\t\t+=======================     Khach hang    ==========================+" << endl;
        cout << "\t\t\t\t|                                                                    |" << endl;
        cout << "\t\t\t\t|                      1.  Mua hang                                  |" << endl;
        cout << "\t\t\t\t|                      2.  Hoa don                                   |" << endl;
        cout << "\t\t\t\t|                      3.  Quay lai                                  |" << endl;
        cout << "\t\t\t\t|                      4.  Thoat                                     |" << endl;
        cout << "\t\t\t\t+====================================================================+" << endl;
    }

    void MenuManagerProducts()
    {
        cout << "\t\t\t\t+======================== Quan li san pham  =========================+" << endl;
        cout << "\t\t\t\t|                                                                    |" << endl;
        cout << "\t\t\t\t|                      1.  Danh sach san pham                        |" << endl;
        cout << "\t\t\t\t|                      2.  Them san pham                             |" << endl;
        cout << "\t\t\t\t|                      3.  Xoa san pham                              |" << endl;
        cout << "\t\t\t\t|                      4.  Sap xep san pham                          |" << endl;
        cout << "\t\t\t\t|                      5.  Tim kiem san pham                         |" << endl;
        cout << "\t\t\t\t|                      6.  Cap nhat san pham                         |" << endl;
        cout << "\t\t\t\t|                      7.  Quay lai                                  |" << endl;
        cout << "\t\t\t\t|                      8.  Thoat                                     |" << endl;
        cout << "\t\t\t\t+====================================================================+" << endl;
    }

    void MenuManagerBill()
    {
        cout << "\t\t\t\t+======================= Quan li hoa don  ===========================+" << endl;
        cout << "\t\t\t\t|                                                                    |" << endl;
        cout << "\t\t\t\t|                      1.  Danh sach hoa don                         |" << endl;
        cout << "\t\t\t\t|                      2.  Xoa hoa don                               |" << endl;
        cout << "\t\t\t\t|                      3.  Tim kiem hoa don                          |" << endl;
        cout << "\t\t\t\t|                      4.  Quay lai                                  |" << endl;
        cout << "\t\t\t\t|                      5.  Thoat                                     |" << endl;
        cout << "\t\t\t\t+====================================================================+" << endl;
    }

    void MenuManagerStaffs()
    {
        cout << "\t\t\t\t+======================= Quan li nhan vien  =========================+" << endl;
        cout << "\t\t\t\t|                                                                    |" << endl;
        cout << "\t\t\t\t|                      1.  Danh sach nhan vien                       |" << endl;
        cout << "\t\t\t\t|                      2.  Them nhan vien                            |" << endl;
        cout << "\t\t\t\t|                      3.  Xoa nhan vien                             |" << endl;
        cout << "\t\t\t\t|                      4.  Cap nhat thong tin nhan vien              |" << endl;
        cout << "\t\t\t\t|                      5.  Quay lai                                  |" << endl;
        cout << "\t\t\t\t|                      6.  Thoat                                     |" << endl;
        cout << "\t\t\t\t+====================================================================+" << endl;
    }
    void ManagerStaffs()
    {
        int x;
        while (true)
        {
            MenuManagerStaffs();
            cout << setw(55) << "Moi chon chuc nang:";
            cin >> x;
            if (x == 1)
            {
                system("cls");
                string str1 = "\t\t************************************************************************************************************************************\n";
                string str2 = "\t\t+------------+--------------------------+--------------+-------------+----------------------------+----------+---------------------+\n";
                cout << "\t\t\t\t\t _____              _                      _             _                         _            " << endl;
                cout << "\t\t\t\t\t|  __ \\            | |                    | |           | |                       (_)           " << endl;
                cout << "\t\t\t\t\t| |  | | __ _ _ __ | |__    ___  __ _  ___| |__    _ __ | |__   __ _ _ __   __   ___  ___ _ __  " << endl;
                cout << "\t\t\t\t\t| |  | |/ _` | '_ \\| '_ \\  / __|/ _` |/ __| '_ \\  | '_ \\| '_ \\ / _` | '_ \\  \\ \\ / / |/ _ \\ '_ \\ " << endl;
                cout << "\t\t\t\t\t| |__| | (_| | | | | | | | \\__ \\ (_| | (__| | | | | | | | | | | (_| | | | |  \\ V /| |  __/ | | |" << endl;
                cout << "\t\t\t\t\t|_____/ \\__,_|_| |_|_| |_| |___/\\__,_|\\___|_| |_| |_| |_|_| |_|\\__,_|_| |_|   \\_/ |_|\\___|_| |_|" << endl;
                cout << str1;
                cout << "\t\t" << setw(10) << "ID"
                     << setw(20) << "Ten"
                     << "\t\t" << setw(3) << "  Gioi tinh"
                     << "\t" << setw(10) << "SDT" << setw(20) << "Dia chi"
                     << "\t\t"
                     << setw(10) << "Pass" << setw(15) << "Luong" << endl;
                cout << str1;
                int size = ListStaffs.GetSize();
                for (int i = 0; i < size; i++)
                {
                    ListStaffs.GetIndex(i).Show();
                    cout << str2;
                }
            }
            else if (x == 2)
            {
                // them nhan vien
                string id, pass, name, addr, sex, phonenb;
                long long salary;
                fflush(stdin);
                cout << "\t\t\t\t\tMoi nhap ID:";
                getline(cin, id);
                int flag = 0;
                int size = ListStaffs.GetSize();
                for (int i = 0; i < size; i++)
                {
                    if (ListStaffs.GetIndex(i).GetID().compare(id) == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    cout << "\t\t\t\t\tID nhan vien da ton tai!" << endl;
                }
                else
                {
                    fflush(stdin);
                    cout << "\t\t\t\t\tMoi nhap pass:";
                    getline(cin, pass);
                    cout << "\t\t\t\t\tMoi nhap ten:";
                    getline(cin, name);
                    cout << "\t\t\t\t\tMoi nhap dia chi:";
                    getline(cin, addr);
                    cout << "\t\t\t\t\tMoi nhap gioi tinh:";
                    getline(cin, sex);
                    cout << "\t\t\t\t\tMoi nhap so dien thoai:";
                    getline(cin, phonenb);
                    cout << "\t\t\t\t\tMoi nhap luong nhan vien:";
                    cin >> salary;
                    Staff staff(id, pass, name, addr, sex, phonenb, salary);
                    ListStaffs.Add(staff);
                    cout << "\t\t\t\t\tThem thanh cong!" << endl;
                }
                sleep(1);
                system("cls");
            }
            else if (x == 3)
            {
                // xoa
                fflush(stdin);
                string id;
                cout << "\t\t\t\t\tMoi nhap ID nhan vien can xoa:";
                getline(cin, id);
                int flag = 0;
                int size = ListStaffs.GetSize();
                for (int i = 0; i < size; i++)
                {
                    if (ListStaffs.GetIndex(i).GetID().compare(id) == 0)
                    {
                        flag = 1;
                        ListStaffs.DeleteIndex(i);
                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << "\t\t\t\t\tKhong tim thay ID!" << endl;
                }
                else
                    cout << "\t\t\t\t\tXoa thanh cong!" << endl;
                sleep(1);
                system("cls");
            }
            else if (x == 4)
            {
                // update
                Staff node;
                string id;
                bool flag = false;
                cout << "\t\t\t\t\tMoi nhap ID khach hang can cap nhat: ";
                fflush(stdin);
                getline(cin, id);
                NodeData<Staff> *p;
                p = ListStaffs.GetPhead();
                while (p != NULL)
                {
                    if (id.compare(p->GetData().GetID()) == 0)
                    {
                        flag = true;
                        break;
                    }
                    p = p->GetPnext();
                }
                if (flag == true)
                {
                    string pass, name, addr, sex, phonenb;
                    long long salary;
                    fflush(stdin);
                    cout << "\t\t\t\t\tMoi nhap lai pass:";
                    getline(cin, pass);
                    cout << "\t\t\t\t\tMoi nhap ten:";
                    getline(cin, name);
                    cout << "\t\t\t\t\tMoi nhap dia chi:";
                    getline(cin, addr);
                    cout << "\t\t\t\t\tMoi nhap gioi tinh:";
                    getline(cin, sex);
                    cout << "\t\t\t\t\tMoi nhap so dien thoai:";
                    getline(cin, phonenb);
                    cout << "\t\t\t\t\tMoi nhap luong nhan vien";
                    cin >> salary;
                    Staff staff(id, pass, name, addr, sex, phonenb, salary);
                    p->SetData(staff);
                    p = new NodeData<Staff>;
                    delete p;
                }
                else
                    cout << "\t\t\t\t\tKhong tim thay ID nhan vien" << endl;
                sleep(1);
                system("cls");
            }
            else if (x == 5)
            {
                // quay lai
                system("cls");
                break;
            }
            else if (x == 6)
            {
                products.ShowFile();
                ShowBillToFile();
                ShowStaffsToFile();
                ShowCustomersToFile();
                exit(1);
            }
        }
    }

    void MenuManagerCustomers()
    {
        cout << "\t\t\t\t+======================= Quan li khach hang  ========================+" << endl;
        cout << "\t\t\t\t|                                                                    |" << endl;
        cout << "\t\t\t\t|                      1.  Danh sach khach hang                      |" << endl;
        cout << "\t\t\t\t|                      2.  Them khach hang                           |" << endl;
        cout << "\t\t\t\t|                      3.  Xoa khach hang                            |" << endl;
        cout << "\t\t\t\t|                      4.  Tim kiem khach hang                       |" << endl;
        cout << "\t\t\t\t|                      5.  Cap nhat thong tin khach hang             |" << endl;
        cout << "\t\t\t\t|                      6.  Quay lai                                  |" << endl;
        cout << "\t\t\t\t|                      7.  Thoat                                     |" << endl;
        cout << "\t\t\t\t+====================================================================+" << endl;
    }
    void ManagerCustomers()
    {
        int x;
        while (true)
        {
            MenuManagerCustomers();
            cout << setw(55) << "Moi chon chuc nang:";
            cin >> x;
            if (x == 1)
            {
                system("cls");
                // danh sach
                string str1 = "\t\t\t**************************************************************************************************************\n";
                string str2 = "\t\t\t+------------+--------------------------+--------------+-------------+----------------------------+----------+\n";
                cout << " \t\t\t\t  _____              _                      _       _    _                _       _                       " << endl;
                cout << " \t\t\t\t|  __ \\            | |                    | |     | |  | |              | |     | |                      " << endl;
                cout << " \t\t\t\t| |  | | __ _ _ __ | |__    ___  __ _  ___| |__   | | _| |__   __ _  ___| |__   | |__   __ _ _ __   __ _ " << endl;
                cout << " \t\t\t\t| |  | |/ _` | '_ \\| '_ \\  / __|/ _` |/ __| '_ \\  | |/ / '_ \\ / _` |/ __| '_ \\  | '_ \\ / _` | '_ \\ / _` |" << endl;
                cout << " \t\t\t\t| |__| | (_| | | | | | | | \\__ \\ (_| | (__| | | | |   <| | | | (_| | (__| | | | | | | | (_| | | | | (_| |" << endl;
                cout << " \t\t\t\t|_____/ \\__,_|_| |_|_| |_| |___/\\__,_|\\___|_| |_| |_|\\_\\_| |_|\\__,_|\\___|_| |_| |_| |_|\\__,_|_| |_|\\__, |" << endl;
                cout << " \t\t\t\t                                                                                                    __/ |" << endl;
                cout << " \t\t\t\t                                                                                                   |___/ " << endl;

                cout << str1;
                cout << "\t\t\t" << setw(10) << "ID"
                     << setw(20) << "Ten"
                     << "\t\t" << setw(3) << "  Gioi tinh"
                     << "\t" << setw(10) << "SDT" << setw(20) << "Dia chi"
                     << "\t\t"
                     << setw(10) << "Pass" << endl;
                cout << str1;
                int size = ListCustomers.GetSize();
                for (int i = 0; i < ListCustomers.GetSize(); i++)
                {
                    ListCustomers.GetIndex(i).Show();
                    cout << str2;
                }
                cout << endl;
            }
            else if (x == 2)
            {
                // them
                system("cls");
                string id, pass, name, addr, sex, phonenb;
                fflush(stdin);
                cout << "Moi nhap ID:";
                getline(cin, id);
                int flag = 0;
                int size = ListCustomers.GetSize();
                for (int i = 0; i < size; i++)
                {
                    if (ListCustomers.GetIndex(i).GetID().compare(id) == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    cout << "ID khach hang da ton tai!" << endl;
                }
                else
                {
                    fflush(stdin);
                    cout << "Moi nhap pass:";
                    fflush(stdin);
                    getline(cin, pass);
                    fflush(stdin);
                    cout << "Moi nhap ten:";
                    getline(cin, name);
                    fflush(stdin);
                    cout << "Moi nhap dia chi:";
                    getline(cin, addr);
                    fflush(stdin);
                    cout << "Moi nhap gioi tinh:";
                    getline(cin, sex);
                    fflush(stdin);
                    cout << "Moi nhap so dien thoai:";
                    getline(cin, phonenb);
                    Customers customer(id, pass, name, addr, sex, phonenb);
                    ListCustomers.Add(customer);
                    cout << "\t\t\t\t\tThem thanh cong!";
                    sleep(1);
                    system("cls");
                }
            }
            else if (x == 3)
            {
                // xoa
                string id;
                cout << "Moi nhap ID khach hang can xoa: ";
                fflush(stdin);
                cin >> id;
                int flag = 0;
                int size = ListCustomers.GetSize();
                for (int i = 0; i < size; i++)
                {
                    if (ListCustomers.GetIndex(i).GetID().compare(id) == 0)
                    {
                        flag = 1;
                        ListCustomers.DeleteIndex(i);
                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << "\t\t\t\t\tKhong tim thay ID!" << endl;
                }
                else
                    cout << "\t\t\t\t\tXoa thanh cong!" << endl;
                sleep(1);
                system("cls");
            }
            else if (x == 4)
            {
                system("cls");
                // tim kiem khach hang
                fflush(stdin);
                string id;
                cout << "Moi nhap ID khach hang can tim: ";
                getline(cin, id);
                int flag = 0;
                int size = ListCustomers.GetSize();
                for (int i = 0; i < size; i++)
                {
                    if (ListCustomers.GetIndex(i).GetID().compare(id) == 0)
                    {
                        flag = 1;
                        string str1 = "\t\t\t**************************************************************************************************************\n";
                        string str2 = "\t\t\t+------------+--------------------------+--------------+-------------+----------------------------+----------+\n";
                        cout << " \t\t\t\t  _____              _                      _       _    _                _       _                       " << endl;
                        cout << " \t\t\t\t|  __ \\            | |                    | |     | |  | |              | |     | |                      " << endl;
                        cout << " \t\t\t\t| |  | | __ _ _ __ | |__    ___  __ _  ___| |__   | | _| |__   __ _  ___| |__   | |__   __ _ _ __   __ _ " << endl;
                        cout << " \t\t\t\t| |  | |/ _` | '_ \\| '_ \\  / __|/ _` |/ __| '_ \\  | |/ / '_ \\ / _` |/ __| '_ \\  | '_ \\ / _` | '_ \\ / _` |" << endl;
                        cout << " \t\t\t\t| |__| | (_| | | | | | | | \\__ \\ (_| | (__| | | | |   <| | | | (_| | (__| | | | | | | | (_| | | | | (_| |" << endl;
                        cout << " \t\t\t\t|_____/ \\__,_|_| |_|_| |_| |___/\\__,_|\\___|_| |_| |_|\\_\\_| |_|\\__,_|\\___|_| |_| |_| |_|\\__,_|_| |_|\\__, |" << endl;
                        cout << " \t\t\t\t                                                                                                    __/ |" << endl;
                        cout << " \t\t\t\t                                                                                                   |___/ " << endl;

                        cout << str1;
                        cout << "\t\t\t" << setw(10) << "ID"
                             << setw(20) << "Ten"
                             << "\t\t" << setw(3) << "  Gioi tinh"
                             << "\t" << setw(10) << "SDT" << setw(20) << "Dia chi"
                             << "\t\t"
                             << setw(10) << "Pass" << endl;
                        cout << str1;
                        ListCustomers.GetIndex(i).Show();
                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << "Khong tim thay ID!" << endl;
                }
            }
            else if (x == 5)
            {
                Customers node;
                string id;
                bool flag = false;
                cout << "Moi nhap ID khach hang can cap nhat: ";
                fflush(stdin);
                getline(cin, id);
                NodeData<Customers> *p;
                p = ListCustomers.GetPhead();
                while (p != NULL)
                {
                    if (id.compare(p->GetData().GetID()) == 0)
                    {
                        flag = true;
                        break;
                    }
                    p = p->GetPnext();
                }
                if (flag == true)
                {
                    string pass, name, addr, sex, phonenb;
                    fflush(stdin);
                    cout << "Moi nhap lai pass:";
                    getline(cin, pass);
                    cout << "Moi nhap ten:";
                    getline(cin, name);
                    cout << "Moi nhap dia chi:";
                    getline(cin, addr);
                    cout << "Moi nhap gioi tinh:";
                    getline(cin, sex);
                    cout << "Moi nhap so dien thoai:";
                    getline(cin, phonenb);
                    Customers customer(id, pass, name, addr, sex, phonenb);
                    p->SetData(customer);
                    p = new NodeData<Customers>;
                    delete p;
                    cout << "\t\t\t\t\tCap nhat thanh cong!" << endl;
                }
                else
                    cout << "Khong tim thay ID khach hang!" << endl;
                sleep(1);
                system("cls");
            }
            else if (x == 6)
            {
                system("cls");
                break;
            }
            else if (x == 7)
            {
                products.ShowFile();
                ShowBillToFile();
                ShowStaffsToFile();
                ShowCustomersToFile();
                exit(1);
            }
        }
    }

    void ProductManagerFeature()
    {
        int x;
        while (true)
        {
            MenuManagerProducts();
            cout << setw(55) << "Moi chon chuc nang:";
            cin >> x;
            if (x == 1)
            {
                system("cls");
                products.Show2();
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
                getline(cin, id);
                products.DeleteID(id);
                system("cls");
            }
            else if (x == 4)
            {
                products.SortASC();
                system("cls");
            }
            else if (x == 5)
            {
                system("cls");
                fflush(stdin);
                string id;
                cout << "Moi nhap id can tim: ";
                getline(cin, id);
                Product x = products.Search(id);
                if (x.GetID().compare("NULL") == 0)
                {
                    cout << "Khong co san pham can tim!" << endl;
                }
                else
                {
                    string str1 = "**************************************************************************************************************************************************\n";
                    string str2 = "+-----------+-------------------------------+--------------+-----------------+-----------------+----------+----------+------------+--------------+\n";
                    cout << str1;
                    cout << setw(10) << "ID"
                         << "\t" << setw(20) << "TenSP"
                         << "\t" << setw(20) << "NSX"
                         << "\t\t" << setw(2) << "Kich co"
                         << "\t" << setw(15) << "Loai giay"
                         << "\t" << setw(20) << "Gia tien"
                         << "\t" << setw(10) << "So luong"
                         << "\t"
                         << " Gia nhap" << endl;
                    cout << str1;
                    cout << setw(10) << x.GetID() << "\t" << setw(20) << x.GetName() << "\t" << setw(20) << x.GetManufacturer()
                         << "\t\t" << setw(2) << x.GetSize() << "\t" << setw(15) << x.GetType() << "\t" << setw(20) << x.GetPrice() << "\t" << setw(10) << x.GetAmount() << "\t" << setw(10) << x.GetImportPrice() << endl;
                    cout << str2;
                }
            }
            else if (x == 6)
            {
                fflush(stdin);
                string id;
                cout << "Moi nhap id san pham can cap nhat: ";
                getline(cin, id);
                bool flag = products.Update(id);
                if (flag)
                {
                    cout << "Cap nhat thanh cong!" << endl;
                }
                else
                {
                    cout << "Khong tim thay ID san pham can cap nhat!" << endl;
                }
                sleep(1);
                system("cls");
            }
            else if (x == 7)
            {
                system("cls");
                break;
            }
            else if (x == 8)
            {
                products.ShowFile();
                ShowBillToFile();
                ShowStaffsToFile();
                ShowCustomersToFile();
                exit(1);
            }
        }
    }

    void BillManagerFeature()
    {
        int menuBill;
        while (true)
        {
            MenuManagerBill();
            cout << setw(55) << "Moi chon chuc nang:";
            cin >> menuBill;
            system("cls");
            if (menuBill == 1)
            {
                system("cls");
                int size = ListBills.GetSize();
                if (size == 0)
                    cout << "Danh sach rong!" << endl;
                else
                {
                    for (int i = 0; i < size; i++)
                    {
                        ListBills.GetIndex(i).Show();
                    }
                }
            }
            else if (menuBill == 2)
            {
                system("cls");
                // xoá hoá đơn
                int size = ListBills.GetSize();
                if (size == 0)
                    cout << "Danh sach rong!" << endl;
                else
                {
                    fflush(stdin);
                    string id;
                    cout << "Moi nhap ID hoa don can xoa: ";
                    getline(cin, id);
                    int flag = 0;
                    int size = ListBills.GetSize();
                    for (int i = 0; i < size; i++)
                    {
                        if (ListBills.GetIndex(i).GetIDB().compare(id) == 0)
                        {
                            flag = 1;
                            ListBills.DeleteIndex(i);
                            break;
                        }
                    }
                    if (flag == 0)
                    {
                        cout << "Khong tim thay ID!" << endl;
                    }
                    else
                        cout << "Xoa thanh cong!" << endl;
                }
                sleep(1);
                system("cls");
            }
            else if (menuBill == 3)
            {
                fflush(stdin);
                int size = ListBills.GetSize();
                if (size == 0)
                    cout << "Danh sach rong!" << endl;
                else
                {
                    string id;
                    cout << "Moi nhap ID hoa don can tim: ";
                    getline(cin, id);
                    int flag = 0;
                    int size = ListBills.GetSize();
                    for (int i = 0; i < size; i++)
                    {
                        if (ListBills.GetIndex(i).GetIDB().compare(id) == 0)
                        {
                            flag = 1;
                            ListBills.GetIndex(i).Show();
                            break;
                        }
                    }
                    if (flag == 0)
                    {
                        cout << "Khong tim thay ID!" << endl;
                    }
                }
            }
            else if (menuBill == 4)
            {
                system("cls");
                break;
            }
            else if (menuBill == 5)
            {
                ShowBillToFile();
                products.ShowFile();
                ShowStaffsToFile();
                ShowCustomersToFile();
                exit(1);
            }
        }
    }

    void AdminFeatures()
    {
        int menuAdmin;
        while (true)
        {
            MenuAdmin();
            cout << setw(55) << "Moi chon chuc nang:";
            cin >> menuAdmin;
            system("cls");
            if (menuAdmin == 1)
            {
                ProductManagerFeature();
            }
            else if (menuAdmin == 2)
            {
                // quản lí khách hàng
                //  show list khách hàng
                ManagerCustomers();
            }
            else if (menuAdmin == 3)
            {
                // quản lí hoá đơn
                BillManagerFeature();
            }
            else if (menuAdmin == 4)
            {
                TinhDoanhthu();
                string str;
                cout << "\t\t\t\t\tBam Y de tiep tuc!" << endl;
                while (cin >> str)
                {
                    if (str == "Y" || str == "y")
                        break;
                    cout << "\t\t\t\t\tMoi nhap lai!" << endl;
                }
                system("cls");
            }
            else if (menuAdmin == 5)
            {
                TinhLoiNhuan();
                string str;
                cout << "\t\t\t\t\tBam Y de tiep tuc!" << endl;
                while (cin >> str)
                {
                    if (str == "Y" || str == "y")
                        break;
                    cout << "\t\t\t\t\tMoi nhap lai!" << endl;
                }
                system("cls");
            }
            else if (menuAdmin == 6)
            {
                // nhanvien
                ManagerStaffs();
            }
            else if (menuAdmin == 7)
            {
                system("cls");
                break;
            }
            else if (menuAdmin == 8)
            {
                products.ShowFile();
                ShowBillToFile();
                ShowStaffsToFile();
                ShowCustomersToFile();
                exit(1);
            }
        }
    }

    void CustomersFeatures()
    {
        int menuCustomers;
        while (true)
        {
            MenuCustomer();
            cout << setw(55) << "Moi chon chuc nang:";
            cin >> menuCustomers;
            system("cls");
            if (menuCustomers == 1)
            {
                int size = ListCustomers.GetSize();
                int i = 0;
                for (i = 0; i < size; i++)
                {
                    if (userCustomer.compare(ListCustomers.GetIndex(i).GetID()) == 0)
                    {
                        Bill temp = ListCustomers.GetIndex(i).Buy(products, ListBills.GetSize());
                        if(temp.GetSize() != 0)
                            ListBills.Add(temp);
                        break;
                    }
                }
                sleep(1);
                system("cls");
            }
            else if (menuCustomers == 2)
            {
                // xuất ra các hoá đơn dựa trên id
                system("cls");
                BillsOfCustomer(ListBills, userCustomer);
                string str;
                cout << "\t\t\t\t\tBam Y de tiep tuc!" << endl;
                while (cin >> str)
                {
                    if (str == "Y" || str == "y")
                        break;
                    cout << "\t\t\t\t\tMoi nhap lai!" << endl;
                }
                system("cls");
            }
            else if (menuCustomers == 3)
            {
                system("cls");
                break;
            }
            else if (menuCustomers == 4)
            {
                products.ShowFile();
                ShowBillToFile();
                ShowStaffsToFile();
                ShowCustomersToFile();
                exit(1);
            }
        }
    }

    void StaffFeatures()
    {
        int menuStaffs;
        while (true)
        {
            MenuStaffs();
            cout << setw(55) << "Moi chon chuc nang:";
            cin >> menuStaffs;
            system("cls");
            if (menuStaffs == 1)
            {
                products.Show();
                string str;
                cout << "\t\t\t\t\tBam Y de tiep tuc!" << endl;
                while (cin >> str)
                {
                    if (str == "Y" || str == "y")
                        break;
                    cout << "\t\t\t\t\tMoi nhap lai!" << endl;
                }
                system("cls");
            }
            else if (menuStaffs == 2)
            {
                cout << "\t\t\t\t\t  _______ _             _    _                                          _                     " << endl;
                cout << "\t\t\t\t\t |__   __(_)           | |  (_)                                        | |                     " << endl;
                cout << "\t\t\t\t\t    | |   _ _ __ ___   | | ___  ___ _ __ ___    ___  __ _ _ __    _ __ | |__   __ _ _ __ ___  " << endl;
                cout << "\t\t\t\t\t    | |  | | '_ ` _ \\  | |/ / |/ _ \\ '_ ` _ \\  / __|/ _` | '_ \\  | '_ \\| '_ \\ / _` | '_ ` _ \\ " << endl;
                cout << "\t\t\t\t\t    | |  | | | | | | | |   <| |  __/ | | | | | \\__ \\ (_| | | | | | |_) | | | | (_| | | | | | |" << endl;
                cout << "\t\t\t\t\t    |_|  |_|_| |_| |_| |_|\\_\\_|\\___|_| |_| |_| |___/\\__,_|_| |_| | .__/|_| |_|\\__,_|_| |_| |_|" << endl;
                cout << "\t\t\t\t\t                                                                 | |                          " << endl;
                cout << "\t\t\t\t\t                                                                 |_|" << endl;
                fflush(stdin);
                string id;
                cout << "\t\t\t\t\tMoi nhap ID san pham can tim:";
                getline(cin, id);
                Product temp = products.Search(id);
                if (temp.GetID().compare("NULL") == 0)
                {
                    cout << "\t\t\t\t\tKhong co san pham can tim!" << endl;
                }
                else
                {
                    cout << "\t\t\t\t _____              _                      _                               _                     " << endl;
                    cout << "\t\t\t\t|  __ \\            | |                    | |                             | |                    " << endl;
                    cout << "\t\t\t\t| |  | | __ _ _ __ | |__    ___  __ _  ___| |__    ___  __ _ _ __    _ __ | |__   __ _ _ __ ___  " << endl;
                    cout << "\t\t\t\t| |  | |/ _` | '_ \\| '_ \\  / __|/ _` |/ __| '_ \\  / __|/ _` | '_ \\  | '_ \\| '_ \\ / _` | '_ ` _ \\ " << endl;
                    cout << "\t\t\t\t| |__| | (_| | | | | | | | \\__ \\ (_| | (__| | | | \\__ \\ (_| | | | | | |_) | | | | (_| | | | | | |" << endl;
                    cout << "\t\t\t\t|_____/ \\__,_|_| |_|_| |_| |___/\\__,_|\\___|_| |_| |___/\\__,_|_| |_| | .__/|_| |_|\\__,_|_| |_| |_|" << endl;
                    cout << "\t\t\t\t                                                                    | |                          " << endl;
                    cout << "\t\t\t\t                                                                    |_|                          " << endl;
                    string str1 = "\t\t***********************************************************************************************************************************\n";
                    string str2 = "\t\t+-----------+-------------------------------+--------------+-----------------+-----------------+----------+----------+------------+\n";
                    cout << str1;
                    cout << "\t\t" << setw(10) << "ID"
                         << "\t" << setw(20) << "TenSP"
                         << "\t" << setw(20) << "NSX"
                         << "\t\t" << setw(2) << "Kich co"
                         << "\t" << setw(15) << "Loai giay"
                         << "\t" << setw(20) << "Gia tien"
                         << "\t" << setw(10) << "So luong" << endl;
                    cout << str1;
                    cout << temp;
                    cout << str1;
                }
                string str;
                cout << "\t\t\t\t\tBam Y de tiep tuc!" << endl;
                while (cin >> str)
                {
                    if (str == "Y" || str == "y")
                        break;
                    cout << "\t\t\t\t\tMoi nhap lai!" << endl;
                }
                system("cls");
            }
            else if (menuStaffs == 3)
            {
                products.SortASC();
            }
            else if (menuStaffs == 4)
            {
                system("cls");
                break;
            }
            else if (menuStaffs == 5)
            {
                products.ShowFile();
                ShowBillToFile();
                ShowStaffsToFile();
                ShowCustomersToFile();
                exit(1);
            }
        }
    }

    Product GetProduct(string id, string name, int Size, double Price, string type, int amount, string manu, long long importprice)
    {
        Product node;
        node.SetID(id);
        node.SetName(name);
        node.SetSize(Size);
        node.SetPrice(Price);
        node.SetType(type);
        node.SetAmount(amount);
        node.SetManufacturer(manu);
        node.SetImportPrice(importprice);
        return node;
    }

    void Create()
    {
        File.open("staff.txt", ios ::in);
        while (!File.eof())
        {
            string name = "", sex = "", phone = "", address = "";
            string id = "", pass = "";
            ;
            string UP;
            string SALARY = "";
            getline(File, UP);
            int size = 0, amount = 0;
            int price = 0;
            int pos = 0;
            for (int i = 0; i < UP.size(); i++)
            {
                if (UP[i] == '|')
                {
                    pos = i;
                    break;
                }
            }
            for (int i = 0; i < pos; i++)
                id += UP[i];
            int pos2 = 0;
            for (int i = pos + 1; i < UP.size(); i++)
            {
                if (UP[i] == '|')
                {
                    pos2 = i;
                    break;
                }
            }
            for (int i = pos + 1; i < pos2; i++)
                pass += UP[i];
            int pos3 = 0;
            for (int i = pos2 + 1; i < UP.size(); i++)
            {

                if (UP[i] == '|')
                {
                    pos3 = i;
                    break;
                }
            }
            for (int i = pos2 + 1; i < pos3; i++)
                name += UP[i];
            int pos4 = 0;
            for (int i = pos3 + 1; i < UP.size(); i++)
            {
                if (UP[i] == '|')
                {
                    pos4 = i;
                    break;
                }
            }
            for (int i = pos3 + 1; i < pos4; i++)
            {
                sex += UP[i];
            }
            int pos5 = 0;
            for (int i = pos4 + 1; i < UP.size(); i++)
            {
                if (UP[i] == '|')
                {
                    pos5 = i;
                    break;
                }
            }
            for (int i = pos4 + 1; i < pos5; i++)
                phone += UP[i];
            int pos6 = 0;
            for (int i = pos5 + 1; i < UP.size(); i++)
            {
                if (UP[i] == '|')
                {
                    pos6 = i;
                    break;
                }
            }
            for (int i = pos5 + 1; i < pos6; i++)
                address += UP[i];
            for (int i = pos6 + 1; i < UP.size() - 1; i++)
                SALARY += UP[i];

            long long salary = 0;
            for (int i = 0; i < SALARY.size(); i++)
            {
                salary = salary * 10 + (SALARY[i] - '0');
            }
            Staff x;
            x = GetStaff(id, pass, name, sex, phone, address, salary);
            ListStaffs.Add(x);
        }
        File.close();

        File.open("admin.txt", ios ::in);
        string s;
        while (!File.eof())
        {
            getline(File, s);
            if (s[0] == ' ')
                continue;
            string id = "", pass = "";
            int pos;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '|')
                {
                    pos = i;
                    break;
                }
            }
            for (int i = 0; i < pos; i++)
                id += s[i];
            for (int i = pos + 1; i < s.size(); i++)
                pass += s[i];
            Admin x = GetAdmin(id, pass);
            ListAdmins.Add(x);
        }
        File.close();
        File.open("customers.txt", ios ::in);
        while (!File.eof())
        {
            string name = "", sex = "", phone = "", address = "";
            string id = "", pass = "";
            ;
            string UP;
            getline(File, UP);
            int size = 0, amount = 0;
            int price = 0;
            int pos = 0;
            for (int i = 0; i < UP.size(); i++)
            {
                if (UP[i] == '|')
                {
                    pos = i;
                    break;
                }
            }
            for (int i = 0; i < pos; i++)
                id += UP[i];
            int pos2 = 0;
            for (int i = pos + 1; i < UP.size(); i++)
            {
                if (UP[i] == '|')
                {
                    pos2 = i;
                    break;
                }
            }
            for (int i = pos + 1; i < pos2; i++)
                pass += UP[i];
            int pos3 = 0;
            for (int i = pos2 + 1; i < UP.size(); i++)
            {

                if (UP[i] == '|')
                {
                    pos3 = i;
                    break;
                }
            }
            for (int i = pos2 + 1; i < pos3; i++)
                name += UP[i];
            int pos4 = 0;
            for (int i = pos3 + 1; i < UP.size(); i++)
            {
                if (UP[i] == '|')
                {
                    pos4 = i;
                    break;
                }
            }
            for (int i = pos3 + 1; i < pos4; i++)
            {
                sex += UP[i];
            }
            int pos5 = 0;
            for (int i = pos4 + 1; i < UP.size(); i++)
            {
                if (UP[i] == '|')
                {
                    pos5 = i;
                    break;
                }
            }
            for (int i = pos4 + 1; i < pos5; i++)
                phone += UP[i];
            int pos6 = 0;
            for (int i = pos5 + 1; i < UP.size() - 1; i++)
                address += UP[i];
            Customers x;
            x = GetCustomers(id, pass, name, sex, phone, address);
            ListCustomers.Add(x);
        }
        File.close();
        File.open("products.txt", ios ::in);
        while (!File.eof())
        {
            Product x;
            string SP;
            getline(File, SP);
            string id = "", name = "", manu = "", type = "";
            string IPPRICE = "";
            int size = 0, amount = 0;
            int price = 0;
            int pos = 0;
            int importprice = 0;
            for (int i = 0; i < SP.size(); i++)
            {
                if (SP[i] == '|')
                {
                    pos = i;
                    break;
                }
            }
            for (int i = 0; i < pos; i++)
                id += SP[i];
            int pos2 = 0;
            for (int i = pos + 1; i < SP.size(); i++)
            {
                if (SP[i] == '|')
                {
                    pos2 = i;
                    break;
                }
            }
            for (int i = pos + 1; i < pos2; i++)
                name += SP[i];
            int pos3 = 0;
            for (int i = pos2 + 1; i < SP.size(); i++)
            {

                if (SP[i] == '|')
                {
                    pos3 = i;
                    break;
                }
            }
            string SIZE = "";
            for (int i = pos2 + 1; i < pos3; i++)
                SIZE += SP[i];
            for (int i = 0; i < SIZE.size(); i++)
            {
                size = size * 10 + (SIZE[i] - '0');
            }
            int pos4 = 0;
            for (int i = pos3 + 1; i < SP.size(); i++)
            {
                if (SP[i] == '|')
                {
                    pos4 = i;
                    break;
                }
            }
            string PRICE = "";
            for (int i = pos3 + 1; i < pos4; i++)
            {
                PRICE += SP[i];
            }
            for (int i = 0; i < PRICE.size(); i++)
            {
                price = price * 10 + (PRICE[i] - '0');
            }
            int pos5 = 0;
            for (int i = pos4 + 1; i < SP.size(); i++)
            {
                if (SP[i] == '|')
                {
                    pos5 = i;
                    break;
                }
            }
            for (int i = pos4 + 1; i < pos5; i++)
                type += SP[i];
            int pos6 = 0;
            for (int i = pos5 + 1; i < SP.size(); i++)
            {
                if (SP[i] == '|')
                {
                    pos6 = i;
                    break;
                }
            }
            string AMOUNT = "";
            for (int i = pos5 + 1; i < pos6; i++)
                AMOUNT += SP[i];
            for (int i = 0; i < AMOUNT.size(); i++)
            {
                amount = amount * 10 + (AMOUNT[i] - '0');
            }
            int pos7 = 0;
            for (int i = pos6; i < SP.size(); i++)
            {
                if (SP[i] == '|')
                {
                    pos7 = i;
                    break;
                }
            }
            int pos8 = 0;
            for (int i = pos7 + 1; i < SP.size(); i++)
            {
                if (SP[i] == '|')
                {
                    pos8 = i;
                    break;
                }
            }
            for (int i = pos7 + 1; i < pos8; i++)
            {
                manu += SP[i];
            }
            for (int i = pos8 + 1; i < SP.size(); i++)
            {
                IPPRICE += SP[i];
            }
            for (int i = 0; i < IPPRICE.size(); i++)
            {
                importprice = importprice * 10 + (IPPRICE[i] - '0');
            }
            x = GetProduct(id, name, size, price, type, amount, manu, importprice);
            products.AddLast(x);
        }
        File.close();
        File.open("Bill.txt", ios ::in);
        int cnt = 0;
        while (!File.eof())
        {
            Bill x;
            string str;
            // cout<<str<<endl;
            for (int j = 1; j <= 5; j++)
            {
                getline(File, str);
                if (str == "")
                    break;
                int pos = -1;
                for (int i = 0; i < str.size(); i++)
                {
                    if (str[i] == ':')
                    {
                        pos = i;
                        break;
                    }
                }
                string need = "";
                string d = "", m = "", y = "";
                int dd = 0, mm = 0, yy = 0;
                for (int i = pos + 2; i < str.size(); i++)
                    need += str[i];
                if (j == 1)
                {
                    x.SetIDB(need);
                    continue;
                }
                if (j == 2)
                {
                    int pos1, pos2;
                    int dem = 0;
                    for (int i = 0; i < need.size(); i++)
                    {
                        if (need[i] == '/')
                        {
                            dem++;
                            if (dem == 1)
                                pos1 = i;
                            if (dem == 2)
                                pos2 = i;
                        }
                    }
                    for (int i = 0; i < pos1; i++)
                        d += need[i];
                    for (int i = pos1 + 1; i < pos2; i++)
                        m += need[i];
                    for (int i = pos2 + 1; i < need.size(); i++)
                        y += need[i];
                    for (int i = 0; i < d.size(); i++)
                    {
                        dd = dd * 10 + (d[i] - '0');
                    }
                    for (int i = 0; i < m.size(); i++)
                    {
                        mm = mm * 10 + (m[i] - '0');
                    }
                    for (int i = 0; i < y.size(); i++)
                    {
                        yy = yy * 10 + (y[i] - '0');
                    }
                    x.SetDay(dd);
                    x.SetMonth(mm);
                    x.SetYear(yy);
                    // cout<<x.GetDay()<<endl;
                    continue;
                }
                if (j == 3)
                {
                    x.SetIDC(need);
                    continue;
                }
                if (j == 4)
                {
                    x.SetNameCustomer(need);
                    continue;
                }
                if (j == 5)
                {
                    int sum = 0;
                    for (int i = 0; i < need.size(); i++)
                        sum = sum * 10 + (need[i] - '0');
                    x.SetSumPrice(sum);
                    // cout << x.GetDay() << " " << x.GetMonth() << " " << x.GetYear() << '\n';
                }
            }
            // cout<<x.GetIDB()<<endl;
            getline(File, str);
            if (str[0] == '[')
            {
                string s;
                while (getline(File, s))
                {
                    // cout<<s<<endl;
                    if (s[0] == ']')
                        break;
                    Product y;
                    string id = "", name = "", manu = "", type = "";
                    string IPPRICE = "";
                    int size = 0, amount = 0;
                    int price = 0;
                    int pos = 0;
                    int importprice = 0;
                    for (int i = 1; i < s.size(); i++)
                    {
                        if (s[i] == '|')
                        {
                            pos = i;
                            break;
                        }
                    }
                    for (int i = 1; i < pos; i++)
                        id += s[i];
                    int pos2 = 0;
                    for (int i = pos + 1; i < s.size(); i++)
                    {
                        if (s[i] == '|')
                        {
                            pos2 = i;
                            break;
                        }
                    }
                    for (int i = pos + 1; i < pos2; i++)
                        name += s[i];
                    int pos3 = 0;
                    for (int i = pos2 + 1; i < s.size(); i++)
                    {

                        if (s[i] == '|')
                        {
                            pos3 = i;
                            break;
                        }
                    }
                    string SIZE = "";
                    for (int i = pos2 + 1; i < pos3; i++)
                        SIZE += s[i];
                    for (int i = 0; i < SIZE.size(); i++)
                    {
                        size = size * 10 + (SIZE[i] - '0');
                    }
                    int pos4 = 0;
                    for (int i = pos3 + 1; i < s.size(); i++)
                    {
                        if (s[i] == '|')
                        {
                            pos4 = i;
                            break;
                        }
                    }
                    string PRICE = "";
                    for (int i = pos3 + 1; i < pos4; i++)
                    {
                        PRICE += s[i];
                    }
                    for (int i = 0; i < PRICE.size(); i++)
                    {
                        price = price * 10 + (PRICE[i] - '0');
                    }
                    int pos5 = 0;
                    for (int i = pos4 + 1; i < s.size(); i++)
                    {
                        if (s[i] == '|')
                        {
                            pos5 = i;
                            break;
                        }
                    }
                    for (int i = pos4 + 1; i < pos5; i++)
                        type += s[i];
                    int pos6 = 0;
                    for (int i = pos5 + 1; i < s.size(); i++)
                    {
                        if (s[i] == '|')
                        {
                            pos6 = i;
                            break;
                        }
                    }
                    string AMOUNT = "";
                    for (int i = pos5 + 1; i < pos6; i++)
                        AMOUNT += s[i];
                    for (int i = 0; i < AMOUNT.size(); i++)
                    {
                        amount = amount * 10 + (AMOUNT[i] - '0');
                    }
                    int pos7 = 0;
                    for (int i = pos6; i < s.size(); i++)
                    {
                        if (s[i] == '|')
                        {
                            pos7 = i;
                            break;
                        }
                    }
                    for (int i = pos7 + 1; i < s.size(); i++)
                    {
                        manu += s[i];
                    }
                    y = GetProduct(id, name, size, price, type, amount, manu, 0);
                    x.Add(y);
                }
                // cout<<x.GetIDB()<<endl;
                ListBills.Add(x);
            }
        }
        // for (int i=0;i<ListBills.GetSize();i++)
        //  ListBills.GetIndex(i).Show();
        File.close();
    }
    void Handle()
    {

        int menu;
        while (true)
        {
            MenuLogin();
            cout << setw(55) <<  "Moi chon chuc nang:";
            cin >> menu;
            if (menu == 1)
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
                        system("cls");
                        break;
                    }
                }
                AdminFeatures();
            }
            else if (menu == 2)
            {
                while (true)
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
                        system("cls");
                        break;
                    }
                }
                StaffFeatures();
            }
            else if (menu == 3)
            {
                while (true)
                {
                    if (Login(3) == 0)
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
                        system("cls");
                        break;
                    }
                }
                CustomersFeatures();
            }
            else
            {
                products.ShowFile();
                ShowBillToFile();
                exit(1);
            }
        }
    }


int main()
{
    cout << setw(29) << char(201);
    for (int i = 0; i < 80; i++)
        cout << char(205);
    cout << char(187);

        cout << "\n" << setw(29) << char(186) << setw(47) << "PBL 2: DO AN CO SO" << setw(34) << char(186);
        cout << "\n" << setw(29) << char(186) << setw(55) << "DE TAI: UNG DUNG QUAN LI BAN GIAY" << setw(26) << char(186);
        cout << "\n" << setw(29) << char(186) << setw(81) << char(186);
        cout << "\n" << setw(29) << char(186) << setw(30) << " Sinh vien thuc hien" << setw(40) << "Giao vien huong dan" << setw(11) << char(186);
        cout << "\n" << setw(29) << char(186) << setw(25) << " - Le Duc Khoa" << setw(40) << "- Vo Duc Hoang" << setw(16) << char(186);
        cout << "\n" << setw(29) << char(186) << setw(27) << " - Pham Tang Huy" << setw(40) <<  setw(54) << char(186);
        cout << "\n" << setw(29) << char(186) << setw(81) << char(186);
        cout << "\n" << setw(28) << " " << char(200);
    for (int i = 0; i < 80; i++)
        cout << char(205);
    cout << char(188) << endl;
    Create();
    Handle();
}
