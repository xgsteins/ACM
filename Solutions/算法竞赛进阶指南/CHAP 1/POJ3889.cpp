#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
pair<ll, ll> cal(int n, ll m)
{
    if(n == 0)  return make_pair(0, 0);
    pair<ll, ll> pos = cal(n-1, m%(1<<(2*n-2)));
    int len = 1<<(n-1);
    ll x = pos.first, y = pos.second;
    int ind = m/(1<<(2*n-2));
    switch (ind)
    {
        case 0:
            return make_pair(y, x);
            break;
        case 1:
            return make_pair(x, y+len);
            break;
        case 2:
            return make_pair(x+len, y+len);
            break;
        case 3:
            return make_pair(2*len-y-1, len-x-1);
            break;
        default:
            break;
    }
}
int main()
{
    int x;
    scanf("%d", &x);
    for(int i = 0; i < x; i++)
    {
        int n;
        ll a, b;
        scanf("%d%lld%lld", &n, &a, &b);
        pair<ll, ll> t1 = cal(n, a-1), t2 = cal(n, b-1);
        ll x1 = t1.first, y1 = t1.second, x2 = t2.first, y2 = t2.second;
        printf("%d\n", (int)round(sqrt(100*(x1-x2)*(x1-x2)+100*(y1-y2)*(y1-y2))));

    }
}