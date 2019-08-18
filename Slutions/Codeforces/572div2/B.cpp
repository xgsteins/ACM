#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+10;
int num[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num+n);
    if(num[n-1] >= num[n-2]+num[n-3])   puts("NO");
    else
    {
        puts("YES");
        if(num[n-2]+num[0] <= num[n-1]) swap(num[n-2], num[n-1]);
        for(int i = 0; i < n; i++)  cout << num[i] << ' ';
        puts("");
    }
}