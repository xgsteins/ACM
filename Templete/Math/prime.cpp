//我也不知道时间复杂度
#include<cstring>
bool ifprime[10000000];//1为素数，0为和数
void prime()
{
	int i,k;
	memset(ifprime,1,sizeof(ifprime));
	ifprime[0]=ifprime[1]=false;
	for(i=2;i<10000000;i++)
		if(ifprime[i])
			for(k=2;k*i<10000000;k++)
				ifprime[k*i]=false;
 }
