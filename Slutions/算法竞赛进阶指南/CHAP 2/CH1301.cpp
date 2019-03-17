#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > st;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        set<pair<int, int>>::iterator it = st.lower_bound(make_pair(x, 0));
        set<pair<int, int>>::iterator il = it;
        if(it != st.begin())    il--;
        if(i != 0)
        {
            if(it == st.end())                                  printf("%d %d\n", abs(il->first-x), il->second);
            else if(it == st.begin())                           printf("%d %d\n", abs(it->first-x), it->second);
            else if(abs(it->first-x) < abs(il->first-x))        printf("%d %d\n", abs(it->first-x), it->second);
            else                                                printf("%d %d\n", abs(il->first-x), il->second);
        }
        st.insert(make_pair(x, 1+i));
    }
}