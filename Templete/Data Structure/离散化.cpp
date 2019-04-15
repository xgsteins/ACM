#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int num[maxn], ter[maxn], n, cnt;
void discrete()
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