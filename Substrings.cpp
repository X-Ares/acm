#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[105][105],s1[105],s2[105]; 
int main()
{
	int t,n,m,f,len,l;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int mi=1000;
		for(int i=0;i<n;i++)
		{
		scanf("%s",&str[i]);
		 len=strlen(str[i]);
		if(len<mi)
		{
			mi=len;
			f=i;
		}
		}
		len =strlen(str[f]);
		int flag=1, ma=0;
		for(int i=0;i<len;i++)
		{
			for(int j=i;j<len;j++)
			{
				for(int k=i;k<=j;k++)
				{
					s1[j-k]=str[f][k];
					s2[k-i]=str[f][k];
				}
				s1[j-i+1]=s2[j-i+1]='\0';
				
				l=strlen(s1);
				for(int k=0;k<n;k++)
				{
				if(!strstr(str[k],s1)&&!strstr(str[k],s2))
				{
					flag=0;
					break;
				}
			}
				if(flag&&l>ma)
				ma=l;
				flag=1;
			
				
			}		
		}
		printf("%d\n",ma);
	}
	return 0;
	
 } 
