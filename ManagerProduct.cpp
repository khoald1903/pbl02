#include "ManagerProduct.h"
#include "fstream"
#include <unistd.h>
ManagerProduct::ManagerProduct()
{
}

Product ManagerProduct::Getindex(int index)
{
    return products.GetIndex(index);
}

void ManagerProduct::ReSetAmount(string id, int amount)
{
    NodeData<Product> *q;
    q = products.GetPhead();
    while (q != NULL)
    {
        if (id.compare(q->GetData().GetID()) == 0)
        {
            Product temp = q->GetData();
            temp.SetAmount(amount);
            q->SetData(temp);
            break;
        }
        q = q->GetPnext();
    }
    q = new NodeData<Product>;
    delete q;
}

int ManagerProduct::GetSize()
{
    return products.GetSize();
}

void ManagerProduct::AddIndexK(Product product, int k)
{
    products.AddIndex(k, product);
}

void ManagerProduct::AddLast(Product product)
{
    products.Add(product);
}

void ManagerProduct::DeleteID(string id)
{
    NodeData<Product> *before, *after;
    after = products.GetPhead();
    int flag = 0;
    while (after != NULL)
    {
        string str = after->GetData().GetID();
        if (!id.compare(str))
        {
            flag = 1;
            break;
        }

        before = after;
        after = after->GetPnext();
    }
    if (flag == 1)
    {
        if (after != NULL)
        {
            if (after == products.GetPhead())
                products.SetPhead(after->GetPnext());
            else
            {
                before->SetPnext(after->GetPnext());
                after->SetPnext(new NodeData<Product>);
                delete after;
            }
        }
        cout << "\t\t\t\t\tThanh cong!" << endl;
    }
    else
    {
        cout << "\t\t\t\t\tKhong tim thay id!" << endl;
    }
    before = new NodeData<Product>;
    delete before;
    sleep(1);
}
void ManagerProduct::DeleteIndexK(int k)
{
    products.DeleteIndex(k);
}

void ManagerProduct::DeleteAll()
{
    int size = products.GetSize();
    for(int i = size - 1; i>=0; i--)
    {
        DeleteID(products.GetIndex(i).GetID());
    }
}
bool ManagerProduct::Update(string id)
{
    bool flag = false;
    NodeData<Product> *p;
    p = products.GetPhead();
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
        Product node;
        string ID;
        string name, manufacturer, type;
        int size;
        float price;
        int amount;
        node.SetID(p->GetData().GetID());
        fflush(stdin);
        cout << "Moi nhap ten moi: ";
        getline(cin,name);
        node.SetName(name);
        fflush(stdin);
        cout << "Moi nhap nha san xuat: ";
        getline(cin,manufacturer);
        node.SetManufacturer(manufacturer);
        fflush(stdin);
        cout << "Moi nhap loai giay: ";
        getline(cin,type);
        node.SetType(type);
        fflush(stdin);
        cout << "Moi nhap size: ";
        cin >> size;
        node.SetSize(size);
        fflush(stdin);
        cout << "Moi nhap gia: ";
        cin >> price;
        node.SetPrice(price);
        fflush(stdin);
        cout << "Moi nhap so luong:";
        cin >> amount;
        node.SetAmount(amount);
        p->SetData(node);
        p = new NodeData<Product>;
        delete p;
    }
    return flag;
}

void ManagerProduct::SortASC()
{
    NodeData<Product> *p;
    NodeData<Product> *q;
    NodeData<Product> *min;
    NodeData<Product> *tmp;
    p = products.GetPhead();
    while (p != NULL) //1 
    {  //2  - n 
        for (q = p->GetPnext(); q != NULL; q = q->GetPnext())
        {
            if (p->GetData().GetPrice() > q->GetData().GetPrice())
            {
            Product a = p->GetData();
            Product b = q->GetData();
            p->SetData(b);
            q->SetData(a);
            }
        }
        p = p->GetPnext();
    }
    cout << "\t\t\t\t\tSap xep thanh cong!" << endl;sleep(1);
}

Product ManagerProduct::Search(string ID)
{
    static Product trash;
    trash.SetID("NULL");
    if(products.GetSize() == 0) return trash;
    NodeData<Product> *p;
    p = products.GetPhead();
    int flag = 0;
    while( p != NULL )
    {
        if(ID.compare(p->GetData().GetID()) == 0)
        {
            flag = 1;
            break;
        }
        p = p->GetPnext();
    }
    if(flag == 0)
    {
        //cout << "Khong tim thay san pham co ID: " << ID << endl;
        p = new NodeData<Product>;
        delete p;
        return trash;
    }
    else
    {
        Product x = p->GetData();
        p = new NodeData<Product>;
        delete p;
        return x;
    }
    
}

