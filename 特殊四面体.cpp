#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
#define zero(x)(((x)>0?(x):(-x))<eps) 
struct point
{
	double x,y,z;
};
double dist(point a,point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}
point xmult(point u,point v)
{
	point ret;
	ret.x=u.y*v.z-u.z*v.y;
	ret.y=u.z*v.x-u.x*v.z;
	ret.z=u.x*v.y-u.y*v.x;
	return ret;
	
}
double dmult(point u,point v)
{
	return u.x*v.x+u.y*v.y+u.z*v.z;
}
point subt(point u,point v )
{
	point ret;
	ret.x=u.x-v.x;
	ret.y=u.y-v.y;
	ret.z=u.z-v.z;
	return ret;
}
point pvec(point s1,point s2,point s3)
{
	return xmult(subt(s1,s2),subt(s2,s3));
}
int ok_on(point a,point b,point c,point d)
{
	return zero(dmult(pvec(a,b,c),subt(d,a)));
}
struct p
{
	int id;
	double dis;
	p(){}
	p(int id1,double dis1)
	{
		id=id1,dis=dis1;
	}
};
vector<p> q;
point a[222];
int main()
{
	int t,n,ca=1;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0,re=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				q.clear();
				for(int z=0;z<n;z++)
				{
					if(dist(a[i],a[z])==dist(a[j],a[z]))
					{
						q.push_back(p(z,dist(a[z],a[j])));
					}
				}
				
				int size=q.size();
				for(int z=0;z<size;z++)
				{
					for(int zz=z+1;zz<size;zz++)
					{
						if(q[z].dis!=q[zz].dis)continue;
						if(ok_on(a[q[z].id],a[q[zz].id],a[i],a[j]))continue;
						ans++;
						if(dist(a[i],a[j])==q[z].dis&&dist(a[q[z].id],a[q[zz].id])==q[z].dis)
						re++;
					}
				}
			}
		}
		ans=ans/2-2*re/6;
		printf("Case #%d: %d\n",ca++,ans);
	}
	
	
}
