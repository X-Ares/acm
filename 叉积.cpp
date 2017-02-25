#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef struct point {
	int  x, y;
} point;
struct line1
{
	point a,b;
}line[10000];
int multi(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
	
}
int cmp (line1 aa,line1 bb)
{
	return aa.a.x<bb.a.x;
 } 
point a[10000],p,p1,p2,p3,p4;
int b[10000],c[10000];
int main()
{
	int n,m,t1,t2,t3,t4;
	while((scanf("%d",&n))&&n!=0)
	{
		for(int i=0;i<10000;i++)
		b[i]=0,c[i]=0;
		scanf("%d%d%d%d%d",&m,&p1.x,&p1.y,&p2.x,&p2.y);
		//cin>>m>>p1.x>>p1.y>>p2.x>>p2.y;
		for(int i=0;i<n;i++)
		{
			cin>>t1>>t2;
			line[i].a.x=t1;
			line[i].a.y=p1.y;
			line[i].b.x=t2;
			line[i].b.y=p2.y;
		}
		sort(line,line+n,cmp);
	
		for(int i=0;i<m;i++)
		{
			cin>>p.x>>p.y;
			int l=0,r=n-1;
			while(r>l)
			{
				int mid=(r+l)/2;
				if(multi(p,line[mid].a,line[mid].b)>0) l=mid+1;
				else
				r=mid;
				
			}
			if(multi(p,line[l].a,line[l].b)<0) b[l]++;
			else
			b[l+1]++;
		}
			printf("Box\n");
	
		for(int i=0;i<=n;i++)
		{
			if(b[i]) c[b[i]]++;
		}
		for(int i=0;i<=n;i++)
		{
			if(c[i])
			printf("%d: %d\n",i,c[i]);
		}
	}
	return 0;
}
