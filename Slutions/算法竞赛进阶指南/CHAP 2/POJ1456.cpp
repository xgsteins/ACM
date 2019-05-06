#include <iostream>
#include <queue>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
typedef struct poi
{
    int val, day;
    poi(int _v, int _d)
    {
        val = _v;
        day = _d;
    }
    bool operator < (const poi a) const
    {
        if(val > a.val) return false;
        else if (val < a.val)   return true;
        else
        {
            return day > a.day;
        }
    }
}poi;
priority_queue<poi> que;
int vis[10000+10];
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++)
        {
            int v, d;
            scanf("%d%d", &v, &d);
            que.push(poi(v, d));
        }
        int res = 0;
        while(!que.empty())
        {
            poi tmp = que.top();
            que.pop();
            int d = tmp.day, v = tmp.val;
            while(d > 0 && vis[d])
            {
                d--;
            }
            if(d == 0)  continue;
            res += v;
            vis[d] = 1;
        }
        printf("%d\n", res);
    }
}