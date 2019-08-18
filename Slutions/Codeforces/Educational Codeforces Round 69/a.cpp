#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+10;
int num[maxn];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> num[i];
        }
        sort(num+1, num+1+n);
        int res = num[n-1];
        if(num[n-1] > n-2)  res = n-2;
        else                res = num[n-1]-1;
        cout << res << endl;
    }
}