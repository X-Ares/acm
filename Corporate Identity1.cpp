#include<cstdio>
#include<cstring>
int nextt[10000];
char m[4050][2020];
void getnext(char p[])
{
	int i=0,j=-1,len;
	nextt[0]=-1;
	len=strlen(p);
	while(i<len)
	{
		if(j==-1||p[i]==p[j])
		nextt[++i]=++j;
		else
		j=nextt[j];
	}
}
int kmp(char p[],char w[])
{
	int i=0,j=0,l1,l2;
	l1=strlen(p);
	l2=strlen(w);
	getnext(p);
	while(l2>i&&l1>j)
	{
		if(j==-1||p[j]==w[i])
		{
			i++,j++;
		}
		else
		j=nextt[j];		
	}
	if(j==l1)
	return i-l1;
	else
	return -1;
}
int main()
{
	int i,j,k,t=0,n;
	char tmp[2200],ans[2200];
	while(~scanf("%d",&n),n)
	{
		scanf("%s",&m[0]);
		int mi=strlen(m[0]);
		for(i=1;i<n;i++)
		{
		scanf("%s",&m[i]);
		int len=strlen(m[i]);
		t=0;
		if(len<mi)
		{
			mi=len;
			t=i;
		}
		}
		ans[0]=0;
		for(i=mi;i>=0;i--)
		{
			for(j=0;j<=mi-i;j++)
			{
				strncpy(tmp,m[t]+j,i);
				tmp[i]=0;//
				//printf("tmp=%s\n",tmp);
				for(k=0;k<n;k++)
				{
					if(k!=t)
					{
						if(kmp(tmp,m[k])==-1)
						break;
					}
				}
				if(k==n)
				{
					if(strlen(ans)<i)strcpy(ans,tmp);
					else if(strlen(ans)==i&&strcmp(ans,tmp)>0)
					strcpy(ans,tmp);
				}
			}
		}
		if(ans[0]==0)
		printf("IDENTITY LOST\n");
		else
		printf("%s\n",ans);
	}
	
	return 0;
 } 
