// 二进制拆分求权值+连通块

#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
const long long maxn = 100000+10;
long long f[maxn], bit[33];
long long find(long long x) { return x == f[x] ? x : f[x] = find(f[x]); }
long long val[maxn];
multiset<long long> gg[maxn];
int main()
{
    long long T;
    cin >> T;
    while(T--)
    {
        long long n, m;
        scanf("%lld%lld", &n, &m);
        for(long long i = 1; i <= n; i++)
        {
            f[i] = i;
            scanf("%lld", &val[i]);
            gg[i].clear();
        }
        for(long long i = 0; i < m; i++)
        {
            long long u, v;
            scanf("%lld%lld", &u, &v);
            f[find(u)] = find(v);
        }
        set<long long> st;
        for(long long i = 1; i <= n; i++)
        {
            st.insert(find(i));
            gg[f[i]].insert(val[i]);
        }
        long long res = 0;
        for(auto i:st)
        {
            memset(bit, 0, sizeof(bit));
            for(auto j:gg[i])
            {
                long long cnt = 0;
                long long tmp = j;
                while(tmp)
                {
                    if(tmp&1)
                    {
                        res += (((1LL<<cnt)%mod*bit[cnt]%mod)%mod)*j%mod;
                        res %= mod;
                        bit[cnt]++;
                    }
                    cnt++;
                    tmp >>= 1;
                }
            }
        }
        printf("%lld\n", res%mod);
    }
}