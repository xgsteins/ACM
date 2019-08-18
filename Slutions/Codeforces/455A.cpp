// dp

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+10;
typedef long long ll;
ll num[maxn], dp[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        num[x]++;
    }
    ll res = 0;
    for(int i = 100000; i >= 0; i--)
    {
        dp[i] = max(dp[i+1], dp[i+2]+num[i]*i);
        res = max(dp[i], res);
    }
    cout << res << endl;
}