//      时间复杂度O(ElogE)  
//      E为边数
//      适用于稀疏图(点多边少)


#include <cstring>
#include <algorithm>
using namespace std;

const int emaxn = 100+10;       //  最大点数
const int vmaxn = 10000+10;     //  最大边数
struct Edge
{
    int u, v, w;                //  起点，终点， 权值
}e[vmaxn];
int f[emaxn];                   //  并查集
int tot = 0;                        //  记录边数

bool cmp(Edge a,Edge b)
{
    return a.w < b.w;
}

int find(int x)
{
    if(f[x] == -1)  return x;
    else            return f[x] = find(f[x]);
}

void addedge(int u, int v, int w)
{
    e[tot].u = u;
    e[tot].v = v;
    e[tot].w = w;
    tot++;
}

int Kruskal(int n)          //  传入点数
{
    int cnt = 0, ans = 0;
    memset(f, -1, sizeof(f));
    sort(e, e+tot, cmp);
    for(int i = 0; i < tot; i++)
    {
        int u = e[i].u;
        int v = e[i].v;
        int w = e[i].w;
        int l = find(u), r = find(v);
        if(l != r)
        {
            ans += w;
            f[r] = l;
            cnt++;
        }
        if(cnt == n-1)  break;
    }
    if(cnt < n-1)   return -1;      //  不连通
    else            return ans;
}