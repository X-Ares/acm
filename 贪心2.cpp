#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std; 
int a[40001],b[40001];
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0)
		break;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
		scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+m);
		int ans=0,sum=0;
		int num=n;
		for(int i=0,j=0;i<n&&j<m;)
		{
		
			if(a[i]<=b[j])
			{
			sum+=b[j];
			num--;
			j++;i++;
			if(num==0)
			   break;
			}
			else
			j++;
		
		}
		//cout<<num;
		if(num)
		printf("Loowater is doomed!\n");
		else
		printf("%d\n",sum);
	}
	return 0;
 } 
