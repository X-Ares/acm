#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define zero(x) (((x)>0?(x):-(x))<eps)  
const double eps=1e-8; 
struct point
{
	double x,y,z;
	point(double x=0,double y=0,double z=0):x(x),y(y),z(z){}  
};
struct line
{
	point a,b;
};
struct plane 
{
	point a,b,c;
};
typedef point vec3;  
vec3 operator + (vec3 a,vec3 b){  
    return vec3(a.x+b.x,a.y+b.y,a.z+b.z);  
}  
vec3 operator - (vec3 a,vec3 b){  
    return vec3(a.x-b.x,a.y-b.y,a.z-b.z);  
}  
vec3 operator * (vec3 a,double p){  
    return vec3(a.x*p,a.y*p,a.z*p);  
}  
vec3 operator / (vec3 a,double p){  
    return vec3(a.x/p,a.y/p,a.z/p);  
} 
point operator * (point a,point b){  
    return point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);  
} 
point xmult(point u,point v)
{
	point ret;
	ret.x=u.y*v.z-v.y*u.z;
	ret.y=u.z*v.x-u.x*v.z;
	ret.z=u.x*v.y-u.y*v.x;
	return ret;
}
double dmult(point u,point v)
{
	return u.x*v.x+u.y*v.y+u.z*v.z;
 } 
 point subt(point u,point v)
 {
 	point ret;
	ret.x=u.x-v.x;
	ret.y=u.y-v.y;
	ret.z=u.z-v.z;
	return ret;
 }
 
 double volume(point a,point b,point c,point d)//四面体体积 
 {
 	return fabs(dmult((b-a)*(c-a),(d-a)))/6.0;
 }
 
 point pvec(point s1,point s2,point s3)/*****平面法向量*********/  
 {
 	return xmult(subt(s1,s2),subt(s2,s3));
 }
 
 double dis(point p1,point p2)/*****两点距离***********/  
 {
 	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
 }
 /*****向量长度***********/  
double vlen(point p){  
    return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);  
} 
/*****点到平面距离***************/  
double ptoplane(point p,point s1,point s2,point s3){  
    return fabs(dmult(pvec(s1,s2,s3),subt(p,s1)))/vlen(pvec(s1 ,s2,s3));  
}  
/*****判四点共面*********/  
int dots_onplane(point a,point b,point c,point d){  
    return zero(dmult(pvec(a,b,c),subt(d,a)));  
}  
/*****判三点共线*********/  
int dots_inline(point p1,point p2,point p3){  
    return vlen(xmult(subt(p1,p2),subt(p2,p3)))<eps;  
}  
/*****点到平面的投影*****/  
point shade_ptoplane(point p, point a, point b, point c) {  
    point nor = (b - a) * (c - a);  
    point nor0 = ( nor * dmult(nor, p - a) ) / vlen(nor) / vlen(nor);  
    return (p - nor0);  
} 

double Length(point a){  
    return sqrt(dmult(a,a));  
}  
point Cross(point a,point b){  
    return point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);  
} 
double area2(point a,point b,point c){  
    return Length(Cross(b-a,c-a))*0.5; 
}
int main()
{
	point p1,p2,p3,p4;
	while(cin>>p1.x>>p1.y>>p1.z>>p2.x>>p2.y>>p2.z>>p3.x>>p3.y>>p3.z>>p4.x>>p4.y>>p4.z)
	{
		if(dots_onplane(p1,p2,p3,p4)||dots_inline(p1,p2,p3)||dots_inline(p1,p2,p4)||dots_inline(p4,p2,p3)||
		dots_inline(p1,p4,p3))
		{
			printf("O O O O\n");
			continue;
		}
		double s1=area2(p2,p3,p4);  
        double s2=area2(p1,p3,p4);  
        double s3=area2(p1,p2,p4);  
        double s4=area2(p1,p2,p3);  
        double R=3.0*volume(p1,p2,p3,p4)/(s1+s2+s3+s4);  
        double x1=(s1*p1.x+s2*p2.x+s3*p3.x+s4*p4.x)/(s1+s2+s3+s4);  
        double y1=(s1*p1.y+s2*p2.y+s3*p3.y+s4*p4.y)/(s1+s2+s3+s4);  
        double z1=(s1*p1.z+s2*p2.z+s3*p3.z+s4*p4.z)/(s1+s2+s3+s4);  
        printf("%.4f %.4f %.4f %.4f\n",x1,y1,z1,R); 	
	}
	return 0;
	
 } 
