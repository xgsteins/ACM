#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 200000+10;
ll a[maxn], c[maxn], lbig[maxn], lsml[maxn], rbig[maxn], rsml[maxn], lim;
ll lowbit(ll x)   { return x&-x; }
void update(ll x, ll val)
{
    while(x <= lim)
    {
        c[x] += val;
        x += lowbit(x);
    }
}
ll ask(ll x)
{
    ll res = 0;
    while(x)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    ll r1 = 0, r2 = 0;
    for(ll i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        lim = max(lim, a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        lsml[i] += ask(a[i]-1);
        lbig[i] += ask(lim)-ask(a[i]); 
        update(a[i], 1);
    }
    memset(c, 0, sizeof(c));
    for(int i = n; i > 0; i--)
    {
        rsml[i] += ask(a[i]-1);
        rbig[i] += ask(lim)-ask(a[i]); 
        update(a[i], 1);
    }
    for(int i = 2; i <= n-1; i++)
    {
        r1 += lsml[i]*rsml[i];
        r2 += lbig[i]*rbig[i];
    }
    printf("%lld %lld\n", r2, r1);
}