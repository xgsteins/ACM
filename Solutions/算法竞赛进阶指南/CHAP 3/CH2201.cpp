#include <bits/stdc++.h>
using namespace std;
int num[20], vis[20], cable[20];
int n, w, res = 2147483647;
void dfs(int cnt, int val)
{
    if(cnt == n)
    {
        res = min(res, val);
        return;
    }
    if(val >= res)   return;
    for(int i = 0; i <= val; i++)
    {
        if(num[cnt]+cable[i] <= w)
        {
            cable[i] += num[cnt];
            dfs(cnt+1, val);
            cable[i] -= num[cnt];
        }
    }
    cable[val+1] = num[cnt];
    dfs(cnt+1, val+1);
    cable[val+1] = 0;
}
int main()
{
    cin >> n >> w;
    for(int i = 0; i < n; i++)  cin >> num[i];
    sort(num, num+n);reverse(num, num+n);
    dfs(0, 0);
    cout << res+1 << endl;
    return 0;
}