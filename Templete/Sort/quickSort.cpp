#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int a[maxn] = {233,114514,1919,19260817,9};

void qSort(int l, int r)
{
    if(l >= r)  return;
    int mid = l-1, x = a[r];
    for(int j = l; j <= r-1; j++)
    {
        if(a[j] < x)
        {
            mid++;
            swap(a[mid], a[j]);
        }
    }
    swap(a[++mid], a[r]);
    qSort(l, mid-1);
    qSort(mid+1, r);
}

int main()
{
    qSort(0, 4);
    for(int i = 0; i <= 4; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}