#include<iostream>
#include<cstring>
using namespace std;
const int maxn =10;
int t,n,m,s1,s2,e1,e2,minn;
int a[maxn][maxn],step[maxn][maxn],time[maxn][maxn];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
void dfs(int x,int y,int len,int tm)
{
	if(x>n||y>m||x<1||y<1)return ;
	if(len<=0||tm>=minn)return ;
	if(a[x][y]==0)return ;	
	if(a[x][y]==3) 
	{
	if(tm<minn) minn=tm;
		return ;
	}
	if(a[x][y]==4)
	{
		len=6;
	}
	if(tm>=step[x][y] && time[x][y]>=len)return;  //ºÙ÷¶ 
    step[x][y]=tm;  
    time[x][y]=len; 
	int tx,ty;
	for(int i=0;i<4;i++)
	{
		tx=x+dir[i][0];
		ty=y+dir[i][1];
		dfs(tx,ty,len-1,tm+1);
	}
	
	
	
}
int main()
{
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof a);
		minn=INT_MAX;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				step[i][j]=INT_MAX-1;
				time[i][j]=0;
				if(a[i][j]==2)
				{
					s1=i;
					s2=j;
				}
				else if(a[i][j]==3)
				{
					e1=i;
					e2=j;
				}
				
			}
		}
		int len=6,cnt=0;
		dfs(s1,s2,len,cnt);
		if(minn==INT_MAX)
		cout<<"-1"<<endl;
		else
		cout<<minn<<endl;
		
	}
	return 0;
 } 
