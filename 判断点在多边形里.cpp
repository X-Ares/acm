#include<iostream>
#include<cmath>
#include<cstring>
#define MAX 10000
#define PI 3.141592653589793
using namespace std;
typedef struct point {
	double x, y;
} point;
bool Is_inline(point Q, point Pi, point Pj) {
	if((Q.x-Pi.x)*(Pj.y-Pi.y) == (Pj.x-Pi.x)*(Q.y-Pi.y)&& min(Pi.x,Pj.x) <= Q.x && Q.x <= max(Pi.x, Pj.x)&& min(Pi.y, Pj.y)<=Q.y && Q.y<=max(Pi.y, Pj.y)) {
		return true;
	}
	return false;
}
bool Is_inside(point *set, int N, point p) {
	int i, j;
	double angle = 0.0;
	bool inside = false;
	for(i=0,j=N-1; i<N; j=i++) {
		if(set[i].x == p.x && set[i].y == p.y) {
			inside = true;
			break;
		} else if(Is_inline(p, set[i], set[j])) {
			inside = true;
			break;
		}
		double x1, y1, x2, y2;
		x1 = set[i].x - p.x;
		y1 = set[i].y - p.y;
		x2 = set[j].x - p.x;
		y2 = set[j].y - p.y;
		double radian = atan2(y1, x1) - atan2(y2, x2);
		radian = abs(radian);
		if(radian > PI) {
			radian = 2*PI - radian;
		}
		angle += radian;
	}
	if(fabs(6.283185307179586 - angle < 1e-5)) {
		inside = true;
	}
	return inside;
}
int main() {
	int T, n;
	point temp[MAX], U;
	scanf("%d", &T);//几组数据
	for(int i = 0; i<T; i++) {
		scanf("%d", &n);//多边形有n个顶点
		for(int j = 0; j < n; j++) {
			scanf("%lf%lf", &temp[j].x, &temp[j].y);
		}
		printf("输入要判断的点:\n");
		scanf("%lf%lf", &U.x, &U.y);
		bool res = Is_inside(temp, n, U);
		memset(temp, 0, sizeof(point));
		if(res==true) {
			printf("OK!\n");
			continue;
		}
		printf("Out!\n");
	}
	return 0;
}
