#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cctype>
#include <map>
#include <iomanip>
                   
using namespace std;
                   
#define eps 1e-5
#define pi acos(-1.0)
#define inf 1<<30
#define linf 1LL<<60
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long

double x[5],y[5],z[5];
double a,b,c;    

inline int sig(double k) {
    return k<-eps?-1:k>eps;
}

bool check(int n){
    if (sig(a*n-floor(a*n+0.5))==0 && sig(b*n-floor(b*n+0.5))==0 && sig(c*n-floor(c*n+0.5))==0) return true;
    else return false;
}

inline double getangle(double a,double b,double c,double d,double e,double f) {
    double aa,bb,cc;
    aa=sqrt((c-a)*(c-a)+(d-b)*(d-b));
    bb=sqrt((e-a)*(e-a)+(f-b)*(f-b));
    cc=sqrt((e-c)*(e-c)+(f-d)*(f-d));
    return acos((aa*aa+bb*bb-cc*cc)/(2*aa*bb));
}

int main() {
    while (1){
        if (scanf("%lf%lf",&x[0],&y[0])==0) break;
        else {
            for (int i=1; i<=2; i++) scanf("%lf%lf",&x[i],&y[i]);
            a=getangle(x[0],y[0],x[1],y[1],x[2],y[2])/pi;
            b=getangle(x[1],y[1],x[2],y[2],x[0],y[0])/pi;
            c=getangle(x[2],y[2],x[0],y[0],x[1],y[1])/pi;
            for (int i=3; i<=1000; i++){
                if (check(i)) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

