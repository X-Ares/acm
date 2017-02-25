#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct point 
{
	double x,y;
	point(double x = 0,double y = 0) :x(x),y(y){}
	double len()
	{
		return sqrt(x*x+y*y+eps);
	}
};
int judge(point p,point v)
{
	point temp;
	temp.x=-1*p.x;
	temp.y=-1*p.y;
	return (temp.x*v.x+temp.y*v.y<0)||(fabs(temp.x*v.x+temp.y*v.y)<eps);
}
double dis(point p1,point p2)
{
	 return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y))+eps;
}
double p_dis(point v,point p)
{
	if(fabs(v.x*p.y - p.x*v.y) < eps) return 0;
    double si = (v.x*p.y-p.x*v.y)/dis(point(0,0),v)/p.len();
    return p.len() * fabs(si);
}
int main()
{
	double Rm,R,r;
	point p,v;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf",&Rm,&R,&r,&p.x,&p.y,&v.x,&v.y)!=EOF)
	{
		double V=v.len();
		double D=p_dis(v,p);  //得到硬币到过原点的运动路线的距离
		double ans=0;
		if(judge(p,v))
		{
			printf("0.0000\n");
			continue;
		}
		if(D<Rm+r)
		{
		double l = sqrt((R+r)*(R+r)-D*D+eps) - sqrt((Rm+r)*(Rm+r)-D*D+eps);
		ans=(l/V);
		}
		else if(D > Rm+r && D < R + r)
		{
			ans = sqrt((R+r)*(R+r) - D*D+eps) / V;
		}
		else
		{
			printf("0.0000\n");
			continue;
		}
		printf("%.3lf\n",2*ans+eps);
	}
	return 0;
}
