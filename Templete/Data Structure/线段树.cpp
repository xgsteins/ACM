//      简单线段树
//      建树 O(nlog(n))
//      查询 O(log(n))
const int maxm = 100000 + 100;
int num[maxm];
int sum;
struct tree
{
	 int left,right;
	 int n;
}t[maxm<<1 + 100];

void make(int l,int r,int k)
{
		if(l==r)
		{
			t[k].left=t[k].right=l;
			t[k].n=num[k];
			return;
		}
		t[k].left=l;
		t[k].right=r;
		make(l,(l+r)>>1,k<<1);
		make((l+r)>>1+1,r,k<<1|1);
		t[k].n = t[k<<1].n + t[k<<1|1].n;
}//建树

void Query(int l,int r,int k)
{
		if(l<=t[k].left&&r>=t[k].right)
		{
			sum+=t[k].n;
			return;
		}
		if(l<=(t[k].left+t[k].right)>>1)
			Query(l,r,k<<1);
		if(r>=(t[k].left+t[k].right)>>1+1)
			Query(l,r,k<<1|1);
}//查询
