//      时间复杂度O(nlogn)
//      使用优先队列


#include <queue>

using namespace std;

const int maxn = 100010;
const int INF = 0x3f3f3f3f;
int head[maxn], tot;        // 使用前需初始化

void init()                 //  初始化
{
    memset(head, -1, sizeof(head));
    tot = 0;
}
struct edge
{
    int v, next, w;
    edge(int _v, int _n, int _w)
    {
        v = _v;
        next = _n;
        w = _w;
    }
    edge(){}
}e[maxn];

struct qnode
{
    int v, w;
    qnode(int _v, int _w)
    {
        v = _v;
        w = _w;
    }
    qnode(){}
    bool operator <(const qnode &a) const
    {
        return w > a.w;
    }
};

void addedge(int u, int v, int w)
{
    e[tot].v = v;
    e[tot].w = w;
    e[tot].next = head[u];
    head[u] = tot++;
}


int dis[maxn], pre[maxn];
bool vis[maxn];
priority_queue<qnode> que;
void dijkstra(int n, int beg)
{
    for(int i = 0; i <= n; i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[beg] = 0;
    while(!que.empty()) que.pop();
    que.push(qnode(beg, 0));
    qnode tmp;
    while(!que.empty())
    {
        tmp = que.top();
        int u = tmp.v;
        que.pop();
        if(vis[u])  continue;
        vis[u] = true;
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].v;
            int w = e[i].w;
            if(!vis[v] && dis[v] > dis[u]+w)
            {
                dis[v] = dis[u]+w;
                pre[v] = u;
                que.push(qnode(v, dis[v]));
            }
        }
    }
}