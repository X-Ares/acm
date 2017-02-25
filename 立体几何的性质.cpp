#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define eps 1e-8
#define zero(x) (((x)>0?(x):(-x))<eps) 
struct point3
{
	double x,y,z;
	point3(){}
	point3(double _x,double _y,double _z)
	{
		x=_x,y=_y,z=_z;
	}
friend	operator /(point3 a,point3 b)
{
	a.x=a.x/b.x,a.y/=b.y,a.z/b.z;
}
};
struct line3
{
	point3 a,b;
	line3(){}
	line3(point3 _a,point3 _b)
	{
		a=_a,b=_b;
	}
};
struct plane3
{
	point3 a,b,c;
	plane3(){}
	plane3(point3 _a,point3 _b,point3 _c)
	{
		a=_a,b=_b,c=_c;
	}
};

point3 xmult(point3 u,point3 v)//叉积 
{
	return point3(u.y*v.z-v.y*u.z,u.z*v.x-u.x*v.z,u.x*v.y-u.y*v.x);
}

double dmult(point3 u,point3 v)//点积 
{
	return u.x*v.x+u.y*v.y+u.z*v.z;
}

point3 subt(point3 u,point3 v)//向量差 
{
	return point3(u.x-v.x,u.y-v.y,u.z-v.z);
}

double vlen(point3 p)//向量大小的计算 
{
	return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}

point3 pvec(plane3 s)//取平面法向量（求法向量） 
{
	return xmult(subt(s.a,s.b),subt(s.b,s.c));
 } 
 
 int dots_onplane(point3 a,point3 b,point3 c,point3 d)//判断四点共面 
 {
 	plane3 ss=plane3(a,b,c);
 	return zero(dmult(pvec(ss),subt(d,a)));//利用点乘判断平面abc法向量与直线ad是否垂直 
 }
 
int parallel(line3 u,line3 v)//判断两直线平行 
{
	return vlen(xmult(subt(u.a,u.b),subt(v.a,v.b)))<eps;//利用差乘判断两直线平行 
 } 
 
 int perpendicular(line3 u,line3 v)//计算两直线垂直 
 {
 	return zero(dmult(subt(u.a,u.b),subt(v.a,v.b)));
  } 
  
  point3 intersection(line3 u,line3 v)//计算两直线的交点 
  {
  	point3 ret=u.a;
  	double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x)); //利用三角形与平行四边形的面积比 
  	ret.x+=(u.b.x-u.a.x)*t;
  	ret.y+=(u.b.y-u.a.y)*t;
  	ret.z+=(u.b.z-u.a.z)*t;
  	cout<<ret.x<<ret.y<<ret.z;
  	cout<<t<<endl;
  	return ret;
   } 
   int main()
   {
   	line3 a[2];
   	for(int i=0;i<2;i++)
   	cin>>a[i].a.x>>a[i].a.y>>a[i].a.z>>a[i].b.x>>a[i].b.y>>a[i].b.z;
   	intersection(a[0],a[1]);
   	
	} 

