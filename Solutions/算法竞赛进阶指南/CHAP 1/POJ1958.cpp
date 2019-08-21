#include <cstdio>
#include <algorithm>
using namespace std;
int f[13], d[13];
int main()
{
    int n;
    d[1] = f[1] = 1;
    for(int i = 1; i <= 12; i++)
    {
        d[i] = 2*d[i-1]+1;
    }
    for(int i = 2; i <= 12; i++)    f[i] = 0x7fffffff;
    f[1] = 1;
    for(int i = 1; i <= 12; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            f[i] = min(2*f[j]+d[i-j], f[i]);
        }
    }
    for(int i = 1; i <= 12; i++)
        printf("%d\n", f[i]);
}