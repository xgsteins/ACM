#include <bits/stdc++.h>
using namespace std;
const int maxn = 30000+10;
int fa[maxn], d[maxn], size[maxn];
int find(int x)
{
    if(x == fa[x])   return x;
    int root = find(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = root;
}
void merge(int x, int y)
{
    x = find(x), y = find(y);
    fa[x] = y;
    d[x] = size[y];
    size[y] += size[x];
}
int main()
{
    int T;
    cin >> T;
    getchar();
    for(int i = 0; i < maxn; i++)
    {
        fa[i] = i;
        size[i] = 1;
    }
    while(T--)
    {
        int i, j;
        char ch;
        scanf("%c %d %d", &ch, &i, &j);
        getchar();
        if(ch == 'M')
        {
            merge(i, j);
        }
        else
        {
            if(find(i) != find(j))
                puts("-1");
            else
            {
                printf("%d\n", abs(d[j]-d[i])-1);
            }
        }
    }
    
}