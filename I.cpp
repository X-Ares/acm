/*i*/
#include<cstdio>
#include<cstring>
using namespace std;

int chess[10][10];
int vis[10][10];
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
int queue[100];
int si,sj,ei,ej,ui,uj;
int ans;

void BFS(int x,int y)
{
	int nx,ny;
	int d;
	int front=0,rear=0;
	int u=x+8*y;
	queue[rear++]=u;
	vis[x][y]=1;
	while(front<rear)
	{
		u=queue[front++];
		x=u%8;y=u/8;
		//printf("%d %d\n",x,y); /**/
		if(x==ei-1&&y==ej-1)
		{
			ans=chess[ei-1][ej-1];
			//printf("ans: %d %d",ei-1, ej-1);/**/
		    return;
		 } 
		for(d=0;d<8;d++)
		{
			nx=x+dx[d];ny=y+dy[d];
			if(vis[nx][ny]==1)    continue;
			if(nx<0||nx>=8||ny<0||ny>=8)    continue;
			chess[nx][ny]=chess[x][y]+1;
			u=nx+ny*8;
			queue[rear++]=u;
			vis[nx][ny]=1; 
		}
		
	} 
	return;
}

int main()
{
	int t=1;
	while(scanf("%d%d%d%d%d%d",&si,&sj,&ei,&ej,&ui,&uj)!=EOF)
	{
		memset(vis,0,sizeof(vis)); 
		memset(queue,0,sizeof(queue));
		memset(chess,0,sizeof(chess));
		vis[ui-1][uj-1]=1;
		ans=0;
		BFS(si-1,sj-1);
		printf("Case %d: %d\n",t++,ans);
	}
	return 0;
}

