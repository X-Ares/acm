#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dcmp(double x)
{
	if(x > eps) return 1;
	return x < -eps ? -1 : 0;
}
struct pp
{
	double x,y;
};

struct point 
{
	double x, y;
	point(){
		x=y=0;
	}
	point (double a, double b)
	{
		x=a,y=b;
	}
	inline point operator  - (const point &b)const
	{
		return point(x-b.x,y-b.y);
	}
	inline point operator + (const point &b)const
	{
		return point(x+b.x,y+b.y);
	}
	inline point operator * (const double &b)const
	{
		return point(x*b,y*b);
	}
	inline double dot(const point &b)const 
	{
		return x*b.x+y*b.y;
	}
	inline double cross(const point &b,const point &c)const
	{
		return (b.x-x)*(c.y-y)-(c.x-x)*(b.y-y);
	}
	inline double dis(const point &b)const 
	{
		return sqrt((*this-b).dot(*this-b));
	}
	inline bool Inline(const point &b,const point &c)const 
	{
		return !dcmp(cross(b,c));
	}
	inline bool Onseg(const point &b, const point &c)const 
	{
		return Inline(b,c) && (*this-c).dot(*this-b)<eps;
	}	
};
queue<point> pii;
inline double min(double a, double b)
{
	return a>b?b:a;
}
inline double max(double a,double b)
{
	return a>b?a:b;
}
inline double Sqr(double x)
{
	return(x*x);
}
inline double Sqr(const point &p)
{
	return p.dot(p);
}
point linecross(const point &a, const point &b,const point &c,const point &d)
{
	double u=a.cross(b,c),v=b.cross(a,d);
	return point ((c.x*v+d.x*u)/(u+v),(c.y*v+d.y*u)/(u+v));
}
double lcc(const point &a,const point &b,const point &r,double R,point &p1, point &p2)
{
	point fp=linecross(r,point(r.x+a.y-b.y,r.y+b.x-a.x),a,b);
	double rtol=r.dis(fp);
	double rtos=fp.Onseg(a,b)?rtol:min(r.dis(a),r.dis(b));
	double atob=a.dis(b);
	double fptoe=sqrt(R*R-rtol*rtol)/atob;
	if(rtos>R-eps) return rtos;
	p1=fp+(a-b)*fptoe;
	p2=fp+(b-a)*fptoe;
	return rtos;
}
double sa(const point &r,const point &a,const point &b ,double R)
{
	double A2=Sqr(r-a),B2=Sqr(r-b),C2=Sqr(a-b);
	//printf("%lf %lf %lf %lf %lf %lf\n", r.x,r.y,a.x,a.y,b.x,b.y);
	//printf("%lf %lf %lf\n", A2,B2,C2);
	return R*R*acos((A2+B2-C2)*0.5/sqrt(A2)/sqrt(B2))*0.5; 
}
double tacia(const point &r,const point &a,const point &b,double R)
{
	double adis=r.dis(a),bdis=r.dis(b);
	if(adis<R+eps && bdis<R+eps) return r.cross(a,b)*0.5;
	point ta,tb;
	if(r.Inline(a,b)) return 0.0;
	double rtos=lcc(a,b,r,R,ta,tb);
	if(rtos>R-eps) return sa(r,a,b,R);
	if(adis<R+eps) return r.cross(a,tb)*0.5+sa(r,tb,b,R);
	if(bdis<R+eps) return r.cross(ta,b)*0.5+sa(r,a,ta,R);
	return r.cross(ta,tb)*0.5+sa(r,a,ta,R)+sa(r,tb,b,R);
}
double spica(int n,point r,double R)
{
	int i;
	point ori,p[2];
	//scanf("%lf%lf",&ori.x,&ori.y);
	ori=pii.front();
	pii.pop();
 	p[0]=ori;
	double res=0,if_clock_t;
	for(i=1;i<=n;i++)
	{
		if(i==n) p[i&1]=ori;
		else
		{
			point tt=pii.front();
			p[i&1].x=tt.x,p[i&1].y=tt.y;
			pii.pop();
		 } 
		if_clock_t=dcmp(r.cross(p[~i & 1],p[i & 1]));
		if(if_clock_t<0) res-=tacia(r,p[i & 1],p[~i & 1],R);
		else res+=tacia(r,p[~i & 1],p[i & 1],R);
	}
	return fabs(res);
}
point boom;
int n;
double R;

int main()
{
	double k,x,y,x1,x2,y1,y2;
	int ca=1;
	while(scanf("%d%lf",&n,&k)!=EOF)
	{
		while(!pii.empty())
		{
			pii.pop();
		}
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&x,&y);
			pii.push(point(x,y));
		}
		double x0,yy0,x1,yy1;
		scanf("%lf %lf",&x0,&yy0);
        scanf("%lf %lf",&x1,&yy1);
        double D=(2*k*k*x0-2*x1)/(1-k*k);
		double E=(2*k*k*yy0-2*yy1)/(1-k*k);
		double F=(x1*x1+yy1*yy1-k*k*(x0*x0+yy0*yy0))/(1-k*k);
		R=sqrt(D*D+E*E-4*F)/2;
		boom=point(-D*0.5,-E*0.5);

        printf("Case %d: %.10lf\n",ca++,spica(n,boom,R));
	}
	return 0;
 } 
