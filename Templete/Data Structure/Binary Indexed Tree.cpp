//      时间复杂度O(logn)
//      它很帅


const int maxn = 10000*2;
int num[maxn], c[maxn];
int lowbit(int x)
{
    return x & -x;
}

void update(int x, int val)
{
    while(x < maxn)
    {
        c[x] += val;
        x += lowbit(x);
    }
}

int que(int x)
{
    int res = 0;
    while(x > 0)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}