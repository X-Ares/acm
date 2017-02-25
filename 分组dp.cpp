#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[3000],bag[30][30],val[33][33];
int main()
{
	int n,m,t,k,ca=1;
	while(cin>>n>>m)
	{
		memset(dp,0,sizeof dp);
		for(int i=0;i<n;i++)
		{
		cin>>t;
		bag[i][0]=t;
		for(int j=1;j<=t;j++)
		{
			cin>>bag[i][j]>>val[i][j];
		}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=m;j>=0;j--)
			{
				for(int z=1;z<=bag[i][0];z++)
				{
					if(bag[i][z]<=j)
					dp[j]=dp[j]>dp[j-bag[i][z]]+val[i][z]?dp[j]:dp[j-bag[i][z]]+val[i][z];
				}
			}
		}
		printf("Case %d: ",ca++);
		cout<<dp[m]<<endl;
		printf("\n");
	}
	return 0;
	
}
