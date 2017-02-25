#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int nextt[100000];
char a[10000],b[10000];
int extend[10000];
void perEKMP(char x[],int m,int nextt[])
{
	nextt[0]=m;int j=0;
	while(j+1<m&&x[j]==x[j+1]) j++;
	nextt[1]=j;
	int k=1;
	for(int i=2;i<m;i++)
	{
		int p=nextt[k]+k-1;
		int l=nextt[i-k];
		if(i+l<p+1)nextt[i]=l;
		else
		{
			j=max(0,p-i+1);
			while(j+i<m&&x[i+j]==x[j])j++;
			nextt[i]=j;
			k=i;
		}
	}
}
void ekmp(char x[],int m,char y[],int n,int nextt[],int extend[])
{
	perEKMP(x,m,nextt);
	int j=0;
	while(j<n&&j<m&&x[j]==y[j]) j++;
	extend[0]=j;
	int k=0;
	for(int i=1;i<n;i++)
	{
		int p=extend[k]+k-1;
		int l=nextt[j-k];
		if(i+l<p+1) extend[i]=l;
		else
		{
			j=max(0,p-i+1);
			while(j+i<n&&j<m&&y[i+j]==x[j])j++;
			extend[i]=j;
			k=i;
		}
	}
}
int main()
{
	while(cin>>a>>b)
	{
	
	memset(nextt,0,sizeof nextt);
	int len=strlen(a);
	int l=strlen(b);
	perEKMP(a,len,nextt);
	ekmp(a,len,b,l,nextt,extend);
	for(int i=0;i<len;i++)
	cout<<nextt[i]<<" ";
	cout<<endl;
	for(int i=0;i<l;i++)
	cout<<extend[i]<<" ";
	}
 } 
