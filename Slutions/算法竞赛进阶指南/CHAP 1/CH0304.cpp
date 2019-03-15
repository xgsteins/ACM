#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+10;
int num[maxn], res[maxn];
int main()
{
    int n;
    long long zheng = 0, fu = 0, ans = 0, kind = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    for(int i = 1; i < n; i++)
    {
        res[i] = num[i]-num[i-1];
        if(res[i] > 0)  zheng += res[i];
        else            fu -= res[i];
    }
    ans += max(zheng, fu);
    kind = abs(zheng-fu)+1;
    printf("%lld\n%lld", ans, kind);
}   