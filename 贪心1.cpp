#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct s
{
	int c,d;
}num[1000010];
int cmp(s a,s b)
{
	return a.c+a.d>b.c+b.d;
}
int main()
{
	int n,m,cas=1;
	while(~scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;i++)
		scanf("%d%d",&num[i].c,&num[i].d);
		long long ans=0,sum=0;
		sort(num,num+n,cmp);
		for(int i=0;i<n;i++)
		{
			ans=max(ans,sum+num[i].d);
			sum+=num[i].c;
		}
		printf("Case %d: %I64d\n",cas++,ans);
	}
 } 
