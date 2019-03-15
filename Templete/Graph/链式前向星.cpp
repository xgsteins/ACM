//      一种很帅的存图方式


const int maxn = 100000;
int n;

int head[maxn]; //  head用来表示以i为起点的第一条边存储的位置
int tot;        // 总边数

struct Edge
{
    int to;     // 表示这条边的另外一个顶点
    int next;   // 指向下一条边的数组下标，值为-1表示没有下一条边
    int weight; // 权值
}edge[maxn];

void init()
{
    memset(head, -1, sizeof(head));
    tot = 0;
}

void addedge(int u, int v, int w)
{
    edge[tot].to = v;
    edge[tot].weight = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void bianli(int u)  //该点连接的边
{
    for(int i = head[u]; ~i; i = edge[i].next)
    {
        /* code */
    }
}