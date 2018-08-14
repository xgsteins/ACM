//      时间复杂度O(n^2)
//      此法求最小生成树与边数无关
//      所以适合求稠密图的最小生成树(点少边多)


#include <cstring>

const int INF = 0x3f3f3f3f;
const int maxn = 1000;
bool vis[maxn];
int low[maxn], cost[maxn][maxn];    //  low记录当前最小权值, cost为邻接矩阵
int Prim(int n)                     //  从 0 ~ n-1
{
    int ans = 0;
    memset(vis, false, sizeof(vis));
    vis[0] = true;
    for(int i = 1; i < n; i++)  low[i] = cost[0][i];
    for(int i = 1; i < n; i++)
    {
        int mmin = INF, p = -1;
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && mmin > low[j])        //  更新最小权值并记录连接的点
            {
                mmin = low[j];
                p = j;
            }
        }
        if(mmin == INF)     return -1;          //  代表图不连通
        ans += mmin;
        vis[p] = true;
        for(int j = 0; j < n; j++)
        {
            if(!vis[j] && low[j] > cost[p][j])
                low[j] = cost[p][j];            //  记录新连结的点中权值最小的边
        }
    }
    return ans;                                 //  返回权值和
}
