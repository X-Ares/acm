#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=2220052;
char a[2000][11],b[2000][11],str[MAX][22];
int num,head[MAX],next[MAX];
int hash(char *str)
{
	int seed=131,sum=0;
	while(*str)
	{
		sum=sum*seed+(*str++);	
	}
	return (sum&MAX)%MAX;
	
}
void hash_insert(int len)
{
	int h=hash(str[len]);
	int u=head[h];
	
	while(u)
	{
		if(!strcmp(str[len],str[u]))
		{
			return ;
		}
		u=next[u];
	}
	next[len]=head[h];
	head[h]=len;
	++num;	
}
int main()
{
	int t,n,m,cnt=0;
	scanf("%d",&t);
	while(t--)
	{
		memset(head,0,sizeof head);
		memset(next,0,sizeof next); 
		 num=1;
		scanf("%d%d",&n,&m);
		getchar();
		for(int i=0;i<n;i++)
		gets(a[i]);
		for(int i=0;i<m;i++)
		gets(b[i]);
		for(int i=0;i<n;i++)
		{
		for(int j=0;j<m;j++)
		{
			sprintf(str[num],"%s%s",a[i],b[j]);
			hash_insert(num);
		}
		}
		printf("Case %d: %d\n",++cnt,num-1);
	}
 } 