void ManagerProduct::Add()
{
    string ID;
    string name, manufacturer, type;
    int size;
    long long price, importprice;
    int amount;

    Product node;
    fflush(stdin);
    int Psize = products.GetSize(), flag = 0;
    
    cout << "Moi nhap ID:";
    getline(cin, ID);
    
        for (int i = 0; i < Psize; i++)
        {
            if (!products.GetIndex(i).GetID().compare(ID))
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "ID san pham da ton tai khong the them!" << endl;
        }
        else
        {
            
    

    node.SetID(ID);
    fflush(stdin);
    cout << "Moi nhap ten: ";
    getline(cin, name);
    node.SetName(name);
    fflush(stdin);
    cout << "Moi nhap nha san xuat: ";
    getline(cin, manufacturer);
    node.SetManufacturer(manufacturer);
    fflush(stdin);
    cout << "Moi nhap loai giay: ";
    getline(cin, type);
    node.SetType(type);
    fflush(stdin);
    cout << "Moi nhap size: ";
    cin >> size;
    node.SetSize(size);
    fflush(stdin);
    cout << "Moi nhap gia: ";
    cin >> price;
    node.SetPrice(price);
    fflush(stdin);
    cout << "Moi nhap so luong:";
    cin >> amount;
    node.SetAmount(amount);
    fflush(stdin);
    cout << "Moi nhap gia nhap cua 1 san pham:";
    cin >> importprice;
    node.SetImportPrice(importprice);
    products.Add(node);
    cout << "\t\t\t\t\tThem thanh cong!";
        sleep(1);
    }
}

void ManagerProduct::Show()
{
    int size = products.GetSize();
    if(size == 0) cout << "Danh sach rong!" << endl;
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
        for (int i = 0; i < size; i++)
        {
                cout << products.GetIndex(i);
                cout << str2;
    }
    cout << str1;
    }



    // for (int i = 0; i < 33; i++)
    //     cout << char(205);
    // cout << char(187) << endl;
    // cout << setw(28) << " " << char(186) << "       1. Dang nhap.             " << char(186) << endl;
    // cout << setw(28) << " " << char(186) << "       0. Thoat.                 " << char(186) << endl;
    // cout << setw(28) << " " << char(200);
    // for (int i = 0; i < 33; i++)
    //     cout << char(205);
    // cout << char(188) << endl;
}

void ManagerProduct::Show2()
{
    cout << "\t\t\t\t _____              _                      _                               _                     " << endl;
    cout << "\t\t\t\t|  __ \\            | |                    | |                             | |                    " << endl;
    cout << "\t\t\t\t| |  | | __ _ _ __ | |__    ___  __ _  ___| |__    ___  __ _ _ __    _ __ | |__   __ _ _ __ ___  " << endl;
    cout << "\t\t\t\t| |  | |/ _` | '_ \\| '_ \\  / __|/ _` |/ __| '_ \\  / __|/ _` | '_ \\  | '_ \\| '_ \\ / _` | '_ ` _ \\ " << endl;
    cout << "\t\t\t\t| |__| | (_| | | | | | | | \\__ \\ (_| | (__| | | | \\__ \\ (_| | | | | | |_) | | | | (_| | | | | | |" << endl;
    cout << "\t\t\t\t|_____/ \\__,_|_| |_|_| |_| |___/\\__,_|\\___|_| |_| |___/\\__,_|_| |_| | .__/|_| |_|\\__,_|_| |_| |_|" << endl;
    cout << "\t\t\t\t                                                                    | |                          " << endl;
    cout << "\t\t\t\t                                                                    |_|                          " << endl;

    string str1 = "****************************************************************************************************************************************************\n";
    string str2 = "+-----------+-------------------------------+--------------+-----------------+-----------------+----------+----------+------------+----------------+\n";
    cout << str1;
    cout << "|" << setw(10) << "ID"
         << "\t" << setw(20) << "TenSP"
         << "\t" << setw(20) << "NSX"
         << "\t\t" << setw(2) << "Kich co"
         << "\t" << setw(15) << "Loai giay"
         << "\t" << setw(20) << "Gia tien"
         << "\t" << setw(10) << "So luong" << "\t" << " Gia nhap  |"  << endl;
    cout << str1;
    int size = products.GetSize();
    for (int i = 0; i < size; i++)
    {
    cout << "|" << setw(10) << products.GetIndex(i).GetID() << "\t" << setw(20) << products.GetIndex(i).GetName() << "\t" << setw(20) << products.GetIndex(i).GetManufacturer()
         << "\t\t" << setw(2) << products.GetIndex(i).GetSize() << "\t" << setw(15) << products.GetIndex(i).GetType() << "\t" << setw(20) << products.GetIndex(i).GetPrice() << "\t" << setw(10) << products.GetIndex(i).GetAmount() << "\t" << setw(10) << products.GetIndex(i).GetImportPrice() << " |" << endl;
    cout << str2;
    }
    cout << str1;
}

fstream FO;
void ManagerProduct::ShowFile()
{
    FO.open("products.txt", ios::out);
    int size = products.GetSize();
        for (int i = 0; i < size; i++)
        {
    FO << products.GetIndex(i).GetID() << "|" << products.GetIndex(i).GetName() << "|" << products.GetIndex(i).GetSize() << "|"
       << products.GetIndex(i).GetPrice() << "|" << products.GetIndex(i).GetType() << "|" << products.GetIndex(i).GetAmount() << "|" << products.GetIndex(i).GetManufacturer() << "|" << products.GetIndex(i).GetImportPrice();
    if (i < size - 1)
        FO << '\n';
        }
    FO.close();
}

ManagerProduct::~ManagerProduct()
{
}
