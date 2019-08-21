#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 100000+10;
ll num[MAXN];
int main()
{
    ll n, zeronum = 0, sum = 0, ncnt = 0, ocnt = 0;
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        cin >> num[i];
        if(num[i] < 0)
        {
            sum += -1-num[i];
            ncnt++;
        }
        else if(num[i] > 0)
        {
            sum += num[i]-1;
            ocnt++;
        }
        else
        {
            zeronum++;
        }
    }
    if(zeronum)
    {
        sum += zeronum;
    }
    else
    {
        if(ncnt&1)  sum += 2;
    }
    cout << sum;
}