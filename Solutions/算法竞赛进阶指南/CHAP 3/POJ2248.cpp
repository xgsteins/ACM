#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100+10;
int n, num[maxn], vis[maxn], res, k;
bool dfs(int ind)
{
    if(num[ind-1] == n)   return true;
    if(ind >= k)    return false;
    memset(vis, 0, sizeof(vis));
    for(int i = ind-1; i >= 0; i--)
    {
        for(int j = ind-1; j >= 0; j--)
        {
            if(num[i]+num[j] < num[ind-1])  break;
            if(num[i]+num[j] <= n && !vis[num[i]+num[j]])
            {
                num[ind] = num[i]+num[j];
                vis[num[ind]] = 1;
                if(dfs(ind+1))  return true;
            }
        }
    }
    return false;
}
int main()
{
    num[0] = 1, num[1] = 2;
    vis[1] = 1, vis[2] = 1;
    while(scanf("%d", &n) != EOF && n)
    {
        for(k = 2; k <= n; k++)
            if(dfs(2))  break;
        int ind = 0;
        while(num[ind] != n)
        {
            printf("%d ", num[ind]);
            ind++;
        }
        printf("%d", n);
        puts("");
    }
    return 0;
}