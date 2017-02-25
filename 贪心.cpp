#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct s
{
	int c,d;
}a[1000010];
bool cmp(s a,s b)
{
	return a.d>b.d;
}

int main()
{
	int t,n,m,q=1;
	//cin>>n;

		//cin>>m;
		while(~scanf("%d",&m)&&m)
		{
		for(int i=0;i<m;i++)
		//cin>>a[i].c>>a[i].d;
		scanf("%d%d",&a[i].c,&a[i].d);
		long long ans=0,num=0;
		sort(a,a+m,cmp);
		for(int i=0;i<m;i++)
		{
			num+=a[i].c;
			if(num+a[i].d>ans) ans=num+a[i].d;
		}
		printf("Case %d: %lld\n",q++,ans);
	}
	
 } 
