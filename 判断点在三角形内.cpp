#include<iostream>
#include<cmath>
using namespace std;

struct point 
{
	int x,y;
};
struct triangle
{
	point a,b,c;
};
struct v
{
	point start,end;
};
double crossProduct(v *v1,v *v2)
{
	v vt1,vt2;
	double result=0;
	vt1.start.x=vt1.start.y=vt2.start.x=vt2.start.y=0;
	vt1.end.x=v1->end.x-v1->start.x;
	vt1.end.y=v1->end.y-v1->start.y;
	vt2.end.x=v2->end.x-v2->start.x;
	vt2.end.y=v2->end.y-v2->start.y;
	result=vt1.end.x*vt2.end.y-vt2.end.x*vt1.end.y;
	return result;
	
}
bool inTriangle(triangle t,point p)
{
	v AB ,AC , BC,PA ,PB, PC;
	AB.start=t.a;
	AB.end=t.b;
	PA.start=p;
	PA.end=t.a;
	AC.start=t.a;
	AC.end=t.c;
	PC.start=p;
	PC.end=t.c;
	//BC.start=t.b;
	//BC.end=t.c;
	PB.start=p;
	PB.end=t.b;
	double Sabc=fabs(crossProduct(&AB,&AC));
	double Spab=fabs(crossProduct(&PA,&PB));
	double Spac=fabs(crossProduct(&PA,&PC));
	double Spbc=fabs(crossProduct(&PB,&PC));
	printf("%lf %lf %lf %lf \n",Sabc,Spab,Spac,Spbc);
	if(Sabc==Spbc+Spab+Spac) return true;
	return false;
	
}
int main()
{
	triangle t;
	point p;
	scanf("%d%d%d%d%d%d%d%d",&t.a.x,&t.a.y,&t.b.x,&t.b.y,&t.c.x,&t.c.y,&p.x,&p.y);
	if(inTriangle(t,p))
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	
	
 } 
