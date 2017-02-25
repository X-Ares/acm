#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 50
typedef int wei;
typedef struct 
{
	int arc[maxn][maxn];
	char data[maxn];
	int vexs;
 } MG,*adj;
 void creat(adj g,int m[][maxn],char d[],int n)
 {
 	int i,j;
 	g->vexs=n;
 	for(i=0;i<n;i++)
 	{
 		g->data[i]=d[i];
 		for(j=0;j<n;j++) g->arc[i][j]=m[i][j];
	 }
 }
 void disp(adj g)
 {
 	int i,j;
 	printf("¶¥µã: \n\t");
 	for(i=0;i<g->vexs;i++)
 	printf("%c\t",g->data[i]);
 	printf("\n\n ÁÚ½Ó¾ØÕó£º");
 	for(i=0;i<g->vexs;i++)
 	{
 		printf("\n%c: \t",g->data[i]);
 		for(j=0;j<g->vexs;j++)
 		printf("%d\t",g->arc[i][j]);
	 }
	 printf("\n\n");
 }
 int getf(adj g,int k)
 {
 	int i;
 	if(k<0||k>g->vexs){
	  printf("³¬³ö·¶Î§\n");
 	  return -1;}
 	  for(i=0;i<g->vexs;i++)
 	  if(g->arc[k][i]==1) return i;
 	  return -1;
 	  
 }
 int getn(adj g,int k,int t)
 {
 	int i;
 	if(k<0||k>g->vexs||t<0||t>g->vexs){
	  printf("³¬³ö·¶Î§\n");
 	  return NULL;}
 	  for(int i=t+1;i<g->vexs;i++)
 	  	  if(g->arc[k][i]==1) return i;
 	  return -1;	  
 }
 /*void putvex(adj g,int k,char x)
 {
 	if(k<0||k>g->vexs){
	  printf("³¬³ö·¶Î§\n");
 	  return ;}
 	  g->data[k]=x;
 	
 }
 char getvex(adj g,int k)
 {
 	if(k<0||k>g->vexs){
	  printf("³¬³ö·¶Î§\n");
 	  return -1;}
 	  return g->data[k];
 }
 void insertarc(adj g,int u,int v,int w)
 {
 	if(v<0||v>g->vexs||u<0||u>g->vexs){
	  printf("³¬³ö·¶Î§\n");
 	  return ;}
 	  g->arc[u][v]=w;
 	
 }
 void del(adj g,int u,int v)
 {
 	if(v<0||v>g->vexs||u<0||u>g->vexs){
	  printf("³¬³ö·¶Î§\n");
 	  return ;}
 	  g->arc[u][v]=0;
 	
 }*/
 int main()
{
	MG gg;
	adj g=&gg;
	int pos,i;
	char d[]={'A','B','C','D','E'};
	int m[][maxn]={{0,1,0,0,1},{1,0,1,1,0},{0,1,0,0,0},{0,1,0,0,1},{1,0,0,1,0}};
	creat(g,m,d,5);
	disp(g);
	for(i=0;i<g->vexs;i++)
	{
		pos=getf(g,i);
		if(pos!=-1)
		{
			printf("\n[%c]\t%c",g->data[i],g->data[pos]);
		}
		else
		printf("\n[%c]",g->data[i]);
		while(pos!=-1)
		{
			pos=getn(g,i,pos);
			if(pos!=-1)printf("\t%c",g->data[pos]);
		}
	}
	return 0;
} 	
 	

