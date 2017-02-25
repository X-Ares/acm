#define  MAX 26
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
using namespace std;
typedef struct Trie
{
	int f;
	int v; //用于存储当前结点的公共前缀的字符串数目
	Trie *next[26]; //用于存储当前结点的子节点数组
}Trie;

Trie *root ;
char s[1000000][15];
void createTrie(char *str,int tmp)
{
	int length = strlen(str);
	Trie *p = root, *q;
	for(int i = 0;i<length;i++)
	{
		int id = str[i]-'a';
		if(p->next[id] == NULL)
		{
			q = (Trie *)malloc(sizeof(Trie));
			q->v = tmp;
			q->f=0;
			for(int j = 0;j<MAX;j++)
				q->next[j] = NULL;
			p->next[id] = q;
		 	p = q;
		}
		else if(p->next[id]->f==0)
		{
			p->next[id]->v=tmp;
			p = p->next[id];
		}
	}
	p->f=1;
}

int  FindTrie(char *str)
{

	int length  = strlen(str);
	Trie *p = root;
	for(int i = 0 ;i<length;i++)
	{
		int id = str[i] - 'a';
		if(p->next[id])
		p = p->next[id];
		else
		return 0; //即该字符串不在此树上
	}
	if(p->f) 
	return p->v;
	else
	return 0;
}
int main()
{
	root =(Trie *)malloc(sizeof(Trie));
	for(int i=0;i<26;i++)
	root->next[i]=NULL;
	root->f=0;
	root->v=0;
	char t[4000],tt[100],b[4000];
	int j=1;
	scanf("%s",s[j]);
	while(1)
	{
	scanf("%s",s[j]);
		if(s[j][0]=='E')
		break;
		j++;
		scanf("%s",s[j]);
		createTrie(s[j],j);
		j++;
	}
	getchar();
	gets(b);
	while(1)
	{
		gets(t);
		if(t[0]=='E')
		break;
		int len=strlen(t);
		j=0;
		for(int i=0;i<len;i++)
		{
			if(t[i]>=97&&t[i]<=122)
			{
				tt[j++]=t[i];
			}
			else
			{
				tt[j]='\0';
				if(FindTrie(tt))
				{
					int num=FindTrie(tt);
					printf("%s",s[num-1]);
				}
				else
				{
					printf("%s",tt);
				}
				printf("%c",t[i]);
				memset(tt,0,sizeof tt);
				j=0;
			}
			
		}
		printf("\n");
	}

	//del(root);
	return 0;
}
