#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct point
{
	double x,y;
	point(){}
	point(double _x,double _y)
	{
		x=_x;y=_y;
	}

}a,b,c,p;
point wx(point a,point b,point c)
{
	double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;
	double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;
	double d=a1*b2-a2*b1;
	return point(a.x+(c1*b2-c2*b1)/d, a.y+(a1*c2-a2*c1)/d);
}
double ds(point a,point b)
{
	double ans=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	return ans;
}
double min(double a,double b)
{
	double ans=a<b?a:b;
	return ans;
	
}
double max(double a,double b)
{
	return a>b?a:b;
}
double cha(point a,point b)
{
	return (a.x*b.y-a.y*b.x);
}
int main()
{
	int t=1;
	point xin;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&p.x,&p.y)!=EOF)
	{
		double x,y,z,ans=0,tmp=0;
		xin=wx(a,b,c);
		x=max(ds(xin,a)-ds(xin,p),ds(xin,p)-ds(xin,a));
		y=(ds(p,a));
		z=(ds(p,c));
		double f1=atan2(a.y-xin.y,a.x-xin.x);
		double f2=atan2(b.y-xin.y,b.x-xin.x);
		double f3=atan2(c.y-xin.y,c.x-xin.x);
		double f4=atan2(p.y-xin.y,p.x-xin.x);
		printf("Case %d: ",t++);
			if(f1<f3)
			{
				if((f1<=f2&&f3>=f2)==(f1<=f4&&f3>=f4))
				{
					printf("%.3lf\n",x);
						continue;
				}
				else
				{
					printf("%.3lf\n",min(y,z));
					continue;
				}
				
			}
			else
			{
				if((f3<=f2&&f1>=f2)==(f3<=f4&&f1>=f4))
				{
					printf("%.3lf\n",x);
						continue;
				}
				else
				{
					printf("%.3lf\n",min(y,z));
						continue;
				}
				
			}

	}
}
