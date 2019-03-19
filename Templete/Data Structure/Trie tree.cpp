#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000+10;    // 开大点
int trie[maxn][26], tot = 1;    // 全由小写字母组成
bool isEnd[maxn];

void insert(char *str)  // 插入
{
    int len = strlen(str), p = 1;
    for(int i = 0; i < len; i++)
    {
        int ch = str[i]-'a';
        if(trie[p][ch] == 0)    trie[p][ch] = ++tot;
        p = trie[p][ch];
    }
    isEnd[p] = true;
}

bool search(char *str)  // 检验字符串是否存在
{
    int len = strlen(str), p = 1;
    for(int i = 0; i < len; i++)
    {
        p = trie[p][str[i]-'a'];
        if(p == 0)  return false;
    }
    return isEnd[p];
}
