#include<iostream>
#include<time.h>
using namespace std;
void shell(int a[],int n)
{
	int i,j,m;
	for(m=n/2;m>0;m=m/2)
	for(i=m;i<n;i++)
	{
		int tmp=a[i];
		for(j=i;j>=m;j=j-m)
		{
		if(tmp<a[j-m])
		a[j]=a[j-m];
		else
		break;
		}
		a[j]=tmp;
	}
}
int main()
{
	int a[100],n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		cin>>a[i];
		shell(a,n);
		for(int i=0;i<n;i++)
		printf("%d ",a[i]);
		printf("\n程序运行了%.2lf秒\n",(double)clock()/CLOCKS_PER_SEC);
	}
	return 0;
 } 
