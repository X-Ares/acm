#include<iostream>
using namespace std;
const int MAX = 20050;
const int M = 20000;    //  M的值题意应为1000000，则对应的wd[]的长度也应为1000000。

int n, k, num[MAX];
int sa[MAX], rank[MAX], height[MAX];
int wa[MAX], wb[MAX], wv[MAX], wd[MAX];

int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int *r, int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; i ++) wd[i] = 0;
    for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;
    for(i = 1; i < m; i ++) wd[i] += wd[i-1];
    for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
        for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++) wv[i] = x[y[i]];
        for(i = 0; i < m; i ++) wd[i] = 0;
        for(i = 0; i < n; i ++) wd[wv[i]] ++;
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++)
        {
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1 : p ++;
        }
    }
}

void calHeight(int *r, int n)
{
    int i, j, k = 0;
    for(i = 1; i <= n; i ++) rank[sa[i]] = i;
    for(i = 0; i < n; height[rank[i ++]] = k)
    {
        for(k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++);
    }
}

bool valid(int len)
{
    int i = 2, cnt;
    while(1)
    {
        while(i <= n && height[i] < len) i ++;
        if(i > n) break;
        cnt = 1;
        while(i <= n && height[i] >= len)
        {
            cnt ++;
            i ++;
        }
        if(cnt >= k) return true;
    }
    return false;
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        cin >> num[i]; 
    }
    num[n] = 0;
    da(num, n + 1, M);
    calHeight(num, n);

    int low = 1, high = n, mid;
    while(low < high)
    {
        mid = (low+high+1) / 2;
        if(valid(mid)) {
            low = mid;
        }else {
            high = mid - 1;
        }
    }
    cout << low << endl;
    return 0;
}
