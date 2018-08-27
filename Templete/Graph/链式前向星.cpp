//      一种很帅的存图方式


const int maxn = 100000;
int tot;            //  使用前赋值0
int head[maxn], to[maxn], nxt[maxn], cap[maxn];


void addedge(int u, int v, int cost)        // 加边
{
    nxt[v] = head[u];
    to[u] = v;
    cap[u] = cost;
    head[u] = tot++;
}

void dfs(int fa, int cur)           //  遍历图
{
    for(int i = head[cur]; ~i; i = nxt[cur])    
    {
        if(to[i] == fa)   continue;
        dfs(cur, to[i]);
    }
}
