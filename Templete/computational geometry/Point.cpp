//      关于计算几何中点的定义及一些相关函数
//      double型到10^14， 没有long long长
//      因此在一些情况下需要注意精度和溢出的问题
#include <cmath>
typedef struct Point
{
    double x, y;
    Point(){}
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
}point;

double CalaArea(point p[], int n)   //计算多边形面积, n为边数
{
    double res = 0;
    for(int i = 0; i < n; i++)
        res += (p[i].x * p[(i+1)%n].y - p[i].y * p[(i+1)%n].x)/2;
    return fabs(res);
}
