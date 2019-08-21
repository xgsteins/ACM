#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2*100000+10;
int num[MAXN];
int main()
{
    int n;
    cin >> n;
    if(n&1)
    {
        puts("YES");
        for(int i = 1; i <= n; i++)
        {
            num[i*2-1] = i*2-1;
        }
        for(int i = 1; i <= n; i++)
        {
            if(n+1+(i-1)*2 > 2*n)
            {
                num[n+1+(i-1)*2-2*n] = i*2;
            }
            else 
                num[n+1+(i-1)*2] = i*2;
        }
        for(int i = 1; i <= 2*n; i++)
        {
            cout << num[i] << ' ';
        }
    }
    else
    {
        puts("NO");
    }
    
}
