#include<iostream>
#include<queue>
using namespace std;
int a[111111];
priority_queue<int> p;
int n,k,sum,mid;
int check(int x)
{
	while(!p.empty()) p.pop();
	int id=0,ret=0;
	for(int i=1;i<=n&&ret<=k;i++)
	{
		p.push(a[i]);
		if(p.size()>=x)
		ret+=p.top()*(++id),p.pop();
		
	}
	while(!p.empty()&&ret<=k)
	ret+=p.top()*(++id),p.pop();
	return ret<=k;
	
}

int main()
{
	
	while(cin>>n>>k)
	{
		for(int i=1;i<=n;i++)
		cin>>a[i];
		int l=1,r=n+1;
		while(l<r)
		{
			mid=(l+r)/2;
			if(check(mid)) r=mid;
			else l=mid+1;	
		}
		printf("%d\n",l==n+1?-1:l);
	
	}
}
