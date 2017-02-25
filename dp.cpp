#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int a[50005],dp[50005],vis[55000],dp1[50005],b[50005],c[52050],dp2[50005];
int bsearch(int c[],int n,int a) {
	int l=1, r=n;
	while(l<=r) {
		int mid = (l+r)/2;
		if( a > c[mid] && a <= c[mid+1] ) return mid+1; // >&&<= »»Îª: >= && <
		else if( a < c[mid] ) r = mid-1;
		else l = mid+1;
	}
}

int LIS(int a[],int n,int dp[]) {
	int i, j, size = 1;
	c[1] = a[1];
	dp[1] = 1;
	for(i=2; i<=n; ++i) {
		if( a[i] <c[1] ) j = 1;// <= »»Îª: <
		else if( a[i] >=c[size] )
			j=++size; // > »»Îª: >=
		else
			j = bsearch(c, size, a[i]);
		c[j] = a[i];
		dp[i] = j;
	}
	return size;
}

int main() {
	int n;
	while(cin>>n) {
		memset(a,0,sizeof a);
		for(int i=1; i<=n; i++)
			cin>>a[i];
		for(int i=n,j=1;i>=1;i--,j++)
		b[i] =-1*a[j];
	 	int ans=LIS(a,n,dp);
		LIS(b,n,dp1);
		for(int i=1,j=n;i<=n;i++,j--)
		{
		dp2[i]=dp1[j];
		//printf("%d ",dp2[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(dp[i]+dp2[i]-1==ans)
			{
			vis[i]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				for(int j=1;j<=n;j++)
				{
					if(!vis[j])
					continue;
					else
					{
						if(i!=j&&dp[i]==dp[j]&&dp[i]+dp2[i]-1==ans&&dp[j]+dp2[j]-1==ans)
						vis[i]=2;
					}
				}
			}
		}
		printf("A:");
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==2)
			printf("%d ",i);
			
		}
		printf("\nB:");
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1)
			printf("%d ",i);
		}
		puts("");
		
	}
	return 0;
}
