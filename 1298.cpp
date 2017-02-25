
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
using namespace std;
 struct trie
{
	int count; //用于存储当前结点的公共前缀的字符串数目
	trie *childs[26]; //用于存储当前结点的子节点数组
	trie()
	{
		 count=0;  
        for(int i=0;i<26;i++)  
        childs[i]=NULL; 
	}
};
int pp;
char s1[105],s2[105],findd[105],ans[105];
char phone[8][4]={{0,1,2},{3,4,5},{6,7,8},{9,10,11},{12,13,14},{15,16,17,18},{19,20,21},{22,23,24,25}};  
int  num[8]={3,3,3,3,3,4,3,4}; 
trie*root ;
trie *current,*newnode;
/*void createTrie(char *str,int k)
{
	int length = strlen(str);
	Trie *p = root, *q;
	for(int i = 0;i<length;i++)
	{
		int id = str[i]-'a';
		if(p->next[id] != NULL)
		{
		   
			p = p->next[id];
			(p->v)+=k; 
		}
		else
		{
			q = new Trie;
	    	(q->v)+=k ;	
			p->next[id] = q;
			p = q;
			
		}
	}
}*/

void insert(char *str,int k) //插入字符串和它的频度
{
	int i,m;
	current=root;
	for(i=0;i<strlen(str);i++)
	{
		m=str[i]-'a';
		if(current->childs[m]!=NULL)
		{
			current=current->childs[m];
			(current->count)+=k;
		}
		else
		{
			newnode=new trie;
			(newnode->count)+=k;
			current->childs[m]=newnode;
			current=newnode;
		}
	}
}
void dfs(int cur,int len,trie *nd)
{
	int i,m;
	if(cur==len)
	{
		if(nd->count>pp)
		{
			pp=nd->count;
			for(int i=0;i<len;i++)
			findd[i]=ans[i];
			findd[len]='\0';
		}
		return ;
	}
	int t=s2[cur]-'2';
	for(int i=0;i<num[t];i++)
	{
		int r=phone[t][i];
		if(nd->childs[r]==NULL)
		continue;
		ans[cur]='a'+r;
		dfs(cur+1,len,nd->childs[r]);
	}
	return;
}

int main()  
{  
    int i,n,m,t,k,cnt,len;  
    scanf("%d",&t);  
    for(k=1;k<=t;k++)  
    {  
        printf("Scenario #%d:\n",k);  
        scanf("%d",&n);  
        root=new trie;
        while(n--)  
        {  
            scanf("%s %d",s1,&cnt);  
           // createTrie(s1,cnt);  
           insert(s1,cnt);
        }  
        scanf("%d",&m);  
        while(m--)  
        {  
            scanf("%s",s2);  
            len=strlen(s2);  
            for(i=1;i<len;i++)  
            {  
                pp=0;  //记录字符出现的频度  
                dfs(0,i,root);  
                if(pp>0)  
                printf("%s\n",findd);  
                else  
                printf("MANUALLY\n");  
            }  
            printf("\n");  
        }  
        printf("\n");  
    }  
    return 0;  
}
