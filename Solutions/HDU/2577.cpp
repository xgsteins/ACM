// dp

#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
char s[maxn];
int dp[maxn][2];
bool isB(char x)
{
    return (x >= 'a' && x <= 'z');
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        scanf("%s", s+1);
        int len = strlen(s+1);
        if(isB(s[1]))
        {
            dp[1][0] = 1;
            dp[1][1] = 2;
        }
        else
        {
            dp[1][0] = 2;
            dp[1][1] = 2;
        }
        
        for(int i = 2; i <= len; i++)
        {
            if(isB(s[i]))
            {
                dp[i][0] = min(dp[i-1][0]+1, dp[i-1][1]+2);
                dp[i][1] = min(dp[i-1][0]+2, dp[i-1][1]+2);
            }
            else
            {
                dp[i][0] = min(dp[i-1][0]+2, dp[i-1][1]+2);
                dp[i][1] = min(dp[i-1][0]+2, dp[i-1][1]+1);
            }
        }
        cout << min(dp[len][0], dp[len][1]+1) << endl;
    }
}