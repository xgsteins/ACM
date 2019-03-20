#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> que;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        que.push(x);
    }
    long long res = 0;
    while(que.size() > 1)
    {
        int a = que.top();
        que.pop();
        int b = que.top();
        que.pop();
        res += a+b;
        que.push(a+b);
    }
    printf("%lld", res);
}