#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 2*100000+10;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
int n, k, num[maxn];
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    sort(num, num+n);
    int cnt = 0;
    que.push(make_pair(num[0], 0));
    while(!que.empty())
    {
        if(cnt == k-1)    break;
        pair<int, int> tmp = que.top();
        que.pop();
        int val = tmp.first, ind = tmp.second;
        if(ind < n-1)
        {
            que.push(make_pair(val-num[ind]+num[ind+1], ind+1));
            que.push(make_pair(val+num[ind+1], ind+1));
        }
        cnt++;
    }
    printf("%d", que.top().first);
}