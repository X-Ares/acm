#include<stdio.h>
#include<stdlib.h>
 typedef struct Node
{
	char data;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode, *BiTree;
void CreateBiTree1(BiTree &bt)
{
	char ch;
	scanf("%c",&ch);
	getchar();
	if(ch=='#')
	{
	bt = (BiTree)malloc(sizeof(Node));
		bt=NULL;
		printf("不产生子树!\n");
		return; 
	}
	else
	{
		bt = (BiTree)malloc(sizeof(Node));
		bt->data = ch;
	    printf("产生左子树!\n");
		CreateBiTree1(bt->LChild);
        printf("产生右子树!\n");
		CreateBiTree1(bt->RChild);
	}
	return;
}
void Visit(char ch)
{
	printf("%c",ch);
}

/*先序遍历二叉树, root为指向二叉树(或某一子树)根结点的指针*/
void  PreOrder(BiTree root)
{
    if (root!=NULL)
	{
         Visit(root ->data);  /*访问根结点*/
         PreOrder(root ->LChild);  /*先序遍历左子树*/
         PreOrder(root ->RChild);  /*先序遍历右子树*/
	}
}


/*中序遍历二叉树, root为指向二叉树(或某一子树)根结点的指针*/
void  InOrder(BiTree root)
{
	if (root!=NULL)
	{
         InOrder(root ->LChild);   /*中序遍历左子树*/
         Visit(root ->data);        /*访问根结点*/
         InOrder(root ->RChild);   /*中序遍历右子树*/
	}
}



/* 后序遍历二叉树，root为指向二叉树(或某一子树)根结点的指针*/
void  PostOrder(BiTree root)
{
	if(root!=NULL)
	{
        PostOrder(root ->LChild); /*后序遍历左子树*/
        PostOrder(root ->RChild); /*后序遍历右子树*/
        Visit(root ->data);       /*访问根结点*/
	}
}
int cost(BiTree root)
{
	if(root==NULL)
	return 0;
	else
	{
		return cost(root->LChild)+cost(root->RChild)+1;
	}
}
int depth(BiTree root)
{
	int ld,rd;
	if(root==NULL)
	return 0;
	else
	{
		ld=depth(root->LChild);
		rd=depth(root->RChild);
		return ld>rd?ld+1:rd+1;
	}
}
int main()
{
	BiTree b;
	CreateBiTree1(b);
	 PreOrder(b); 
	 printf("\n"); 
	InOrder(b);
	printf("\n");
	PostOrder(b);
	printf("\n");
	printf("%d\n",cost(b));
	printf("%d\n",depth(b));
 } 
