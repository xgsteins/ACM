#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 10000+10;
pair<int, int> mono[maxn];
int fa[maxn];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

bool cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < maxn; i++) fa[i] = i;
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &mono[i].first, &mono[i].second);
        }
        sort(mono, mono+n, cmp);
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(find(mono[i].second) > 0)
            {
                res += mono[i].first;
                fa[find(mono[i].second)] = find(mono[i].second)-1;
            }
        }
        printf("%d\n", res);
    }
}