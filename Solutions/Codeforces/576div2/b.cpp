#include <bits/stdc++.h>
using namespace std;
int main()
{
    double h, l;
    cin >> h >> l;
    printf("%.7f", (h*h+l*l)/(2.0*h)-h);
}