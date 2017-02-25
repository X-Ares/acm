#include <iostream>  
#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
  
typedef long long LL;  
const int M=2005;  
  
struct Point  
{  
    int x,y;  
    Point(int _x = 0,int _y = 0) : x(_x),y(_y) {}  
    Point operator+(const Point &a)const  
    {  
        return Point(x+a.x,y+a.y);  
    }  
    Point operator-(const Point &a)const  
    {  
        return Point(x-a.x,y-a.y);  
    }  
    Point operator=(const Point &a)  
    {  
        x=a.x;y=a.y;  
        return *this;  
    }  
    void read()  
    {  
        scanf("%d%d",&x,&y);  
    }  
    void show()const  
    {  
        printf("%d %d\n",x,y);  
    }  
}p_or[M],pn[M*2];  
LL det(const Point &a,const Point &b)  
{  
    return (LL)a.x*b.y-(LL)a.y*b.x;  
}  
LL dot(const Point &a,const Point &b)  
{  
    return a.x * 1ll * b.x + a.y * 1ll * b.y;  
}  
  
bool polar_cmp(const Point &a,const Point &b)  
{  
    if((LL)a.y*b.y<=0)  
    {  
        if(a.y>0||b.y>0) return a.y<b.y;  
        if(a.y==0&&b.y==0) return a.x<b.x;  
    }  
    return det(a,b)>0;  
}  
  
int n;  
LL ans;  
LL naa,noa;//锐角数量，直角钝角数量  
void cntaa(int core)//寻找以某点为中心的锐角，钝角直角数量  
{  
    //cout<<"core "<<core<<endl;  
    int nn=n-1;  
    for(int i=0,j=0;i<n;i++)  
        if(i!=core)  
            pn[j++]=p_or[i]-p_or[core];  
    sort(pn,pn+nn,polar_cmp);  
    for(int i=0;i<nn;i++)  
        pn[i+nn]=pn[i];  
    //cout<<"sort ok"<<endl;  
    int j=0,k=0,l=0;//相同极角的点的位置，锐角极角的位置，钝角极角的位置  
    for(int i=0;i<nn;i++)  
    {  
        while(j<i+nn&&det(pn[i],pn[j])==0&&dot(pn[i],pn[j])>0)  
            j++;  
        k=max(j,k);  
        while(k<i+nn&&det(pn[i],pn[k])>0&&dot(pn[i],pn[k])>0)  
            k++;  
        l=max(k,l);  
        while(l<i+nn&&det(pn[i],pn[l])>0)  
            l++;  
        naa+=k-j;  
        noa+=l-k;  
        //cout<<"naa noa "<<naa<<" "<<noa<<endl;  
    }  
}  
  
int main() {  
    //freopen("1.in","r",stdin);  
    //freopen("1.out","w",stdout);  
    while (scanf("%d",&n)!=EOF)  
    {  
        for(int i=0;i<n;i++)  
            p_or[i].read();  
        naa=noa=0;  
        for(int i=0;i<n;i++)  
        {  
            cntaa(i);  
        }  
        ans=(naa-noa*2)/3;  
        printf("%I64d\n",ans);  
    }  
}  
