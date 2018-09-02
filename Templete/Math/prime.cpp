//我也不知道时间复杂度
#include<cstring>
#define maxm (int)1e7
bool ifprime[maxm];//true为素数，false为和数
void prime()
{
	memset(ifprime,1,sizeof(ifprime));
	ifprime[0]=ifprime[1]=false;
	for(int i=2;i<maxm;i++)
		if(ifprime[i])
			for(int k=2;k*i<maxm;k++)
				if(ifprime[k*i])
					ifprime[k*i]=false;
 }
