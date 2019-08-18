#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;
    for(long long i = 1; i <= n; i++)
    {
        if(i*(i+1)/2 - (n-i) == k)
        {
            cout << n-i << endl;
            break;
        }
    }
    return 0;
}