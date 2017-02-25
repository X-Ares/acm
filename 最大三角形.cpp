#include<iostream>
#include<algorithm>
#define N 50005
#define max(a,b) a>b?a:b
using namespace std;
struct node 
{
	int x,y;
}dd[N];
int n,stak[N],top,top1;
bool cmp(node a,node b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
 } 
bool judge_right(int o,int a,int b)
{
	int ax=dd[a].x-dd[o].x;
	int bx=dd[b].x-dd[o].x;
	int ay=dd[a].y-dd[o].y;
	int by=dd[b].y-dd[o].y;
	return (__int64)bx*ay>(__int64)ax*by;
}
double area(int o,int a,int b)
{
	int ax=dd[a].x-dd[o].x;
	int bx=dd[b].x-dd[o].x;
	int ay=dd[a].y-dd[o].y;
	int by=dd[b].y-dd[o].y;
	return abs(bx*ay-ax*by)*1.0/2.0;
}
void build_map()
{
	int i;
	top=0;
	sort(dd,dd+n,cmp);
	stak[top++]=0;
	stak[top++]=1;
	for(int i=2;i<n;i++)
	{
		stak[top++]=i;
		while(top>=3)
		{
			if(judge_right(stak[top-3],stak[top-2],stak[top-1]))
				break;
				stak[top-2]=stak[top-1];
				top--;
		}
	}
	top1=top;
	stak[top++]=n-2;
	for(int i=n-3;i>=0;i--)
	{
		stak[top++]=i;
			while(top-top1>=2)
		{
			if(judge_right(stak[top-3],stak[top-2],stak[top-1]))
				break;
				stak[top-2]=stak[top-1];
				top--;
		}
	}
	top--;
	
}
int main()
{
	int i,j,k;
	while(scanf("%d",&n),n!=-1)
	{
		for(int i=0;i<n;i++)
		scanf("%d%d",&dd[i].x,&dd[i].y);
		build_map();
		double ans=0;
		for(int i=0;i<top;i++)
		{
			j=(i+1)%top;
			k=(j+1)%top;
			while(k!=i&&area(stak[i],stak[j],stak[k])<area(stak[i],stak[j],stak[(k+1)%top]))
			k=(k+1)%top;
			if(k==i)
			continue;
			int kk=(k+1)%top;
			while(j!=kk&&k!=i)
			{
				ans=max(ans,area(stak[i],stak[j],stak[k]));
				while(k!=i&&area(stak[i],stak[j],stak[k])<area(stak[i],stak[j],stak[(k+1)%top]))
				k=(k+1)%top;
				j=(j+1)%top;
			}
			
		}
		printf("%.2lf\n",ans);
	}
	return 0;
 } 
