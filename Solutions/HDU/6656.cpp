// 概率dp

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MAXN = 500000+10;
ll r[MAXN], s[MAXN], x[MAXN], a[MAXN], dp[MAXN];
ll sum[MAXN];
ll pow_m(ll base, ll n)
{
    ll res = 1;
    while(n)
    {
        if(n&1)
        {
            res *= base;
            res %= MOD;
        }
        base *= base;
        base %= MOD;
        n >>= 1;
    }
    return res;
}
ll inv(ll a)
{
    return pow_m(a, MOD-2);
}
int main()
{
    int T;
    scanf("%lld", &T);
    while(T--)
    {
        sum[1] = dp[1] = 0;
        int n, q;
        scanf("%lld%lld", &n, &q);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld%lld", &r[i], &s[i], &x[i], &a[i]);
        }
        for(int i = 1; i<= n; i++)
        {
            dp[i+1] = ((s[i]*inv(r[i])%MOD)*(((1-(r[i]*inv(s[i])%MOD)+MOD)%MOD)*(dp[i]-dp[x[i]]+MOD)%MOD+a[i])%MOD+MOD)%MOD;
            dp[i+1] = (dp[i+1]+dp[i]+MOD)%MOD;
        }
        while(q--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", (dp[r]-dp[l]+MOD)%MOD);
        }
    }
}