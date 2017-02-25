#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char a[1000110],b[1001100];
void clean(char *a)
{
	
	int len=strlen(a),i=0,j=0,s=0,k=0;
	for( i=0;i<len;i++)
	{
		if(s==0&&a[i]!='0') s=1;
		if(s==1) a[j++]=a[i];	
		if(a[i]=='.') k=1;
	}
     a[j]='\0'; 
     len=strlen(a);
	for( i=len-1;k==1&&a[i]!='.';i--)
	{
		if(a[i]=='0'||a[i]=='.')
		a[i]='\0';
		else
		k=0;
	}
	if(k==1) a[i]='\0';	
		cout<<a<<endl;
}
int main()
{
	while(cin>>a>>b)
	{
		clean(a);
		clean(b);
		cout<<a<<" "<<b<<endl;
		if(strcmp(a,b)==0)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	
 } 
