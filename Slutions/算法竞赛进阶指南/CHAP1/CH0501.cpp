#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+10;
int num[maxn];
int main()
{
    int n, res = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    sort(num, num+n);
    for(int i = 0; i < n; i++)
        res += abs(num[n/2]-num[i]);
    printf("%d", res);
}