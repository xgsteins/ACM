// 最短路+思维

#include <bits/stdc++.h>
using namespace std;
const int maxn = 400+10;
const int INF = 0x3f3f3f3f;
int g[maxn][maxn];
int dis[maxn];
bool vis[maxn];
void dij(int beg, int n)
{
    for(int i = 1; i <= n; i++)
    {
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[beg] = 0;
    for(int i = 1; i <= n; i++)
    {
        int k = -1;
        int min = INF;
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && dis[j] < min)
            {
                min = dis[j];
                k = j;
            }
        }
        if(k == -1) break;
        vis[k] = 1;
        for(int j = 1; j <= n; j++)
        {
            if(!vis[j] && dis[k]+g[k][j] < dis[j])
            {
                dis[j] = dis[k]+g[k][j];
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = g[v][u] = 1;
    }
    dij(1, n);
    int res = dis[n];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(g[i][j] == 1)    g[i][j] = INF;
            else                g[i][j] = 1;
        }
    }
    dij(1, n);
    res = max(res, dis[n]);
    cout << (res == INF ? -1 : res) << endl;
}