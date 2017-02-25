#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char t[2000],s[2000];
int c[2000];
 int main()
 {
 	int k,len,q=1;
 	while(scanf("%d",&k)!=EOF)
 	{
 		getchar();
 		gets(t);
 		int l=strlen(t);
 		int cnt=0;
 		for(int i=0;i<l;i++)
 		{
 		if((t[i]>='a'&&t[i]<='z')||('A'<=t[i])&&t[i]<='Z')
 		{
		if('A'<=t[i]&&t[i]<='Z')
 		t[i]=t[i]-'A'+'a';
 		}	
 		if(t[i]>='a'&&t[i]<='z')
 		{
 		c[cnt]=i;
 		s[cnt++]=t[i];
 		}
 		}
 		s[cnt]='\0';
 		int maxlen=1,pos=1;
 		for(int j=cnt;j>=1;j--)
 		{
 			for(int i=0;i+j-1<cnt;i++)
 			{
 				int st=i+j-1,cnt=0;
 				int len=c[st]-c[i]+1;
 				if(len<maxlen) continue;
 				for(int l1=i,l2=st;l1<l2;l1++,l2--)
 				{
 					if(s[l1]!=s[l2]) cnt+=2;
 					if(cnt>2*k) break;
 					
				 }
				 if(cnt<=2*k)
				 {
			
				    if(maxlen<len||(maxlen==len&&i<pos))
				    {
				    maxlen=len;
				    pos=i;
					}
			 }
		 }
 	
		}	
	 printf("Cace %d: %d %d\n",q++,maxlen,c[pos]+1);
 	}
 	return 0;

}
