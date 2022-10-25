#include "Element.h"
Element<admin> ListAdmin;
Element<Staff> ListStaff;
ofstream outfile;
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

template <class T>
void CreateRepo(Element<T> &element, string str, T Func(string, string),fstream &File)
{
    char *x = new char[str.size() - 1];
    for (int i=0;i<str.size();i++)
    {
        *(x+i)=str[i];
    }
    File.open(x, ios ::in);
    string s;
    while (!File.eof())
    {
        getline(File,s);
        File.ignore(1, '\n');
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
}

int main()
{
    outfile.open("file.out", ios::out);
    fstream fAdmin;
    CreateRepo(::ListAdmin, "account01.txt", GetAdmin, fAdmin);
    for (int i = 0; i < ::ListAdmin.Getsize(); i++)
    {
        outfile << ::ListAdmin.Getindex(i).getUser();
        outfile << endl;
    }
    fstream fStaff;
    CreateRepo(::ListStaff, "account.txt", GetStaff,fStaff);
    for (int i = 0; i < ::ListStaff.Getsize(); i++)
    {
        outfile << ::ListStaff.Getindex(i).GetID();
        outfile << endl;
    }
    outfile.close();
}