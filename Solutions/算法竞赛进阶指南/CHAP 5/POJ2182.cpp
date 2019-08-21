#include <cstdio>
using namespace std;
const int maxn = 8001;
int num[maxn], res[maxn], suf[maxn];
int lowbit(int x)   { return x&-x; }

void add(int val, int x)
{
    while(x < maxn)
    {
        suf[x] += val;
        x += lowbit(x);
    }
}

int ask(int x)
{
    int res = 0;
    while(x)
    {
        res += suf[x];
        x -= lowbit(x);
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
    {
        scanf("%d", &num[i]);
        add(1, i);
    }
    for(int i = n; i >= 1; i--)
    {
        int cnt = 0;
        int l = 1, r = n;
        while(l < r)
        {
            int mid = (l+r)>>1;
            int gg = ask(l);
            if(gg < mid)    r = mid-1;
            else            l = mid;
        }
        res[i] = l;
        add(-1, l);
    }
    for(int i = 1; i <= n; i++)
        printf("%d\n", res[i]);
}