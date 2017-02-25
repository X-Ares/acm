#include<iostream>
#include<cstring>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
using namespace std;
 typedef struct {
 	int key;
 }datatype;
typedef struct node
{
	datatype data;
	struct node *left,*right;
	
 } bstnode,*bstree;

 bstnode *bsts(bstree r,datatype x)
 {
 	bstnode *p;
 	p=r;
 	if(r==NULL) return NULL;
 	while(p!=NULL)
 	{
 		if(p->data.key==x.key) return p;
 		if(p->data.key<x.key) p=p->right;
 		else
 		p=p->left;
	 }
	 return NULL;
 }
 void bstin(bstree *r,datatype x)
 {
 	bstnode *p,*q=NULL;
 	p=*r;
 	while(p!=NULL)
 	{
 		q=p;
 			if(p->data.key==x.key) return ;
 		if(p->data.key<x.key) p=p->right;
 		else
 		p=p->left;
 		
	 }
	 p=(bstnode *)malloc(sizeof(bstnode));
	 p->data=x;
	 p->left=NULL;
	 p->right=NULL;
	 if(q==NULL)
	 {*r=p;return ; }
	if(q->data.key>x.key) q->left=p;
 	else
 	q->right=p;
 }
 void creat(bstree *r,datatype items[],int n)
 {
 	int i;
 	for(i=0;i<n;i++)
	bstin(r,items[i]);
 }
 void bstd(bstree *r,datatype x)
 {
 	bstnode *p,*q=NULL,*s;
 	p=*r;
 	while(p!=NULL&&p->data.key==x.key)
 	{
 		q=p;
 		if(p->data.key<x.key) p=p->right;
 		else p=p->left;
	 }
	 if(p==NULL) return ;
	 s=p;
	 if(s->left&&s->right)
	 {
	 	q=s;p=s->left;
	 	while(p->right!=NULL)
	 	{
	 		q=p;
	 		p=p->right;
		 }
	}
		 if(p!=s) s->data=p->data;
		 s=(p->left)?p->left:p->right;
		 if(!q) *r=s;
		 else
		 {
		 	if(q->left==p)
		 	q->left=s;
		 	else
		 	q->right=s;
		 }
	 free(p);
 }
 void dis(bstree r)
 {
 	if(!r) return ;
 	if(r->left!=NULL)
 	dis(r->left);
 	printf("%d\t",r->data.key);
 	if(r->right!=NULL)
 	dis(r->right);
 }
 int main()
 {
	bstree root=NULL;
	bstnode *p;
	datatype items[]={5,9,4,1,15,8,2};
	datatype x={10};
	creat(&root,items,7);
	dis(root);printf("\n"); 
	p=bsts(root,items[2]);
	printf("%d\n",p->data.key);
	bstin(&root,x);
	dis(root);("\n");
	bstd(&root,items[3]);
	dis(root);("\n");
	bstd(&root,items[1]);
	dis(root);("\n");
	printf("%.7lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
  } 
 
