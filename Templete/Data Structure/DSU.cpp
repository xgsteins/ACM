//      DSU���鼯
//      ʱ�临�Ӷ�O(M Alpha(N), ����Alpha��Ackerman������ĳ��������, NΪ�ϲ�����, MΪ���Ҵ���
//      �ռ临�Ӷ�O(n)
const int INF = 0x3f3f3f3f;
const int maxn = 1000;
int pre[maxn];//���浱ǰ����ĸ��ڵ�
int Find(int x)//Ѱ�Ҹ��ڵ�
{
    int r = x;
    while(pre[r] != r)
        r=pre[r];
    int i = x, j;
    while(i != r)//ѹ��·��
    {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

void mix(int x, int y)//�������ӹ�ϵ
{
	int fx = Find(x);
	int fy = Find(y);
	if(fx != fy)
    {
		pre[fx] = fy;
	}
}
