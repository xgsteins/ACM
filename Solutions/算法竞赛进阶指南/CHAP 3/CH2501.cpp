#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+10;
string s[maxn];
int res[maxn][maxn], vis[maxn][maxn], n, m;
int nxtx[] = {0, -1, 1, 0};
int nxty[] = {-1, 0, 0, 1};
bool inB(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
typedef struct point
{
    int x, y, dis;
    point(){}
    point(int _x, int _y, int _dis)
    {
        x = _x;
        y = _y;
        dis = _dis;
    }
}point;

queue<point> que;
void bfs()
{
    while(!que.empty())
    {
        int x = que.front().x, y = que.front().y, dis = que.front().dis;
        que.pop();
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        res[x][y] = dis;
        for(int i = 0; i < 4; i++)
        {
            if(inB(x+nxtx[i], y+nxty[i]) && !vis[x+nxtx[i]][y+nxty[i]] && s[x+nxtx[i]][y+nxty[i]] != '1')
                que.push(point(x+nxtx[i], y+nxty[i], dis+1));
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(s[i][j] == '1')
                que.push(point(i, j, 0));
    bfs();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", res[i][j]);
        }
        puts("");
    }   
}