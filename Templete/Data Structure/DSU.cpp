//      DSU并查集
//      时间复杂度O(M Alpha(N), 这里Alpha是Ackerman函数的某个反函数, N为合并次数, M为查找次数
//      空间复杂度O(n)
const int maxn = 1000;

int fa[maxn];

void init(int n)
{
    for(int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void merge(int x, int y) { fa[find(x)] = find(y); }


