#include<cstdio>
#include<cstring>
char p[2000110],s[1000110];
int t[2000110];
int mmx=-1,iid;
int min(int a,int b)
{
	return a>b?b:a;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int  init()
{
	int l=strlen(s);
	p[0]='$';
	for(int i=1;i<=l*2;i+=2)
	{
		p[i]='#';
		p[i+1]=s[i/2];
	}
	p[l*2+1]='#';
	p[l*2+2]='$';
	return l*2+1;
	
}
int manacher(char p[],int l)
{
	int mx=0,id=0,ans=0;
	mmx=-1;
	for(int i=1;i<=l;i++)
	{
		if(mx>i)
		t[i]=min(mx-i,t[id*2-i]);
		else
		t[i]=1;
		while(p[i+t[i]]==p[i-t[i]])
		t[i]++;
		if(t[i]+i>mx)
		{

		mx=t[i]+i;
		id=i;
		}
		if(t[i]-1>mmx)
		{
		mmx=t[i]-1;
		iid=i;
		}
		ans=max(ans,t[i]);
	}
	return ans-1;
}
int main()
{
	int q=0;
	char c;
	while(scanf("%c %s",&c,&s)!=EOF)
	{
		getchar();
		int k=c-'a';
		int len=strlen(s);
		
		int ans=0,l;
		for(int i=0;i<=len;i++)
		{
			s[i]-=k;
			if(s[i]<'a')
			s[i]+=('z'-'a'+1);
		}
		
		l=init();
		//for(int i=0;i<=l-2;i++)
		//printf("%c ",p[i]);
		ans=manacher(p,l);
		if(ans==1)
		printf("No solution!\n");
		else
		{

		printf("%d %d\n",(iid-mmx+1)/2-1,(iid+mmx-1)/2-1);
		for(int i=(iid-mmx+1);i<=(iid+mmx-1);i++)
		if(p[i]!='#'&&p[i]!='$')
		printf("%c",p[i]);
		printf("\n");
		}
	  memset(p,0,sizeof p);
	  memset(s,0,sizeof s);
		}
	}
