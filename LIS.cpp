#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100005],dp[100005],c[100005],num[300];
char str[100005];

int bsearch(int  c[],int n,int a) {
	int l=1, r=n;
	while(l<=r) {
		int mid = (l+r)/2;
		if( a > c[mid] && a <= c[mid+1] ) return mid+1; // >&&<= »»Îª: >= && <
		else if( a < c[mid] ) r = mid-1;
		else l = mid+1;
	}
}

int LIS(int a[], int n) {
	int i, j, size = 1;
	c[1] = a[1];
	dp[1] = 1;
	for(i=2; i<=n; ++i) {
		if(a[i] <=c[1]) j = 1;// <= »»Îª: <
		else if( a[i] >c[size] )
			j=++size; // > »»Îª: >=
		else
			j = bsearch(c, size, a[i]);
		c[j] = a[i];
		dp[i] = j;
	}
	return size;
}
int main() {
	int n,ca=1;
	cin>>n;
		for(int i=1; i<=n; i++)
		{
		cin>>str+1;
		memset(a,0,sizeof a);
		memset(dp,0,sizeof dp);
		memset(c,0,sizeof c);
		printf("Case #%d: ",ca++);
       	int len=strlen(str+1);
       	for(int i=1;i<=len;i++)
       	{  
       	//cout<<a[i]<<endl;
       	}
		cout<<LIS(a,len)<<endl;
		}
	
	return 0;
}
