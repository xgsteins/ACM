// 区间dp

#include <bits/stdc++.h>
using namespace std;
const int maxn = 500+10;
int num[maxn], dp[maxn][maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 0; i < n; i++) dp[i][i] = 1;
    for(int len = 2; len <= n; len++)
    {
        for(int i = 0; i+len-1 < n; i++)
        {
            int j = i+len-1;
            if(num[i] == num[j] && len > 2)
            {
                dp[i][j] = dp[i+1][j-1];
            }
            else if(num[i] == num[j])
            {
                dp[i][j] = 1;
            }
            for(int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
}