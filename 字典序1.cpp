#include<iostream>
#include<cstring>
using namespace std;
char s[200];
int lass(int p,int q)
{
	int n=strlen(s);
	for(int i=0;i<n;i++)
	if(s[(q+i)%n]!=s[(p+i)%n])
	return s[(q+i)%n]>s[(p+i)%n];
	return 0;
	
	
}
int main()
{
	int t,m;
	cin>>t;
	while(t--)
	{   int ans=0;
		memset(s,0,sizeof s);	
		cin>>s;
		int len=strlen(s);
		for(int i=1;i<len;i++)
		{
		if(lass(i,ans))
		ans=i;
		cout<<ans;
		}
		for(int i=0;i<len;i++)
		cout<<s[(i+ans)%len];
		cout<<endl; 
	}
	return 0;
	} 
 
