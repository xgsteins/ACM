#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int vis[27][10], record[9][9], cnt, zeroNum, flag;
typedef struct point
{
    int x, y, sum;
    point(){sum = 9;}
    point(int _x, int _y)
    {
        x = _x;
        y = _y;
        sum = 9;
    }
}point;
point poi[82];
char s[9][10];
bool cmp(point a, point b)  { return a.sum > b.sum; }
void dfs(int ind)
{
    if(flag)    return;
    if(cnt+ind == 81)
    {
        for(int i = 0; i < 9; i++)  cout << s[i] << endl;
        flag = 1;
        return;
    }
    int x = poi[ind].x, y = poi[ind].y;
    for(int i = 1; i <= 9; i++)
    {
        if(!vis[x][i] && !vis[9+y][i] && !vis[18+x/3*3+y/3][i])
        {
            vis[x][i] = vis[9+y][i] = vis[18+x/3*3+y/3][i] = 1;
            s[x][y] = '0'+i;
            dfs(ind+1);
            vis[x][i] = vis[9+y][i] = vis[18+x/3*3+y/3][i] = 0;
        }
    }
};
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        flag = 0;
        zeroNum = 0;
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < 9;i++)
        {
            cin >> s[i];
            for(int j = 0; j < 9; j++)
            {
                if(s[i][j] != '0')  
                {
                    cnt++;
                    vis[i][s[i][j]-'0'] = 1;
                    vis[9+j][s[i][j]-'0'] = 1;
                    vis[18+i/3*3+j/3][s[i][j]-'0'] = 1;
                    for(int x = 0; x < 9; x++)
                    record[i][x]++, record[x][i]++;
                    for(int x = i-i%3; x < i-i%3+3; x++)
                        for(int y = j-j%3; y < j-j%3+3; y++)
                        {
                            record[x][y]++;
                        }
                }
                else
                {
                    poi[zeroNum++] = point(i, j);
                }
            }
        }
        for(int i = 0; i < zeroNum; i++)    poi[i].sum = record[poi[i].x][poi[i].y];
        sort(poi, poi+zeroNum, cmp);
        dfs(0);
    }
}