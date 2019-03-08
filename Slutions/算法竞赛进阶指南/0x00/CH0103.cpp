#include <bits/stdc++.h>
using namespace std;
const int maxn = 22;
int g[maxn][maxn], res[1<<20][maxn], n;
int main()
{
    memset(res, 0x3f, sizeof(res));
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    res[1][0] = 0;
    for(int i = 1; i < 1<<n; i++)
    {
        for(int j = 0; j < n; j++)
            if(res[i>>j&1])
                for(int k = 0; k < n; k++)
                {
                    if(res[(i^1<<j)>>k&1])
                        res[i][j] = min(res[i^1<<j][k]+g[j][k], res[i][j]);
                }
    }
    printf("%d", res[(1<<n)-1][n-1]);
}