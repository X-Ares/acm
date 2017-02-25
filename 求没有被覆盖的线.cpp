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
point p;
double multi(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int Across(vector v1,vector v2)
{
	if(max(v1.start.x,v1.end.x)>=min(v2.start.x,v2.end.x)&&max(v2.start.x,v2.end.x)>=min(v1.start.x,v1.end.x)&&
	max(v1.start.y,v1.end.y)>=min(v2.start.y,v2.end.y)&&multi(v2.start,v1.end,v1.start)*multi(v1.end,v2.end,v1.start)>=0
	&&multi(v1.start,v2.end,v2.start)*multi(v2.end,v1.end,v2.start)>=0)
	return 1;
	return 0;
} 
vector line[222222];
int a[111111];
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;i++)
		{
		scanf("%lf %lf %lf %lf",&line[i].start.x,&line[i].start.y,&line[i].end.x,&line[i].end.y);
		}
		int flag=0,k=0;
		for(int i=0;i<n;i++)
		{
			flag=0;
			for(int j=i+1;j<n;j++)
			{
				
				if(Across(line[i],line[j]))
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			a[k++]=i;
		}
		printf("Top sticks:");
		for(int i=0;i<k-1;i++)
		printf(" %d,",a[i]+1);
		printf(" %d.\n",a[k-1]+1);
		
	}
}
