#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
int g[maxn][maxn], de[maxn], cnt, ind, n, m;
typedef struct point
{
    int x, y;
    point(){}
    point(int _x, int _y) { x = _x; y = _y; }
}point;
bool cmp(point a, point b)
{
    if(a.x < b.x)       return true;
    else if(a.x > b.x)  return false;
    else                return a.y < b.y;
}
point poi[maxn*maxn];
queue<int> que;
bool search()
{
    while(!que.empty())
    {
        int x = que.front(), flag = 1, pos = -1;
        que.pop();
        if(de[x]%2 == 0)    continue;
        for(int i = 1; i <= n; i++)
        {
            if(x == i)  continue;
            if((de[i]&1) && !g[x][i])
            {
                de[x]++;
                de[i]++;
                g[x][i] = g[i][x] = 1;
                int tmpx = x, tmpy = i;
                if(tmpx > tmpy) swap(tmpx, tmpy);
                poi[ind++] = point(tmpx, tmpy);
                flag = 0;
                break;
            }
            if(de[i]%2 == 0 && !g[x][i])
                pos = i;
        }
        if(flag)
        {
            if(pos == -1)    return true;
            de[x]++;
            de[pos]++;
            g[x][pos] = g[pos][x] = 1;
            que.push(pos);
            if(x > pos) swap(x, pos);
            poi[ind++] = point(x, pos);
        }
    }
    return false;
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y] = 1;
        g[y][x] = 1;
        de[x]++, de[y]++;
    }
    for(int i = 1; i <= n; i++) 
        if(de[i]&1) 
        {
            que.push(i);
            cnt++;
        }
    if(search())
    {
        puts("-1");
        return 0;
    }
    sort(poi, poi+ind, cmp);
    printf("%d\n", ind);
    for(int i = 0; i < ind; i++)
    {
        printf("%d %d\n", poi[i].x, poi[i].y);
    }
}