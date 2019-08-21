#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 66;
int num[maxn], vis[maxn], n, res;

bool cmp(int a, int b) { return a > b; }
bool dfs(int cnt, int len, int limit, int pre)
{
    if (cnt == res)
    {
        return true;
    }
    if (len == limit)
        return dfs(cnt + 1, 0, limit, 0);
    for (int i = pre; i < n; i++)
    {
        if (!vis[i] && len + num[i] <= limit)
        {
            vis[i] = 1;
            if(dfs(cnt, len + num[i], limit, i))    return true;
            vis[i] = 0;
            if(len == 0 || len+num[i] == limit) return false;
        }
    }
    return false;
}
int main()
{
    while (scanf("%d", &n) != EOF && n)
    {
        int l = 0, r = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            l = max(l, num[i]);
            r += num[i];
        }
        sort(num, num + n, cmp);
        for (int i = l; i <= r; i++)
        {
            if (r % i != 0)
                continue;
            res = r / i;
            memset(vis, 0, sizeof(vis));
            if (dfs(0, 0, i, 0))
            {
                printf("%d\n", i);
                break;
            }
        }
    }
}