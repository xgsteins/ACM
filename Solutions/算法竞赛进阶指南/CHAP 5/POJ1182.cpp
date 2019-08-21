#include <bits/stdc++.h>
using namespace std;
const int maxn = 3*50000+10;
int fa[maxn];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main()
{
    int n, k, res = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i <= 3*n; i++)
        fa[i] = i;
    for(int i = 0; i < k; i++)
    {
        int e, x, y;
        scanf("%d%d%d", &e, &x, &y);
        if(x > n || y > n)
        {
            res++;
            continue;
        }
        if(e&1)
        {
            if(find(x+n) == find(y) || find(y+n) == find(x))
            {
                res++;
                continue;
            }
            else
            {
                fa[find(x)] = find(y);
                fa[find(x+n)] = find(y+n);
                fa[find(x+2*n)] = find(y+2*n);
            }
        }
        else
        {
            if(find(x) == find(y) || find(y+n) == find(x))
            {
                res++;
                continue;
            }
            else
            {
                fa[find(x+n)] = find(y);
                fa[find(x)] = find(y+2*n);
                fa[find(x+2*n)] = find(y+n);
            }
            
        }
    }
    printf("%d\n", res);
}