#include "Element.h"


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

ostream &operator<<(ostream &out, Staff staff)
{
    out << staff.GetID() << staff.GetPass() << endl;
    return out;
}

template <class T>
void CreateRepo(Element<T> &element, string str, T Func(string, string))
{
    char *x = new char[str.size() - 1];
    for (int i=0;i<str.size();i++)
    {
        *(x+i)=str[i];
    }
    FILE* f = freopen(x, "r", stdin);
    string s;
    while (cin >> s)
    {
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
    fclose(f);
}

int main()
{
    Element<Staff> list01;
    CreateRepo(list01, "account01.txt", GetStaff);
    for (int i = 0; i < list01.Getsize(); i++)
    {
        cout << list01.Getindex(i);
        cout << endl;
    }

    Element<admin> list;
    CreateRepo(list, "account.txt", GetAdmin);
    for (int i = 0; i < list.Getsize(); i++)
    {
        cout << list.Getindex(i).getUser();
        cout << endl;
    }
}