#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+10;
int num[maxn], sum[maxn];
int main()
{
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> num[i];
        sum[i] = sum[i-1] + num[i];
    }
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << (sum[r]-sum[l-1])/10 << endl;
    }
}