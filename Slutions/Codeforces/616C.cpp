// dfs

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+10;
char s[maxn][maxn];
int n, m, vis[maxn][maxn], res, ind, num[maxn*maxn];
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
bool inb(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
void dfs(int x, int y)
{
    vis[x][y] = ind;
    res++;
    for(int i = 0;  i < 4; i++)
    {
        if(inb(x+dx[i], y+dy[i]) && s[x+dx[i]][y+dy[i]] == '.' && !vis[x+dx[i]][y+dy[i]])
        {
            dfs(x+dx[i], y+dy[i]);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%s", s[i]+1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            res = 0;
            if(!vis[i][j] && s[i][j] == '.')
            {
                ind++;
                dfs(i, j);
                num[ind] = res;
            }
        }
    }
    set<int> st;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i][j] == '.')  putchar(s[i][j]);
            else
            {
                int ans = 0;
                st.clear();
                for(int gg = 0; gg < 4; gg++)
                    if(inb(i+dx[gg], j+dy[gg]))
                        st.insert(vis[i+dx[gg]][j+dy[gg]]);
                for(set<int>::iterator it = st.begin(); it != st.end(); it++)
                    ans += num[*it];
                ans++;
                printf("%d", ans%10);
            }
        }
        puts("");
    }
}