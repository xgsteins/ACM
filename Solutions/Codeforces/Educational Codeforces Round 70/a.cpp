#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string x, y;
        cin >> x >> y;
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        int ind = 0;
        for(int i = 0; i < y.size(); i++)
        {
            if(y[i] == '1')
            {
                ind = i;
                break;
            }
        }
        int cnt = 0;
        for(int i = ind; i < x.size(); i++)
        {
            if(x[i] == '1')
            {
                break;
            }
            cnt++;
        }
        cout << cnt << endl;
    }
}