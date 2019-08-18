#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s[3];
    for(int i = 0; i < 3; i++)  cin >> s[i];
    sort(s, s+3);
    if(s[0] == s[1] && s[1] == s[2])
    {
        puts("0");
    }
    else
    {
        if(s[0][1] == s[1][1] && s[1][0]-s[0][0] == 1)
        {
            if(s[1][1] == s[2][1] && s[2][0]-s[1][0] == 1)
                puts("0");
            else
                puts("1");
        }
        else if(s[2][1] == s[1][1] && s[2][0]-s[1][0] == 1)
        {
            if(s[0][1] == s[1][1] && s[1][0]-s[0][0] == 1)
                puts("0");
            else
                puts("1");
        }
        else if(s[1] == s[2] || s[0] == s[1])
        {
            puts("1");
        }
        else if(s[0][1] == s[1][1] && s[1][0]-s[0][0] == 2)
        {
            puts("1");
        }
        else if(s[1][1] == s[2][1] && s[2][0]-s[1][0] == 2)
        {
            puts("1");
        }
        else if(s[2][0] - s[0][0] == 2 && s[2][1] == s[0][1])
        {
            puts("1");
        }
        else if(s[2][0] - s[0][0] == 1 && s[2][1] == s[0][1])
        {
            puts("1");
        }
        else
        {
            puts("2");
        }
    }
}