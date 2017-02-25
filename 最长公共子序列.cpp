#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
char a[2000],b[2000],vis[2000];
int lcs[2000][2000];

int main()
{
	while(~scanf("%s",a))
	{
		memset(lcs,0,sizeof lcs);
		int x,y,len,z=1;
		len=0;
		getchar();
		scanf("%s",b);
		getchar();
		int n=strlen(a);
		int m=strlen(b);
		//cout<<n<<m<<endl;
		int ss=1;
	for(x=1;x<=n;x++)
	{
		for(y=1;y<=m;y++)
		{
			if(x==0||y==0)
			lcs[x][y]=0;
			else if(a[x-1]==b[y-1])
			{  	
			lcs[x][y]=lcs[x-1][y-1]+1;
			} 
			else
			{
			lcs[x][y]=max(lcs[x-1][y],lcs[x][y-1]);
			}
		}
	}
	/* for(int i = 0 ; i <= n; i++)
     {
         for(int  j = 0; j <= m; j++)
         {
            cout << lcs[i][j] << " ";
         }
         cout << endl;
    }*/
	for(int i=n,j=m;i>=1&&j>=1;)
	{
		if(a[i-1]==b[j-1])
		{
			vis[z++]=a[i-1];
			i--,j--;
		}
		else
		{
		
		if(lcs[i][j-1]>lcs[i-1][j])
		{
			j--;
		}
		else
		{
			i--;
		}
		}
	}
	
	for(int i=z-1;i>=1;i--)
	cout<<vis[i];
	//cout<<endl;
	}
	
	return 0;

}
/*
bdcaba
abcbdab
*/
