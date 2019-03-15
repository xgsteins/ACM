#include <bits/stdc++.h>
using namespace std;
int val(int x, int i, int j)
{
    int tmp = x ^ (1 << (i * 5 + j));
    if (i + 1 < 5)  tmp ^= (1 << ((i + 1) * 5 + j));
    if (i - 1 >= 0) tmp ^= (1 << ((i - 1) * 5 + j));
    if (j - 1 >= 0) tmp ^= (1 << (i * 5 + j - 1));
    if (j + 1 < 5)  tmp ^= (1 << (i * 5 + j + 1));
    return tmp;
}

int main()
{
    int n;
    scanf("%d", &n);
    char ch[6][6];
    while(n--)
    {
        for (int j = 0; j < 5; j++)
            scanf("%s", ch[j]);
        int ans = 0;
        for (int a = 0; a < 5; a++)
            for (int b = 0; b < 5; b++)
            {
                if (ch[a][b] == '1')
                    ans |= 1 << (a * 5 + b);
            }
        int res = 1000000000;
        for(int i = 0; i < 1<<5; i++)
        {
            int tmp = ans, step = 0;
            for(int a = 0; a < 5; a++)
                if((i>>a)&1)    tmp = val(tmp, 0, a), step++;

            for(int a = 1; a < 5; a++)
            {
                for(int b = 0; b < 5; b++)
                {
                    if(((tmp>>((a-1)*5+b))&1) == 0)
                        tmp = val(tmp, a, b), step++;
                }
            }
            if(tmp == (1<<25)-1)    res = min(res, step);
        }
        if (res <= 6)
            printf("%d\n", res);
        else
            puts("-1");
    }
}