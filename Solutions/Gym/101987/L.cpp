#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000+10;
int day[maxn], p[maxn], wkflag[maxn];
vector<int> res[maxn];
int main()
{
    int m, n, w, h, flag = 0;
    scanf("%d%d%d%d", &m, &n, &w, &h);
    for(int i = 0; i < m; i++)  scanf("%d", &p[i]);
    for(int i = 0; i < n; i++)  scanf("%d", &day[i]);
    for(int i = 0; i < n-w+1; i++)
    {
        if(!day[i]) continue;
        priority_queue<pair<int, int> > que;
        for(int ind = 0; ind < m; ind++)
            que.push(make_pair(p[ind], ind));
        int cnt = 0;
        while(!que.empty() && cnt < day[i])
        {
            int num = que.top().first, ind = que.top().second;
            que.pop();
            if(wkflag[ind] > i) continue;
            p[ind] -= w;
            res[ind].push_back(i);
            wkflag[ind] = i+w+h;
            cnt++;
        }
        if(cnt < day[i])
        {
            puts("-1");
            return 0;
        }
        for(int k = 0; k < w; k++)
        {
            day[i+k] -= cnt;
            if(day[i+k] < 0)
            {
                puts("-1");
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(day[i] != 0)
        {
            puts("-1");
            return 0;
        }
    }
    for(int i = 0; i < m; i++)
    {
        if(p[i] != 0)
        {
            puts("-1");
            return 0;
        }
    }
    puts("1");
    for(int i = 0; i < m; i++)
    {
        for(auto j:res[i])
            cout << j+1 << ' ';
        puts("");
    }
}