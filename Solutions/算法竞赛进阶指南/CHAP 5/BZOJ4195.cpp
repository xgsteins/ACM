#include <bits/stdc++.h>
using namespace std;
const int maxn = (1000000+10)*2;
int fa[maxn], num[maxn], ter[maxn], cnt;
template <class T>
inline bool scan_d(T &ret) 
{
    char c;
    int sgn;
    if( c=getchar() , c==EOF ) return 0; //EOF
    while(c != '-' && ( c<'0' || c>'9')) c=getchar();
    sgn = (c=='-') ? -1 : 1;
    ret = (c=='-') ? 0 : (c-'0');
    while( c=getchar(), c>='0'&& c<='9' ) ret = ret*10+(c-'0');
    ret *= sgn;
    return 1;
}
typedef struct edge
{
    int i, j;
}edge;
edge edg[maxn], gg[maxn];
void discrete(int n)
{
    sort(num, num+n);
    for(int i = 0; i < n; i++)
    {
        if(i == 0 || num[i] != num[i-1])
            ter[cnt++] = num[i];
    }
}
int queryPos(int x)
{
    return lower_bound(ter, ter+cnt, x)-ter;
}
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    fa[find(x)] = fa[find(y)];
}
int main()
{
    // freopen("in.in", "r", stdin);
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        cnt = 0;
        scan_d(n);
        int i, j, e, flag = 0, ind = 0, ggind = 0, edind = 0;
        for(int k = 0; k < n; k++)
        {
            scan_d(i), scan_d(j), scan_d(e);
            if(e)
            {
                edg[edind].i = i, edg[edind].j = j;
                edind++;
            }
            else
            {
                gg[ggind].i = i, gg[ggind].j = j;
                ggind++;
            }
            num[ind++] = i;
            num[ind++] = j;
        }
        discrete(ind);
        for(int i = 0; i <= cnt; i++)   fa[i] = i;
        for(int k = 0; k < edind; k++)
        {
            int posi = queryPos(edg[k].i), posj = queryPos(edg[k].j);
            merge(posi, posj);
        }
        for(int k = 0; k < ggind; k++)
        {
            int posi = queryPos(gg[k].i), posj = queryPos(gg[k].j);
            if(find(posi) == find(posj))
            {
                flag = 1;
                break;
            }
        }
        if(flag)    puts("NO");
        else        puts("YES");
    }
    return 0;
}