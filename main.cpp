#include "Element.h"
#include "conio.h"
#include "fstream"
ManagerProduct Products;
Element<admin> ListAdmin;
Element<Customers> ListCustomer;
Element<Bill> Bills;
string user;
fstream fi;


void Layhoadon();
bool ASC(string a, string b)
{
    return a.compare(b) >= 0;
}

void AddProductFile()
{
    fstream fo;
    fo.open("products.txt", ios::out);
    for (int i = 0; i < Products.GetSize(); i++)
    {
        fo << Products.Getindex(i).GetID() << " " << Products.Getindex(i).GetName() << " " << Products.Getindex(i).GetSize() << " " << Products.Getindex(i).GetPrice() << " " << Products.Getindex(i).GetType() << " " << Products.Getindex(i).GetManufacturer();
        if (i < Products.GetSize() - 1) fo << "\n";
    }
}

admin GetAdmin(string user, string pass)
{
    admin node;
    node.setuser(user);
    node.setpass(pass);
    return node;
}

Customers GetCustomers(string id, string pass, string name, string sex, string phonenb, string address)
{
    Customers node;
    node.SetID(id);
    node.SetPass(pass);
    node.Set_Name(name);
    node.Set_Sex(sex);
    node.Set_PhoneNumber(phonenb);
    node.Set_Address(address);
    return node;
}

Product GetProduct(string id, string name, int Size, double Price, string type, string manu)
{
    Product node;
    node.SetID(id);
    node.SetName(name);
    node.SetSize(Size);
    node.SetPrice(Price);
    node.SetType(type);
    node.SetManufacturer(manu);
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
    cout << "\t\t|                      2.  Quan li khach hang                        |" << endl;
    cout << "\t\t|                      3.  Quan li hoa don                           |" << endl;
    cout << "\t\t|                      4.  Thoat                                     |" << endl;
    cout << "\t\t+---------------------------------------------------------------------" << endl;
}

void ManagerBill()
{
    cout << "\t\t+------------------------ Quan li hoa don  -------------------------+" << endl;
    cout << "\t\t|                                                                    |" << endl;
    cout << "\t\t|                      1.  Danh sach hoa don                         |" << endl;
    cout << "\t\t|                      2.  Xoa hoa don                               |" << endl;
    cout << "\t\t|                      3.  Tim kiem hoa don                          |" << endl;
    cout << "\t\t|                      4.  Thoat                                     |" << endl;
    cout << "\t\t+---------------------------------------------------------------------" << endl;
}

void MenuCustomer()
{
    cout << "\t\t+------------------------     Khach hang    -------------------------+" << endl;
    cout << "\t\t|                                                                    |" << endl;
    cout << "\t\t|                      1.  Mua hang                                  |" << endl;
    //cout << "\t\t|                      2.  Hoa don                                   |" << endl;
    // cout << "\t\t|                      3.  Hoa don                                   |" << endl;
    cout << "\t\t|                      2.  Thoat                                     |" << endl;
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
    for (int i = 0; i < ::ListCustomer.Getsize(); i++)
    {
        if (::ListCustomer.Getindex(i).GetID().compare(id) == 0)
        {
            if (::ListCustomer.Getindex(i).GetPass().compare(pass) == 0)
                return true;
        }
    }
    return false;
}

