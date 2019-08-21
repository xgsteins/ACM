#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000+10;
int isP[maxn], prime[100000], res[maxn];
int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
    {
        if(!isP[i])
        {
            prime[cnt++] = i;
            for(long long j = i; j*i <= n; j++) // long long !!!!
            {
                isP[i*j] = 1;
            }
        }
    }
    for(int i = 0; i < cnt; i++)
    {
        long long tmp = prime[i];   // long long !!!!
        while(tmp <= n)
        {
            res[prime[i]] += n/tmp;
            tmp *= prime[i];
        }
    }
    for(int i = 0; i < cnt; i++)
    {
        if(res[prime[i]])
            printf("%d %d\n", prime[i], res[prime[i]]);
    }
    return 0;
}