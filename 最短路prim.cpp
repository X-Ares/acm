
#include <stdio.h>

#include <string.h>

#define MaxInt 0x3f3f3f3f

#define N 10000

//创建map二维数组储存图表，low数组记录每2个点间最小权值，visited数组标记某点是否已访问

int map[N][N],low[N],visited[N];

int n,m;
int prim() {

	int i,j,pos,min,result=0;

	memset(visited,0,sizeof(visited));

//从某点开始，分别标记和记录该点

	visited[1]=1;
	pos=1;

//第一次给low数组赋值

	for(i=1; i<=n; i++)

		if(i!=pos) low[i]=map[pos][i];

//再运行n-1次

	for(i=1; i<n; i++)

	{

//找出最小权值并记录位置

		min=MaxInt;

		for(j=1; j<=n; j++)

			if(visited[j]==0&&min>low[j])

			{

				min=low[j];
				pos=j;

			}

//最小权值累加

		result+=min;

//标记该点

		visited[pos]=1;

//更新权值

		for(j=1; j<=n; j++)

			if(visited[j]==0&&low[j]>map[pos][j])

				low[j]=map[pos][j];

	}

	return result;

}



int main()

{
	int i,v,j,ans;
//printf("%d",MaxInt);
//所有权值初始化为最大
	while(~scanf("%d%d",&n,&m)) {

		memset(map,MaxInt,sizeof(map));
		for(int z=0; z<m; z++) {
			scanf("%d%d%d",&i,&j,&v);
			map[i][j]=map[j][i]=v;
		}
		ans=prim();
		printf("%d\n",ans);

	}

	return 0;

}
