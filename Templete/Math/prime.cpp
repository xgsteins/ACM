//我也不知道时间复杂度
int ifprime[1000000];//1为素数，0为和数
void prime()
{
	int i,k;
	for(i=0;i<1000000;i++)
		ifprime[i]=1;
	ifprime[0]=ifprime[1]=0;
	for(i=2;i<1000000;i++)
		if(ifprime[i]==1)
			for(k=1;k*i<1000000;k++)
				ifprime[k*i]=0;
 }
