//      快速求因子数量 
//      时间复杂度O(logn)

int CountFactor(int n)
{
    int sum = 1;
    for(int i = 2; i*i <= n; i++)
    {
        int cnt = 0;
        while(n%i == 0)
        {
            n /= i;
            cnt++;
        }
        sum *= cnt+1;
    }
    if(n > 1)
        sum *= 2;
    return sum;
}