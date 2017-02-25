#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#define LL(x) (x<<1)
#define RR(x) (x<<1)|1
int tree[5000000*4];
void build(int l,int r,int num)
{
    tree[num]=r-l+1;
    if(l==r)
    return ;
    int mid=(l+r)/2;
    build(l,mid,LL(num));
    build(mid+1,r,RR(num));
}
int find(int L,int R,int lift,int right,int num)
{
    if(L==lift&&R==right)
    return tree[num];
    if(tree[num]==right-lift+1)
    return R-L+1;
    if(tree[num]==0)
    return 0;
    int sum=0;
    int mid=(lift+right)/2;
    if(R<=mid)
    sum+=find(L,R,lift,mid,LL(num));
    else if(L>mid)
    sum+=find(L,R,mid+1,right,RR(num));
    else
    {
        sum+=find(L,mid,lift,mid,LL(num));
        sum+=find(mid+1,R,mid+1,right,RR(num));
    }
    return sum;
}
int update(int L,int R,int lift,int right,int k,int num)
{
    if(L==lift&&R==right)
    {
        if(k==-1)
        tree[num]=0;
        else
        tree[num]=R-L+1;
        return 0;
    } 
    int mid=(lift+right)/2;
    if(tree[num]==right-lift+1)
    {
        tree[LL(num)]=mid-lift+1;
        tree[RR(num)]=right-mid;
    }
    if(tree[num]==0)
    {
    tree[LL(num)]=0;
    tree[RR(num)]=0;    
    }
    if(mid>=R)
    update(L,R,lift,mid,k,LL(num));
    else if(mid<L)
    update(L,R,mid+1,right,k,RR(num));
    else
    {
        update(L,mid,lift,mid,k,LL(num));
        update(mid+1,R,mid+1,right,k,RR(num));
    }
    tree[num]=tree[LL(num)]+tree[RR(num)];
    return 0;
}
int main()
{
	int t,n,m,a,b,k,sum,s,e,l,r,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		build(1,n,1);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&k,&a,&b);
			if(k==1)
			{
				a++;
				sum=find(a,n,1,n,1);
				if(sum==0)
        	    printf("Can not put any one.\n");
				else
				{
					s=a;
					l=a;
					r=n;
					while(l<=r)
					{
						mid=(l+r)/2;
						if(find(l,mid,1,n,1)>0)
						{
							r=mid-1;
							s=mid;
						}
						else
						l=mid+1;
					}
					if(sum<=b)
					{
						r=n;
						l=a;
					while(l<=r)
					{
						mid=(l+r)/2;
						if(find(mid,r,1,n,1)>0)
						{
							l=mid+1;
							e=mid;
						}
						else
						r=mid-1;
					}
					}
					else
					{
						r=n;
						l=s;
					while(l<=r)
					{
						mid=(l+r)/2;
						if(find(s,mid,1,n,1)>=b)
						{
							r=mid-1;
							e=mid;
						}
						else
						l=mid+1;
					}						
					}
					printf("%d %d\n",s-1,e-1);
					update(s,e,1,n,-1,1);
				}				
			}
			else
			{
				sum=b-a+1-find(a+1,b+1,1,n,1);
				printf("%d\n",sum);
				update(a+1,b+1,1,n,1,1);
				
			}
		}
		printf("\n");
	}
	return 0;
 } 
