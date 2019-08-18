#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 2147483648;
const int maxn = 4001;
ll num[maxn], dp[maxn];
int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            dp[j] += dp[j-i];
            dp[j] %= mod;
        }
    }
    cout << (dp[n]>0 ? dp[n]-1 : mod-1) << endl;
}