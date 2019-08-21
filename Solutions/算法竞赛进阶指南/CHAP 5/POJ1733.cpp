#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 10000*2+10;
int num[maxn], fa[maxn], d[maxn], n, T;
struct { int l, r, ans; } que[maxn];
int find(int x)
{
    if(x == fa[x])  return x;
    int root = find(fa[x]);
    d[x] ^= d[fa[x]];
    return fa[x] = root;
}
void in_discrete()
{
    scanf("%d%d", &n, &T);
    char s[10];
    for(int i = 0; i < T; i++)
    {
        scanf("%d%d%s", &que[i].l, &que[i].r, s);
        if(s[0] == 'o') que[i].ans = 1;
        else            que[i].ans = 0;
        num[2*i] = que[i].l-1, num[2*i+1] = que[i].r;
    }
    sort(num, num+2*T);
    n = unique(num, num+2*T)-num;
}
int main()
{
    in_discrete();
    for(int i = 0; i <= n; i++) fa[i] = i;
    for(int i = 0; i < T; i++)
    {
        int x = lower_bound(num, num+n, que[i].l-1)-num;
        int y = lower_bound(num, num+n, que[i].r)-num;
        int a = find(x), b = find(y);
        if(a == b)
        {
            if(d[x]^d[y] != que[i].ans)
            {
                printf("%d\n", i);
                return 0;
            }
        }
        else
        {
            fa[a] = b;
            d[a] = d[x]^d[y]^que[i].ans;
        }
    }
    printf("%d\n", T);
}