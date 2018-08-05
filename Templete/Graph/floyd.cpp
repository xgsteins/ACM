//      floyd寻找最短路
//      时间复杂度O(n^3)
//      空间复杂度O(n^2)
const int inf = 0x3f3f3f3f;
const int maxn = 1000;
int e[maxn][maxn];
int path[maxn][maxn];
void floyd(int n)                               //传入参数为节点总数
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            path[i][j] = -1;                    //路径初始化
    
    for(int k = 1; k <= n; k++)                 //必须最外层
        for(int i = 1; i <= n; i++)
             for(int j = 1; j <= n; j++)
                if(e[i][k] < inf && e[k][j] < inf && e[i][k]+e[k][j] < e[i][j])
                {
                    e[i][j] = e[i][k]+e[k][j];
                    path[i][j] = k;             //从i到j经过k
                }
}