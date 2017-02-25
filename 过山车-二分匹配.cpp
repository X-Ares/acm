#include<iostream>
#include<cstring>
using namespace std;
int g[1000][1000],vis[1000];
bool used[1000];
int n,m,nn,mm; 
int dfs(int u)
{
	int k;
	for(int j=1;j<=m;j++)
	{
		if(!used[j]&&g[u][j])
		{
			used[j]=true;
			if(vis[j]==-1||dfs(vis[j]))
			{
			vis[j]=u;
			return true;
			}
		}
		
	}
	return false;
	
}
int p()
{
	int ans=0;
		memset(vis,-1,sizeof vis);
	
	for(int i=1;i<=n;i++)
	{
		memset(used,0,sizeof(used));
		if(dfs(i))
		ans++;
	}
	return ans;
}
int main()
{
	int k;

	while((cin>>k)&&k)
	{
	
		memset(g,0,sizeof g);
		cin>>n>>m;
		for(int i=1;i<=k;i++)
		{
		cin>>nn>>mm;
		g[nn][mm]=1;
		}
		printf("%d\n",p());
		
	}
	return 0;
	
 } 
