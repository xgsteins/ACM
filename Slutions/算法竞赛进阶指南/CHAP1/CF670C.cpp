#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000+10;
int b[maxn], c[maxn];
map<int, int> mp;
int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        mp[x]++;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for(int i = 0; i < m; i++)
        scanf("%d", &c[i]);
    int mmax1 = -1, mmax2 = -1, ans = -1;
    for(int i = 0; i < m; i++)
    {
        if(mp[b[i]] > mmax1)
        {
            ans = i;
            mmax1 = mp[b[i]];
            mmax2 = mp[c[i]];
        }
        else if(mp[b[i]] == mmax1)
        {
            if(mp[c[i]] > mmax2)
            {
                ans = i;
                mmax2 = mp[c[i]];
            }
        }
    }
    printf("%d", ans+1);
}