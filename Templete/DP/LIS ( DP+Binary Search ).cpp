const int maxn =30005;
const int INF=0x7fffffff;
int low[maxn],a[maxn];//字符串存在a里，从a[1]开始
int n,ans;
int binary_search(int *a,int r,int x)
//二分查找，返回a数组中第一个>=x的位置
{
    int l=1,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(a[mid]<x)
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}
int LIS(int n)//字符数量
{
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> acbd0b867810d092a9b38b11ca0c418909f2b0b2
    for(int i=1;i<=n;i++)
        low[i]=INF;//由于low中存的是最小值，所以low初始化为INF
    low[1]=a[1];
    ans=1;//初始时LIS长度为1
    for(int i=2;i<=n;i++)
<<<<<<< HEAD
=======
    int len = 1;                        // len为子序列长度
    b[1] = a[1];
    for(int i = 2; i <= n; i++)
>>>>>>> 53e08d93253ec01717ca3ea3ae18b798ca7b6b2e
=======
>>>>>>> acbd0b867810d092a9b38b11ca0c418909f2b0b2
    {
        if(a[i]>low[ans])//若a[i]>=low[ans]，直接把a[i]接到后面
            low[++ans]=a[i];
        else //否则，找到low中第一个>=a[i]的位置low[j]，用a[i]更新low[j]
            low[binary_search(low,ans,a[i])]=a[i];
    }
    return ans;//返回最长上升子序列长度
}
