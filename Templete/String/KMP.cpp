//      时间复杂度O(n+m)
//      n为主串长度
//      m为模式串长度
const int maxn = 100000;
int next[maxn] = {0};
char part[maxn], s[maxn];           // part为模式串， s为主串
void pre(char part[], int m)
{
    int i, j;
    j = next[0] = -1;
    i = 0;
    while(i < m)
    {
        while(j != -1 && part[i] != part[j])
            j = next[j];

        i++;
        j++;
        next[i] = j;
    }
}

int kmp(char part[], int m, char s[], int n)
{
    int i = 0, j = 0, ans = 0;
    pre(part, m);
    while(i < n)
    {
        while(j != -1 && s[i] != part[j])
            j = next[j];

        i++;
        j++;
        if(j >= m)
        {
            ans++;
            j = next[j];
        }
    }
    return ans;
}