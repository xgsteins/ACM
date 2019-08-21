#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int minn = 2000+10;
ll a[minn], b[minn], dp[minn][minn], n, cnt;
bool cmp (ll a, ll b) { return a > b; }
ll solUp()
{
    sort(b+1, b+n+1);
    for(int i = 1; i <= n; i++) 
        dp[1][i] = abs(a[1]-b[i]);

    for(int i = 2; i <= n; i++)
    {
        ll val = dp[i-1][1];
        for(int j = 1; j <= n; j++)
        {
            val = min(val, dp[i-1][j]);
            dp[i][j] = val+abs(a[i]-b[j]);
        }
    }
    return *min_element(dp[n]+1, dp[n]+1+n);
}
ll solDn()
{
    sort(b+1, b+n+1, cmp);
    for(int i = 1; i <= n; i++) 
        dp[1][i] = abs(a[1]-b[i]);

    for(int i = 2; i <= n; i++)
    {
        ll val = dp[i-1][1];
        for(int j = 1; j <= n; j++)
        {
            val = min(dp[i-1][j], val);
            dp[i][j] = val+abs(a[i]-b[j]);
        }
    }
    return *min_element(dp[n]+1, dp[n]+1+n);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    cout << min(solDn(), solUp());
}