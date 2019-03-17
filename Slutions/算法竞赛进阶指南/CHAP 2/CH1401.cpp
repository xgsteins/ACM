#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000+10;
const int hhh = 2333;
char ch[maxn];
unsigned int sum[maxn], gg[maxn];
int main()
{
    int m;
    scanf("%s", ch+1);
    int len = strlen(ch+1);
    scanf("%d", &m);
    gg[0] = 1;
    for(int i = 1; i <= len; i++)
    {
        sum[i] += hhh*sum[i-1]+(ch[i]-'a')+1;
        gg[i] = gg[i-1]*hhh;
    }
    for(int i = 0; i < m; i++)
    {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if(sum[r1]-sum[l1-1]*gg[r1-l1+1] == sum[r2]-sum[l2-1]*gg[r2-l2+1])  puts("Yes");
        else                                                                puts("No");
    }
}
