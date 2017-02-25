#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
int c;
const double eps = 1e-8;
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
struct Point
{
    double  x,y;
    int num;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }
    //叉积
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    //点积
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
};
 Point p[1000];
//*两点间距离
double dist(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}
bool cmp(Point a,Point b)
{
	double tmp=(a-p[c])^(b-p[c]);
	if(sgn(tmp)==0)
	return dist(a,p[c])<dist(b,p[c]);
	if(sgn(tmp)<0)
	return false;
	else
	return true;
	
} 

 int main()
 {
 	int t,n,num;
 	cin>>t;
 	while(t--)
 	{
 		cin>>n;
 		for(int i=0;i<n;i++)
 		{
 		cin>>p[i].num>>p[i].x>>p[i].y;
 		if(p[0].y>p[i].y||p[0].y==p[i].y&&p[0].x>p[i].x)
 		swap(p[0],p[i]);
 		}
 	 c=0;
 		for(int i=1;i<n;i++)
 		{
 			sort(p+i,p+n,cmp);
 			c++;
		}
		printf("%d",n);
		for(int i=0;i<n;i++)
		printf(" %d",p[i].num);
		puts("");
	 }
 }
