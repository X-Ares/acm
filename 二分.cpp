#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int  n,m;
long long L;
int a[666666];

int main()
{
	std::ios::sync_with_stdio(false);
	while(scanf("%lld%d%d",&L,&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		a[n+1]=L;
		sort(a,a+n+1);
		
		int maxx=0;
		for(int i=0;i<=n;i++)
		{
			if(a[i+1]-a[i]>maxx)
			maxx=a[i+1]-a[i];
		}
		long long l=maxx,r=L,mid,ans=0;
		while(r>=l)
		{
			mid=(l+r)/2;
			int ans=0,pos=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]-a[pos]<=mid&&a[i+1]-a[pos]>mid)
				{
					pos=i;
					ans++;
				}	
			}
			ans++;
			if(ans>m) l=mid+1;
			else
			r=mid-1; 
			
		}
		cout<<l<<endl;
	}
 } 
