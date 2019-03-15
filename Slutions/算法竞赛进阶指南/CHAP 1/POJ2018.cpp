#include <bits/stdc++.h>
using namespace std;
const int maxn = 2001;
const double eps = 1e-6;
double tmp[maxn], num[maxn], sum[maxn];
int main()
{
    int n, f;
    scanf("%d%d", &n, &f);
    for(int i = 1; i <= n; i++)
        scanf("%lf", &num[i]);
    double l = -1e5, r = 1e5;
    while(r-l > eps)
    {
        double mid = (l+r)/2;
        for(int i = 1; i <= n; i++)  tmp[i] = num[i]-mid;
        for(int i = 1; i <= n; i++)
            sum[i] = sum[i-1]+tmp[i];
        double mmax = -1e10, minVal = 1e10;
        for(int i = f; i <= n; i++)
        {
            minVal = min(minVal, sum[i-f]);
            mmax = max(mmax, sum[i]-minVal);
        }
        if(mmax > 0)    l = mid;
        else            r = mid;
    }
    printf("%.0f", (1000*l));
    return 0;
}