// 中国剩余定理

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 10;
int m[maxn], r[maxn];
typedef long long ll;
ll exgcd(ll a, ll b, ll&x, ll &y)
{
    if(a == 0 && b == 0) return -1;
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}
int main()
{
    int T;
    cin >> T;
    for(int ind = 1; ind <= T; ind++)
    {
        printf("Case %d: ", ind);
        ll d, x, y, ggm, ggr;
        int n, flag = 1;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> m[i];
        for(int i = 1; i <= n; i++) cin >> r[i];
        ggm = m[1], ggr = r[1];
        for(int i = 2; i <= n; i++)
        {
            if(!flag)   break;
            d = exgcd(ggm, m[i], x, y);
            if((r[i]-ggr)%d)   flag = 0;
            else
            {
                x = (r[i]-ggr)/d*x%(m[i]/d);
                ggr += x*ggm;
                ggm = ggm/d*m[i];
                ggr %= ggm;
            }
        }
        if(flag)    printf("%d\n", ggr > 0 ? ggr:ggr+ggm);
        else        printf("-1\n");
    }
}