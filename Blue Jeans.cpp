#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std; 
char t[62][62],p[62];
int n,m,ma,len,nextt[62];
void makenext()
{
	int i=0,j=-1;
	nextt[0]=-1;
	while(i<len)
	{
		if(j==-1||p[i]==p[j])
		{
		nextt[++i]=++j;
	}
		else
		j=nextt[j];
	}
}
void kmp()
{
	int k,i,j,ans;
	makenext();ma=100;
	for(k=1;k<n;k++)
	{
		i=0;j=0;m=0;
		while(i<60&&j<len)
		{
			if(j==-1||t[k][i]==p[j])
			{
				i++;j++;
			}
			else 
			j=nextt[j];
			if(j>m)  m=j;
		}
		if(m<ma) ma=m;
	}
	
}
int main()
{
	int a,i;
	char r[62];
	scanf("%d",&a);
	while(a--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%s",t[i]);
			int ans=0;
			for(i=0;i<=57;i++)
			{
				strcpy(p,t[0]+i);
			//	cout<<p<<endl;
				len=60-i;
				kmp();
				if(ans<ma)
				{
					ans=ma;
					strncpy(r,t[0]+i,ans);
					r[ans]='\0';
				}
				else if(ans==ma)
				{
					char tmp[62];
					strncpy(tmp,t[0]+i,ans);
					tmp[ans]='\0';
					if(strcmp(tmp,r)<0)
					strcpy(r,tmp);
					
				}
			}
			if(ans>=3)
			printf("%s\n",r);
			else
			printf("no significant commonalities\n");
		
	}
}
