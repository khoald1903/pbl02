#include "Element.h"
#include "conio.h"
#include "ManagerProduct.h"
ManagerProduct Products;
Element<admin> ListAdmin;
Element<Staff> ListStaff;
//Element<Customers> ListCustomer;
// template <class T>
// void CreateRepo(Element<T> &element, string str, T Func(string, string));

bool ASC(string a, string b)
{
    return a.compare(b) >= 0;
}

admin GetAdmin(string user, string pass)
{
    admin node;
    node.setuser(user);
    node.setpass(pass);
    return node;
}

Staff GetStaff(string id, string pass)
{
    Staff node;
    node.SetID(id);
    node.SetPass(pass);
    return node;
}   



void MenuLogin()
{
    cout << "\t\t+------------------------     Dang nhap     -------------------------+" << endl;
    cout << "\t\t|                                                                    |" << endl;
    cout << "\t\t|                      1.  Quan tri vien                             |" << endl;
    cout << "\t\t|                      2.  Khach hang                                |" << endl;
    cout << "\t\t|                      3.  Chua co tai khoan                         |" << endl;
    cout << "\t\t|                      4.  Thoat                                     |" << endl;
    cout << "\t\t+---------------------------------------------------------------------" << endl;
}

void MenuAdmin()
{
    cout << "\t\t+------------------------     Admin         -------------------------+" << endl;
    cout << "\t\t|                                                                    |" << endl;
    cout << "\t\t|                      1.  Quan li san pham                          |" << endl;
    cout << "\t\t|                      3.  Quan li khach hang                        |" << endl;
    cout << "\t\t|                      4.  Quan li hoa don                           |" << endl;
    cout << "\t\t|                      5.  Thoat                                     |" << endl;
    cout << "\t\t+---------------------------------------------------------------------" << endl;
}

void MenuCustomer()
{
    cout << "\t\t+------------------------     Khach hang    -------------------------+" << endl;
    cout << "\t\t|                                                                    |" << endl;
    cout << "\t\t|                      1.  Danh sach san pham                        |" << endl;
    cout << "\t\t|                      2.  Gio hang                                  |" << endl;
    cout << "\t\t|                      3.  Hoa don                                   |" << endl;
    cout << "\t\t|                      4.  Thoat                                     |" << endl;
    cout << "\t\t+---------------------------------------------------------------------" << endl;
}

bool CheckAdmin(string id, string pass)
{
    for (int i = 0; i < ::ListAdmin.Getsize(); i++)
    {
        if (::ListAdmin.Getindex(i).getUser().compare(id) == 0)
        {
            if (::ListAdmin.Getindex(i).getPass().compare(pass) == 0)
                return true;
        }
    }
    return false;
}

bool CheckCustomers(string id, string pass)
{
    for (int i = 0; i < ::ListStaff.Getsize(); i++)
    {
        if (::ListStaff.Getindex(i).GetID().compare(id) == 0)
        {
            if (::ListStaff.Getindex(i).GetPass().compare(pass) == 0)
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
fstream File;
template <class T>
void CreateRepo(Element<T> &element, string str, T Func(string, string))
{
    char *x = new char[str.size() - 1];
    for (int i = 0; i < str.size(); i++)
    {
        *(x + i) = str[i];
    }
    File.open(x, ios ::in);
    string s;
    while (!File.eof())
    {
        getline(File, s);
        // File.ignore(1, '\n');
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

        T node = Func(id, pass);
        element.Add(node);
    }
    File.close();
    delete x;
}

void Handle()
{
    MenuLogin();
    int button;
    cin >> button;
    if(button == 1)
    {
        while (true)
        {
            if (Login(1) == 0)
            {
                cout << "Tai khoan hoac mat khau sai! Ban co muon nhap lai khong Y/N\n";
                char var;
                cin >> var;
                if(var == 'Y' || var == 'y') continue;
                else exit(1);
            }
            else break;
        }
        while(true)
        {
            MenuAdmin();
            int buttonAdmin;
            cin >> buttonAdmin;
            if (buttonAdmin == 1)
            {   
                while(true)
                {
                cout << "\t\t+------------------------ Quan li san pham  -------------------------+" << endl;
                cout << "\t\t|                                                                    |" << endl;
                cout << "\t\t|                      1.  Danh sach san pham                        |" << endl;
                cout << "\t\t|                      2.  Them san pham                             |" << endl;
                cout << "\t\t|                      3.  Xoa san pham                              |" << endl;
                cout << "\t\t|                      4.  Doanh thu                                 |" << endl;
                cout << "\t\t|                      5.  ////////////                              |" << endl;
                cout << "\t\t|                      6.  Danh sach khach hang                      |" << endl;
                cout << "\t\t|                      7.  Thoat                                     |" << endl;
                cout << "\t\t+---------------------------------------------------------------------" << endl;
                int choose;
                cin >> choose;
                if(choose == 1)
                {
                    cout << "Danh sach san pham:\n";
                    cout << setw(3) << "STT" << "\t\t" << "ID" << "\t" << setw(20) << "Ten" << "\t" << setw(20) << "Nha san xuat"
                        << "\t" << setw(10) << "Kich thuoc" << "\t" << setw(15) << "Loai giay" << "\t" << setw(20) << "Gia" << endl;
                    cout << Products;
                }
                else if (choose == 2)
                {
                    Product x;
                    cin >> x;
                    Products.AddLast(x);
                }
                else if (choose == 3)
                {
                    int k;
                    cout << "Moi nhap stt san pham can xoa: ";
                    cin >> k;
                    Products.DeleteIndexK(k);
                }
                else if (choose == 4)
                {
                    // cộng tất cả các hoá đơn của khách hàng
                }
                else if (choose == 5)
                {
                    Products.SortASC(0, Products.GetSize(),ASC);
                }
                else if(choose == 6)
                {

                }
                else if(choose == 7)
                {
                    break;
                }
                }
            }
        }
    }
}
int main()
{
    CreateRepo(::ListAdmin, "account.txt", GetAdmin);
    CreateRepo(::ListStaff, "account01.txt", GetStaff);
    Handle();
    //  cout << Login(1);
    //  cout << Login(2);
    // cout << "\n";
    // cout <<"Staff:" <<  ListStaff.Getsize();
    // cout << "Admin:" << ListAdmin.Getsize();
}