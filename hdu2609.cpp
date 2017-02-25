#include<cstdio>
#include<cstring>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
int nextt[1000010];
char a[10001][105];
int cmp(const void *p1,const void *p2)
{
	return strcmp((char *)p1,(char *)p2);
}
 int min_max(char a[])
 {
 	int len=strlen(a);
 	int i=0,j=1,k=0;
 	while(i<len&&j<len&&k<len)
 	{
 		int t=a[(j+k)%len]-a[(i+k)%len];
 		if(t==0) k++;
 		else
 		{
 		
 			if(t>0) j+=k+1;
 			else  i+=k+1;
 		
 			if(i==j) j++;
 			k=0;
		 }
	  } 
	  return min(i,j);
 }
 int main()
 {
 	char str[105];
 	int n;
 	while(scanf("%d",&n)!=EOF)
 	{
 		int ans=1;
 		for(int i=0;i<n;i++)
 		{
 		scanf("%s",str);
 		int len=strlen(str);
 		int  mi=min_max(str);
 		cout<<mi<<endl; 
 		int count=0;
 		for(int j=mi;j<len;j++)
 		{
 			a[i][count++]=str[j];
		 }
		 for(int j=0;j<mi;j++)
		 {
		 	a[i][count++]=str[j];
		 }
		 a[i][count]='\0';
		 count=0;
		}
		 qsort(a,n,sizeof(a[0]),cmp);
		 for(int i=0;i<n;i++)
		 {
		 	if(strcmp(a[i],a[i+1])!=0)
		 	ans++;
		 }		 
 	printf("%d\n",ans-1);
 	 
  } 
  return 0;
}
