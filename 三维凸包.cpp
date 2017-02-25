#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define N 510
struct tpoint
{
	double x,y,z;
	tpoint(){}
	tpoint(double _x,double _y,double _z)
	{
		x=_x,y=_y,z=_z;
	}
	tpoint operator -(const tpoint p)
	{
		return tpoint(x-p.x,y-p.y,z-p.z);
	}
	tpoint  operator *(const tpoint p)
	{
		return tpoint (y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);//叉积 
	}
	double operator ^(const tpoint p)
	{
		return x*p.x+y*p.y+z*p.z;//点积 
	}
};
struct fac
{
	int a,b,c;
	bool ok;	
};
struct t3dhull
{
	int n;//初始点数
	tpoint ply[N];//初始点 
	int trianglecnt;//凸包上三角形数 
	fac tri[6*N];//凸包三角形可以证明被创建的点不超过6N
	int vis[N][N];
	double dist(tpoint a) 
	{
		return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);//两点长度 
	 } 
	 double area(tpoint a,tpoint b,tpoint c)
	 {
	 	return dist((b-a)*(c-a));//三角面积*2 
	 }
	 double volume(tpoint a,tpoint b,tpoint c,tpoint d)
	 {
	 	return (b-a)*(c-a)^(d-a);//四面体有效体积*6 
	 }
	 double ptoplane(tpoint &p,fac &f)
	 {
	 	tpoint m=ply[f.b]-ply[f.a],n=ply[f.c]-ply[f.a],t=p-ply[f.a];
	 	return (m*n)^t;
	 }
	 void deal(int p ,int a,int b)
	 {
	 	int f=vis[a][b];
	 	fac add;
	 	if(tri[f].ok)
	 	{
	 		if(ptoplane(ply[p],tri[f])>eps) dfs(p,f);
	 		else
	 		{
	 			add.a=b,add.b=a,add.c=p,add.ok=1;
	 			vis[p][b]=vis[a][p]=vis[b][a]=trianglecnt;
	 			tri[trianglecnt++]=add;
			 }
		 }
	  } 
	  void dfs(int p,int cnt)
	  {
	  	tri[cnt].ok=0;
	  	deal(p,tri[cnt].b,tri[cnt].a);
	  	deal(p,tri[cnt].c,tri[cnt].b);
	  	deal(p,tri[cnt].a,tri[cnt].c);
	  	
	  }
	  void construct() //构建凸包 
	  {
	  	int i,j;
	  	trianglecnt=0;
	  	if(n<4) return;
	  	bool tmp=true;
	  	for(i=1;i<n;i++)
	  	{
	  		if(dist(ply[0]-ply[i])>eps)
	  		{
	  			swap(ply[1],ply[i]);
	  			tmp=false;
	  			break;
			  }
		  }
		  if(tmp) return ;
		  tmp=true;
		  for(i=2;i<n;i++)//前三点不共线 
		  {
		  		if(dist((ply[0]-ply[1])*(ply[1]-ply[i]))>eps)
	  		{
	  			swap(ply[2],ply[i]);
	  			tmp=false;
	  			break;
			  }
		  }
		  if(tmp) return ;
		  tmp=true;
		  for(i=3;i<n;i++)
		  {
		  		if(fabs((ply[0]-ply[1])*(ply[1]-ply[2])^(ply[0]-ply[i]))>eps)
	  		{
	  			swap(ply[3],ply[i]);
	  			tmp=false;
	  			break;
			  }
		  	
		  }
		  if(tmp) return ;
		  fac add;
		  for(i=0;i<4;i++)
		  {
		  	add.a=(i+1)%4,add.b=(i+2)%4,add.c=(i+3)%4,add.ok=1;
			  if(ptoplane(ply[i],add)>0) swap(add.b,add.c);
			  vis[add.a][add.b]=vis[add.b][add.c]=vis[add.c][add.a]=trianglecnt;
			  tri[trianglecnt++]=add;
		}
			  for(i=4;i<n;i++) //构建更新凸包 
			  {
			  	for(j=0;j<trianglecnt;j++)
			  	{
			  		if(tri[j].ok&&(ptoplane(ply[i],tri[j]))>eps)
			  		{
			  			dfs(i,j);break;
					  }
				  }
			  	
			   } 
			   
		   
			   int cnt=trianglecnt;
			   trianglecnt=0;
			   for(i=0;i<cnt;i++)
			   {
			   	if(tri[i].ok)
			   	tri[trianglecnt++]=tri[i];
			   }
		  
	  }
	  double area()//表面积
	  {
	  	double ret=0;
	  	for(int i=0;i<trianglecnt;i++)
	  	ret+=area(ply[tri[i].a],ply[tri[i].b],ply[tri[i].c]);
	  	return ret/2.0;
	   } 
}hull;
int main()
{
	while(scanf("%d",&hull.n)!=EOF)
	{
		int i;
		for(i=0;i<hull.n;i++)
		{
			scanf("%lf%lf%lf",&hull.ply[i].x,&hull.ply[i].y,&hull.ply[i].z);
		}
		hull.construct();
		printf("%.3f\n",hull.area());
	}
	return 0;
 } 
/*
4 
0 0 0
4 0 0
2 3 0
1 1 2
*/
