
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

char str[1010][100];
struct Trie
{
    int next[1010*50][128],fail[1010*50],end[1010*50];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 128;i++)
            next[L][i] = -1;
        end[L++] = -1;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char s[],int id)
    {
        int len = strlen(s);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][s[i]] == -1)
                next[now][s[i]] = newnode();
            now = next[now][s[i]];
        }
        end[now] = id;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 128;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < 128;i++)
                if(next[now][i] == -1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int num[1010];
    void query(char buf[],int n)
    {
        for(int i = 0;i < n;i++)
            num[i] = 0;
        int len=strlen(buf);
        int now=root;
        for(int i=0;i<len;i++)
        {
            now=next[now][buf[i]];
            int temp = now;
            while( temp != root )
            {
                if(end[temp] != -1)
                    num[end[temp]]++;
                temp = fail[temp];
            }
        }
        for(int i = 0;i < n;i++)
            if(num[i] > 0)
                printf("%s: %d\n",str[i],num[i]);
    }

};

char buf[2000010];
Trie ac;
void debug()
{
    for (int i = 0; i < ac.L; i++)
    {
        printf("id = %3d ,fail = %3d ,end = %3d, chi = [",i,ac.fail[i],ac.end[i]);
        for (int j = 0; j < 128; j++)
            printf("%2d ",ac.next[i][j]);
        printf("]\n");
    }
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n) == 1)
    {
        ac.init();
        for(int i = 0;i < n;i++)
        {
            scanf("%s",str[i]);
            ac.insert(str[i],i);
        }
        ac.build();
        scanf("%s",buf);
        ac.query(buf,n);
    }
    return 0;
}
