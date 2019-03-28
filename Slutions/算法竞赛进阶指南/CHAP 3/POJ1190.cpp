#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
int n, m, res = 2147483647;
int rad[22], high[22];
void dfs(int layer, int area, int vol)
{
    if(layer == 0)
    {
        if(vol == n)
            res = min(res, area+rad[m]*rad[m]);
        return;
    }
    int tmp = ((layer-1)*layer)>>1;
    if(vol + tmp > n)    return;
    if(area+tmp+rad[m]*rad[m] > res) return;
    int tmp1 = min(rad[layer+1]-1, (int)sqrt(n-vol));
    for(int i = tmp1; i >= layer; i--)
    {
        rad[layer] = i;
        if(2*(n-vol)/rad[layer]+area > res)    break;
        int tmp2 = min(high[layer+1]-1, (n-vol)/(rad[layer]*rad[layer]));
        for(int j = tmp2; j >= layer; j--)
        {
            high[layer] = j;
            dfs(layer-1, area+rad[layer]*high[layer]*2, vol+rad[layer]*rad[layer]*high[layer]);
        }
    }
}
int main()
{
    memset(rad, 0x3f, sizeof(rad));
    memset(high, 0x3f, sizeof(high));
    scanf("%d%d", &n, &m);
    dfs(m, 0, 0);
    if(res == 2147483647)   puts("0");
    else               printf("%d", res);
}