#include<iostream>
#include<cstdio>
using namespace std;
const double EXP=1e-5; 
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
	max(v1.start.y,v1.end.y)>=min(v2.start.y,v2.end.y)&&multi(v2.start,v1.end,v1.start)*multi(v1.end,v2.end,v1.start)>0
	&&multi(v1.start,v2.end,v2.start)*multi(v2.end,v1.end,v2.start)>0)
	return 1;
	return 0;
}
int distance(point a,point b)
{
	return (a.x-b.x)*(a.x-b.x)-(a.y-b.y)*(a.y*b.y);
}
vector line[100],l;
point s,e;
int main()
{
	int n;
	while(cin>>n)
	{
	for(int i=0;i<n;i++)
	{
		cin>>line[i].start.x>>line[i].start.y>>line[i].end.x>>line[i].end.y;
	}
	cin>>s.x>>s.y;
	int minn=30000,c,j,i;
	for(int i=1;i<100;i++)
	{		j=0;
			c=0;
			l.start.x=s.x,l.start.y=s.y,l.end.x=i,l.end.y=j;
			for(int z=0;z<n;z++)
			{
			if(Across(l,line[z]))
			c++;
			}
			if(c<minn)
			minn=c;
	}
	for(int i=1;i<100;i++)
	{		j=100;
			c=0;
			l.start.x=s.x,l.start.y=s.y,l.end.x=i,l.end.y=j;
			for(int z=0;z<n;z++)
			{
			if(Across(l,line[z]))
			c++;
			}
			if(c<minn)
			minn=c;
	}
	for(int j=1;j<100;j++)
	{		i=100;
			c=0;
			l.start.x=s.x,l.start.y=s.y,l.end.x=i,l.end.y=j;
			for(int z=0;z<n;z++)
			{
			if(Across(l,line[z]))
			c++;
			}
			if(c<minn)
			minn=c;
	}
		for(int j=1;j<100;j++)
	{		i=0;
			c=0;
			l.start.x=s.x,l.start.y=s.y,l.end.x=i,l.end.y=j;
			for(int z=0;z<n;z++)
			{
			if(Across(l,line[z]))
			c++;
			}
			if(c<minn)
			minn=c;
	}
	printf("Number of doors = %d\n",minn+1);
}
return 0;
	
 } 
