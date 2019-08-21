#include <bits/stdc++.h>
using namespace std;
const int maxn = 201;
int dp[1001][maxn][maxn], c[maxn][maxn], pos[1001];
int main()
{
    int l, n;
    memset(dp, 0x3f, sizeof(dp));
    scanf("%d%d", &l, &n);
    for(int i = 1; i <= l; i++)
        for(int j = 1; j <= l; j++)
            scanf("%d", &c[i][j]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &pos[i]);
    pos[0] = 3, dp[0][1][2] = 0;
    for(int i = 0; i < n; i++)
    {
        for(int x = 1; x <= l; x++)
        {
            for(int y = 1; y <= l; y++)
            {
                if(y != pos[i+1] && pos[i] != pos[i+1])
                    dp[i+1][pos[i]][y] = min(dp[i][x][y]+c[x][pos[i+1]], dp[i+1][pos[i]][y]);
                if(x != pos[i+1] && pos[i] != pos[i+1])
                    dp[i+1][x][pos[i]] = min(dp[i][x][y]+c[y][pos[i+1]], dp[i+1][x][pos[i]]);
                if(x != pos[i+1] && y != pos[i+1])
                    dp[i+1][x][y] = min(dp[i][x][y]+c[pos[i]][pos[i+1]], dp[i+1][x][y]);
            }
        }
    }
    int res = 0x3f3f3f3f;
    for(int i = 1; i <= l; i++)
        for(int j = 1; j <= l; j++)
            res = min(res, dp[n][i][j]);
    printf("%d\n", res);
}