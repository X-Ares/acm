#include<iostream>
#include<cstring>
using namespace std;
char s[2000],str[2000];
int dp[4000][2000];
int main()
{
	while(cin>>s)
	{
	int len=strlen(s);
	for(int i=0,j=len-1;i<len&&j>=0;j--,i++)
	{	
	str[j]=s[i];	
	}
	dp[0][0]=0;
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=len;j++)
		{
			if(str[i-1]==s[j-1]) dp[i][j]=max(dp[i-1][j-1]+1,max(dp[i][j-1],dp[i-1][j]));
			else
			dp[i][j]=max(dp[i-1][j-1],max(dp[i][j-1],dp[i-1][j]));
		}
		
	}
	cout<<len-dp[len][len]<<endl;
	}
	return 0;
	
 } 
