#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const ll N= 1000010;
ll father[N],head[N];//记录节点数 
bool vis[N];
ll n,m,cont;
double sum=0;
typedef struct 
{
	ll v,u,w;
}BY;
typedef struct 
{
	ll from,to,next,w;
}TH;
TH th[N];//路径存储 
BY ed[N];
ll find(ll x)
{
	return x==father[x]?x:father[x]=find(father[x]);
}
void add(ll from,ll to, ll w)
{
	th[cont].to=to;
	th[cont].w=w;
	th[cont].next=head[from];
	head[from]=cont++;
	
}
bool cmp(BY a,BY b)
{
	return a.w<b.w;
}
ll kruskal()
{
	ll i=0,ans=0;
	for(i=0;i<=n;i++)
	father[i]=i;
	sort(ed,ed+m,cmp);
	for(int i=0;i<m;i++)
	{
		ll a,b;
		a=find(ed[i].u);
		b=find(ed[i].v);
		if(a!=b)
		{
			father[b]=a;
			add(ed[i].u,ed[i].v,ed[i].w);
			add(ed[i].v,ed[i].u,ed[i].w);
			ans+=ed[i].w;
		}
	}
	return ans;
}
ll dfs (ll x)
{
	vis[x]=1;
	ll num=1,tmp=0;
	for(ll i=head[x];i!=-1;i=th[i].next)
	{
		ll t=th[i].to;
		ll w=th[i].w;
		if(!vis[t])
		{
			tmp=dfs(t);
			sum+=tmp*(n-tmp)*w*1.0;
			num+=tmp;
		}
		
	}
	return num;
}
int main()
{
	int t,i;
	cin>>t;
	while(t--)
	{
		sum=cont=0;
		scanf("%lld%lld",&n,&m);
		memset(head,-1,sizeof head);
		memset(vis,false,sizeof vis);
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&ed[i].u,&ed[i].v,&ed[i].w);
		}
		ll ans=kruskal();
		dfs(1);
		printf("%lld %.2lf\n",ans,sum*2.0/(n*(n-1)*1.0));
	}
	return 0;
 } 
