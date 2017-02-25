#include<iostream>
#include<cstring>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
queue<int>s2[2000],s1;

int  a[2000000];

int main()
{	string str;
	int n,m,k,c=0;
	while(cin>>n&&n!=0)
	{
		while(!s1.empty())
		{
			s1.pop();
		}
		for(int i=0;i<1222;i++) 
		{
		while(!s2[i].empty())
			s2[i].pop();
		}
		memset(a,0,sizeof a);
		for(int i=0;i<n;i++)
		{
			cin>>m;
			for(int j=0;j<m;j++)
			{
				cin>>k;
				a[k]=i;
			}
	
		}
		int x,count=0;int d=0;
		printf("Scenario #%d\n",++c);
		while(cin>>str&&str[0]!='S')
		{
			if(str[0]=='E')
			{
				cin>>x;
			if(s2[a[x]].empty())
			s1.push(a[x]);	
			s2[a[x]].push(x);
			}
			else
			{
				int w=s1.front();
				printf("%d\n",s2[w].front());
				s2[w].pop();
				if(s2[w].empty())
				s1.pop();

			}
		}
		if(str[0]='S')
		printf("\n");
	}
	return 0;
 } 
