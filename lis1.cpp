#include<iostream>
#include<cstdio>
using namespace std;
int a[500005],ans[500005];
int main()
{
	int n,ca=1;
	while(scanf("%d",&n)!=EOF)
	{
		int x,y,len=1;
		for(int i=1;i<=n;i++)
		{
		scanf("%d%d",&x,&y);
		a[x]=y;
		}	
		ans[1]=a[1];
		for(int i=2;i<=n;i++)
		{
			int low=1;
			int up=len;
			
			while(low<=up)
			{
				int mid=(up+low)/2;
				if(ans[mid]<a[i]) low=mid+1;
				else 
				up=mid-1;
			}
			ans[low]=a[i];
			if(low>len) len++;
		}
		printf("Case %d:\n",ca++);
		if(len==1)
		printf("My king, at most 1 road can be built.\n");
		else
		printf("My king, at most %d roads can be built.\n",len);
		printf("\n");
	}
 } 
