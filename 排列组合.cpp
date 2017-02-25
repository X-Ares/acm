#include<iostream>
using namespace std;
long long c[100][200];
int main()
{
	for(int i=1,j;i<=66;i++)
	{
		c[i][0]=c[i][i]=1;
		for( j=1;j<i;j++)
		c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	cout<<c[5][4]<<endl;
} 