bool Login(int flag)
{
    string pass;
    fflush(stdin);
    cout << "Moi nhap user: ";
    getline(cin, ::user);
    cout << "Moi nhap mat khau: ";
    getline(cin, pass);

    
    if (flag == 1)
    {
        if (CheckAdmin(::user, pass) == true)
        {
            return true;
        }
    }
    else if (flag == 2)
    {
        if (CheckCustomers(::user, pass) == true)
        {
            return true;
        }
    }
     return false;
}
void Xuathoadon();
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
    cout << "\t\t+------------------ Chuong trinh quan li ban giay  -------------------+" << endl;
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
            else
            {
                cout << "Dang nhap thanh cong!" << endl;
                break;
            } 
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
                cout << "\t\t|                      5.  Sap xep san pham                          |" << endl;
                cout << "\t\t|                      6.  Tim kiem san pham                         |" << endl;
                cout << "\t\t|                      7.  Cap nhat san pham                         |" << endl;
                cout << "\t\t|                      8.  Thoat                                     |" << endl;
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
                    long long sum = 0;
                    for(int i = 0; i < Bills.Getsize(); i++)
                    {
                        sum+= Bills.Getindex(i).GetSumPrice();
                    }
                    cout << "\t\t+---------------------------------------------------------------------" << endl;
                    cout << "\t\t\t\t\t" << "Doanh thu :" << sum << endl;
                    cout << "\t\t+---------------------------------------------------------------------" << endl;
                }
                else if (choose == 5)
                {
                    Products.SortASC(0, Products.GetSize() - 1);
                }
                else if(choose == 6)
                {
                    string name;
                    cout << "Moi nhap ten san pham can tim kiem:";
                    fflush(stdin);
                    getline(cin, name);
                    cout << setw(3) << "STT"
                         << "\t\t"
                         << "ID"
                         << "\t" << setw(20) << "Ten"
                         << "\t" << setw(20) << "Nha san xuat"
                         << "\t" << setw(10) << "Kich thuoc"
                         << "\t" << setw(15) << "Loai giay"
                         << "\t" << setw(20) << "Gia" << endl;
                    Products.Search(name);
                }
                else if (choose == 7)
                {
                    string id;
                    fflush(stdin);
                    cout << "Moi nhap ID can thay doi:";
                    cin >> id;
                    bool flag = Products.Update(id);
                    if(flag == true) cout << "Cap nhat thanh cong!" << endl;
                    else cout << "Cap nhat that bai xin kiem tra lai!" << endl;
                }
                else if (choose == 8)
                {
                    AddProductFile();
                    break;
                }

                }
            }
            else if (buttonAdmin == 2)
            {
                //quan li khach hang - xuat danh sach khach hang
                cout << "ID" << "\t" << "Ten" << "\t" << "Gioi tinh" << "\t" << "SDT" << "\t" << "Dia chi" << endl;

                for(int i = 0; i < ListCustomer.Getsize(); i++)
                {
                    cout << ListCustomer.Getindex(i);
                }
            }
            else if (buttonAdmin == 3)
            {
                int n;
                while(true)
                {
                    ManagerBill();
                    cin >> n;
                    if(n == 1)
                    {
                        for(int i = 0; i < Bills.Getsize(); i++)
                        {
                            Bills.Getindex(i).Show();
                        }
                    }
                    else if(n == 2)
                    {
                        int k;
                        cout << "Moi nhap stt hoa don can xoa:";
                        cin >> k;
                        Bills.Delete(k);
                    }
                    else if(n == 3)
                    {
                        string idb;int flag = 0;
                        fflush(stdin);
                        cout << "Moi nhap IDB can tim:";
                        getline(cin, idb);
                        for (int i = 0; i < Bills.Getsize(); i++)
                        {
                            if(Bills.Getindex(i).GetIDB().compare(idb) == 0)
                            {
                                flag = 1;
                                Bills.Getindex(i).Show();
                            }
                        }
                        if(flag == 0) cout << "Khong tim thay Bill!\n";
                    }
                    else if(n == 4) break;
                }
                Xuathoadon();
            }
            else if (buttonAdmin == 4) break;
        }
    }
    else if (button == 2)
    {
        while(true)
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
                cout << "Dang nhap thanh cong!\n";
                break;
            }
        }

        while(true)
        {
            MenuCustomer();
            int n;
            int index = -1;
            cin >> n;
            if (n == 1)
            {
                cout << "Danh sach san pham:\n";
                cout << setw(3) << "STT"
                    << "\t\t"
                    << "ID"
                    << "\t" << setw(20) << "Ten"
                    << "\t" << setw(20) << "Nha san xuat"
                    << "\t" << setw(10) << "Kich thuoc"
                    << "\t" << setw(15) << "Loai giay"
                    << "\t" << setw(20) << "Gia" << endl;
                cout << Products;
                for(int i = 0; i < ListCustomer.Getsize(); i++)
                {
                    if(::user.compare(ListCustomer.Getindex(i).GetID()) == 0)
                    {
                        index = i;
                        break;
                    }
                }
                Bills.Add(ListCustomer.Getindex(index).Buy(Products));

                cout << "\t+-----------------------------Hoa don---------------------------------" << endl;
                Bills.Getindex(Bills.Getsize() - 1).Show();
                cout <<"\t\t"<< setw(15) << "Ten" << "\t\t" << setw(15) << "Gia" << endl;
                ListCustomer.Getindex(index).ShowItems();
                cout << "\t+---------------------------------------------------------------------" << endl;
                cout << " Hen gap lai!";
                Xuathoadon();
                return;
           }
           else if(n == 2)
           {
                cout << "Hen gap lai!\n";
                return;
           }

        }
    }
    else if (button == 3) cout << "vui long lien he nhan vien de duoc cap tai khoan!" << endl;
    else if (button == 4)
    {
        cout << "Tam biet !";
    }
}
void Xuathoadon()
{
    fstream fo;
    fo.open("In4Bill.txt", ios::out);
    for (int i=0;i<Bills.Getsize();i++)
    {
        fo<<"Ma hoa don: "<<Bills.Getindex(i).GetIDB()<<'\n';
        fo << "Ngay Thang Nam thanh toan: " << Bills.Getindex(i).GetDay() << "/" << Bills.Getindex(i).GetMonth() << "/" << Bills.Getindex(i).GetYear()<<'\n';
        fo << "Ma khach hang: " << Bills.Getindex(i).GetIDC() << '\n';
        fo << "Ten khach hang: " << Bills.Getindex(i).GetNameCustomer() << '\n';
        fo << "Tong tien: "<<Bills.Getindex(i).GetSumPrice();
        if (Bills.Getsize()-1 > i) cout << "\n";
    }
}

