#include <bits/stdc++.h>
using namespace std;
const int maxn = 4*100000+10;
map<int, int> mp;
int main()
{
    long long i;
    int n;
    cin >> n >> i;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    int res = 1000000000+7;
    i = i*8/n;
    if(i >= 32)  i = 2147483647;
    else        i = 1<<i;
    map<int, int>::iterator it1 = mp.begin(), it2 = mp.begin();
    int ind = 0, sum = 0;
    while(ind < i && it2 != mp.end())
    {
        sum += (*it2).second;
        ind++;
        it2++;
    }
    res = min(res, n-sum);
    for(; it2 != mp.end(); it1++, it2++)
    {
        sum -= (*it1).second;
        sum += (*it2).second;
        res = min(res, n-sum);
    }
    cout << res << endl;
}