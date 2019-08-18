#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 10007;
ll qpow(int x, int n)
{
    ll res = 1, base = x;
    while(n)
    {
        if(n&1) res = res*base%MOD;
        base = base*base%MOD;
        n >>= 1;
    }
    return res%MOD;
}
int c(int n, int k)
{
    int res = 1;
    for(int i = k+1; i <= n; i++) res = res*i%MOD;
    for(int i = 1; i <= n-k; i++)
    {
        res = res*qpow(i, MOD-2)%MOD;
    }
    return res;
}
int main()
{
    int a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    ll res = 1;
    res = res*qpow(a, n)%MOD;
    res = res*qpow(b, m)%MOD;
    res = res*c(k, n)%MOD;
    cout << res << endl;
}