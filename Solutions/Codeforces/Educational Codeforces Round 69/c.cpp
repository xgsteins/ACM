#include <bits/stdc++.h>
using namespace std;
const int maxn = 3*100000+10;
int num[maxn], sub[maxn], cnt[maxn], sum[maxn];
typedef struct point
{
    int id, num;
}point;
point poi[maxn];
map<int, int> mp;
bool cmp(point a, point b)
{
    return a.num > b.num;
}
int main()
{
    int n, k;
    long long res = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> num[i];
        poi[i].id = i;
        poi[i].num = num[i]-num[i-1];
    }
    sort(poi+2, poi+n+1, cmp);
    for(int i = 2; i < 2+k-1; i++)    mp[poi[i].id] = 1;
    for(int i = 2; i <= n; i++)
    {
        res += num[i]-num[i-1];
        if(mp[i])   res -= num[i]-num[i-1];
    }
    cout << res << endl;
}