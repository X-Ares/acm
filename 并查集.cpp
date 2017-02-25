#include<iostream>
#include<algorithm>
using namespace std;
struct p
{
	int x,y,z;
}a[200000];
int fin[200000];
int cmp(p a,p b)
{
	return a.z>b.z;
}
int findd(int x)
{
	return fin[x]==x?x:fin[x]=findd(fin[x]);
}
bool uni(int b,int c)
{
	int x=findd(b),y=findd(c);
	if(x==y) return false;
	fin[x]=y;
	return true;
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		
		for(int i=0;i<m;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a,a+m,cmp);
		for(int i=0;i<=n;i++)
		fin[i]=i;
		int ans=0,f=-1;
		for(int i=0;i<m;i++)
		{
			if(uni(a[i].x,a[i].y)&&f!=a[i].z)
			{
				ans++;
				f=a[i].z;
			}
		}
		cout<<ans<<endl;
	}
	
 } 
