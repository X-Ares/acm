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
//�����ڽӱ�洢���� 
typedef char VexType;
typedef struct EdgeNode//����߱������� 
{
    int adjvex;
    EdgeNode *next;
}EdgeNode,*EdgeLink;
typedef struct VexNode
{
    VexType data;
    EdgeNode *firstedge;
}VexNode,AdjList[MAX_VEX_NUM];
typedef struct//����ͼ������������ 
{
    AdjList adjList;
    int vexnum,edgenum;
}GraphAdjList;
//�����������ݽṹ 
typedef struct QNode //����һ����������������� 
{
    int data;
    QNode *next;
}*Linklist;
typedef struct Queue
{
    Linklist front;
    Linklist rear; 
}QList;
Status InitQueue(QList &Q)//��ʼ������ 
{
    Q.front=Q.rear=new QNode;
    if(!Q.front) exit(OVERFLOW);
    Q.front->next=NULL;
    Q.front->data=0; 
    return OK;
}
Status EnQueue(QList &Q,int e)//���뺯���������ڶ�β��������e 
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
Status DeQueue(QList &Q,int &e)//ɾ��������ɾ����ͷԪ�أ�����ֵ����e
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
//����ͼ���ڽӱ�ṹ
Status CreateGraph(GraphAdjList &G)
{
    int i,j,k;
    EdgeLink e;
    puts("�����붥����Ŀ�ͱ���:");
    cin>>G.vexnum>>G.edgenum;
    puts("�����붥����ֵ��"); 
    getchar(); 
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.adjList[i].data;
        G.adjList[i].firstedge=NULL;
		
    }
    puts("�����������(Vi,Vj)�Ķ������:");
    for(k=0;k<G.edgenum;k++)//��ӱ߱��� 
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
//�ڽӱ��������ȱ���
bool visited[MAX_VEX_NUM]; //����һ��ȫ�����飬���ڼ�¼����״̬ 
/*void DFS(GraphAdjList G,int i)//�ݹ�ӵ�I�����������ȱ���ͼ 
{
    EdgeLink p;
    visited[i]=TRUE;
    cout<<G.adjList[i].data;
    p=G.adjList[i].firstedge;
    while(p)
    {
        if(!visited[p->adjvex])//�ж��Ƿ��ѷ��� 
            DFS(G,p->adjvex);
        p=p->next; 
    }
}
Status DFSTraverse(GraphAdjList G)
{
    int i;
    memset(visited,0,sizeof(visited));//Visited���� 
    for(i=0;i<G.vexnum;i++)//���η������н�㣬��ֹ���ֶԷ���ͨͼ�Ĳ���ȫ���� 
        if(!visited[i])
            DFS(G,i);
    return OK;
}*/
//�ڽӱ�Ĺ�����ȱ���
Status BFSTraverse(GraphAdjList G)
{
    int i;
    EdgeLink p;
    QList Q;
    InitQueue(Q);
    memset(visited,0,sizeof(visited));//Visited���� 
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
   // puts("�ڽӱ��������ȱ���Ϊ:");
   // DFSTraverse(G);
    puts("\n�ڽӱ�Ĺ�����ȱ���Ϊ:");
    BFSTraverse(G);
    system("pause");
    return OK;
}
