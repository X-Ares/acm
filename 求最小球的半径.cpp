#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=50;
const double eps=1e-7;
struct 		P
{
	double x,y,z;
}p[maxn],s;
int n;
double delta,ans;
void input()
{
	for(int i=0;i<n;i++)
	scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
}
double dis(P a,P b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
void solve()
{
	s.x=s.y=s.z=0;
	delta=100,ans=1e20;
	while(delta>eps)
	{
		int d=0;
		for(int i=0;i<n;i++)
		  if(dis(s,p[i])>dis(s,p[d])) d=i;
		double md=dis(s,p[d]);
		ans=min(ans,md);
		s.x+=(p[d].x-s.x)/md*delta;
		s.y+=(p[d].y-s.y)/md*delta;
		s.z+=(p[d].z-s.z)/md*delta;
		delta*=0.98;
	}
	printf("%.5f",ans);
}
int main()
{
	while(scanf("%d",&n),n)
	{
	input();
	solve();
	}
	return 0;
}
