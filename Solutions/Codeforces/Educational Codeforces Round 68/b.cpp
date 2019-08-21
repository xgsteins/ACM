#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000+10;
string s[maxn];
int suml[maxn], sumc[maxn];
int main()
{
    int q;
    scanf("%d", &q);
    while(q--)
    {
        memset(suml, 0, sizeof(suml));
        memset(sumc, 0, sizeof(suml));
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) cin >> s[i];
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(s[i][j] == '*')
                {
                    suml[i]++;
                    sumc[j]++;
                }
            }
        }
        int res = m+n-1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(s[i][j] != '*')
                    res = min(res, m+n-1-suml[i]-sumc[j]);
                else
                    res = min(res, m+n-suml[i]-sumc[j]);
            }
        }
        printf("%d\n", res);
    }
}