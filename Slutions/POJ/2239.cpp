// 二分图匹配模板

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 5010;  //点数的最大值
const int MAXM = 50010; //边数的最大值
struct Edge
{
    int to, next;
} edge[MAXM];
int head[MAXN], tot;
void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}
void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
int linker[MAXN];
bool used[MAXN];
int uN;
bool dfs(int u)
{
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!used[v])
        {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for (int u = 0; u < uN; u++) //点的编号0~uN-1
    {
        memset(used, false, sizeof(used));
        if (dfs(u))
            res++;
    }
    return res;
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        init();
        uN = 7*12+302;
        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            for(int j = 0; j < x; j++)
            {
                int u, v;
                scanf("%d%d", &u, &v);
                addedge((u-1)*12+v, 7*12+i);
            }
        }
        printf("%d\n", hungary());
    }
}