// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     freopen("list.inp", "r", stdin);
//     freopen("list.out", "w", stdout);
//     string s;
//     while (cin >> s)
//     {
//         string id = "", pass = "";
//         int pos;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] == '|')
//             {
//                 pos = i;
//                 break;
//             }
//         }
//         for (int i = 0; i < pos; i++)
//             id += s[i];
//         for (int i = pos + 1; i < s.size(); i++)
//             pass += s[i];
//         cout << "ID la: " << id << '\n';
//         cout << "Pass la: " << pass << '\n';
//     }
// }