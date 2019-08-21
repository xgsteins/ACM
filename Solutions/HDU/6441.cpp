#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool scan_d(T &ret) 
{
    char c;
    long long sgn;
    if( c=getchar() , c==EOF ) return 0; //EOF
    while(c != '&#8722;' && ( c<'0' || c>'9')) c=getchar();
    sgn = (c=='&#8722;') ? -1 : 1;
    ret = (c=='&#8722;') ? 0 : (c-'0');
    while( c=getchar(), c>='0'&& c<='9' ) ret = ret*10+(c-'0');
    ret *= sgn;
    return 1;
}


void cal(long long a)
{
    if (a % 2 == 1)
    {
        long long int k = (a - 1) / 2;
        long long int b = 2 * k * (k + 1);
        long long int c = 2 * k * (k + 1) + 1;
        cout << b << " " << c << endl;
    }
    else if (a % 8 == 0)
    {
        long long int k = a / 8;
        long long int b = 16 * k * k - 1;
        long long int c = 16 * k * k + 1;
        cout << b << " " << c << endl;
    }
    else if (a % 2 == 0)
    {
        if (a == 4)
        {
            puts("3 5");
            //cout << "3 5" << endl;
        }
        else
        {
            long long int a1 = a;
            while (a%2 == 0)
            {
                a >>= 1;
            }
            long long int beishu = a1 / a;
            long long int k = (a - 1) / 2;
            long long int b = beishu * (2 * k * (k + 1));
            long long int c = beishu * (2 * k * (k + 1) + 1);
            cout << b << " " << c << endl;
        }
    }
}

int main()
{
    int T;
    scan_d(T);
    while (T--)
    {
        long long int n, a, ans;
        scan_d(n), scan_d(a);
        if (n > 2 || n == 0)
        {
            puts("-1 -1");
            //cout << "-1 -1" << endl;
        }
        else if (n == 2)
        {
            cal(a);
        }
        else if (n == 1)
        {
            cout << "1 " << a+1 << endl;
        }
    }
    return 0;
}