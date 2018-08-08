//      时间复杂度O(n^2)
//      本质贪心
//      求单源最短路, 不可算负权边

const int INF = 0x3f3f3f3f;
const int maxn = 1000;
int e[maxn][maxn];                  // 邻接矩阵
int dis[maxn];                      // 记录源点到各点最短距离
int pre[maxn];                      // 记录当前节点最短路径的父节点
bool vis[maxn];                     // 记录是否遍历过
void Dijkstra(int beg, int n)
{
    for(int i = 1; i <= n; i++)      //初始化
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[beg] = 0;
    for(int i = 1; i <= n; i++)
    {
        int k = -1;
        int min = INF;
        for(int j = 0; j < n; j++)
            if(!vis[j] && dis[j] < min)
            {
                min = dis[j];
                k = j;
            }
        
        if(k == -1) break;
        vis[k] = true;
        for(int j = 1; j <= n; j++)
        {
            if(!vis[i] && dis[k]+e[k][j] < dis[j])
            {
                dis[j] = dis[k]+e[k][j];
                pre[j] = k;
            }
        }
    }
}