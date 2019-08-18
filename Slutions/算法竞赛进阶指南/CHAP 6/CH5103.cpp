#include <bits/stdc++.h>
using namespace std;
const int maxn = 51;
int dp[maxn*2][maxn][maxn], w[maxn][maxn];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)  
            scanf("%d", &w[i][j]);
    
    for(int i = 1; i <= n+m-2; i++)
    {
        for(int x1 = 1; x1 <= n; x1++)
        {
            for(int x2 = 1; x2 <= n; x2++)
            {
                if(x1 != x2 && i+2-x1 <= m && i+2-x2 <= m && i+2-x1 > 0 && i+2-x2 > 0)
                {
                    dp[i][x1][x2] = max(dp[i][x1][x2], dp[i-1][x1][x2]+w[x1][i+2-x1]+w[x2][i+2-x2]);
                    dp[i][x1][x2] = max(dp[i][x1][x2], dp[i-1][x1-1][x2]+w[x1][i+2-x1]+w[x2][i+2-x2]);
                    dp[i][x1][x2] = max(dp[i][x1][x2], dp[i-1][x1][x2-1]+w[x1][i+2-x1]+w[x2][i+2-x2]);
                    dp[i][x1][x2] = max(dp[i][x1][x2], dp[i-1][x1-1][x2-1]+w[x1][i+2-x1]+w[x2][i+2-x2]);                    
                }
                else if(i+2-x1 <= m && i+2-x2 <= m && i+2-x1 > 0 && i+2-x2 > 0)
                {
                    dp[i][x1][x2] = max(dp[i][x1][x2], dp[i-1][x1][x2]+w[x1][i+2-x1]);
                    dp[i][x1][x2] = max(dp[i][x1][x2], dp[i-1][x1-1][x2]+w[x1][i+2-x1]);
                    dp[i][x1][x2] = max(dp[i][x1][x2], dp[i-1][x1][x2-1]+w[x1][i+2-x1]);
                    dp[i][x1][x2] = max(dp[i][x1][x2], dp[i-1][x1-1][x2-1]+w[x1][i+2-x1]);
                }
            }
        }
    }
    cout << dp[n+m-2][n][n] << endl;
}