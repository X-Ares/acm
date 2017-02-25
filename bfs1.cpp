#include<iostream>
#include<cstring>
#define mem(a) memset(a,0,sizeof a)
using namespace std;
int q[200005],vis[200005],d[200005];
 int maxn;
void dfs(int n,int k)
{
	mem(q),mem(vis),mem(d);
	vis[n]=1;
	int mi=0,ma=0;
	q[ma++]=n;
	while(mi<ma)
	{
		n=q[mi++];
		if(n==k) return ;
		if(!vis[n-1]&&n>0){vis[n-1]=1;q[ma++]=n-1;d[n-1]=d[n]+1;}
		if(!vis[n+1]&&n<100000){vis[n+1]=1;q[ma++]=n+1;d[n+1]=d[n]+1;}
		if(!vis[2*n]&&n<50001){vis[2*n]=1;q[ma++]=n*2;d[2*n]=d[n]+1;}
	}
}
int main()
{
	int k,n;
	while(cin>>n>>k)
	{
		dfs(n,k);
		cout<<d[k]<<endl;
	}
	return 0;
 } 
