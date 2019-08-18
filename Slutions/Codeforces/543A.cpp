// dp

#include <bits/stdc++.h>
using namespace std;
const long long maxn = 500+10;
long long num[maxn], dp[maxn][maxn];
int main()
{
    long long n, m, b, mod;
    cin >> n >> m >> b >> mod;
    for(long long i = 1; i <= n; i++) cin >> num[i];
    dp[0][0] = 1;
    for(long long i = 1; i <= n; i++)
    {
        for(long long j = 1; j <= m; j++)
        {
            for(long long k = num[i]; k <= b; k++)
            {
                dp[j][k] += dp[j-1][k-num[i]];
                dp[j][k] %= mod;
            }
        }
    }
    long long res = 0;
    for(int i = 0; i <= b; i++)
    {
        res += dp[m][i];
        res %= mod;
    }
    cout << res << endl;
}