#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+10;
long long peo[2][maxn], num[2][maxn], ind[2];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> peo[0][i];
    for(int i = 1; i <= n; i++) cin >> peo[1][i];
    ind[0] = 0, ind[1] = 1;
    for(int i = 1; i <= n; i++)
    {
        num[0][i] = max(num[1][i-1]+peo[0][i], num[0][i-1]);
        num[1][i] = max(num[0][i-1]+peo[1][i], num[1][i-1]);
    }
    cout << max(num[0][n], num[1][n]) << endl;
}
