#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+10;
string s, t, p;
int numt[27], nump[27];
int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        memset(numt, 0, sizeof(numt));
        memset(nump, 0, sizeof(numt));
        cin >> s >> t >> p;
        int inds = 0, indt = 0;
        while(inds < s.size() && indt < t.size())
        {
            if(s[inds] == t[indt])
            {
                inds++;
                indt++;
            }
            else
            {
                numt[t[indt]-'a']++;
                indt++;
            }
        }
        if(inds != s.size())
        {
            puts("NO");
        }
        else
        {
            while(indt < t.size())
            {
                numt[t[indt]-'a']++;
                indt++;
            }
            for(int i = 0; i < p.size(); i++)
            {
                nump[p[i]-'a']++;
            }
            int flag = 0;
            for(int i = 0; i < 27; i++)
            {
                if(nump[i] < numt[i])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)    puts("NO");
            else        puts("YES");
        }
        
    }
}