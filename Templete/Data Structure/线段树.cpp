//      简单线段树
//      建树 O(nlog(n))
//      查询 O(log(n))
//			点修改 O(logn)
//			段修改 O(nlogn)
#include<algorithm>
using namespace std;
const int maxm = 1000000 + 100;//点的数量
int num[maxm];
int b[maxm];
int Max,Min,sum;
struct tree
{
    int left,right;
    int maxx,minn;
    int sum;
}t[maxm*3 + 100];
void push_up(int k)
{
    t[k].maxx =max( t[k<<1].maxx, t[k<<1|1].maxx);
    t[k].minn =min( t[k<<1].minn, t[k<<1|1].minn);
    t[k].sum =t[k<<1].sum+t[k<<1|1].sum;
}
void refresh(int k)//点标号
{
  k=b[k]>>1;
  while(k>0)
  {
    push_up(k);
    k=k>>1;
  }
}//快速点更新
void make(int l,int r,int k)//1，n，1
{
		if(l==r)
		{
			t[k].left=t[k].right=l;
	        t[k].maxx=t[k].minn=t[k].sum=num[l];
			b[l]=k;//不需要点修改的时候这行可以删掉
			return;
		}
		t[k].left=l;
		t[k].right=r;
		make(l,(l+r)>>1,k<<1);
		make(((l+r)>>1)+1,r,k<<1|1);
		push_up(k);
}//建树
void Add(int l,int r,int k,int x)//左端点，右端点，1，加x
{
		if(t[k].left==t[k].right)
		{
			t[k].sum+=x;
			return;
		}
		if(l<=(t[k].left+t[k].right)>>1)
				Add(l,r,k<<1,x);
		if(r>(t[k].left+t[k].right)>>1)
				Add(l,r,k<<1|1,x);
		push_up(k);
}//段加法
void add(int d,int x)//点标号，加x
{
		num[d]+=x;
		refresh(d);
}//点加法
void Sub(int l,int r,int k,int x)//左端点，右端点，1，减x
{
		if(t[k].left==t[k].right)
		{
			t[k].sum-=x;
			return;
		}
		if(l<=(t[k].left+t[k].right)>>1)
				Sub(l,r,k<<1,x);
		if(r>(t[k].left+t[k].right)>>1)
				Sub(l,r,k<<1|1,x);
		push_up(k);
}//段减法
void sub(int d,int x)//点标号，减x
{
		num[d]-=x;
		refresh(d);
}//点减法
void Query(int l,int r,int k)//左端点，右端点，，1
{
    if(l<=t[k].left&&r>=t[k].right)
    {
        Max=max(Max,t[k].maxx);
        Min=min(Min,t[k].minn);
        sum+=t[k].sum;
        return;
    }
    if(l<=(t[k].left+t[k].right)>>1)
        Query(l,r,k<<1);
    if(r>(t[k].left+t[k].right)>>1)
        Query(l,r,k<<1|1);
}//查询段和
