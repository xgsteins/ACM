#include <bits/stdc++.h>
using namespace std;
const int maxn = 30000+10;
vector<int> g[maxn];
int d[maxn], n, m, a[maxn], cnt;
bitset<30000> res[maxn], one("1");

void topo()
{
    queue<int> que;
    for(int i = 1; i <= n; i++)
        if(d[i] == 0)  que.push(i);
    while(!que.empty())
    {
        int x = que.front();
        que.pop();
        a[cnt++] = x;
        for(auto i:g[x])
        {
            d[i]--;
            if(d[i] == 0)   que.push(i);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        d[v]++;
    }
    for(int i = 1; i <= n; i++) res[i] |= one<<(i-1);
    topo();
    for(int i = cnt-1; i >= 0; i--)
    {
        for(auto x:g[a[i]])
        {
            res[a[i]] |= res[x];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << res[i].count() << endl;
    }
    return 0;
}

