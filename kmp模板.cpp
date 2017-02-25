#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=50000;
int nexta[N];
char a[N],b[N];
int n,m;
void getnext()
{
	int j=-1,i=0;
	nexta[0]=-1;
	while(i<n)
	{
		if(j==-1||b[j]==b[i]) i++,j++,nexta[i]=j;
		else
		j=nexta[j];
	}
}
int kmp()
{
	int i=0,j=0;
	while(i<n&&j<m)
	{
		if(j==-1||a[i]==b[j])
		i++,j++;
		else 
		j=nexta[j];
		if(j==m)
		return i-m+1;
	}
	return -1;
}
int main()
{
	//cin>>a>>b;
	//n=strlen(a);
	cin>>b;
	n=strlen(b);
	getnext();
	for(int i=0;i<=n;i++)
	printf("%d ",nexta[i]);
	//cout<<kmp()<<endl; 
	
 } 
