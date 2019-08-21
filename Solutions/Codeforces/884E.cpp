// DSU

#include <bits/stdc++.h>
using namespace std;
int f[1<<15+1];
bool num[2][1<<14+1];
char s[1<<14+1];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
int main()
{
    int n, m, sum = 0, unsum = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= m*2; i++) f[i] = i;
    for(int i = 0; i < n; i++)
    {
        int now = i&1;
        scanf("%s", s);
        int cnt = 0;
        for(int j = 0; j < m/4; j++)
        {
            int tmp;
            if(s[j] >= 'A' && s[j] <= 'F')  tmp = 10+s[j]-'A';
            else                            tmp = s[j]-'0';
            for(int j = 3; j >= 0; j--)
            {
                sum += (tmp&1);
                num[now][cnt+j] = (tmp&1);
                tmp >>= 1;
            }
            cnt += 4;
        }
        for(int j = 0; j < m; j++)  f[j+now*m] = j+now*m;
        for(int j = 0; j < m-1; j++)
        {
            if(num[now][j] && num[now][j+1])
            {
                int t1 = find(now*m+j), t2 = find(now*m+j+1);
                if(t1 != t2)
                {
                    f[t2] = t1;
                    sum--;
                }
            }
        }
        for(int j = 0; j < m; j++)
        {
            if(num[now][j] && num[now^1][j])
            {
                int t1 = find(now*m+j), t2 = find((now^1)*m+j);
                if(t1 != t2)
                {
                    f[t2] = t1;
                    sum--;
                }
            }
        }
    }
    printf("%d\n", sum);
}