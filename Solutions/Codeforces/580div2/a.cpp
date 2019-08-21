#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, resa = -1, resb = -1;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        resa = max(resa, x);
    }
    cin >> m;
    while(m--)
    {
        int x;
        cin >> x;
        resb = max(resb, x);
    }
    cout << resa << ' ' << resb;
}