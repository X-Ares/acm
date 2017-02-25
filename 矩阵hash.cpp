#include<cstdio>
#include<cstring>
long long x,y,n,m,hash,h,kk,p,seed=131;
char str1[1005][1005],str2[105][105];
int d(int t,int i)
{
	int dd=0,j,k;
	for(j=i;j<i+y;j++)
	{
	hash-=p*str1[t-x][j];
	hash=hash*seed+str1[t][j];
	}
	if(hash==h)
	return 1;
	else
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		hash=h=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
		scanf("%s",str1[i]);
		}
		scanf("%d%d",&x,&y);
		for(int i=0;i<x;i++)
		{
		scanf("%s",str2[i]);
		}
		 p=1;
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			h=h*seed+str2[i][j];
		}
		for(int i=0;i<x*y-1;i++)
			p=p*seed;
		for(int i=0;i<=m-y;i++)
		{
		hash=0;
		for(int j=0;j<x;j++)
		{
			for(int k=i;k<i+y;k++)
			hash=hash*seed+str1[j][k];
		}
		if(hash==h)
			ans++;
			kk=x;
			while(kk<n)
			{
			ans+=d(kk,i);
			kk++;
			}
		}
	printf("%d\n",ans);
		
	}
	
 } 
