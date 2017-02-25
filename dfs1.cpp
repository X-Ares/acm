#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ss[1000][101];
bool vis[101][101];
int n,m,cnt;
void dfs(int x,int y,int k)
{
	
	if(x<1||x>=n+1||y<0||y>=m) return;
	if(vis[x][y]>0||ss[x][y]!='@') return;
	vis[x][y]=k;
	for(int i=-1;i<=1;i++)
	for(int j=-1;j<=1;j++)
	if(i!=0||j!=0)dfs(x+i,j+y,k);
}

int main()
{
	int t;
	while(cin>>n>>m)
	{
		if(n==0&&m==0)
		break; 
		memset(vis,0,sizeof vis);
		cnt=0;
		for(int i=1;i<=n;i++)
		cin>>ss[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		if(ss[i][j]=='@'&&vis[i][j]==0) dfs(i,j,++cnt);
	}
/*	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		cout<<vis[i][j]<<" ";
		cout<<endl;
	}*/
	   cout<<cnt<<endl;
	}
 } 
