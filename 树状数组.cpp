#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int N=100005;
int a[N],b[N],ans[N],sum[N],n;
int  lowbit(int x)
{
	return x&(-x);
}
void update(int x)
{
	while(x<=n)
	{
		sum[x]++;
		x+=lowbit(x);	
	}
}
int query(int x)
{
	int ans=0;
	while(x)
	{
		ans+=sum[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	int t,ca=1;
	cin>>t;
	while(t--)
	{
		memset(b,0,sizeof b);
		memset(ans,0,sizeof ans);
		memset(sum,0,sizeof sum);
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=n;i>=1;i--)
		{
		b[i]=query(a[i]);
		update(a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			ans[a[i]]=max(abs(i-a[i]),max(b[i],i+b[i]-a[i]));
		}
		printf("Case #%d:",ca++);
		for(int i=1;i<=n;i++)
		printf(" %d",ans[i]);
		puts("");
	}
}

