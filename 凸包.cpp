#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 10500;
const double esp = 1e-5;
int n,top;
bool EQL(double a, double b){
    return fabs(a-b) < esp;
}
struct pt{
    double x, y;
    pt(){}
    pt(double a, double b){ x = a, y = b; }
	pt operator -( const pt &b)const
	{
		return pt(x-b.x,y-b.y);
	}
}dot[N], tree[N];
double dis(pt a, pt b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double cromul(pt a, pt b, pt c){ //ab × ac
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

double cross(pt a,pt b)
{
	return a.x*b.y-a.y*b.x;
}
bool cmp(pt a, pt b){
    double m = cromul(tree[0], a, b);
    if(m < 0) return 0;
    else if(m == 0) return dis(tree[0], a) <  dis(tree[0], b);
    else return 1;
}
double poly_are(pt dot[],int n)
{
	double ans=0.0;
	for(int i=1;i<n-1;i++)
	ans+=cross(dot[i]-dot[0],dot[i+1]-dot[0]);
	return fabs(ans)/2.0;
}
double Convex1(){
	memset(dot, 0,sizeof dot);
    int pos = 0;
    for(int i = 1; i < n; ++i){
        if(tree[pos].y > tree[i].y) pos = i;
        else if(EQL(tree[pos].y, tree[i].y) && tree[pos].x > tree[i].x) 
            pos = i;
    }
    if(pos) swap(tree[0], tree[pos]);
    sort(tree+1, tree+n, cmp);
    tree[n] = tree[0];
    for(int i = 0; i < 3; ++i) dot[i] = tree[i];
    top = 2;
    for(int i = 3; i <= n; ++i){
        while(cromul(dot[top-1], dot[top], tree[i]) < 0) top -= 1;
        dot[++top] = tree[i];
    }
    double ans = 0;
        ans = poly_are(dot,top);
    
    return ans;
}
int main(){ 
    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i < n; ++i){
            scanf("%lf %lf", &tree[i].x, &tree[i].y);
        }
        if(n <= 2) puts("0.00");
        else printf("%d\n",(int) Convex1()/50);
        printf("%d\n",top); 
        
    }
}
