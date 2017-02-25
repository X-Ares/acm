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
		printf("����������!\n");
		return; 
	}
	else
	{
		bt = (BiTree)malloc(sizeof(Node));
		bt->data = ch;
	    printf("����������!\n");
		CreateBiTree1(bt->LChild);
        printf("����������!\n");
		CreateBiTree1(bt->RChild);
	}
	return;
}
void Visit(char ch)
{
	printf("%c",ch);
}

/*�������������, rootΪָ�������(��ĳһ����)������ָ��*/
void  PreOrder(BiTree root)
{
    if (root!=NULL)
	{
         Visit(root ->data);  /*���ʸ����*/
         PreOrder(root ->LChild);  /*�������������*/
         PreOrder(root ->RChild);  /*�������������*/
	}
}


/*�������������, rootΪָ�������(��ĳһ����)������ָ��*/
void  InOrder(BiTree root)
{
	if (root!=NULL)
	{
         InOrder(root ->LChild);   /*�������������*/
         Visit(root ->data);        /*���ʸ����*/
         InOrder(root ->RChild);   /*�������������*/
	}
}



/* ���������������rootΪָ�������(��ĳһ����)������ָ��*/
void  PostOrder(BiTree root)
{
	if(root!=NULL)
	{
        PostOrder(root ->LChild); /*�������������*/
        PostOrder(root ->RChild); /*�������������*/
        Visit(root ->data);       /*���ʸ����*/
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
