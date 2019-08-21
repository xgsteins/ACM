// 二进制

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+10;
int num[5*10000+10], res[5*10000+10];
typedef struct point
{
    int x;
    int id;
    int flag = 0;
}point;
point poi[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    for(int ind = 1; ind <= T; ind++)
    {
        memset(num, 0, sizeof(num));
        memset(res, 0, sizeof(num));
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            poi[i].id = i;
            poi[i].x = x;
            poi[i].flag = 0;
            if(x <= 5*10000)
                num[x]++;
        }
        int gg = 1, neednum = 1;
        for(int i = 1; i <= 5*10000; i++)
        {
            if(neednum > 5*10000)   break;
            if(num[i] >= neednum)
            {
                res[i] = neednum;
                num[i] -= res[i];
                neednum = 0;
                break;
            }
            neednum -= num[i];
            res[i] = num[i];
            num[i] = 0;
            neednum *= 2;
        }
        for(int i = 1; i <= 5*10000; i++)   
        {
            if(gg > 5*10000)    break;
            if(num[i] >= gg)
            {
                gg = 0;
                break;
            }
            gg -= num[i];
            gg *= 2;
        }
        printf("Case %d: %s\n", ind, gg ? "NO" : "YES");
        if(!gg)
        {
            for(int i = 0; i < n; i++)
            {
                if(poi[i].x <= 5*10000 && res[poi[i].x])
                {
                    putchar('1');
                    res[poi[i].x]--;
                }
                else    putchar('0');
            }
            puts("");
        }
    }
}