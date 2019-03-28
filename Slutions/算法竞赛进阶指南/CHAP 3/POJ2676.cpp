#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int gg[(1<<9)+1];
int vis[27];
int cnt, zeroNum, flag;
pair<int, int> poi[82];
string s[9];
inline int lowbit(int x)   { return x&-x; }
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
    int tmp = vis[x]&vis[9+y]&vis[18+x/3*3+y/3];
    while(tmp)
    {
        int nooow = lowbit(tmp);
        int now = gg[nooow];
        tmp -= nooow;
        vis[x] ^= nooow;
        vis[9+y] ^= nooow;
        vis[18+x/3*3+y/3] ^= nooow;
        s[x][y] = now+'0';
        dfs(ind+1);
        vis[x] ^= nooow;
        vis[9+y] ^= nooow;
        vis[18+x/3*3+y/3] ^= nooow;
    }
}
int main()
{
    for(int i = 1; i <= 9; i++)
    {
        gg[1<<(i-1)] = i;
    }
    int T;
    cin >> T;
    while(T--)
    {
        flag = 0;
        zeroNum = 0;
        cnt = 0;
        for(int i = 0; i < 27; i++) vis[i] = (1<<9)-1;
        for(int i = 0; i < 9;i++)
        {
            cin >> s[i];
            for(int j = 0; j < 9; j++)
            {
                if(s[i][j] != '0')  
                {
                    cnt++;
                    vis[i] ^= 1<<(s[i][j]-'0'-1);
                    vis[9+j] ^= 1<<(s[i][j]-'0'-1);
                    vis[18+i/3*3+j/3] ^= 1<<(s[i][j]-'0'-1);
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