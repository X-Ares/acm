#include<bits/stdc++.h>
using namespace std;
const int CHAR = 26;
const int MAXN = 1000100;
struct SAM_Node {
	SAM_Node *fa,*next[CHAR];
	int len;
	int id,pos;
	int n1,m1;
	SAM_Node() {}
	SAM_Node(int _len) {
		fa = 0;
		len = _len;
		n1=0,m1=len;
		memset(next,0,sizeof(next));
	}
};
SAM_Node SAM_node[MAXN*2], *SAM_root, *SAM_last;
int SAM_size;
SAM_Node *newSAM_Node(int len) {
	SAM_node[SAM_size] = SAM_Node(len);
	SAM_node[SAM_size].id = SAM_size;
	return &SAM_node[SAM_size++];
}
SAM_Node *newSAM_Node(SAM_Node *p) {
	SAM_node[SAM_size] = *p;
	SAM_node[SAM_size].id = SAM_size;
	return &SAM_node[SAM_size++];
}
void SAM_init() {
	SAM_size = 0;
	SAM_root = SAM_last = newSAM_Node(0);
	SAM_node[0].pos = 0;
}
void SAM_add(int x,int len) {
	SAM_Node *p = SAM_last, *np = newSAM_Node(p->len+1);
	np->pos = len;
	SAM_last = np;
	for(; p && !p->next[x]; p = p->fa)
		p->next[x] = np;
	if(!p) {
		np->fa = SAM_root;
		return;
	}
	SAM_Node *q = p->next[x];
	if(q->len == p->len + 1) {
		np->fa = q;
		return;
	}
	SAM_Node *nq = newSAM_Node(q);
	 nq->len=nq->m1=p->len+1; 
	q->fa = nq;
	np->fa = nq;
	for(; p && p->next[x] == q; p = p->fa)
		p->next[x] = nq;
}
/*void SAM_add(int x,int len)  
{  
    SAM_Node *p=SAM_last,*np=newSAM_Node(p->len+1);  
    SAM_last=np;  
    while(p&&!p->next[x])  
    {  
        p->next[x]=np;  
        p=p->fa;  
    }  
    if(!p)  
        np->fa=SAM_root;  
    else  
    {  
        SAM_Node *q=p->next[x];  
        if(q->len==p->len+1)  
            np->fa=q;  
        else  
        {  
            SAM_Node *nq=newSAM_Node(q);  
            nq->len=nq->m1=p->len+1;  
            q->fa=nq;  
            np->fa=nq;  
            while(p&&p->next[x]==q)  
            {  
                p->next[x]=nq;  
                p=p->fa;  
            }  
        }  
    }  
}*/
void SAM_build(char *s) {
	SAM_init();
	int len = strlen(s);
	for(int i = 0; i < len; i++)
		SAM_add(s[i] - 'a',i+1);
}

//加入串后进行拓扑排序。
char str[MAXN];
int topocnt[MAXN*2];
SAM_Node *topsam[MAXN*2];

/*多串的建立：
//多串的建立,注意SAM_init()的调用
void SAM_build(char *s) {
	int len = strlen(s);
	SAM_last = SAM_root;
	for(int i = 0; i < len; i++)

	{
		if( !SAM_last->next[s[i] -'0'] || !(SAM_last->next[s[i] -'0']->len==
		                                    i+1) )
			SAM_add(s[i] - '0',i+1);
		else SAM_last = SAM_last->next[s[i] - '0'];
	}
}*/

int main()
{
	scanf("%s",str);
	int n = strlen(str);
        SAM_build(str);
        memset(topocnt,0,sizeof(topocnt));    
        for(int i = 0;i < SAM_size;i++)
            topocnt[SAM_node[i].len]++;
        for(int i = 1;i <= n;i++)
            topocnt[i] += topocnt[i-1];
        for(int i = 0;i <SAM_size;i++)
            topsam[--topocnt[SAM_node[i].len]] = &SAM_node[i];
            while(scanf("%s",str)!=EOF)
            {
            	n=strlen(str);
            	SAM_Node *p=SAM_root;
            	int num=0;
            	for(int i=0;i<n;i++)
            	{
            		int j=str[i]-'a';
            		if(p->next[j])
            		{
            			num++;
            			p=p->next[j];
					}
					else
					{
						while(p&&!p->next[j])p=p->fa;
						if(p) {
							num=p->len+1;
							p=p->next[j];
						}
						else
						num=0,p=SAM_root;
					}
					p->n1=max(num,p->n1);
				}
				for(int i=SAM_size-1;i>=0;i--)
				{
					p=topsam[i];
					if(p->n1<p->m1)p->m1=p->n1;
					if(p->fa&&p->fa->n1<p->n1)
					p->fa->n1=p->n1;
					p->n1=0;
				}
			}
			int ans=0;
			for(int i=0;i<SAM_size;i++)
			if(SAM_node[i].m1>ans)ans=SAM_node[i].m1;
			printf("%d\n",ans);
			return 0;
	
}

