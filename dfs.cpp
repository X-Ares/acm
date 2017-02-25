#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
int ss[7][7];
bool vis[7][7];
struct node
{
	int a,b;
};
stack<node> p;
void init()
{
	memset(vis,0,sizeof vis);
	for(int i=0;i<7;i++)
	{
		ss[i][0]=1;
		ss[0][i]=1;
		ss[6][i]=1;
		ss[i][6]=1;
	}
}
void dfs(int x,int y)
{
	 //cout<<x<<' '<<y<<endl; 
	if(!vis[x][y])
	{
		node cur;
		cur.a=x;
		cur.b=y;
		vis[x][y]=1;
		p.push(cur);
	}
	if(x==5&&y==5) return ;
	if(!vis[x+1][y]&&!ss[x+1][y]) dfs(x+1,y);
	else if(!vis[x][y+1]&&!ss[x][y+1])dfs(x,y+1);
	else
	{
		p.pop();
		node cur=p.top();
		dfs(cur.a,cur.b);
	}
	
	
}
int main()
{
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		scanf("%d",&ss[i][j]); 
	}
	init();
	/*for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		cout<<ss[i][j]<<" ";
		cout<<endl;
	 } */
	dfs(1,1);
	vector<node> v;
	while(p.empty()==false)
	{
		v.push_back(p.top());
		p.pop();
	}
	for(int i=v.size()-1;i>=0;i--)
	{
		printf("(%d, %d)\n",v[i].a-1,v[i].b-1);
	}

		
}
