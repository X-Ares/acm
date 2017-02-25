#include<iostream>
#include<cmath>
#include<cstdio> 
using namespace std;

struct Tpoint
{
	double x,y;
	Tpoint(){}
	Tpoint(double _x,double _y)
	{
		x=_x;y=_y; 
	}
	Tpoint operator -( const Tpoint &b)const
	{
		return Tpoint(x-b.x,y-b.y);
	}
};
Tpoint p[22222];
double cross(Tpoint a,Tpoint b)
{
	return a.x*b.y-a.y*b.x;
}
double poly_are(Tpoint p[],int n)
{
	double ans=0.0;
	for(int i=1;i<n-1;i++)
	ans+=cross(p[i]-p[0],p[i+1]-p[0]);
	return fabs(ans)/2.0;
}
int main()
{
	int n;
	double ans=0.0;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>p[i].x>>p[i].y;
	ans=poly_are(p,n);
	printf("%.2f",ans);
	
 } 
