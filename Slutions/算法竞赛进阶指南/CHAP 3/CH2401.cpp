#include <bits/stdc++.h>
using namespace std;
const long long maxn = 100;
int num[maxn], w, n, res, wei[1<<25], len;
set<int> st;
bool cmp(int a, int b)  { return a > b; }
void dfs(int sum, int now)
{
    if(now > n/2-3 || num[now] > w-sum)
    {
        if(sum)
            st.insert(sum);
        return;
    }
    dfs(sum+num[now], now+1);
    dfs(sum, now+1);
}
void findR(int sum, int now)
{
    if(now >= n || num[now] > w-sum)
    {
        int tmp = w - sum;
		int l = 0, r = len, m;
        while(l < r)
		{
            m = l+r+1 >> 1;
            if(wei[m] <= tmp) l = m; 
            else              r = m - 1;
        }
        if(l)   sum += wei[l];
        res = max(sum, res);
        return;
    }
    findR(sum+num[now], now+1);
    findR(sum, now+1);
}
int main()
{
    scanf("%d%d", &w, &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    sort(num, num+n);
    dfs(0, 0);
    for(auto i:st)  wei[++len] = i;
    findR(0, n/2-2);
    printf("%d", res);
}