#include<bits/stdc++.h>
using namespace std;
const int size = 26;
const int maxn=10000+1000;
struct state {
	state* go[size],*per;
	int max;
	void clear()
	{
		per=0;
		max=0;
		memset(go,0,sizeof go);
	}
		int calc()
		{
			if(per==0) return 0;
			else
			return max-per->max;	
		}
};
state pool[maxn*3],*cur;
state*root,*last;
void init()
{
	cur=pool;
	root=last=cur++;
	root->clear();
}
int tot;
void extend(int w) {
	state* p=last;
	state* np=cur++;//
	np->clear();//
	np->max=p->max+1;
	while(p&&p->go[w]==0)
	p->go[w]=np,p=p->per;
	if(!p)
	{
	np->per=root;
	tot+=np->calc();//
	}
	else
	{
		state *q=p->go[w];
		if(p->max+1==q->max)
		{
		np->per=q;
		tot+=np->calc();//
		}
		else
		{
			state* nq=cur++;//
			memcpy(nq->go,q->go,sizeof q->go);
			tot-=p->calc()+q->calc();  //
			nq->max=p->max+1;//
			nq->per=q->per;
			q->per=nq;
			np->per=nq;
			tot+=p->calc()+q->calc()+np->calc()+nq->calc();  //
			while(p&&p->go[w]==q)
			p->go[w]=nq,p=p->per;
		}
	}
	last=np;
}

 char s[maxn];
 int ans[maxn][maxn];
int main() {
	int n,t,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		n=strlen(s);
		for(int i=0;i<n;i++)
		{
			init();
			tot=0;
			for(int j=i;j<n;j++)
			{
				extend(s[j]-'a');
				ans[i][j]=tot;		
			}
		}
		scanf("%d",&m);
		int x,y;
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			x--,y--;
			printf("%d\n",ans[x][y]);
		}
	
	}
	return 0;

}
