#include "Customers.h"

Customers::Customers()
{

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
        cin >> id;
        if (id == "-1") break;



        Product p = products.Search(id);
         if (p.GetID() == "NULL")
        {
                cout << "Khong tim thay ID san pham! Moi nhap lai " << endl;
                continue;
        }
        cout << "Nhap so luong can mua: ";
        cin >> amount;

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
                if(flag != 1) 
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
    //Bill 
    // quăng ra cái bill sau đó xoá toàn bộ 

}