#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-8;
bool f;
int n;
struct point {
	double x,y;
};

struct vector {
	point start,end;
};
point p;
vector line[1000];
double multi(point p1,point p2,point p0) {
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
bool fun(point a,point b) {
	if(fabs(a.x-b.x)<eps&&fabs(a.y-b.y)<eps)
		return false;
	for(int i=0; i<n; i++) {
		if(multi(line[i].start,a,b)*multi(line[i].end,a,b)>eps)
			return false;
	}

	return true;

}

int main() {
	int t;
	cin>>t;
	while(t--) {
		f=false;
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>line[i].start.x>>line[i].start.y>>line[i].end.x>>line[i].end.y;
		if(n<3)
			f=true;
		for(int i=0; i<n&&!f; i++) {
			//	if(fun(line[i].end,line[i].start))
			//	f=true;
			for(int j=i+1; j<n&&!f; j++)
				if(fun(line[i].start,line[j].end)||
				        fun(line[i].end,line[j].start)||
				        fun(line[i].end,line[j].end)||
				        fun(line[i].start,line[j].start))
					f=true;
		}
		if(!f)
			printf("No!\n");
		else
			printf("Yes!\n");
	}
	return 0;
}
