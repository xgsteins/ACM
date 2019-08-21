#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll prime[] = {2,3,5,7,11,13,17,19,23,29,31}, res, n, facres;
void dfs(ll cnt, ll pre, ll sum, ll expcnt)
{
    if(cnt == 11)
    {
        if(expcnt > facres)
        {
            res = sum;
            facres = expcnt;
        }
        if(expcnt >= facres && sum < res)
        {
            res = sum;
            facres = expcnt;
        }
        return;
    }
    ll tmp = 1;
    for(ll i = 0; i <= pre; i++)
    {
        if(tmp*sum > n)    break;
        dfs(cnt+1, i, sum*tmp, expcnt*(i+1));
        tmp *= prime[cnt];
    }
}
int main()
{
    scanf("%lld", &n);
    dfs(0, 20, 1, 1);
    printf("%lld", res);
}