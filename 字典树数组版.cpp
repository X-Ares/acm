#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10000;
int tot;
int trie[maxn][26];
bool isw[maxn];
void insert(char *s,int rt)
{
	for(int i=0;s[i];i++)
	{
	int x=s[i]-'a';
	if(trie[rt][x]==0)
	{
		trie[rt][x]=++tot;
	}
	rt=trie[rt][x];
	}
	isw[rt]=true; 
}
bool find(char *s,int rt)
{
	for(int i=0;s[i];i++)
	{
		int x=s[i]-'a';
		if(trie[rt][x]==0)
		return false;
		rt=trie[rt][x];
	}
	return isw[rt];
}
char s[22];
int main()
{
	tot=0;
	int rt=++tot;
	memset(trie[rt],0,sizeof(rt));
	memset(isw,false,sizeof isw);
	while(gets(s)&&s[0]!='\0')
	{
		insert(s,rt);
	}
	while(scanf("%s",s)!=EOF)
	{
		if(find(s,rt))
		printf("%s\n",s);
	}
	return 0;
}
