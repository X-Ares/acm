#include<cstdio> 
#include<cstdlib> 
#define maxn 50
typedef struct arc
{
	int adj ;
	struct arc *next;
}arcn,*pa;
typedef struct
{
	char data;
	arcn *head;
}vex;
typedef struct {
	vex list[maxn];
	int edg,vexs;
}VG,*adjl;
void creat(adjl *g,int m[][maxn],int n)
{
	int i,j;
	pa p;
	*g=(adjl)malloc(sizeof(VG));
	(*g)->edg=0;
	(*g)->vexs=n;
	for(i=0;i<n;i++)
	{
		(*g)->list[i].head=NULL;
		for(j=n-1;j>=0;j--)
		{
			if(m[i][j]!=0)
			{
				p=(pa)malloc(sizeof(arcn));
				p->adj=j;
				p->next=(*g)->list[i].head;
					(*g)->list[i].head=p;
					(*g)->edg++;
			}
		}
	 } 
	}
	void disp(adjl g)
	{
		int i;
		pa p;
		for(i=0;i<g->vexs;i++)
		{
			printf("\nline %d\t",i);
			p=g->list[i].head;
			while(p!=NULL)
			{
				printf("[%d]\t",p->adj);
				p=p->next;
			}
		}
	}
	int getf(adjl g,int k)
	{
		if(k<0||k>g->vexs){
	  printf("³¬³ö·¶Î§\n");
 	  return -1;}
 	  if(g->list[k].head==NULL) return -1;
 	  else return g->list[k].head->adj;
	 } 
	 int getn(adjl g,int k,int u)
	 {
	 	pa p;
	 	if(k<0||k>g->vexs||u<0||u>g->vexs){
	  printf("³¬³ö·¶Î§\n");
 	  return -1;}
 	  p=g->list[k].head;
 	  while(p->next!=NULL&&p->adj!=u) p=p->next;
 	  if(p->next==NULL) return -1;
 	  else return p->next->adj;
	 }
	 int main()
	 {
	 	adjl g;
	 	int pos,i;
	 	int m[][maxn]={{0,1,1,0,0},{1,0,0,1,1},{1,0,0,0,0},{0,1,0,0,1},{0,1,0,1,0}};
	 	creat(&g,m,5);
	 	printf("\n1:\n");
	disp(g);
	printf("\n\n\n2:\n");
	for(i=0;i<g->vexs;i++)
	{
		pos=getf(g,i);
		if(pos!=-1)
		{
			printf("\nline%d\t[%d]",i,pos);
		}
		else
		printf("\nline%d11",i);
		while(pos!=-1)
		{
			pos=getn(g,i,pos);
			if(pos!=-1)printf("\t[%d]",pos);
		}
	}
	return 0;
	 	
	 }
