#include <bits/stdc++.h>
using namespace std;
const int maxn = 2*100000+10;
int num[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> num[i];
    int ind = -1, mmax = -1;
    for(int i = 1; i <= n; i++)
    {
        if(num[i] > mmax)
        {
            mmax = num[i];
            ind = i;
        }
    }
    int flag = 1;
    for(int i = ind; i > 0; i--)
    {
        if(num[i] < num[i-1])
        {
            flag = 0;
            break;
        }
    }
    for(int i = ind; i < n; i++)
    {
        if(num[i] < num[i+1])
        {
            flag = 0;
            break;
        }
    }
    if(flag)    puts("YES");
    else        puts("NO");
}
