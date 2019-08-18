//dp

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000+10;
int num[maxn], dp[maxn][maxn];
int main()
{
    int n, k;
    while(cin >> n >> k)
    {
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 1; i <= n; i++)
        {
            cin >> num[i];
            dp[i][0] = 0;
        }
        dp[0][0] = 0;
        sort(num+1, num+1+n);
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j*2 <= i; j++)
            {
                dp[i][j] = min(dp[i-2][j-1]+(num[i]-num[i-1])*(num[i]-num[i-1]), dp[i-1][j]);
            }
        }
        cout << dp[n][k] << endl;
    }
}       