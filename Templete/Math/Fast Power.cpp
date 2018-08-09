//      时间复杂度O(logn)
//      用于快速算底数n次幂
//      注意数据范围随题目要求更改


int FastPow(int x, int n)       // x为底数， n为幂次
{
    int res = 1, base = x;
    while(n != 0)
    {
        if(n&1)
            res *= base;
        base *= base;
        n >>= 1;
    }
    return res;
}