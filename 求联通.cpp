#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

struct point 
{
	int x,y;
	bool friend operator <(const point &x,const point &y)
	{
		if(x.x!=y.x) return x.x<y.x;
		return x.y<y.y;
	}
	
};
struct line
{
	point a,b;
}a[22222];
map<point,int>hash1;
int n,p[22222];
int find(int x)
{
	p[x]!=x?find(p[x]):p[x];
	
}
void solve()
{
	for(int i=0;i<2*n;i++)
	p[i]=i;
	int cnt=0;
	for(int i=1,u,v;i<=n;i++)
	{
		if(hash1.count(a[i].a)) u=hash1[a[i].a];
		else
		u=hash1[a[i].a]=cnt++;
		if(hash1.count(a[i].b)) v=hash1[a[i].b];
		else
		v=hash1[a[i].b]=cnt++;
		u=find(u),v=find(v);
		if(u==v)
		{
		printf("%d\n",i);
		return ;
		}
		p[u]=v;
		
	}
	puts("0");
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a[i].a.x,&a[i].a.y,&a[i].b.x,&a[i].b.y);
		
	}
	solve();
	return 0;
	
	
 } 
