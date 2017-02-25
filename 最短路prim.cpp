
#include <stdio.h>

#include <string.h>

#define MaxInt 0x3f3f3f3f

#define N 10000

//����map��ά���鴢��ͼ��low�����¼ÿ2�������СȨֵ��visited������ĳ���Ƿ��ѷ���

int map[N][N],low[N],visited[N];

int n,m;
int prim() {

	int i,j,pos,min,result=0;

	memset(visited,0,sizeof(visited));

//��ĳ�㿪ʼ���ֱ��Ǻͼ�¼�õ�

	visited[1]=1;
	pos=1;

//��һ�θ�low���鸳ֵ

	for(i=1; i<=n; i++)

		if(i!=pos) low[i]=map[pos][i];

//������n-1��

	for(i=1; i<n; i++)

	{

//�ҳ���СȨֵ����¼λ��

		min=MaxInt;

		for(j=1; j<=n; j++)

			if(visited[j]==0&&min>low[j])

			{

				min=low[j];
				pos=j;

			}

//��СȨֵ�ۼ�

		result+=min;

//��Ǹõ�

		visited[pos]=1;

//����Ȩֵ

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
//����Ȩֵ��ʼ��Ϊ���
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
