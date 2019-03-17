#include <bits/stdc++.h>
using namespace std;
deque<pair<int, int> > que;
const int maxn = 300000+10;
int num[maxn];
int main()
{
    int n, m, res = -2147483648;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
        num[i] += num[i-1];
    }
    que.push_back(make_pair(0, 0));
    for(int i = 1; i <= n; i++)
    {
        while(!que.empty() && i-que.front().second > m)    que.pop_front();
        res = max(res, num[i]-que.front().first);
        while(!que.empty() && num[i] < que.back().first)
        {
            res = max(res, que.back().first-que.front().first);
            que.pop_back();
        }
        que.push_back(make_pair(num[i], i));
    }
    printf("%d", res);
}