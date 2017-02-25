#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
struct p
{
	int len,x,y;
}a[100];
int main()
{
	int n;
	while(cin>>n&&n)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].len;
			a[i].x=0;
			for(int j=1;j<i;j++)
			a[i].x=max(a[i].x,a[j].y-abs(a[i].len-a[j].len));
			a[i].y=a[i].x+2*a[i].len;
			//printf("%d %d\n",a[i].x,a[i].y);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
				if(a[i].x<a[j].y&&a[i].len<a[j].len)
				a[i].x=a[j].y;	
			for(int j=i+1;j<=n;j++)
			if(a[i].y>a[j].x&&a[i].len<a[j].len)
			a[i].y=a[j].x;
		}
		bool first=true;
		for(int i=1;i<=n;i++)
		{
			//printf("\n %d %d \n",a[i].x,a[i].y);
			if(a[i].x<a[i].y)
			{
			if(first) first=false;
			else printf(" ");
			printf("%d",i);
			}
			
		}
		puts("");
	}
}
