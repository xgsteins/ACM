#include <iostream>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int vis[27][10], cnt, zeroNum, flag;
pair<int, int> poi[82];
string s[9];
void dfs(int ind)
{
    if(flag)    return;
    if(cnt+ind == 81)
    {
        for(int i = 0; i < 9; i++)  cout << s[i] << endl;
        flag = 1;
        return;
    }
    int x = poi[ind].first, y = poi[ind].second;
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
}
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
                }
                else
                {
                    poi[zeroNum++] = make_pair(i, j);
                }
            }
        }
        dfs(0);
    }
}