#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000+10;
int f[maxn][maxn], a[maxn], b[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++)
    {
        int val = 0;
        for(int j = 1; j <= n; j++)
        {
            if(a[i] == b[j])    f[i][j] = val+1;
            else                f[i][j] = f[i-1][j];
            if(b[j] < a[i])     val = max(val, f[i-1][j]);
        }
    }
    cout << *max_element(f[n], f[n]+n+1);
}