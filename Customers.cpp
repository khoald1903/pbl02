#include "Customers.h"

Customers::Customers()
{

}

Customers::Customers(string id, string pass, string name, string addr, string sex, string phonenb)
{
    this->ID = id;
    this->Pass = pass;
    this->Name = name;
    this->Address = addr;
    this->Sex = sex;
    this->PhoneNumber = phonenb;
}

Customers::~Customers()
{
    
}

int Customers::SumPrice()
{
    int sum = 0;
    int size = cart.GetSize();
    for (int i = 0; i < size; i++)
    {
        sum += cart.Getindex(i).GetPrice() * cart.Getindex(i).GetAmount();
    }
    return sum;
}
void Customers::DeleteAll()
{
    
}
//giải phóng giỏ hàng, check hàng đã tồn tại trong giỏ
Bill Customers::Buy(ManagerProduct products, int size)
{
    products.Show();
    cout << "Moi chon mat hang can mua:" << endl;
    string id;
    int amount = 0;
    Product node;
    while (true)
    {
        fflush(stdin);
        cout << "Moi nhap ID san pham can mua hoac nhap -1 de thanh toan: ";
        getline(cin, id);
        if (id == "-1")
            break;

        Product p = products.Search(id);
        if (p.GetID() == "NULL")
        {
            cout << "Khong tim thay ID san pham! Moi nhap lai " << endl;
            continue;
        }
        while(true)
        {
            cout << "Nhap so luong can mua: ";
            cin >> amount;
            if(amount <= 0 )
            {
                cout << "So luong ban nhap khong hop le moi nhap lai!\n";
            }
            else break;
        }


        int available = p.GetAmount();
        if (available - amount >= 0)
        {
            int flag = 0;
            int size = cart.GetSize();
            for (int i = 0; i < size; i++)
            {
                if (cart.Getindex(i).GetID().compare(id) == 0)
                {
                    cart.ReSetAmount(id, cart.Getindex(i).GetAmount() + amount);
                    products.ReSetAmount(id, available - amount);
                    flag = 1;
                    break;
                }
            }
            if (flag != 1)
            {
                node = p;
                node.SetAmount(amount);
                cart.AddLast(node);
                products.ReSetAmount(id, available - amount);
            }
        }
        else
        {
            cout << "So luong san pham con lai khong du!";
        }
    }

    time_t hientai = time(0);
    tm *dt = localtime(&hientai);

    Bill temp;
    temp.SetDay(dt->tm_mday);
    temp.SetMonth(dt->tm_mon + 1);
    temp.SetYear(dt->tm_year + 1900);
    temp.SetNameCustomer(this->Name);
    temp.SetIDC(this->ID);
    temp.SetPhoneNB(this->PhoneNumber);
    temp.SetIDB(this->Name + to_string(size));
    
    int sizeCart = cart.GetSize();
    for (int i = 0; i < sizeCart; i++)
    {
        temp.Add(cart.Getindex(i));
    }
    temp.SetSumPrice(SumPrice());
    cart.DeleteAll();
    return temp;

}

void Customers::Show()
{
    cout << "\t\t\t" << setw(10) << this->ID
         << "\t"
         << setw(20) << this->Name
         << "\t\t"
         << setw(3) << this->Sex
         << "\t"
         << setw(10) << this->PhoneNumber
         << setw(20) << this->Address
         << "\t\t" << setw(10) << this->Pass << endl;
}