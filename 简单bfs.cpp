#include<iostream>
#include<cstdio>
#include<queue> 
#include<cstring>
#include<cmath>
using namespace std;
int t1,t2;
int vis[10000];
struct number
{
	int num,step;
};
int prime(int tt)
{
	int i;
	for(i=2;i*i<=tt;i++) if(tt%i==0) return 0;
	return 1;
}
int bfs(int tt)
{
	
	memset(vis,0,sizeof vis);
	number u;
	u.num=t1,u.step=0;
	queue<number>q;
	q.push(u);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		if(u.num==tt) return u.step;
		int i,j;
		for(i=3;i>=0;i--)
		{
			double p=pow(10,(double) i);
			int x=(u.num/(int (p)))%10;
			//cout<<u.num<<endl;
			for(j=0;j<10;j++)
			{
				if(i==3&&j==0) continue;
				int y=u.num+(j-x)*p;
				if(!vis[y]&&prime(y))
				{
					vis[y]=1;
					number v;
					v.num=y; v.step=u.step+1;
					q.push(v);
				}
			}
		}
	}
	return -1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>t1>>t2;
		int ok=bfs(t2);
		if(ok==-1)
		printf("Impossible\n");
		else
		printf("%d\n",ok);
	}
	return 0;
}
