//      时间复杂度O(logn)
//      用于快速算底数n次幂
//      注意数据范围随题目要求更改
//      矩阵快速幂只要修改传入数据类型并重载*运算符即可


const int maxn = 100;

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

// 矩阵定义及乘法运算符重载
#include <cstring>

struct Matrix
{
    int n, m;
    int num[maxn][maxn];            //  不能太大， 太大在main里声明会栈溢出

    void clear()
    {
        n = m = 0;
        memset(num, 0, sizeof(num));
    }

    Matrix operator *(const Matrix &x) const
    {
        Matrix temp;
        temp.clear();
        temp.n = n;
        temp.m = x.m;

        for(int i =  0; i < n; i++)
            for(int j = 0; j < x.m; j++)
                for(int k = 0; k < m; k++)
                    temp.num[i][j] += num[i][k]*x.num[k][j];

        return temp;
    }
};