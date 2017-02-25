#include<iostream>
#include<cstdio>
using namespace std;
int a[200000],b[200000],p[200000];
int main()
{ 
   int n,m,k,l,ans,i,j;
   while(scanf("%d",&n)!=EOF)
   {
   	for( i=0;i<n;i++)
   	{
   	scanf("%d",&a[i]);
	 p[a[i]]=1;  
	 }
   	scanf("%d",&m); ans=0;
   	for( i=0;i<m;i++)
   	{
   scanf("%d",&b[i]);
   if(p[b[i]])ans++;
   else
   for( j=0;j<n;j++)
   {
   if(a[j]*2>b[i])break;
   if(p[b[i]-a[j]])
   {
   	ans++;//break;
   //	cout<<ans<<endl; 
   }
	}
   	}
   printf("%d",ans);
   }
   return 0;
 } 
