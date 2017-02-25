#include<bits/stdc++.h>
using namespace std;
struct p
{
	int to,next,val;
}a[5005];
int cnt=0;
int head[5005];
int path[5005][5005],dp[5005][5005];
int n,m,k;
void add(int s,int e,int val)
{
	a[cnt].to=e;
	a[cnt].val=val;
	a[cnt].next=head[s];
	head[s]=cnt++;
	
}
void dfs(int cur,int num,int t,int fa)
{
	if(t>=dp[cur][num]) return ;
	dp[cur][num]=t;
	path[cur][num]=fa;
	if(cur==n) return ;
	for(int i=head[cur];i!=-1;i=a[i].next)
	{
		int x=a[i].to;
		dfs(x,num+1,t+a[i].val,cur);
	}
	
}
void dfs1(int cur,int num)
{
	int fa=path[cur][num];
	if(fa>0)
	{
		for(int i = head[fa]; i != -1; i = a[i].next)
		{
			int x=a[i].to;
			if(cur != x) continue;
			dfs1(fa,num-1);		
		}
	}
	printf("%d ",cur);
}
int main()
{
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		memset(head,-1,sizeof head);
		for(int i=0;i<m;i++)
		{
			int u,v,s;
			scanf("%d%d%d",&u,&v,&s);
			add(u,v,s);
		}
	
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				dp[i][j]=1e9+7;
			}
		}
		dfs(1,1,0,0);
		int ans=0;
		for(int i = 1; i <= n; i++)
		{
			if(dp[n][i]<=k) ans=max(ans,i);
		}
		printf("%d\n",ans);
		dfs1(n,ans);
	}
	return 0;
}
