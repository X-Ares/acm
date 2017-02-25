#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct point
{
	double x,y;
};
struct Circle
{
	double r;
	point center;
};
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
	Circle tmp;
Circle waixin(const Triangle t)
{

	double a,b,c,c1,c2;
	double xa,ya,xb,yb,xc,yc;
	a=distance(t.t[0],t.t[1]);
	b=distance(t.t[2],t.t[1]);
	c=distance(t.t[0],t.t[2]);
	printf("%lf %lf %lf\n",a,b,c);
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
Triangle t;
Circle ans;
int main()
{
	for(int i=0;i<3;i++)
	cin>>t.t[i].x>>t.t[i].y; 
	 waixin(t);
	printf("%lf %lf %lf\n",tmp.center.x,tmp.center.y,tmp.r);
	
	
}

