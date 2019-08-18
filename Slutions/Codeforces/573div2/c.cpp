#include <bits/stdc++.h>
using namespace std;
const long long maxn = 10+100000;
long long num[maxn];
int main()
{
    long long n, m, k, res = 0;
    cin >> n >> m >> k;
    for(long long i = 0; i < m; i++)
    {
        cin >> num[i];
    }
    long long ind = (num[0]-1)/k*k, nid = 0, flag = 0;
    while(ind < n && nid < m)
    {
        flag = 1;
        long long cnt = nid;
        while(cnt < m && num[cnt]-nid <= ind+k)
        {
            flag = 0;
            cnt++;
        }
        if(!flag)
        {
            res++;
            nid = cnt;
        }
        else
        {
            ind = (num[nid]-nid-1)/k*k;
        }
    }
    cout << res << endl;
}