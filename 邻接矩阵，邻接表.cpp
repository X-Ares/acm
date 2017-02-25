#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OVERFLOW -2
#define MAX_VEX_NUM 20
using namespace std;
typedef int Status;
//定义邻接表存储类型 
typedef char VexType;
typedef struct EdgeNode//定义边表结点类型 
{
    int adjvex;
    EdgeNode *next;
}EdgeNode,*EdgeLink;
typedef struct VexNode
{
    VexType data;
    EdgeNode *firstedge;
}VexNode,AdjList[MAX_VEX_NUM];
typedef struct//定义图抽象数据类型 
{
    AdjList adjList;
    int vexnum,edgenum;
}GraphAdjList;
//建立队列数据结构 
typedef struct QNode //定义一个链表抽象数据类型 
{
    int data;
    QNode *next;
}*Linklist;
typedef struct Queue
{
    Linklist front;
    Linklist rear; 
}QList;
Status InitQueue(QList &Q)//初始化队列 
{
    Q.front=Q.rear=new QNode;
    if(!Q.front) exit(OVERFLOW);
    Q.front->next=NULL;
    Q.front->data=0; 
    return OK;
}
Status EnQueue(QList &Q,int e)//插入函数，用于在队尾插入数据e 
{
    Linklist s;
    if(!(s=new QNode))
    exit(ERROR);
    s->data=e;
    s->next=NULL; 
    Q.rear->next=s;
    Q.rear=s;
    Q.front->data++; 
    return OK;
}
Status DeQueue(QList &Q,int &e)//删除函数，删除队头元素，并把值赋予e
{
      Linklist q;
      if(Q.front==Q.rear) exit(ERROR);
      q=Q.front->next;
      Q.front->next=q->next;
       e=q->data;
       if(q==Q.rear) Q.rear=Q.front;
       Q.front->data--;
     free(q);
       return OK;
}
Status QueueEmpty(QList Q)
{
    if(Q.front==Q.rear)
        return TRUE;
    return FALSE;
}
//创建图的邻接表结构
Status CreateGraph(GraphAdjList &G)
{
    int i,j,k;
    EdgeLink e;
    puts("请输入顶点数目和边数:");
    cin>>G.vexnum>>G.edgenum;
    puts("请输入顶点数值："); 
    getchar(); 
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.adjList[i].data;
        G.adjList[i].firstedge=NULL;
		
    }
    puts("请依次输入边(Vi,Vj)的顶点序号:");
    for(k=0;k<G.edgenum;k++)//添加边表结点 
    {
        cin>>i>>j;
        e=new EdgeNode;
        e->adjvex=j;
        e->next=G.adjList[i].firstedge;
        G.adjList[i].firstedge=e;
        e=new EdgeNode;
        e->adjvex=i;
        e->next=G.adjList[j].firstedge;
        G.adjList[j].firstedge=e;
    }
    return OK;
}
//邻接表的深度优先遍历
bool visited[MAX_VEX_NUM]; //定义一个全局数组，用于记录遍历状态 
/*void DFS(GraphAdjList G,int i)//递归从第I个结点深度优先遍历图 
{
    EdgeLink p;
    visited[i]=TRUE;
    cout<<G.adjList[i].data;
    p=G.adjList[i].firstedge;
    while(p)
    {
        if(!visited[p->adjvex])//判断是否已访问 
            DFS(G,p->adjvex);
        p=p->next; 
    }
}
Status DFSTraverse(GraphAdjList G)
{
    int i;
    memset(visited,0,sizeof(visited));//Visited置零 
    for(i=0;i<G.vexnum;i++)//依次访问所有结点，防止出现对非连通图的不完全访问 
        if(!visited[i])
            DFS(G,i);
    return OK;
}*/
//邻接表的广度优先遍历
Status BFSTraverse(GraphAdjList G)
{
    int i;
    EdgeLink p;
    QList Q;
    InitQueue(Q);
    memset(visited,0,sizeof(visited));//Visited置零 
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            visited[i]=TRUE;
            cout<<G.adjList[i].data;
            EnQueue(Q,i);
            while(!QueueEmpty(Q))
            {
                DeQueue(Q,i);
                p=G.adjList[i].firstedge;
                while(p)
                {
                    if(!visited[p->adjvex])
                    {
                        visited[p->adjvex]=TRUE;
                        cout<<G.adjList[p->adjvex].data;
                        EnQueue(Q,p->adjvex);
                    }
                    p=p->next;
                }
            }
        }
    }
    return OK;
}
Status main()
{
    GraphAdjList G;
    CreateGraph(G);
   // puts("邻接表的深度优先遍历为:");
   // DFSTraverse(G);
    puts("\n邻接表的广度优先遍历为:");
    BFSTraverse(G);
    system("pause");
    return OK;
}
