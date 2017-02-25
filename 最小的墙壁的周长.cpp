#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
#define size 1000
struct point 
{
	int x,y;
}x[size];
int n,l,ans[size],cnt,sta[size],tail;
bool cmp(point a,point b)
{
	return (a.y<b.y||a.y==b.y&&a.x<b.x);
}
bool Crossleft(point p1,point p2,point p3)//是否严格左转，共线不算左转 
{
	return ((p3.x-p1.x)*(p2.y-p1.y)-(p2.x-p1.x)*(p3.y-p1.y))<0;
}
void jarvis()
{
	tail=cnt=0;
	sort(x,x+n,cmp);
	sta[tail++]=0,sta[tail++]=1;
	for(int i=2;i<n;i++)
	{
		while(tail>1&&!Crossleft(x[sta[tail-1]],x[sta[tail-2]],x[i]))
		tail--;
		sta[tail++]=i;
	}
	for(int i=0;i<tail;i++)
	ans[cnt++]=sta[i];
	tail=0;sta[tail++]=n-1;sta[tail++]=n-2;
	for(int i=n-3;i>=0;i--)
	{
		while(tail>1&&!Crossleft(x[sta[tail-1]],x[sta[tail-2]],x[i]))
		tail--;
		sta[tail++]=i;
	}
	for(int i=0;i<tail;i++)
	ans[cnt++]=sta[i];
}
int main()
{
	scanf("%d%d",&n,&l);
	for(int i=0;i<n;i++)
	scanf("%d%d",&x[i].x,&x[i].y);
	jarvis();
	double re=4*acos(0.0)*l;
	for(int i=0;i<cnt-1;i++)
	re+=sqrt((x[ans[i]].x-x[ans[i+1]].x)*(x[ans[i]].x-x[ans[i+1]].x)+(x[ans[i]].y-x[ans[i+1]].y)*(x[ans[i]].y-x[ans[i+1]].y)*1.0);
	printf("%.0f\n",re);
	return 0;	
} 
