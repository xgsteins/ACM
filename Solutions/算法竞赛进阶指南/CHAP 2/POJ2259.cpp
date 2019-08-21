#include <iostream>
#include <queue>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int num[1000000];
int main()
{
    int n, ind = 1;
    while(scanf("%d", &n) != EOF && n)
    {
        queue<int> que[1000+10], tque;
        int cnt = 0;
        if(ind == 1)    printf("Scenario #%d\n", ind++);
        else            printf("\nScenario #%d\n", ind++);
        for(int i = 0; i < n; i++)
        {
            int m;
            scanf("%d", &m);
            for(int j = 0; j < m; j++)
            {
                int x;
                scanf("%d", &x);
                num[x] = i;
            }
        }
        string s;
        while(cin >> s)
        {
            if(s == "STOP") break;
            if(s == "ENQUEUE")
            {
                int x;
                scanf("%d", &x);
                if(que[num[x]].empty()) tque.push(num[x]);
                que[num[x]].push(x);
            }
            if(s == "DEQUEUE")
            {
                printf("%d\n", que[tque.front()].front());
                que[tque.front()].pop();
                if(que[tque.front()].empty())   tque.pop();
            }
        }
    }
}