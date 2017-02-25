#define  MAX 26
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
using namespace std;
typedef struct Trie
{
	int v; //用于存储当前结点的公共前缀的字符串数目
	Trie *next[26]; //用于存储当前结点的子节点数组
}Trie;

Trie root ;

void createTrie(char *str)
{
	int length = strlen(str);
	Trie *p = &root, *q;
	for(int i = 0;i<length;i++)
	{
		int id = str[i]-'a';
		if(p->next[id] == NULL)
		{
			q = (Trie *)malloc(sizeof( root));
			q->v = 1;
			for(int j = 0;j<MAX;j++)
				q->next[j] = NULL;
			p->next[id] = q;
			p = p->next[id];
		}
		else
		{
			p->next[id]->v++;
			p = p->next[id];
		}
	}
}

int  FindTrie(char *str)
{

	int length  = strlen(str);
	Trie *p = &root;
	for(int i = 0 ;i<length;i++)
	{
		int id = str[i] - 'a';
		p = p->next[id];
		if(p == NULL)
		return 0; //即该字符串不在此树上
	}
	return p->v;
}
int main()
{
	char temp[16];
	int i;

	for( i=0;i<26;i++)
	root.next[i]=NULL;
	
	while(gets(temp)&&temp[0]!='\0')	
		createTrie(temp);
		memset(temp,0,sizeof temp);
		while(scanf("%s",temp)!=EOF)
		{
			printf("%d\n",FindTrie(temp));
		}
	
}
