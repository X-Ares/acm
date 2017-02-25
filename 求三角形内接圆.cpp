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
	//求面积 
	return fabs(t.t[0].x*t.t[1].y+t.t[1].x*t.t[2].y+t.t[2].x*t.t[0].y-t.t[1].x*t.t[0].y-
	t.t[2].x*t.t[1].y-t.t[0].x*t.t[2].y)/2;
}
double distance(const point p1,const point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
Circle tmp;
Circle neixin(const Triangle t)
{
	//内接圆
	double a,b,c,angleA,angleB,angleC,p1,p2,p3,f1,f2;
	double xa,ya,xb,yb,xc,yc;
	a=distance(t.t[0],t.t[1]);
	b=distance(t.t[2],t.t[1]);
	c=distance(t.t[0],t.t[2]);
//	printf("%lf %lf %lf\n",a,b,c);//
	tmp.r=2*triangleArea(t)/(a+b+c);
	angleA=acos((b*b+c*c-a*a)/(2*b*c));
	angleB=acos((a*a+c*c-b*b)/(2*a*c)); 
	angleC=acos((b*b+a*a-c*c)/(2*a*b));  
	p1=sin(angleA/2);
	p2=sin(angleB/2);
	p3=sin(angleC/2);
	xa=t.t[0].x;ya=t.t[0].y;
	xb=t.t[1].x;yb=t.t[1].y;
	xc=t.t[2].x;yc=t.t[2].y;
	//cout<<p2<<endl;
	f1=((tmp.r/p2)*(tmp.r/p2)-(tmp.r/p1)*(tmp.r/p1)+xa*xa-xb*xb+ya*ya-yb*yb)/2;
	f2=((tmp.r/p3)*(tmp.r/p3)-(tmp.r/p1)*(tmp.r/p1)+xa*xa-xc*xc+ya*ya-yc*yc)/2;
	//cout<<f1<<f2<<endl;
	tmp.center.x=(f1*(ya-yc)-f2*(ya-yb))/((xa-xb)*(ya-yc)-(xa-xc)*(ya-yb));
	tmp.center.y=(f1*(xa-xc)-f2*(xa-xb))/((ya-yb)*(xa-xc)-(ya-yc)*(xa-xb));	
	return tmp; 
	
}

	

Triangle t;
Circle ans;
int main()
{
	for(int i=0;i<3;i++)
	cin>>t.t[i].x>>t.t[i].y; 
	 neixin(t);
	printf("%lf %lf %lf\n",tmp.center.x,tmp.center.y,tmp.r);
		
}

