#include <bits/stdc++.h>
using namespace std;
const int maxn = (100000+10)*31;    // 开大点
int trie[maxn][2], tot = 1;
int num[maxn];
bool isEnd[maxn];
char s[40];

int qpow(int x)
{
    int res = 1, base = 2;
    while(x)
    {
        if(x&1) res *= base;
        x >>= 1;
        base *= base;
    }
    return res;
}

void insert(char *str)
{
    int len = strlen(str), p = 1;
    for(int i = 0; i < len; i++)
    {
        int ch = str[i]-'0';
        if(trie[p][ch] == 0)    trie[p][ch] = ++tot;
        p = trie[p][ch];
    }
    isEnd[p] = true;
}

int search(char *str)
{
    int sum = 0;
    int len = strlen(str), p = 1;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == '0')
        {
            if(trie[p][1])
            {
                sum += qpow(30-i);
                p = trie[p][1];
            }
            else    p = trie[p][0];
        }
        else
        {
            if(trie[p][0])
            {
                sum += qpow(30-i);
                p = trie[p][0];
            }
            else    p = trie[p][1];
        }
    }
    return sum;
}

void change(int x)
{
    for(int j = 0; j < 31; j++) s[j] = '0';
    int cnt = 30;
    while(x)
    {
        s[cnt] += x&1;
        x >>= 1;
        cnt--;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        int x = num[i];
        change(x);
        insert(s);
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        change(num[i]);
        res = max(res, search(s));
    }
    printf("%d", res);
}