#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define min(a,b) a>b?b:a
#define eps 1e-8
const int MAXN=10010;
struct point 
{
	double x,y;
	point()
	{}
	point (double _x,double _y)
	{
		x=_x,y=_y;
	}
	void input()
	{
	scanf("%lf%lf",&x,&y);
	}
 };
 inline double pdis(point a,point b)
 {
 	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
 }
 inline double dotcross(point p0,point p1,point p2)
 {
 	return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
 }
 inline double difcross(point p0,point p1,point p2)
 {
 	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
 }
 point p[MAXN],q[MAXN];
 int np,nq;
 inline double p2segline(point a,point p1,point p2)
 {
 	return fabs(difcross(a,p1,p2)/pdis(p1,p2));
 }
 inline double p2seg(point a,point p1,point p2)
 {
 	if(dotcross(p1,p2,a)<-eps) return pdis(a,p1);
 	if(dotcross(p2,p1,a)<-eps) return pdis(a,p2);
 	return p2segline(a,p1,p2);
 }
 inline double fourpoint(point p1,point p2,point q1,point q2)
 {
 	double ans1=min(p2seg(p1,q1,q2),p2seg(p2,q1,q2));
 	double ans2=min(p2seg(q1,p1,p2),p2seg(q2,p1,p2));
 	return min(ans1,ans2);
 }
 inline double solve(point *p,point *q,int np,int nq)
 {
 	p[np]=p[0];
 	q[nq]=q[0];
 	int sp=0,sq=0;
 	for(int i=0;i<np;i++)
 	{
 		if(p[i].y+eps<p[sp].y) sp=i;
	 }
	 for(int i=0;i<nq;i++)
	 {
	 	if(q[i].y+eps<q[sq].y) sq=i;
	 }
	 double tmp,ans=1e99;
	 for(int i=0;i<np;i++)
	 {
	 	while(tmp=difcross(q[sq],p[sp],p[sp+1])-difcross(q[sq+1],p[sp],p[sp+1])<-eps)
	 	sq=(sq+1)%nq;
	 	if(tmp>eps)
	 	{
	 		ans=min(ans,p2seg(q[sq],p[sp],p[sp+1]));
		 }
		 else
		 ans=min(ans,fourpoint(p[sp],p[sp+1],q[sq],q[sq+1]));
		 sp=(sp+1)%np;
	 }
	 return ans;
 }
 inline double nearestpoint(point *p,point *q,int np,int nq)
 {
 	return min(solve(p,q,np,nq),solve(q,p,nq,np));
 }
int main()
{
	while(scanf("%d%d",&np,&nq)!=EOF)
	{
		if(nq==0&&np==0)
		break;
		for(int i=0;i<np;i++) p[i].input();
		for(int i=0;i<nq;i++) q[i].input();
		double ans= nearestpoint(p,q,np,nq);
		printf("%lf\n",ans);
		
	}
	return 0;
	
 } 
