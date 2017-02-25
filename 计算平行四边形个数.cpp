#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct st
{
	int q,p;
	
};
st a[10010],m[4000000];
int cmp(st a,st b)
{
	if(a.q==b.q)
	return a.p<b.p;
	return a.q<b.q;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>a[i].q>>a[i].p;
		int k=0;
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				m[k].q=a[i].q+a[j].q;
				m[k].p=a[i].p+a[j].p;
				k++;
			}
		}
		sort(m,m+k,cmp);
		int flag=0,total=0,sum=1;
		for(int i=1;i<k;i++)
		{
			if(m[i].q==m[flag].q&&m[i].p==m[flag].p)
			sum++;
			else
			{
				flag=i;
				total+=sum*(sum-1)/2;
				sum=1;
			}
		}
		cout<<total<<endl;
		
	}
	return 0;
}

