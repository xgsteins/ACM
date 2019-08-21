#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100000+10;
ll a[maxn], c[2][maxn], sum[maxn];
ll lowbit(ll x)   { return x&-x; }
void add(ll x, ll val, int k)
{
    while(x < maxn)
    {
        c[k][x] += val;
        x += lowbit(x);
    }
}
ll ask(ll x, int k)
{
    ll res = 0;
    while(x)
    {
        res += c[k][x];
        x -= lowbit(x);
    }
    return res;
}
int main()
{
    ll n, q;
    scanf("%lld%lld", &n, &q);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum[i] += sum[i-1]+a[i];
    }
    for(int i = 0; i < q; i++)
    {
        getchar();
        char ch;
        ll l, r;
        scanf("%c %lld %lld", &ch, &l, &r);
        if(ch == 'C')
        {
            ll d;
            scanf("%lld", &d);
            add(l, d, 0);
            add(r+1, -d, 0);
            add(l, l*d, 1);
            add(r+1, -(r+1)*d, 1);
        }
        else
        {
            printf("%lld\n", ((sum[r]+(r+1)*ask(r, 0)-ask(r, 1)) - (sum[l-1]+l*ask(l-1, 0)-ask(l-1, 1))));
        }
        
    }
}