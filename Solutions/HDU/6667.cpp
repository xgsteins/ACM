// Hall's marriage thereom

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1000000+10;

ll a[MAXN], b[MAXN];

int main()
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        ll suma = 0, sumb = 0, res;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", a+i);
            scanf("%lld", b+i);
            suma += a[i];
            sumb += b[i];
        }
        res = min(suma, sumb);
        for(int i = 0; i < n; i++)
        {
            res = min(res, suma+sumb-a[i]-b[i]);
        }
        printf("%lld\n", res);
    }
}