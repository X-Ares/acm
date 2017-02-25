#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k;
long long a[200000],b[200000],c[200000];
long long  ok(long long  l,long long  r)
{
	while(l<=r)
	{
	long long sum=0,mid;
	mid=(l+r)/2;
	for(int i=1;i<=n;i++)
	{
		if(b[i]<a[i]*mid)
		sum+=(a[i]*mid)-b[i];
		if(sum>k)
		break;	
	}
	if(sum==k)
	return mid;
	else if(sum>k)
	r=mid-1;
	else
	l=mid+1; 
	}
	return l-1;
}
int main()
{
	while(cin>>n>>k)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
		}
		long long l=1,r=2*1e9+10,ans=0;
			ans=ok(l,r-1);
		 	cout<<ans<<endl;
		}
		
	 } 
