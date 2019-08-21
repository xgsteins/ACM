// 拓展kmp板子

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000+10;
char s[maxn];
int nxt[maxn], ext[maxn];
void pre_EKMP(char x[], int m)
{
    nxt[0] = m;
    int j = 0;
    while (j + 1 < m && x[j] == x[j + 1])
        j++;
    nxt[1] = j;
    int k = 1;
    for (int i = 2; i < m; i++)
    {
        int p = nxt[k] + k - 1;
        int L = nxt[i - k];
        if (i + L < p + 1)
            nxt[i] = L;
        else
        {
            j = max(0, p - i + 1);
            while (i + j < m && x[i + j] == x[j])
                j++;
            nxt[i] = j;
            k = i;
        }
    }
}
void EKMP(char x[], int m, char y[], int n)
{
    pre_EKMP(x, m);
    int j = 0;
    while (j < n && j < m && x[j] == y[j])
        j++;
    ext[0] = j;
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        int p = ext[k] + k - 1;
        int L = nxt[i - k];
        if (i + L < p + 1)
            ext[i] = L;
        else
        {
            j = max(0, p - i + 1);
            while (i + j < n && j < m && y[i + j] == x[j])
                j++;
            ext[i] = j;
            k = i;
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%s", s);
        int len = strlen(s);
        EKMP(s, len, s, len);
        long long sum = 0;
        for(int i = 1; i < len; i++)
        {
            if(ext[i])
            {
                sum += ext[i];
                if(i+ext[i] == len) sum--;
            }
            sum++;
        }
        printf("%lld\n", sum);
    }
}
