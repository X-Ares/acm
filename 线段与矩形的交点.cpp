#include<iostream>
#include<cstdio>
using namespace std;
struct point 
{
	double x,y;
};
struct vector
{
	point start,end;
};

double multi(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int Across(vector v1,vector v2)
{
	if(max(v1.start.x,v1.end.x)>=min(v2.start.x,v2.end.x)&&max(v2.start.x,v2.end.x)>=min(v1.start.x,v1.end.x)
	&&max(v1.start.y,v1.end.y)>=min(v2.start.y,v2.end.y)&&max(v2.start.y,v2.end.y)>=min(v1.start.y,v1.end.y)
	&&multi(v2.start,v1.end,v1.start)*multi(v1.end,v2.end,v1.start)>=0
	&&multi(v1.start,v2.end,v2.start)*multi(v2.end,v1.end,v2.start)>=0)
	return 1;
	return 0;
}
vector line[10],l;
point p[10];
int main()
{
	double x1,y1,x2,y2;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>l.start.x>>l.start.y>>l.end.x>>l.end.y>>x1>>y1>>x2>>y2;
		p[0].x=min(x1,x2),p[0].y=max(y1,y2);p[2].x=max(x1,x2),p[2].y=min(y1,y2);
		p[1].x=p[0].x,p[1].y=p[2].y,p[3].x=p[2].x,p[3].y=p[0].y;
		for(int i=0;i<4;i++)
		{
			line[i].start.x=p[i].x;
			line[i].start.y=p[i].y;
			line[i].end.x=p[(i+1)%4].x;
			line[i].end.y=p[(i+1)%4].y;
			
		}
		int flag=0;
			if((l.start.x==l.end.x)&&flag==0)
		{
			if((p[2].y<=l.start.y&&l.start.y<=p[0].y)||(p[2].y<=l.end.y&&l.end.y<=p[0].y))
			{
			flag=1;
			printf("T\n");
			}
		}
		if((l.start.y==l.end.y)&&flag==0)
		{
			if((p[0].x>=l.start.x&&l.start.x>=p[2].x)||(p[2].x>=l.end.x&&l.end.x>=p[0].x))
			{
			flag=1;
			printf("T\n");
			}
		}
		if(flag==0)
		for(int i=0;i<4;i++)
		{
			if(Across(line[i],l))
			{
				flag=1;
				printf("T\n");
				break;
			}
		}
		
	
		if((l.start.x>=p[0].x&&l.start.y<=p[0].y&&l.start.x<=p[2].x&&l.start.y>=p[2].y&&flag==0)||
		(l.end.x>=p[0].x&&l.end.y<=p[0].y&&l.end.x<=p[2].x&&l.end.y>=p[2].y&&flag==0)){
			flag=1;
				printf("T\n");
		}
	
		if(flag==0)
		printf("F\n");
		
		}
		return 0;
  }
  /*
  9 2 9 1 4 3 9 6
  9 1 9 2 4 3 9 6
  */
 
