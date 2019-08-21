#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+10;
int num[maxn];
int main()
{
    int n, k, res = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        num[x]++;
    }
    for(int i = 1; i <= 1000; i++)
    {
        if(num[i]%2 == 1)   res++;
        
    }
}