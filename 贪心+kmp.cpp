#include<iostream>
#include<cstring> 
#include<map>
using namespace std;
char str[2222222],b[222222];
int nn[222222];

int main()
{ int t=1;
	while(cin>>str+1)
	{
		memset(b,0,sizeof b);
	
		int l=strlen(str+1);
		b[1]=str[1];
		int last=0,m=1;
		for(int i=1,j=0;i<=l;i++)
		{
			while(j&&str[i]!=b[j+1])j=nn[j];
			if(str[i]==b[j+1]) j++;
			if(!j)
			{
				for(int k=last+1,t=nn[m];k<=i;k++)
				{
				b[++m]=str[k];
				while(t&&b[m]!=b[t] ) t=nn[t];
				if(b[t+1]==b[m])t++;
				nn[m]=t;	
				}
				j=m;
			}
			if(j==m) last=i;
		}
		for(int i=0;i<=m;i++)
		printf("%c ",b[i]); 
	//	printf("Case %d: %d\n",t++,l+m-last);
	}
	return 0;
} 
