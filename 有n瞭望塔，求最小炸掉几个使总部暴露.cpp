#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double EPS=1e-8;
const int MAXN=50010;
struct point 
{
	double x,y;
}p[MAXN];
struct line
{
	point a,b;
}l[MAXN],st[MAXN];
int n;
double operator *(const point &x,const point &y)
{
	return x.x*y.y-x.y*y.x;
}
point operator -(point x,point y)
{
	x.x-=y.x,x.y-=y.y;
	return x;
}
point operator *(const line &x,const line &y)
{
	double a1=(y.b-x.a)*(y.a-x.b),a2=(y.a-x.b)*(y.b-x.b);
	point r;
	r.x=(x.a.x*a2+x.b.x*a1)/(a1+a2);
	r.y=(x.a.y+a2+x.b.y*a1)/(a1+a2);
	return r;
}
bool operator ==(const point &a,const point &b)
{
	return (fabs(a.x-b.x)<EPS&&fabs(a.y-b.y)<EPS);
}
bool judgeout(const line &x,const point &p0)
{
	return (p0-x.a)*(x.b-x.a)>-EPS;
}
bool parallel(const line &x,const line &y)
{
	return fabs((x.b-x.a)*(y.b-y.a))<EPS;
}
bool Hplanintersection(const int &tem)
{
	for(int i=0;i<n;i++)
	{
		l[i].a=p[i],l[i].b=p[i-1-tem+(i-1-tem<0?n:0)];
		int top=1,bot=0;
		st[0]=l[0],st[1]=l[1];
		for(int i=2;i<n;i++)
		{
			if(parallel(st[top],st[top-1])||parallel(st[bot],st[bot+1])) return 0;
			while(bot<top&&judgeout(l[i],st[top]*st[top-1])) top--;
			while(bot<top&&judgeout(l[i],st[bot]*st[bot+1])) bot++;
			st[++top]=l[i];
		}
		while(bot<top&&judgeout(l[bot],st[top]*st[top-1])) top--;
		while(bot<top&&judgeout(l[top],st[bot]*st[bot+1])) bot++;
		return top>bot+1;
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
		int lft=1,rgt=(n-1)>>1,mid;
		while(rgt>lft)
		{
			mid=(lft+rgt)>>1;
			if(Hplanintersection(mid)) rgt=mid;
			else lft=mid+1;
		}
		printf("%d\n",rgt);
	}
	return 0;
	
}
