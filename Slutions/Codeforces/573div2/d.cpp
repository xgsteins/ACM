#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+10;
int num[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> num[i];
    sort(num, num+n);
    if(n > 1 && num[0] == num[1] && num[0] == 0)
    {
        puts("cslnb");
    }
    else
    {
        int f = 0, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(i && num[i] == num[i-1])
            {
                f++;
                if(i >= 2)
                {
                    if(num[i-2]+1 == num[i])
                    {
                        puts("cslnb");
                        return 0;
                    }
                }
            }
            sum += num[i]-i;
        }
        if(f >= 2)  puts("cslnb");
        else
        {
            if(sum&1)   puts("sjfnb");
            else        puts("cslnb");
        }
        
    }
}