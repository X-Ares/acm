#include<iostream>
#include<cmath>
using namespace std;
int a[60000],b[60000],dp[60000][2];
int main()
{
	int n,m;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		cin>>a[i];
	
	dp[0][0]=dp[1][0]=dp[1][1]=0;
	for(int i=2;i<=n;i++)
	{
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]+abs(a[i-1]-1));//µÍ¹È 
		dp[i][1]=max(dp[i-1][0]+abs(a[i]-1),dp[i-1][1]+abs(a[i]-a[i-1]));//¸ß·å 
	}
	cout<<max(dp[n][1],dp[n][0])<<endl;
}
return 0;
	
 } 
