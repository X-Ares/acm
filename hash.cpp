#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
//#include<map>
//#include<queue>
//#include<cmath>
const int maxn=100010;
char a[maxn],b[maxn],tmp[maxn];
int n,m;
#define ull unsigned long long
const ull B=1e5+7;
ull ah[maxn],base[maxn];
using namespace std;
int c(int len)
{
	int pos=m-len+1;
	ull bh=0,tm=0;
	for(int i=0;i<len;i++)
	tm=tm*B+a[i];
	ah[0]=tm;
	for(int i=0;i+len<=n;i++)
	ah[i+1]=ah[i]*B+a[i+len]-a[i]*base[len];
	sort(ah,ah+n-len+1);
	for(int i=0;i<len;i++)
	bh=bh*B+b[i];
	for(int k=0;k<pos;k++)
	{
		if(binary_search(ah,ah+n-len+1,bh))
		{
			return 1;
		}
		bh=bh*B+b[k+len]-b[k]*base[len];
	}
	return 0;
	
	
}
int solve()
{
	n=strlen(a);
	m=strlen(b);
	if(n<m)
	{
		swap(n,m);
		strcpy(tmp,a);
		strcpy(a,b);
		strcpy(b,tmp);
	}
	int d=0,p=m+1,mid;
	while(p>d+1)
	{
		mid=(p+d)/2;
		if(c(mid)) d=mid;
		else 
		p=mid;
	}
	return d;
	
}

int main()
{
	base[0]=1;
	for(int i=1;i<maxn;i++)
	base[i]=base[i-1]*B;
	while(scanf("%s%s",a,b)!=EOF)
	{
		
		printf("%d\n",solve());
		
	}
	
 } 
