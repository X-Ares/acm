#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=10;
const double T=100,EPS=1e-7,delt=0.8;
int eps(double x,double y)
{
	if(fabs(x-y)<EPS) return 0;
	return x<y?-1:1;
}
double tar[maxn];
double getdouble()
{
	double ret=(rand()*rand()%1000000)*1.0/1e6;
	if(rand()&1) ret*=-1;
	return ret;
}
double y;
inline double F(double x)
{
	return 6*x*x*x*x*x*x*x+8*x*x*x*x*x*x+7*x*x*x+5*x*x-y*x;
}
void init()
{
	for(int i=0;i<maxn;i++)
	{
		tar[i]=fabs(getdouble())*100;
	}
}
double cold()
{
	double ret=F(2.0);
	for(int t=T;t>EPS;t*=delt)
	{
		for(int i=0;i<maxn;i++)
		{
			double tmp=F(tar[i]);
			for(int j=0;j<maxn;j++)
			{
				double x1=tar[i]+getdouble()*t;
				if(eps(x1,0)>=0&&eps(x1,100)<=0)
				{
					double f1=F(x1);
					if(eps(tmp,f1)>0) tar[i]=x1;
				}
			}
		}
	}
	for(int i=0;i<maxn;i++)
	{
		ret=min(ret,F(tar[i]));
	}
	return ret;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	while(cas--)
	{ 
		scanf("%lf",&y);
		init();
		printf("%.4f\n",cold());
	}
	return 0;
}
 
