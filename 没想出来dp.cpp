#include<cstdio>
#include<cstring>
#include<iostream>
const long long mod=1000000007;
using namespace std;
int a[5005],dp[2][5005],sum[5005];
int main()
{
	int n,m,k,x;
	while(cin>>n>>m>>k)
	{
		int flag=1;
		for(int i=1;i<=m;i++)
		{
			cin>>x;
			x++;
			a[x]=1;
			if(a[x-1]==1)
			flag=0;
		}
		for(int i=1;i<=k;i++)
		{
			cin>>x;
			x++;
			a[x]=2;
			if(a[x-1]==2||a[x]==1)
			flag=0;
		}
		if(flag==0)
		{
			printf("0\n");
			return 0;
		}
		int now=1,ans=0;
		memset(dp[now],0,sizeof dp[now]);
		dp[now][1]=sum[1]=1;sum[0]=0;
		for(int i=2;i<=n;i++)
		{
			now^=1;
			memset(dp[now],0,sizeof dp[now]);
			for(int j=1;j<=i;j++)
			{
				if(a[i]==0)
				{
					if(a[i-1]==0) dp[now][j]=sum[i-1];
					if(a[i-1]==1) dp[now][j]=sum[j-1];
					if(a[i-1]==2) dp[now][j]=(((sum[i-1]-sum[j-1])%mod)+mod)%mod;
					
				}
				else if(a[i]==1) dp[now][j]=(((sum[i-1]-sum[j-1])%mod)+mod)%mod;
				else dp[now][j]=sum[j-1];
				
			}
			for(int j=1;j<=i;j++) sum[j]=((dp[now][j]+sum[j-1])%mod);
		}
		for(int i=1;i<=n;i++)
		ans=(ans+dp[now][i])%mod;
		cout<<(ans+mod)%mod<<endl;
	}
	return 0;
	
}
