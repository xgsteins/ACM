//      时间复杂度O(nlogn)
//      可求最长上升子序列长度或者最长非递减子序列长度
//      以及该子序列内容

const int maxn = 100000;
int a[maxn], b[maxn];       // a存储原序列， b为目标最长子序列

int BinSearch(int num, int low, int high)
{
    int mid;
    while(low <= high)
    {
        mid = (low+high) / 2;
        if(num >= b[mid])  low = mid+1;
        else               high = mid-1;
    }
    return low;
}

int DP(int n)                           // n为该序列长度
{
    int len = 1;                        // len为子序列长度
    for(int i = 2; i <= n; i++)
    {
        if(a[i] >= b[len])              // 若大于b最后一个列，直接添加到末尾（此为最长非递减， 将>=修改为>则为最长递增）
        {
            len++;
            b[len] = a[i];
        }
        else                            // 否则在b中查找第一个大于a[i]的位置并替换为a[i]
        {
            int pos = BinSearch(a[i], 1, len);
            b[pos] = a[i];
        }
    }
    return len;
}