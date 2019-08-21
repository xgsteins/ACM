#include <bits/stdc++.h>
using namespace std;
stack<char> stk[2333];
int main()
{
    char ch;
    bool error = false, imp = false, flag = false;
    int ind = 0;
    while(ch = getchar())
    {
        if(ch == '\n')  break;
        if(ch == ' ' || error)   continue;
        if(ch == '(')
        {
            ind++;
        }
        else if(ch == ')')
        {
            flag = true;
            if(stk[ind].size() != 3)    imp = true;
            while(!stk[ind].empty())
            {
                if(flag)
                {
                    if(stk[ind].top() >= 'a' && stk[ind].top() <= 'z')
                        flag = false;
                    else
                    {
                        error = true;
                        break;
                    }
                }
                else
                {
                    if(stk[ind].top() >= 'a' && stk[ind].top() <= 'z')
                    {
                        error = true;
                        break;
                    }
                    else
                        flag = true;
                }
                stk[ind].pop();
            }
            ind--;
            if(ind < 0 || flag)
            {
                error = true;
                break;
            }
            stk[ind].push('a');
        }
        else    stk[ind].push(ch);
    }
    if(stk[0].size() != 3)  imp = true;
    flag = true;
    while(!stk[0].empty())
    {
        if(flag)
        {
            if(stk[0].top() >= 'a' && stk[0].top() <= 'z')
                flag = false;
            else
            {
                error = true;
                break;
            }
        }
        else
        {
            if(stk[0].top() >= 'a' && stk[0].top() <= 'z')
            {
                error = true;
                break;
            }
            else
                flag = true;
        }
        stk[0].pop();
    }
    if(error || flag)       puts("error");
    else if(imp)            puts("improper");
    else                    puts("proper");
    return 0;
}