// 多源bfs

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000+10;
typedef struct point
{
    int x, y, step;
    point(){}
    point(int _x, int _y, int _s): x(_x), y(_y), step(_s) {}
}point;
const int dx[] = {0, 1, -1, 0};
const int dy[] = {-1, 0, 0, 1};
queue<point> que[10], tmpque[10];
int speed[10], res[10], vis[MAXN][MAXN];
char s[MAXN][MAXN];
int n, m, p;

bool inB(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
int bfs(int ind)
{
    int flag = 0;
    swap(tmpque[ind], que[ind]);
    while(!que[ind].empty())
    {
        point tmp = que[ind].front();
        que[ind].pop();
        int x = tmp.x, y = tmp.y, step = tmp.step;
        for(int i = 0; i < 4; i++)
        {
            if(inB(x+dx[i], y+dy[i]) && s[x+dx[i]][y+dy[i]] == '.' && !vis[x+dx[i]][y+dy[i]])
            {
                flag = 1;
                vis[x+dx[i]][y+dy[i]] = 1;
                if(step+1 < speed[ind])    que[ind].push(point(x+dx[i], y+dy[i], step+1));
                else                        tmpque[ind].push(point(x+dx[i], y+dy[i], 0));
                res[ind]++;
            }
        }
    }
    return flag;
}

void solve()
{
    int flag = 1;
    while(flag)
    {
        flag = 0;
        for(int i = 0; i < p; i++)
        {
            flag += bfs(i);
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 0; i < p; i++)    scanf("%d", &speed[i]);
    for(int i = 1; i <= n; i++)   scanf("%s", s[i]+1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i][j] != '.')
            {
                if(s[i][j] != '#')
                {
                    tmpque[s[i][j]-'1'].push(point(i, j, 0));
                    res[s[i][j]-'1']++;
                }
                vis[i][j] = 1;
            }
        }
    }
    solve();
    for(int i = 0; i < p; i++)
        printf("%d ", res[i]);
}