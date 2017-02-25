#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
const double eps=1e-8;
struct point 
{
	double x,y;
};
struct vector
{
	point start,end;
};
point p;
double intersect(point a1, point b1, point a2, point b2)
{
double x1 = a1.x, x2 = b1.x, x3 = a2.x, x4 = b2.x;
double y1 = a1.y, y2 = b1.y, y3 = a2.y, y4 = b2.y;
double y =(y3-y1+x1*(y2-y1)/(x2-x1)-x3*(y4-y3)/(x4-x3))/((y2-y1)/(x2-x1)-(y4-y3)/(x4-x3));
double x=x3+(x4-x3)*(y2-y3)/(y4-y3);
//printf("%lf %lf\n",x,y);
return y;

}
point dot[50],dot1[50]; 
bool ok;
double ans;
int n;
 void work(point a,point b)
{
	b.y-=1;
	for(int i=0;i<n;i++)
	{
		point p, q1, q2;
		 p.x = dot[i].x;
		 p.y = a.y - (b.y - a.y) / (b.x - a.x) * (a.x - p.x);
		if ((p.y + eps < dot[i].y && p.y - eps > dot[i].y -1) || abs(p.y
		- dot[i].y) < eps || abs(p.y - dot[i].y +1) < eps)
		continue;
		if(i==0)
		return;
		if (p.y - eps > dot[i].y)
	 ans = max(ans, intersect(a, b, dot[i -1], dot[i]));
	else
	 {
	 q1 = dot[i -1];
	 q1.y -=1;
	 q2 = dot[i];
	 q2.y -=1;
	 ans = max(ans, intersect(a, b, q1, q2));
	 }
	return;
	 }
	 ok =true;	
}
int main()
{
	
	while(cin>>n&&n)
	{
		ok=false;
		
		for(int i=0;i<n;i++)
		{
		cin>>dot[i].x>>dot[i].y;
		}	
		ans=dot[0].x;
	//	intersect(dot[0],dot[1],dot[2],dot[3]);
		for(int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if(i!=j&&!ok)
				work(dot[i],dot[j]);
			 } 
		}
		if(ok)
		printf("Through all the pipe.\n");
		else
		 printf("%.2f\n", ans);
	 }
		return 0;
}
