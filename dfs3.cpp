//#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int ttt,dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char map[50][50][12];
struct point
{
	int x,y,step,type;
}p[105];
int dfs(point x)
{
	point t,tt;
	queue <point>q;
	q.push(x);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(map[t.type][t.x][t.y]=='*')
		continue;
		if(map[t.type][t.x][t.y]=='P') return 1;
		map[t.type][t.x][t.y]='*';
		for(int i=0;i<4;i++)
		{
			tt.x=t.x+dir[i][0];
			tt.y=t.y+dir[i][1];
			tt.step=t.step+1;
			tt.type=t.type;
			if(tt.step>ttt||map[tt.type][tt.x][tt.y]=='*')
			continue;
			if(map[tt.type][tt.x][tt.y]=='#')
			{
			map[tt.type][tt.x][tt.y]='*';
			tt.type=1-tt.type;
			if(map[tt.type][tt.x][tt.y]=='#'||map[tt.type][tt.x][tt.y]=='*')
			{
		
			map[tt.type][tt.x][tt.y]=map[1-tt.type][tt.x][tt.y]='*';
			continue;
			}
			}
			q.push(tt);
		}
	}
	return 0;
	
}
int main()
{
	int qq,n,m;
	cin>>qq;
	while(qq--)
	{
		point s;
		memset(map,'*',sizeof map);
		cin>>n>>m>>ttt;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		cin>>map[0][i][j];
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		cin>>map[1][i][j];
		s.x=1;s.y=1;s.step=0;s.type=0;
		if(dfs(s)) printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
