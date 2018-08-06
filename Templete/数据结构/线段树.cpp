//简单线段树
//建树 O(nlog(n))
//查询 O(log(n))
const int maxm = 100000 + 100;
int num[maxm]
int sum;
struct tree
{
	 int left,right;
	 int n;
}t[2 * maxm + 100];
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
	make(l,(l+r)/2,2*k);
	make((l+r)/2+1,r,2*k+1);
	t[k].n = t[2*k].n + t[2*k+1].n;
}//建树
void Query(int l,int r,int k)
{
	if(l<=t[k].left&&r>=t[k].right)
	{
		sum+=t[k].n;
		return;
	}
	if(l<=(t[k].left+t[k].right)/2)
		Query(l,r,2*k,a);
	if(r>=(t[k].left+t[k].right)/2+1)
		Query(l,r,2*k+1,a);
}//查询
