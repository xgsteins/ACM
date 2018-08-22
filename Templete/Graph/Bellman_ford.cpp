//      可处理负权边
//      采用邻接表
//      时间复杂度O(EV)

#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 550;
int dis[maxn];
struct Edge
{
    int u, v, cost;
};

vector<Edge> e;                     

bool bellman_ford(int beg, int n)               //点的编号从1开始
{
    for(int i = 1; i <= n; i++)   dis[i] = INF;

    dis[beg] = 0;

    for(int i = 1; i < n; i++)                  //最多做n-1次
    {
        bool flag = false;
        for(int j = 0; j < e.size(); j++)
        {
            int u = e[j].u;
            int v = e[j].v;
            int cost = e[j].cost;
            if(dis[v] > dis[u]+cost)
            {
                dis[v] = dis[u]+cost;
                flag = true;
            }
        }
        if(!flag)   return true;                //没有负环回路
    }

    for(int j = 0; j < e.size(); j++)
        if(dis[e[j].v] > dis[e[j].u]+e[j].cost)
            return false;                       //有负环回路

    return true;                                //没有负环回路
}