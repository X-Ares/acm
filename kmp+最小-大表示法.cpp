#include<cstdio>
#include<cstring>
#include<math.h>
#include<iostream>
using namespace std;
int nextt[1000010];
char a[1000010];
void getnext(char a[])
{
	int i=0,j=-1;
	nextt[0]=-1;
	int len=strlen(a);
	while(i<len)
	{
		if(j==-1||a[i]==a[j])
		//nextt[++i]=nextt[++j];
		{
			i++,j++;
			if(a[i]==a[j])
			nextt[i]=nextt[j];
			else
			nextt[i]=j;
		}
		
		else
		j=nextt[j];
	}
 }
 int min_max(char a[],bool flag)
 {
 	int len=strlen(a);
 	int i=0,j=1,k=0;
 	while(i<len&&j<len&&k<len)
 	{
 		int t=a[(j+k)%len]-a[(i+k)%len];
 		if(t==0) k++;
 		else
 		{
 			if(flag)
 			{
 			if(t>0) j+=k+1;
 			else  i+=k+1;
 			}
 			else
 			{
 				if(t>0) i+=k+1;
 				else j+=k+1;
			 }
 			if(i==j) j++;
 			k=0;
		 }
	  } 
	  return min(i,j);
 }
 int main()
 {
 	int ans,l;
 	while(scanf("%s",a)!=EOF)
 	{
 		int mi=min_max(a,true);
 		int ma=min_max(a,false);
 		cout<<ma<<mi<<endl;
 		getnext(a);
 		int len=strlen(a);
 		l=len-nextt[len];
 		ans=len%l?1:len/l;
 		printf("%d %d %d %d\n",mi+1,ans,ma+1,ans); 
 		for(int i=0;i<len;i++)
		 cout<<nextt[i]<<" "; 
 		
	 }
	 return 0;
 }
