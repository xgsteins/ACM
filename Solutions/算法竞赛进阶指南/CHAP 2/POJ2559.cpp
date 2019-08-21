    #include <cstdio>
    #include <iostream>
    #include <stack>
    using namespace std;
    stack<pair<long long, long long> > stk;
    int main()
    {
        long long n;
        while (scanf("%lld", &n) != EOF && n)
        {
            long long res = 0, cnt = 0;
            for (long long i = 0; i < n; i++)
            {
                long long x;
                scanf("%lld", &x);
                if (stk.empty())
                {
                    stk.push(make_pair(x, 1));
                }
                else
                {
                    if (x > stk.top().first)
                    {
                        stk.push(make_pair(x, 1));
                    }
                    else
                    {
                        cnt = 0;
                        while (!stk.empty() && stk.top().first >= x)
                        {
                            long long tmp = stk.top().first, num = stk.top().second;
                            stk.pop();
                            cnt += num;
                            res = max(res, cnt*tmp);
                        }
                        stk.push(make_pair(x, cnt+1));
                    }
                }
            }
            cnt = 0;
            while (!stk.empty())
            {
                long long tmp = stk.top().first, num = stk.top().second;
                stk.pop();
                cnt += num;
                res = max(res, cnt*tmp);
            }
            printf("%lld\n", res);
        }
        return 0;
    }