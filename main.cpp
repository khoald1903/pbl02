#include "Element.cpp"

admin Get(string user, string pass)
{
    admin node;
    node.setuser(user);
    node.setpass(pass);
    return node;
}

template <class T>
void CreateRepo(Element<T> &element, string str, T Func(string, string))
{
    char *x = new char[str.size() - 1];
    for (int i=0;i<str.size();i++)
    {
        *(x+i)=str[i];
    }
    freopen(x, "r", stdin);
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
}

int main()
{
    
    Element<admin> list;
    CreateRepo( list,"account.txt", Get);
    for (int i = 0; i < list.Getsize(); i++)
    {
        cout << list.Getindex(i).getUser();
        cout << endl;
    }
}