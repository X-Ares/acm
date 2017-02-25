#include<iostream>
#include<cstring>
#include<cstdio>
const int MAXN=2000010;
using namespace std;
int nextt[MAXN];
//char str1[MAXN],str2[MAXN];
int extend[MAXN];
void perEKMP(char x[],char y[])
{
	int lens=strlen(x);
	int lent=strlen(y); 
	nextt[0]=lent;int j=0;
	while(j+1<lent&&y[j]==y[j+1]) j++;
	nextt[1]=j;
	int k=1;
	for(int i=2;i<lent;i++)
	{
		int p=nextt[k]+k-1;
		int l=nextt[i-k];
		if(i+l<p+1)nextt[i]=l;
		else
		{
			j=max(0,p-i+1);
			while(j+i<lent&&y[i+j]==y[j])j++;
			nextt[i]=j;
			k=i;
		}
	}
	 j=0;
	while(j<lens&&j<lent&&x[j]==y[j]) j++;
	extend[0]=j;
	 k=0;
	for(int i=1;i<lens;i++) 
	{
		int p=extend[k]+k-1;
		int l=nextt[i-k];
		if(i+l<p+1) extend[i]=l;
		else
		{
			j=max(0,p-i+1);
			while(j+i<lens&&j<lent&&x[i+j]==y[j])j++;
			extend[i]=j;
			k=i;
		}
	}
}
void getnext(char a[],int len)
{
	int i=0,j=-1;
	nextt[0]=-1;
	while(i<len)
	{
		if(j==-1||a[i]==a[j])
		nextt[++i]=++j;
		else
		j=nextt[j];
	}
}

char str1[MAXN],str2[MAXN];
int main()
{
    int T;
    int iCase=0;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        scanf("%s",str1);
        int len=strlen(str1);
        strcpy(str2,str1);
        strcat(str2,str1);
       perEKMP(str2,str1);
        int cnt1=0,cnt2=0,cnt3=0;

        for(int i=0;i<len;i++)
        {
            if(extend[i]>=len)cnt2++;
            else
            {
                if(str2[i+extend[i]]<str1[extend[i]])cnt1++;
                else cnt3++;
            }
        }
        getnext(str1,len);
        int t=len-nextt[len];
        int tol=1;
        if(len%t==0)tol=len/t;
        printf("Case %d: %d %d %d\n",iCase,cnt1/tol,cnt2/tol,cnt3/tol);
    }
    return 0;
}
