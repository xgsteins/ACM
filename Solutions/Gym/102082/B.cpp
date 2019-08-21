#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000+10;
int num[maxn];
int dp[maxn][maxn];
int main()
{
    int n, res = 2;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]); 
    }
    sort(num+1, num + n + 1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = 2;
    for (int i = 1; i < n; i++)
    {
        int ind = i-1;
        for (int j = i+1; j <= n; j++)
        {
            while(ind > 0 && num[i]-num[ind] < num[j]-num[i])   ind--;
            if(!ind)    continue;
            if(num[i]-num[ind] == num[j]-num[i])
                dp[j][i] = max(dp[j][i], dp[i][ind]+1);
            res = max(res, dp[j][i]);
        }
    }
    printf("%d", res);
}