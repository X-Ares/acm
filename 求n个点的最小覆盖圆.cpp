#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1005;
const double eps=1e-6;
struct point
{
	double x,y;
};
struct Circle
{
	double r;
	point center;
};
Circle c;
point a[maxn];
struct Triangle
{
	point t[3];
};
double triangleArea(const Triangle t)
{
	//ÇóÃæ»ý 
	return fabs(t.t[0].x*t.t[1].y+t.t[1].x*t.t[2].y+t.t[2].x*t.t[0].y-t.t[1].x*t.t[0].y-
	t.t[2].x*t.t[1].y-t.t[0].x*t.t[2].y)/2;
}
double distance(const point p1,const point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
	
Circle waixin(const Triangle t)
{
	Circle tmp;
	double a,b,c,c1,c2;
	double xa,ya,xb,yb,xc,yc;
	a=distance(t.t[0],t.t[1]);
	b=distance(t.t[2],t.t[1]);
	c=distance(t.t[0],t.t[2]);
	//printf("%.2lf  %.2lf  %.2lf\n",a,b,c);
	xa=t.t[0].x;ya=t.t[0].y;
	xb=t.t[1].x;yb=t.t[1].y;
	xc=t.t[2].x;yc=t.t[2].y;
	tmp.r=a*b*c/triangleArea(t)/4;
	c1=(xa*xa+ya*ya-xb*xb-yb*yb)/2;
	c2=(xa*xa+ya*ya-xc*xc-yc*yc)/2;
	tmp.center.x=(c1*(ya-yc)-c2*(ya-yb))/((xa-xb)*(ya-yc)-(xa-xc)*(ya-yb));
	tmp.center.y=(c1*(xa-xc)-c2*(xa-xb))/((ya-yb)*(xa-xc)-(ya-yc)*(xa-xb));
	return tmp;
}
Circle Mincircle1(int tce,Triangle ce)
{
	Circle tmp;
	if(tce==0)
	tmp.r=-2;
	else if(tce==1)
	{
		tmp.center=ce.t[0];
		tmp.r=0;
	}
	else if(tce==2)
	{
		tmp.r=distance(ce.t[0],ce.t[1])/2;
		tmp.center.x=(ce.t[0].x+ce.t[1].x)/2;
		tmp.center.y=(ce.t[0].y+ce.t[1].y)/2;
	}
	else if(tce==3) tmp= waixin(ce);
	return tmp;
}
void Mincircle(int t,int tce,Triangle ce)
{
	int i,j;
	point tmp;
	c=Mincircle1(tce,ce);
	if(tce==3) return ;
	for(i=1;i<=t;i++)
	{
		if(distance(a[i],c.center)>c.r)
		{
			ce.t[tce]=a[i];
			Mincircle(i-1,tce+1,ce);
			tmp=a[i];
			for(j=i;j>=2;j--)
			{
				a[j]=a[j-1];
			}
			a[1]=tmp;
		}
	}
	
}
void run(int n)
{
	Triangle ce;
	int i;
	Mincircle(n,0,ce);
	printf("%.2lf %.2lf %.2lf\n",c.center.x,c.center.y,c.r);
}
Triangle t;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
		run(n);
	}
	return 0;
}

