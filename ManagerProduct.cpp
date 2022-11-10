#include "ManagerProduct.h"

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
    while (after != NULL )
    {
        string str = after->GetData().GetID();
        if(!id.compare(str))
        {
            flag = 1;
            break;
        }

        before = after;
        after = after->GetPnext();
    }
    if(flag == 1)
    {
        if (after != NULL)
        {
            if (after == products.GetPhead())
                products.SetPhead(after->GetPnext());
            else
            before->SetPnext(after->GetPnext());
            delete after;
        }
    }
    else
    {
        cout << "khong tim thay id!" << endl;
    }
    before = new NodeData<Product>;
    delete before;
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
        cin >> name;
        node.SetName(name);
        fflush(stdin);
        cout << "Moi nhap nha san xuat: ";
        cin >> manufacturer;
        node.SetManufacturer(manufacturer);
        fflush(stdin);
        cout << "Moi nhap loai giay: ";
        cin >> type;
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
    while (p != NULL)
    {
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
    float price;
    int amount;
    Product node;
    fflush(stdin);
    cout << "Moi nhap ID:";
    cin >> ID;
    node.SetID(ID);
    fflush(stdin);
    cout << "Moi nhap ten: ";
    cin >> name;
    node.SetName(name);
    fflush(stdin);
    cout << "Moi nhap nha san xuat: ";
    cin >> manufacturer;
    node.SetManufacturer(manufacturer);
    fflush(stdin);
    cout << "Moi nhap loai giay: ";
    cin >> type;
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

    products.Add(node);
}

void ManagerProduct::Show()
{
    int size = products.GetSize();
    if(size == 0) cout << "Danh sach rong!" << endl;
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << products.GetIndex(i);
        }
    }
    
}
ManagerProduct::~ManagerProduct()
{
}
