#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int  nextt[200000],len,n,m;
char a[27],p[200000],b[27],q[200000];
void getnext (char a[])
{
	int i=0,j=-1;
	nextt[0]=-1;
	while(i<n)
	{
		if(j==-1||a[i]==a[j])
		nextt[++i]=++j;
		else
		j=nextt[j];
	}
	
}
int main()
{
	cin>>m;
	while(m--)
	{
		memset(p,0,sizeof p);
		memset(a,0,sizeof a);
		memset(nextt,0,sizeof nextt);
		memset(q,0,sizeof q);
		cin>>a>>p;
		for(int i=0;i<26;i++) b[a[i]-'a']=i+'a';
		n=strlen(p),len=n;
		for(int i=0;i<(n+1)/2;++i) q[i]=b[p[i]-'a'];
		for(int i=(n+1)/2;i<=n;++i)  q[i]=p[i];
		getnext(q);
		while(nextt[len]>n/2) len=nextt[len];
		cout<<p;
		for(int i=nextt[len];i<n-nextt[len];++i)
		cout<<b[p[i]-'a'];
		cout<<endl;
	}
	
 } 
