#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN=100010;
const int MAXM=25010;
int a[MAXN];
int b[MAXN];
int n,m,s;
int as[MAXN][30];
int bs[MAXM][30];
void init()
{
for(int i=0;i<n;i++)
{
if(i==0)
{
for(int j=1;j<=25;j++)as[i][j]=0;
}
else
{
for(int j=1;j<=25;j++)as[i][j]=as[i-1][j];
}
as[i][a[i]]++;
}
for(int i=0;i<m;i++)
{
if(i==0)
{
for(int j=1;j<=25;j++)bs[i][j]=0;
}
else
{
for(int j=1;j<=25;j++)bs[i][j]=bs[i-1][j];
}
bs[i][b[i]]++;
}
}
int next[MAXM];
void kmp_pre()
{
int i,j;
j=next[0]=-1;
i=0;
while(i<m)
{
int t11=0,t12=0,t21=0,t22=0;
for(int k=1;k<b[i];k++)
{
if(i-j>0)t11+=bs[i][k]-bs[i-j-1][k];
else t11+=bs[i][k];
}
if(i-j>0)t12=bs[i][b[i]]-bs[i-j-1][b[i]];
else t12=bs[i][b[i]];
for(int k=1;k<b[j];k++)
{
t21+=bs[j][k];
}
t22=bs[j][b[j]];
if(j==-1 || (t11==t21&&t12==t22))
{
next[++i]=++j;
}
else j=next[j];
}
}
vector<int>ans;
void kmp()
{
ans.clear();
int i,j;
kmp_pre();
i=j=0;
while(i<n)
{
int t11=0,t12=0,t21=0,t22=0;
for(int k=1;k<a[i];k++)
{
if(i-j>0)t11+=as[i][k]-as[i-j-1][k];
else t11+=as[i][k];
}
if(i-j>0)t12=as[i][a[i]]-as[i-j-1][a[i]];
else t12=as[i][a[i]];
for(int k=1;k<b[j];k++)
{
t21+=bs[j][k];
}
t22=bs[j][b[j]];
if(j==-1 || (t11==t21&&t12==t22))
{
i++;j++;
if(j>=m)
{
ans.push_back(i-m+1);
j=next[j];
}
}
else j=next[j];
}
}
int main()
{
	while(scanf("%d%d%d",&n,&m,&s)==3)
	{
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(int j=0;j<m;j++)
		scanf("%d",&b[j]);
		init();
		kmp_pre();
		kmp();
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
		printf("%d\n",ans[i]);
	}
 } 
