#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+10;
int dp[maxn], num[101];
int main()
{
    int n, m;
    cin >> n >> m;
    dp[0] = 1;
    for(int i = 1; i <= n; i++) cin >> num[i];
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= num[i]; j--)
            dp[j] += dp[j-num[i]];
            
    cout << dp[m] << endl;
}