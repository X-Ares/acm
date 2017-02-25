#include<iostream>
using namespace std;
const int mod=1000000007;
int dp[500000];
int cost[13]={1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
int main()
{
	int n;
	while(cin>>n)
	{
		dp[0]=1;
		for(int i=0;i<13;i++)
		{ 
			for(int j=cost[i];j<=n;j++)
			dp[j]=(dp[j]+dp[j-cost[i]])%mod;
		}
		cout<<dp[n]<<endl;
	}
 } 
