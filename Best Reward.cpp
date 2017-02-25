#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
 const int m=500005; 
int nextt[m],pos[m],per[m],vis[m],sum[m];
#define INF 99999999
char s[m],s1[m];
void getnext(char a[],int len)
{
	int i=0,j=-1;
	nextt[0]=-1;
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
int kmp(char a[],char b[],int len)
{
	int i=0,j=0;
	while(i<len&&j<len)
	{
		if(j==-1||a[j]==b[i])
		{
			i++,j++;
		}
		else
		j=nextt[j];
	}
	return j;
}

int main()
{
	int n,k;
	scanf("%d",&n);
	while(n--)
	{
		for(int i=0;i<26;++i) scanf("%d",&vis[i]);
		scanf("%s",&s);
		int len=strlen(s);
		for(int i=0;i<len;i++)
		s1[i]=s[len-1-i],sum[i+1]=sum[i]+vis[s[i]-'a'];
		getnext(s,len);
		k=kmp(s,s1,len);
			//cout<<k<<endl;
		while(k)
		{
			pos[k]=n+1;
			k=nextt[k];
		}
		getnext(s1,len);
		k=kmp(s1,s,len);
		//cout<<k<<endl; 
		while(k)
		{
			per[k]=n+1;
			k=nextt[k];
		}
		int ans=-INF,num=0;
		for(int i=1;i<len;i++)
		{
			if(pos[i]==n+1) num+=sum[i];
			if(per[len-i]==n+1) num+=sum[len]-sum[i];
			if(num>ans)
			ans=num;
			num=0; 
		}
		printf("%d\n",ans);
	}
	
 } 
