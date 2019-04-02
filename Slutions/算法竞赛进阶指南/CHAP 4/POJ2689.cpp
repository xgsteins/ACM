#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int isP[1000000+10], res[1000000+10], prime[50000+10];
int main()
{
    int limit = (int)sqrt(2147483647), cnt = 0;
    for(int i = 2; i <= limit; i++)
    {
        if(!isP[i])
        {
            prime[cnt++] = i;
            for(int j = i; j*i < limit; j++)
            {
                isP[i*j] = 1;
            }
        }
    }
    int l, r;
    while(scanf("%d%d", &l, &r) != EOF)
    {
        if(l == 1)  l = 2;              // !!! 
        memset(res, 0, sizeof(res));
        int rr = (int)sqrt(r);
        for(int i = 0; i < cnt; i++)
        {   
            if(prime[i] > rr)   break;
            long long ind = l/prime[i];
            while(ind*prime[i] <= r)
            {
                if(ind*prime[i] < l || ind == 1)
                {
                    ind++;
                    continue;
                }
                res[ind*prime[i]-l] = 1;
                ind++;
            }
        }
        int ma, mb, mx, my, tmp1 = 2147483647, tmp2 = -1, pre = -1;
        for(int i = 0; i <= r-l; i++)
        {
            if(!res[i])
            {
                if(pre == -1)  pre = i;
                else
                {
                    if(i-pre < tmp1)
                    {
                        ma = pre;
                        mb = i;
                        tmp1 = i-pre;
                    }
                    if(i-pre > tmp2)
                    {
                        mx = pre;
                        my = i;
                        tmp2 = i-pre;
                    }
                }
                pre = i;
            }
        }
        if(tmp2 == -1)  puts("There are no adjacent primes.");
        else
        {
            printf("%d,%d are closest, %d,%d are most distant.\n", ma+l, mb+l, mx+l, my+l);
        }
        
    }
}