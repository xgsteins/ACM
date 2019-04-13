#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int res[2333], T, n;
int phi(int n)
{
    int ans = n;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            ans = ans/i*(i-1);
            while(n%i == 0) n /= i;
        }
    }
    if(n > 1)   ans = ans/n*(n-1);
    return ans;
}

void euler()
{
    for(int i = 2; i <= n; i++)
    {
        res[i] = i;
    }
    for(int i = 2; i <= n; i++)
    {
        if(res[i] == i)
        {
            for(int j = i; j <= n; j += i)
                res[j] =  res[j]/i*(i-1);
        }
    }
}

int main()
{
    scanf("%d", &T);

    for(int ind = 1; ind <= T; ind++)
    {
        scanf("%d", &n);
        printf("%d %d %d\n", ind, n, res[n]*2+3);
    }
    return 0;
}