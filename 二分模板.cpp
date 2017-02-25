#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
long long a[100005],b[100005];
struct p
{
	long long x,y;
}c[100005];
int n,m;
int ok(int r)
{
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		c[i].x=b[i]-r;
		c[i].y=b[i]+r;
	}
	int l=1,i=1;
	while(l<=n&&i<=m)
	{
		if(c[i].x<=a[l]&&a[l]<=c[i].y)
		l++,ans++;
		else
		i++;
	}
	if(ans>=n)
	return 1;
	else
	return 0;
}
int main()
{

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=m;i++)
	cin>>b[i];
	long long  l=0,r=4e9+1000,ans=0;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(ok(mid)) r=mid-1;
		else
		l=mid+1;
	}
	cout<<r+1<<endl;
	
}
