#include<iostream>
#include<cstdio>
using namespace std;
#define lson l,m,rt*2  
#define rson m+1,r,rt*2+1 
int sum[200005];
inline void pushplus(int rt)
{
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%d",&sum[rt]);
		//printf("%d %d\n",rt,sum[rt]);
		return ;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
	pushplus(rt);
}
void updata(int p,int add,int l,int r,int rt)
{
	if(l==r)
	{
		sum[rt]+=add;
		return ;
	}
	int m=(l+r)/2;
	if(p<=m)
	updata(p,add,lson);
	else
	updata(p,add,rson);
	pushplus(rt);
}
int query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		return sum[rt];
	}
	int m=(l+r)/2;
	int ans=0;
	if(L<=m)
	ans+=query(L,R,lson);
	if(R>m)
	ans+=query(L,R,rson);
	return ans;
}
int main()
{
	int t,n,q=1,a,b;
	cin>>t;
	while(t--)
	{
		printf("Case %d:\n",q++);
		cin>>n;
		build(1,n,1);
		//printf("%d ",&sum[2]);
		char op[10];
		while(scanf("%s",op)&&op[0]!='E')
		{
			scanf("%d %d",&a,&b);
			if(op[0]=='Q')
			{
				printf("%d\n",query(a,b,1,n,1));
			}
				else if(op[0]=='S')
				{
					updata(a,-b,1,n,1);
				}
				else
				{
					updata(a,b,1,n,1);
				}
			
		}
	}
	return 0;
 } 
