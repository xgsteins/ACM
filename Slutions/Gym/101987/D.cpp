#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, flag = 0;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        string tmp = s.substr(s.size() - 1, 1);
        if (tmp == "a")
        {
            flag = 1;
            cout << s.substr(0, s.size() - 1) + "as" << endl;
        }
        else if (tmp == "i" || tmp == "y")
        {
            flag = 1;
            cout << s.substr(0, s.size() - 1) + "ios" << endl;
        }
        else if (tmp == "l")
        {
            flag = 1;
            cout << s.substr(0, s.size() - 1) + "les" << endl;
        }
        else if (tmp == "n")
        {
            flag = 1;
            cout << s.substr(0, s.size() - 1) + "anes" << endl;
        }
        else if(s.substr(s.size() - 2, 2) == "ne")
        {
            cout << s.substr(0, s.size() - 2)+"anes" << endl;
        }
        else if(tmp == "o")
        {
            flag = 1;
            cout << s.substr(0, s.size() - 1) + "os" << endl;
        }
        else if(tmp == "r")
        {
            flag = 1;
            cout << s.substr(0, s.size() - 1) + "res" << endl;
        }
        else if(tmp == "t")
        {
            flag = 1;
            cout << s.substr(0, s.size() - 1) + "tas" << endl;
        }
        else if(tmp == "u")
        {
            flag = 1;
            cout << s.substr(0, s.size() - 1) + "us" << endl;
        }
        else if(tmp == "v")
        {
            flag = 1;
            cout << s.substr(0, s.size() - 1) + "ves" << endl;
        }
        else if(tmp == "w")
        {
            flag = 1;
            cout << s.substr(0, s.size() - 1) + "was" << endl;
        }
        else
        {
            cout << s+"us" << endl;
        }
        
    }
}