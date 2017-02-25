#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double a,b,c,d,e,f;
	double tr1,tr2,tr3,tr4,temp,ans;
	scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
	tr1=acos((c*c+b*b-f*f)/(2.0*b*c));
	tr2=acos((a*a+c*c-e*e)/(2.0*a*c));
	tr3=acos((a*a+b*b-d*d)/(2.0*a*b));
	tr4=(tr1+tr2+tr3)/2.0;
	temp=sqrt(sin(tr4)*sin(tr4-tr1)*sin(tr4-tr2)*sin(tr4-tr3));
	ans=a*b*c*temp/3.0;
	printf("%.4f\n",ans);
	return 0;
	
 } 
