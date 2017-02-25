#include<iostream>
using namespace std;
struct point 
{
	double x,y;
};
struct vector
{
	point start,end;
};
point p;
double multi(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int Across(vector v1,vector v2)
{
	if(max(v1.start.x,v1.end.x)>=min(v2.start.x,v2.end.x)&&max(v2.start.x,v2.end.x)>=min(v1.start.x,v1.end.x)&&
	max(v1.start.y,v1.end.y)>=min(v2.start.y,v2.end.y)&&max(v2.start.y,v2.end.y)>=min(v1.start.y,v1.end.y)
	&&multi(v2.start,v1.end,v1.start)*multi(v1.end,v2.end,v1.start)>=0
	&&multi(v1.start,v2.end,v2.start)*multi(v2.end,v1.end,v2.start)>=0)
	return 1;
	return 0;
}
int  intersection(vector u,vector v)
{
	
	if(Across(u,v))
	{
		p.x=(multi(v.end,u.end,u.start)*v.start.x-multi(v.start,u.end,u.start)*v.end.x)/(multi(v.end,u.end,u.start)-multi(v.start,u.end,u.start));
		p.y=(multi(v.end,u.end,u.start)*v.start.y-multi(v.start,u.end,u.start)*v.end.y)/(multi(v.end,u.end,u.start)-multi(v.start,u.end,u.start));
		
		return 1;
	}
	return 0;
}
int main()
{

	vector a,b;
	cin>>a.start.x>>a.start.y>>a.end.x>>a.end.y;
	cin>>b.start.x>>b.start.y>>b.end.x>>b.end.y;
	intersection(a,b);
	printf("%.2lf %.2lf\n",p.x,p.y);
	return 0;
	
 } 
