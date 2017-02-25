#include <cstdio>  
#include <cstring>  
#include <cctype>  
#include <algorithm>  
using namespace std;  
#define lson l , m , rt << 1  
#define rson m + 1 , r , rt << 1 | 1  
   
const int maxn = 2222;  
int cnt[maxn << 2];  
double sum[maxn << 2],inlen[maxn<<2];  
double X[maxn];  
struct Seg {  
    double h , l , r;  
    int s;  
    Seg(){}  
    Seg(double a,double b,double c,int d) : l(a) , r(b) , h(c) , s(d) {}  
   friend bool operator < (const Seg a,const Seg b)  {  
        return a.h<b.h;  
    }  
}ss[maxn]; 
void PushUp(int rt,int l,int r) {  
    if (cnt[rt]) sum[rt] = X[r+1] - X[l];  
    else if (l == r) sum[rt] = 0;  
    else sum[rt] = sum[rt<<1] + sum[rt<<1|1];  
} 
void inPushUp(int k,int s,int t)
{
    if(cnt[k]>=2)//若被覆盖了俩次以上，则inlen[k]等于区间长度
        inlen[k]=X[t+1]-X[s];
    else if(t==s)//叶节点，等于零
        inlen[k]=0;
    else if(cnt[k]==1)//若该区间整体被覆盖过一次，则inlen[k]等于子区间被覆盖过一次的线段长度之和
        inlen[k]=sum[k<<1]+sum[k<<1|1];
    else inlen[k]=inlen[k<<1]+inlen[k<<1 |1];//若整体没被标记过，则inlen[k]等于子区间被覆盖过俩次的线段长度之和
} 
void update(int L,int R,int c,int l,int r,int rt) {  
    if (L <= l && r <= R) {  
        cnt[rt] += c;  
        PushUp(rt , l , r); 
		inPushUp(rt , l , r); 
        return ;  
    }  
    int m = (l + r) >> 1;  
    if (L <= m) update(L , R , c , lson);  
    if (m < R) update(L , R , c , rson);  
    PushUp(rt , l , r);
	inPushUp(rt , l , r);   
}  
int Bin(double key,int n,double X[]) {  
    int l = 0 , r = n - 1;  
    while (l <= r) {  
        int m = (l + r) >> 1;  
        if (X[m] == key) return m;  
        if (X[m] < key) l = m + 1;  
        else r = m - 1;  
    }  
    return -1;  
}  
int main() {  
    int n , cas = 1,t;
	scanf("%d",&t); 
	while(t--)
	{ 
    scanf("%d",&n );
        int m = 0;  
        while (n --) {  
            double a , b , c , d;  
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);  
            X[m] = a;  
            ss[m++] = Seg(a , c , b , 1);  
            X[m] = c;  
            ss[m++] = Seg(a , c , d , -1);  
        }  
        sort(X , X + m);  
        sort(ss , ss + m);  
        int k = 1;  
        for (int i = 1 ; i < m ; i ++) {  
            if (X[i] != X[i-1]) X[k++] = X[i];  
        }  
        memset(cnt , 0 , sizeof(cnt));  
        memset(sum , 0 , sizeof(sum));  
        memset(inlen, 0 , sizeof(inlen)); 
        double ret = 0.0;  
        for (int i = 0 ; i < m - 1 ; i ++) {  
            int l = Bin(ss[i].l , k , X);  
            int r = Bin(ss[i].r , k , X) - 1;  
            if (l <= r) update(l , r , ss[i].s , 0 , k - 1, 1);  
            ret += inlen[1] * (ss[i+1].h - ss[i].h);  
        }  
        printf("%.2lf\n", ret);  
  }
    return 0;  
}  
