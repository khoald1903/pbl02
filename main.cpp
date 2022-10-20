#include "List.cpp"


int main()
{
    List<admin> l;
    admin x("dsada", "sadsadsad");
    admin y("nhucc", "cailon");
    admin z("nhucc", "cailon");
    l.Add(x);
    l.Add(y);
    l.Add(z);
    l.Delete(1);
    for(int i = 0; i<l.Getsize();i++)
    {
        l.Getindex(i).show();
        cout<<endl;
    }
}