#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cstdio>
using namespace std;
const int maxn = 10000+10;
int tmp[maxn], ans[maxn];
map<pair<int, int>, int> mp;
int main()
{
    int n, ind, h, r;
    scanf("%d%d%d%d", &n, &ind, &h, &r);
    ans[ind] = h;
    for(int i = 0; i < r; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if(x > y)   swap(x, y);
        if(mp[make_pair(x, y)]) continue;
        mp[make_pair(x, y)] = 1;
        tmp[x+1]--;
        tmp[y]++;
    }
    
    for(int i = ind-1; i > 0; i--)
    {
        ans[i] = ans[i+1]-tmp[i+1];
    }
    for(int i = ind+1; i <= n; i++)
    {
        ans[i] = ans[i-1]+tmp[i];
    }
    for(int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
}