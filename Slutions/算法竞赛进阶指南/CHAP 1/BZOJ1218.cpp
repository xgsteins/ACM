#include <bits/stdc++.h>
using namespace std;
const int maxn = 5002;
int g[maxn][maxn];
int main()
{
    int n, r, res = 0;
    scanf("%d%d", &n, &r);
    for(int i = 0; i < n; i++)
    {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        g[x+1][y+1] = v;
    }
    for(int i = 0; i < 5002; i++)
        for(int j = 1; j < 5002; j++)
            g[i][j] += g[i][j-1];
    for(int i = 1; i < 5002; i++)
        for(int j = 0; j < 5002; j++)
            g[i][j] += g[i-1][j];
    for(int i = r; i < 5002; i++)
    {
        for(int j = r; j < 5002; j++)
        {
            int tmp = g[i][j]+g[i-r][j-r]-g[i][j-r]-g[i-r][j];
            res = max(res, tmp);
        }
    }
    printf("%d", res);
}