#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;
priority_queue<int, vector<int>, less<int>> que1;
priority_queue<int, vector<int>, greater<int>> que2;
int main()
{
    int p;
    cin >> p;
    for (int ind = 1; ind <= p; ind++)
    {
        while (!que1.empty())
            que1.pop();
        while (!que2.empty())
            que2.pop();
        int inddd, n, cnt = 0, flag = 1;
        cin >> inddd >> n;
        cout << ind << ' ' << (n + 1) / 2 << endl;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (!que1.empty() && x > que1.top())
                que2.push(x);
            else
                que1.push(x);
            int len1 = que1.size(), len2 = que2.size();
            while (len1 - len2 > 1)
            {
                int tmp = que1.top();
                que1.pop();
                que2.push(tmp);
                len1--;
                len2++;
            }
            len1 = que1.size(), len2 = que2.size();
            while (len2 - len1 >= 1)
            {
                int tmp = que2.top();
                que2.pop();
                que1.push(tmp);
                len2--;
                len1++;
            }
            if (i % 2 == 0)
            {
                cout << que1.top() << ' ';
                if (i % 2 == 0)
                {
                    if (((i + 2) / 2) % 10 == 0)
                        puts("");
                    else if (n % (i + 1) == 0 && i + 1 == n)
                        puts("");
                }
            }
        }
    }
    return 0;
}