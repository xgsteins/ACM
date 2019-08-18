#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+10;
int num[maxn];
int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    int f1 = 0, f2 = 0;
    for(int i = 1; i <= n; i++)
    {
        f1 = f2 = 0;
        for(int j = i-1; j > i-x-1 && j > 0; j--)
        {
            if(num[j] <= num[i])
            {
                f1 = 1;
                break;
            }
        }
        for(int j = i+1; j < i+y+1 && j <= n; j++)
        {
            if(num[j] <= num[i])
            {
                f2 = 1;
                break;
            }
        }
        if(f1 == 0 && f2 == 0)
        {
            cout << i << endl;
            break;
        }
    }
}