#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000+10;
int trie[maxn][26], tot = 1;
int isEnd[maxn];
void insert(char *str)
{
    int len = strlen(str), p = 1;
    for(int i = 0; i < len; i++)
    {
        int ch = str[i]-'a';
        if(trie[p][ch] == 0)    trie[p][ch] = ++tot;
        p = trie[p][ch];
    }
    isEnd[p]++;
}
int search(char *str)
{
    int len = strlen(str), p = 1, sum = 0;
    for(int i = 0; i < len; i++)
    {
        p = trie[p][str[i]-'a'];
        sum += isEnd[p];
        if(p == 0)  break;
    }
    return sum;
}

char s[maxn];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", s);
        insert(s);
    }
    int sum = 0;
    for(int i = 0 ; i < m; i++)
    {
        scanf("%s", s);
        printf("%d\n", search(s));
    }
}