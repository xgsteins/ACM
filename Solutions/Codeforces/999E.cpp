// Tarjan 缩点

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20010; 
const int MAXM = 50010; 
struct Edge
{
    int to, next;
} edge[MAXM];
int head[MAXN], tot;
int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN];
int Index, top;
int scc; 
bool Instack[MAXN];
int num[MAXN]; 
int u[MAXM], v[MAXM], in[MAXM], vis[MAXN];
vector<int>vv[5006];
void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void Tarjan(int u)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].to;
        if (!DFN[v])
        {
            Tarjan(v);
            if (Low[u] > Low[v])
                Low[u] = Low[v];
        }
        else if (Instack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if (Low[u] == DFN[u])
    {
        scc++;
        do
        {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
            num[scc]++;
        } while (v != u);
    }
}
void solve(int N)
{
    memset(DFN, 0, sizeof(DFN));
    memset(Instack, false, sizeof(Instack));
    memset(num, 0, sizeof(num));
    Index = scc = top = 0;
    for (int i = 1; i <= N; i++)
        if (!DFN[i])
            Tarjan(i);
}
void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}
void dfs(int x)
{
    vis[x] = 1;
    for(int i = 0; i < vv[x].size(); i++)
        if(!vis[vv[x][i]])  
            dfs(vv[x][i]);
}
int main()
{
    init();
    int n, m, s;
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i];
        addedge(u[i], v[i]);
    }
    solve(n);
    memset(in, 0, sizeof(in));
    for(int i = 0; i < m; i++)
    {
        if(Belong[u[i]] == Belong[v[i]]) continue;
        vv[Belong[u[i]]].push_back(Belong[v[i]]);
        in[Belong[v[i]]]++;
    }
    memset(vis,0,sizeof(vis));
    dfs(Belong[s]);
    int res = 0;
    for(int i = 1; i <= scc; i++)
    {
        res += (!vis[i] && !in[i]);
    }
    cout << res << endl;
}