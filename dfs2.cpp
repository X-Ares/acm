#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,sum;
void dfs(int x,int y,int z)
{
	if(y<z)
	swap(y,z);
	int a,b,c;
	sum=1;
	b=y,c=0,a=z;
	while(a!=x)
	{
		if(c==0)
		{
			if(b>=z)
			{
				c=z;
				b-=c;
			}
			else
			{
				c=b;
				b=0;
			}
			sum++;
		}
		else
		{
			if(c==z)
			{
			a+=c;
			c=0;
			sum++;
			}
			else if(b==0)
			{
				b=y;
				a-=b;
				sum++;
			}
			else if(b>0)
			{
				if(b>=z-c)
				{
					int t=z-c;
					c=z;
					b-=t;
				}
				else
				{
					b=0;
					c+=b;
				}
				sum++;
			}
		}
		if(a==b+c)
		break;
	}
		if(a==x)
		sum=0;
	
}
int main()
{
	while(cin>>n>>m>>k)
	{
		if(n==0&&m==0&&k==0)
		break;
		sum=0;
		if(n>k+m)
		{
			printf("NO\n");
		}
	    else if(m==k)
		{
			cout<<"1"<<endl;
		}
		else
		{
		dfs(n,m,k);
		if(sum)
		printf("%d\n",sum);
		else
		printf("NO\n");
		}
	}
 } 
