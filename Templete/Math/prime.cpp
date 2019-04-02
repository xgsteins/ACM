// 埃氏筛
// 时间复杂度 O(nloglogn)

const int maxn = (int)1e7;
int isP[maxn], prime[maxn-1], cnt; // 0为质数
void countPrime()
{
	for (int i = 2; i <= maxn; i++)
	{
		if (!isP[i])
		{
			prime[cnt++] = i;
			for (long long j = i; j * i < maxn; j++)
			{
				isP[i * j] = 1;
			}
		}
	}
}
