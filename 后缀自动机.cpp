#include<bits/stdc++.h>
using namespace std;
const int size = 26;
const int maxn=10000+1000;
struct state {
	state* go[size],*per;
	int max;
	state(int _max=0) {
		per=0,max=_max;
		memset(go,0,sizeof go);
	}
};
int sz;
state pool[maxn*3];
inline state* newnode(int _Max = 0) {
	memset(pool[sz].go , 0 , sizeof(pool[sz].go));
	pool[sz].per = 0;
	pool[sz].max = _Max;
	return &pool[sz++];
};
state*root,*last;
void extend(int w) {
	state* p=last;
	state* np=newnode(p->max+1);
	while(p&&p->go[w]==0)
	p->go[w]=np,p=p->per;
	if(!p)
	np->per=root;
	else
	{
		state *q=p->go[w];
		if(p->max+1==q->max)
		np->per=q;
		else
		{
			state* nq=newnode(p->max+1);
			memcpy(nq->go,q->go,sizeof q->go);
			nq->per=q->per;
			q->per=nq;
			np->per=nq;
			while(p&&p->go[w]==q)
			p->go[w]=nq,p=p->per;
		}
	}
	last=np;
}
int query(int n)
{
	state* now=root;
	while(n--)
	{
		for(int i=0;i<size;i++)
		if(now->go[i])
		{
			now=now->go[i];
			break;
		}
	}
	return now->max;
}
 inline int  id(char c )
 {
 	return c - 'a';
 }
 char s[maxn];
int main() {
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		sz=0;
		root=newnode();
		last=root;
		n=strlen(s);
		for(int i=0;i<2;i++)
		for(int j=0;j<n;j++)
		extend(id(s[j]));
		printf("%d\n",query(n)-n+1);
	}
	return 0;

}
