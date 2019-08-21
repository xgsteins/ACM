// 初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
int sum[maxn], res[maxn];
int main()
{
    int n;
    res[0] = -2147483648;           // 初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化
    while (scanf("%d", &n) != EOF)
    {
        stack<int> stk, aft;       // 初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化初始化
        char ch;
        int x, cnt = 1;
        for (int i = 0; i < n; i++)
        {
            getchar();
            scanf("%c", &ch);
            int tmp;
            switch (ch)
            {
            case 'I':
            {
                scanf("%d", &x);
                stk.push(x);
                sum[cnt] = sum[cnt - 1] + x;
                res[cnt] = max(sum[cnt], res[cnt-1]);   
                cnt++;
                break;
            }
            case 'Q':
            {
                scanf("%d", &x);
                if(x >= cnt)    printf("%d\n", res[cnt-1]);
                else            printf("%d\n", res[x]);
                break;
            }
            case 'L':
            {
                if (stk.empty())
                    break;
                tmp = stk.top();
                stk.pop();
                cnt--;
                aft.push(tmp);
                break;
            }
            case 'D':
            {
                if (stk.empty())
                    break;
                stk.pop();
                cnt--;
                break;
            }
            case 'R':
            {
                if (aft.empty())
                    break;
                tmp = aft.top();
                aft.pop();
                stk.push(tmp);
                sum[cnt] = sum[cnt - 1] + tmp;
                res[cnt] = max(res[cnt-1], sum[cnt]);
                cnt++;
                break;
            }
            default:
                break;
            }
        }
    }
}