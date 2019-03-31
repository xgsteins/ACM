#include <bits/stdc++.h>
using namespace std;
int g[2][20];
int main()
{
    int n;
    scanf("%d", &n);
    char s[20];
    scanf("%s", s);
    int len = strlen(s), num = 0, ind = 0;
    for(int i = 0; i < len; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            num *= 10;
            num += s[i]-'0';
        }
        else
        {
            if(num != 0)
            {
                g[0][ind++] = num;
            }
            num = 0;
            g[0][ind++] = s[i]+999999999;
        }
    }
    if(num != 0)    g[0][ind++] = num;
    while(n--)
    {
        memset(g[1], 0, sizeof(g[1]));
        scanf("%s", s);
        num = ind = 0;
        len = strlen(s);
        for(int i = 0; i < len; i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                num *= 10;
                num += s[i]-'0';
            }
            else
            {
                if(num != 0)
                {
                    g[1][ind++] = num;
                }
                num = 0;
                g[1][ind++] = s[i]+999999999;
            }
        }
        if(num != 0)    g[1][ind++] = num;
        int iii = 0, flag = 0;
        while(g[0][iii] != 0 && g[1][iii] != 0)
        {
            if(g[0][iii] > g[1][iii])
            {
                flag = 1;
                break;
            }
            if(g[0][iii] < g[1][iii])
            {
                flag = 2;
                break;
            }
            iii++;
        }
        if(!flag)
        {
            if(g[0][iii] > g[1][iii])           flag = 1;
            else                                flag = 2;
        }
        if(flag == 1)   puts("-");
        else            puts("+");
    }
    return 0;
}