#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+10;
vector<int> g[maxn];
int vis[maxn];
void dfs(int x, int num)
{
    if(vis[x])  return;
    // cout << x << endl;
    vis[x] = 1;
    if(num)
    {
        puts("NO");
        exit(0);
    }
    int len = g[x].size();
    for(int i = 0; i < len; i++)
    {
        if(len == 2)
        {
            dfs(g[x][i], num+1);
        }
        else
        {
            dfs(g[x][i], 0);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int st = -1;
    for(int i = 1; i <= n; i++)
    {
        if(g[i].size() == 1)
        {
            st = i;
            break;
        }
    }
    dfs(st, 0);
    puts("YES");
    return 0;
}