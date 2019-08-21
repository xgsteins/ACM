// 线段树 or 分块
// 这里使用分块

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100000+10;
ll num[MAXN], sum[MAXN], add[MAXN];
int pos[MAXN], l[MAXN], r[MAXN], blocksize;

void change(int x, int y, ll d)
{
    int p = pos[x], q = pos[y];
    if(p == q)
    {
        for(int i = x; i<= y; i++)  num[i] += d;
        sum[p] += (y-x+1)*d;
    }   
    else
    {
        for(int i = p+1; i <= q-1; i++)
            add[i] += d;
        for(int i = x; i <= r[p]; i++)
        {
            num[i] += d;
            sum[p] += d;
        }
        for(int i = l[q]; i <= y; i++)
        {
            num[i] += d;
            sum[q] += d;
        }
    }
}
ll query(int x, int y)
{
    int p = pos[x], q = pos[y];
    ll ans = 0;
    if(p == q)
    {
        for(int i = x; i <= y; i++) ans += num[i];
        ans += (y-x+1)*add[p];
    }
    else
    {
        for(int i = p+1; i <= q-1; i++) ans += sum[i]+add[i]*(r[i]-l[i]+1);
        for(int i = x; i <= r[p]; i++)  ans += num[i];
        ans += (r[p]-x+1)*add[p];
        for(int i = l[q]; i <= y; i++)  ans += num[i];
        ans += (y-l[q]+1)*add[q];
    }
    return ans;
}
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &num[i]);
    blocksize = (int)sqrt(n);
    for(int i = 1; i <= blocksize; i++)
    {
        l[i] = (i-1)*blocksize+1;
        r[i] = i*blocksize;
    }
    if(r[blocksize] < n)
    {
        blocksize++;
        l[blocksize] = r[blocksize-1]+1;
        r[blocksize] = n;
    }
    for(int i = 1; i <= blocksize; i++)
    {
        for(int j = l[i]; j <= r[i]; j++)
        {
            pos[j] = i;
            sum[i] += num[j];
        }
    }
    while (q--)
    {
        char op[3];
        int x, y;
        scanf("%s%d%d", op, &x, &y);
        if(op[0] == 'C')
        {
            ll tmp;
            scanf("%lld", &tmp);
            change(x, y, tmp);
        }
        else
        {
            printf("%lld\n", query(x, y));
        }
    }
}