void Create()
{
    CreateRepo(::ListAdmin, "account.txt", GetAdmin);
    Layhoadon();
    File.open("account01.txt", ios ::in);
    while (!File.eof())
    {
        string up, name, sex, phone, address;
        File >> up;
        File >> name;
        File >> sex;
        File >> phone;
        getline(File, address);
        string id = "", pass = "";
        int pos;
        for (int i = 0; i < up.size(); i++)
        {
           if (up[i] == '|')
           {
                pos = i;
                break;
           }
        }
        for (int i = 0; i < pos; i++)
           id += up[i];
        for (int i = pos + 1; i < up.size(); i++)
           pass += up[i];

        Customers x;
        x = GetCustomers(id, pass, name, sex, phone, address);
        ListCustomer.Add(x);
    }
    File.close();

    File.open("products.txt", ios ::in);
    while (!File.eof())
    {
        string id, name, manu, type;
        int size;
        double price;
        File >> id;
        File >> name;
        File >> size;
        File >> price;
        File >> type;
        getline(File, manu);
        Product x;
        x = GetProduct(id, name, size, price, type, manu);
        Products.AddLast(x);
    }
    File.close();
}

void Layhoadon()
{
    fi.open("In4Bill.txt", ios::in);
    int cnt=0;
    Bill x;
    while (!fi.eof())
    {
        string str;
        getline(fi,str);
        cnt++;
        int pos=-1;
        for (int i=0;i<str.size();i++)
        {
            if (str[i]==':') 
            {
                pos=i;
                break;
            }
        };
        string need="";
        string d = "", m = "", y = "";
        int dd = 0, mm = 0, yy = 0;
        for (int i=pos+2;i<str.size();i++)
          need+=str[i];
        if (cnt==1) x.SetIDB(need);
        if (cnt==2)
        {
            int pos1,pos2;
            int dem=0;
            for (int i=0;i<need.size();i++)
            {
                if (need[i]=='/') {dem++;
                if (dem==1) pos1=i;
                if (dem==2) pos2=i;}
            }
            for (int i=0;i<pos1;i++)
              d+=need[i];
            for (int i=pos1+1;i<pos2;i++)
              m+=need[i];
            for (int i=pos2+1;i<need.size();i++)
              y+=need[i];
            for (int i=0;i<d.size();i++)
              {
                dd=dd*10+(d[i]-'0');
              }
            for (int i=0;i<m.size();i++)
              {
                mm=mm*10+(m[i]-'0');
              }
            for (int i=0;i<y.size();i++)
            {
                yy=yy*10+(y[i]-'0');
            }
            x.SetDay(dd);
            x.SetMonth(mm);
            x.SetYear(yy);
        } 
        if (cnt==3) x.SetIDC(need);
        if (cnt==4) x.SetNameCustomer(need);
        if (cnt==5) 
        {
            int sum=0;
            for (int i=0;i<need.size();i++)
             sum=sum*10+(need[i]-'0');
            x.SetSumPrice(sum);
            //cout << x.GetDay() << " " << x.GetMonth() << " " << x.GetYear() << '\n';
            Bills.Add(x);
            cnt=0;
        }
    }
       
}
int main()
{
    Create();
    Handle();
}