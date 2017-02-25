#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
map<long long,int>g;
int a[50000][35],cnt[35];
int main()
{
	int t,l,n,m,ca=1;
	cin>>t;
	while(t--)
	{
		memset(cnt,0,sizeof cnt);
		memset(a,0,sizeof a);
		g.clear();
		cin>>l>>n;
		for(int i=0;i<n;i++)
		{
			cin>>m;
			int x;
			for(int j=0;j<m;j++)
			{
			cin>>x;
			a[x][i]++;
			}
			
		}
		int ret=0;
		for(int i=0;i<l;i++)
		{
			int mi=l+1,ma=-1;
			for(int j=0;j<n;j++)
			{
				if(i) a[i][j]+=a[i-1][j];
				mi=min(mi,a[i][j]);
				ma=max(ma,a[i][j]);
			}
			if(ma==mi) ret=i+1;
			for(int j=0;j<n;j++)
			cnt[j]=a[i][j]-mi;
			long long tmp=0;
			for(int j=0;j<n;j++)
			{
				tmp*=16777619;
				cout<<tmp<<" "<<cnt[j]<<endl;
				tmp^=cnt[j];
				cout<<tmp<<endl;
			}
			int tt=g[tmp];
			if(tt)
			ret=max(ret,i-tt+1);
			else
			g[tmp]=i+1;
		
		}
			printf("Case %d: %d meter(s)\n",ca++,ret);
		
	 } 
	
}
