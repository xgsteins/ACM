#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a = 0, b = 0;
    string s;
    cin >> n >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '0') a++;
        else            b++;
    }
    if(a != b)
    {
        cout << 1 << endl << s << endl;
    }
    else
    {
        cout << 2 << endl;
        cout << s[0] << ' ';
        for(int i = 1; i < s.size(); i++)   cout << s[i];
        puts("");
    }
}