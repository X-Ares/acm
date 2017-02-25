#include<cstdio>
#include<cstring>
int nextt[1000010],ans[1000010];
char a[1000010];
void getnext(char a[])
{
	int i=0,j=-1;
	nextt[0]=-1;
	int len=strlen(a);
	while(i<len)
	{
		if(j==-1||a[i]==a[j])
		{
			nextt[++i]=++j;
		}
		else
		j=nextt[j];
	}
}
int  main()
{
	int n,qq=1;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",&a);
		getnext(a);
		int len=strlen(a);
		/*for(int i=1;i<=len;i++)
		printf("%d ",nextt[i]);*/
		int o=nextt[len];
		int sum=0;
		while(o)
		{
			ans[sum++]=len-o;
			o=nextt[o];
		}
		ans[sum++]=len;
		printf("Case #%d: %d\n",qq++,sum);
		for(int i=0;i<sum;i++)
		printf("%d ",ans[i]);
	//	printf("%d\n",ans[sum-1]);
	printf("\n");
	
	}
	
}
