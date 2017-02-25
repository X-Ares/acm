#include<iostream>
#include<cstring>
using namespace std;
struct s
{
	int x,y,z;
}a[55555];
int dp[50005];
void z(int cost,int weight,int n)
{
	for(int i=n;i>=cost;i--)
	dp[i]=max(dp[i],dp[i-cost]+weight);
}
void c(int cost ,int weight,int n )
{
	for(int i=cost ;i<=n;i++)
	dp[i]=max(dp[i],dp[i-cost]+weight);
}
int  mu(int n,int m)
{
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].z*a[i].x>m)
		
			c(a[i].x,a[i].y,m);
			else
			{
				int k=1;
				while(k<a[i].z)
				{
					z(k*a[i].x,k*a[i].y,m);
					a[i].z-=k;
					k=k*2;
				}
				z(a[i].z*a[i].x,a[i].z*a[i].y,m);
			}
		
	}
	return dp[m];
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		cout<<mu(n,m)<<endl;
	}
 } 
