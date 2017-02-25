#include<bits/stdc++.h>
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
using namespace std;
typedef long long ll;

const int N = 2e5+5;
ll mx[N<<2], mi[N<<2], sum[N<<2];
ll lazy[N<<2], cover[N<<2];
void push_up(int rt){
    mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
    mi[rt] = min(mi[rt<<1], mi[rt<<1|1]);
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void build(int rt, int l, int r){
    if(l == r){
    	scanf("%lld",&mx[rt]);
        mi[rt] = sum[rt] = mx[rt];
        return;
    }
    int mid = (l+r) >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}
void push_down(int rt, int l, int r){
    if(lazy[rt]){
        int mid = (l+r) >> 1;
        mi[rt<<1] += lazy[rt];
        mx[rt<<1] += lazy[rt];
        mi[rt<<1|1] += lazy[rt];
        mx[rt<<1|1] += lazy[rt];
        sum[rt<<1] += (mid-l+1)*lazy[rt];
        sum[rt<<1|1] += (r-mid)*lazy[rt];
        if(cover[rt<<1]) cover[rt<<1] += lazy[rt]+lazy[rt<<1], lazy[rt<<1] = 0;
        else lazy[rt<<1] += lazy[rt];
        if(cover[rt<<1|1]) cover[rt<<1|1] += lazy[rt]+lazy[rt<<1|1], lazy[rt<<1|1] = 0;
        else lazy[rt<<1|1] += lazy[rt];
        lazy[rt] = 0;
    }
    if(cover[rt]){
        int mid = (l+r) >> 1;
        mi[rt<<1] = mx[rt<<1] = mi[rt<<1|1] = mx[rt<<1|1] = cover[rt];
        sum[rt<<1] = (mid-l+1)*cover[rt];
        sum[rt<<1|1] = (r-mid)*cover[rt];
        cover[rt<<1] = cover[rt<<1|1] = cover[rt];
        lazy[rt<<1] = lazy[rt<<1|1] = 0;
        cover[rt] = 0;
    }
}
void addval(int rt, int l, int r, int ql, int qr, ll val){
    if(ql <= l && qr >= r){
        mx[rt] += val, mi[rt] += val, sum[rt] += (r-l+1)*val;
        if(cover[rt]) cover[rt] += val+lazy[rt], lazy[rt] = 0;
        else lazy[rt] += val;
        return;
    }
    int mid = (l+r) >> 1;
    push_down(rt, l, r);
    if(ql <= mid) addval(lson, ql, qr, val);
    if(qr > mid) addval(rson, ql, qr, val);
    push_up(rt);
}
void sqrtdown(int rt, int l, int r){
    if(mi[rt] == mx[rt]){
        ll tmp = sqrt(mi[rt]);
        mx[rt] = mi[rt] = tmp;
        sum[rt] = (r-l+1)*tmp;
        lazy[rt] = 0;
        cover[rt] = tmp;
        return;
    }
    int mid = (l+r) >> 1;
    push_down(rt, l, r);
    sqrtdown(lson);
    sqrtdown(rson);
    push_up(rt);
}
void sqrtval(int rt, int l, int r, int ql, int qr){
    if(ql <= l && qr >= r){
        sqrtdown(rt, l, r);
        return;
    }
    int mid = (l+r) >> 1;
    push_down(rt, l, r);
    if(ql <= mid) sqrtval(lson, ql, qr);
    if(qr > mid) sqrtval(rson, ql, qr);
    push_up(rt);
}
ll query(int rt, int l, int r, int ql, int qr){
    if(ql <= l && qr >= r) return sum[rt];
    int mid = (l+r) >> 1;
    ll res = 0;
    push_down(rt, l, r);
    if(ql <= mid) res += query(lson, ql, qr);
    if(qr > mid) res += query(rson, ql, qr);
    push_up(rt);
    return res;
}
int main(){

    int T;
    scanf("%d",&T);
    while(T--){
        int n, m;
        memset(lazy,0,sizeof lazy);
		 memset(cover,0,sizeof cover);
       scanf("%d%d",&n,&m);
        build(1, 1, n);
        while(m--){
            int t, l, r, x;
            scanf("%d%d%d",&t,&l,&r);
            if(t == 1){
                scanf("%d",&x);
                addval(1, 1, n, l, r, x);
            }
            else if(t == 2){
                sqrtval(1, 1, n, l, r);
            }
            else{
            ll tmp = query(1, 1, n, l, r);
               printf("%lld\n",tmp);
            }
        }
    }
}
