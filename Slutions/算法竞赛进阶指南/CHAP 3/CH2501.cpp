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

void bfs(int a, int b)
{
    if(s[a][b] == '1')  return;
    if(res[a][b])       return;
    memset(vis, 0, sizeof(vis));
    queue<point> que1, que2;
    que1.push(point(a, b, 0));
    int x, y, dis, rcd, len;
    while(!que1.empty())
    {
        x = que1.front().x, y = que1.front().y, dis = que1.front().dis;
        if(res[x][y] || s[x][y] == '1')
        {
            rcd = dis;
            len = res[x][y];
            break;
        }
        que2.push(que1.front());
        que1.pop();
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++)
        {
            if(inB(x+nxtx[i], y+nxty[i]) && !vis[x+nxtx[i]][y+nxty[i]])
                que1.push(point(x+nxtx[i], y+nxty[i], dis+1));
        }
    }
    while(!que2.empty())
    {
        x = que2.front().x, y = que2.front().y, dis = que2.front().dis;
        res[x][y] = len-dis+rcd;
        que2.pop();
    }

}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            bfs(i, j);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", res[i][j]);
        }
        puts("");
    }
        
}