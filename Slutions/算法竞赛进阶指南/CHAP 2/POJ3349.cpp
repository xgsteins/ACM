#include <map>
#include <iostream>
#include <algorithm>
#include <list>
#include <cstdio>
using namespace std;
const int maxn = 200000+10;
const int mod = 131071;
int vis[maxn];
typedef struct snow
{
    int num[6];
}snow;
list<snow> l[maxn];
int main()
{   
    int n, flag = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        snow tmp;
        int sum = 0;
        long long product = 1;
        for(int j = 0; j < 6; j++)
        {
            scanf("%d", &tmp.num[j]);
            sum += tmp.num[j];
            product *= tmp.num[j];
            sum %= mod;
            product %= mod;
        }
        if(flag)    continue;
        sum = (sum+product)%mod;
        if(!vis[sum])
        {
            vis[sum] = 1;
            l[sum].push_back(tmp);
        }
        else
        {
            for(list<snow>::iterator ind = l[sum].begin(); ind != l[sum].end(); ind++)
            {
                int che = 0;
                for(int a = 0; a < 6; a++)
                {
                    che = 1;
                    for(int b = 0; b < 6; b++)
                    {
                        if(ind->num[b] != tmp.num[(a+b)%6])
                        {
                            che = 0;
                            break;
                        }
                    }
                    if(che)
                    {
                        puts("Twin snowflakes found.");
                        return 0;
                    }
                    che = 1;
                    for(int b = 5; b >= 0; b--)
                    {
                        if(ind->num[5-b] != tmp.num[(a+b)%6])
                        {
                            che = 0;
                            break;
                        }
                    }
                    if(che)
                    {
                        puts("Twin snowflakes found.");
                        return 0;
                    }
                }
            }
            l[sum].push_back(tmp);
        }
    }
    puts("No two snowflakes are alike.");
}