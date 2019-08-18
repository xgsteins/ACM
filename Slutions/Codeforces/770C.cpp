// 拓扑排序

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+10;
int num[maxn], vis[maxn];
vector<int> g[maxn], res;
void dfs(int x)
{
    if(vis[x] == 1)
    {
        puts("-1");
        exit(0);
    }
    if(vis[x] == 2) return;
    vis[x] = 1;
    for(auto i:g[x])
    {
        dfs(i);
    }
    vis[x] = 2;
    res.push_back(x);
}
int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> num[i];
    }
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        while(x--)
        {
            int tmp;
            cin >> tmp;
            g[i].push_back(tmp);
        }
    }
    for(int i = 0; i < k; i++)
    {
        dfs(num[i]);
    }
    cout << res.size() << endl;
    for(auto i:res)
    {
        cout << i << ' ';
    }
}