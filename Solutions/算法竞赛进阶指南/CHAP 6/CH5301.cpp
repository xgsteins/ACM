#include <bits/stdc++.h>
using namespace std;
const int maxn = 300+10;
int num[maxn], dp[maxn][maxn], sum[maxn];
int main()
{
    int n;
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        cin >> num[i];
        dp[i][i] = 0;
        sum[i] = num[i]+sum[i-1];
    }
    for(int i = 2; i <= n; i++)
    {
        for(int l = 1; l <= n-i+1; l++)
        {
            int r = i+l-1;
            for(int k = l; k < r; k++)
            {
                dp[l][r] = min(dp[l][k]+dp[k+1][r], dp[l][r]);
            }
            dp[l][r] += sum[r]-sum[l-1];
        }
    }
    cout << dp[1][n] << endl;
}