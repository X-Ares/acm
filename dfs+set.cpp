#include<iostream>
#include<set>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100],n,m,b[100];
set< pair<int ,int> >s;
void dfs(int x)
{
	if(x==m)
	{
		if(b[0]<=b[1]&&b[1]<=b[2]&&b[0]+b[1]>b[2])
		{
			s.insert(make_pair(b[0],b[1]));
			cout<<b[0]<<b[1]<<b[2]<<endl;
		}
		return ;
	}
	for(int i=0;i<3;i++)
	{
		b[i]+=a[x];
		//cout<<b[i]<<endl; 
		dfs(x+1);
		b[i]-=a[x];
	}
	
}
int main()
{

		cin>>n;		
	
		while(n--)
		{
			s.clear();
			cin>>m;
			for(int i=0;i<m;i++)
				cin>>a[i];
				dfs(0);	
			
			cout<<s.size()<<endl;
		}
	
	return 0;
 } 
