//多边形的面积并，要逆时针输入 
#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	return x>0?1:-1;
}
struct point 
{
	double x,y;
	point(){}
	point(double _x,double _y)
	{
		x=_x,y=_y;
	}
}p;
double seg(point o,point a,point b)
{
	if(dcmp(b.x-a.x)==0) return (o.y-a.y)/(b.y-a.y);
	return (o.x-a.x)/(b.x-a.x);
}
point operator -(point a,point b) {
	return point (a.x-b.x,a.y-b.y);
}
double Dot(point a,point b)
{
	return a.x*b.x+a.y*b.y;
}
double Cross(point a,point b)
{
	return a.x*b.y-a.y*b.x;
}
vector<point> pp[100];
pair <double,int>s[2000];
double PolyUnion(vector<point>*p,int n)
{
	double ret=0;
	for(int i=0;i<n;i++)
	{
		int sz1=p[i].size();
		for(int ii=0;ii<sz1;ii++)
		{
			int M=0;
			s[M++]=make_pair(0,0);
			s[M++]=make_pair(1,0);
			point A=p[i][ii],B=p[i][(ii+1)%sz1];
			for(int j=0;j<n;j++)
			if(i!=j)
			{
				int sz2=p[j].size();
				for(int jj=0;jj<sz2;jj++)
				{
					point C=p[j][jj],D=p[j][(jj+1)%sz2];
					int c1=dcmp(Cross(B-A,C-A));
					int c2=dcmp(Cross(B-A,D-A));
					if(c1==0&&c2==0)
					{
						if(dcmp(Dot(B-A,D-C))>0&&i>j)
						{
								s[M++]=make_pair(seg(C,A,B),1);
			   					s[M++]=make_pair(seg(D,A,B),-1);
						}
					}
					else
					{
						double s1=Cross(D-C,A-C);
						double s2=Cross(D-C,B-C);
						if(c1>=0&&c2<0) s[M++]=make_pair(s1/(s1-s2),1);
						else if(c1<0&&c2>=0) s[M++]=make_pair(s1/(s1-s2),-1);
					}
				}
			}
			std::sort(s,s+M);
			double pre=std::min(std::max(s[0].first,0.0),1.0),now;
			double sum=0;
			int cov=s[0].second;
			for(int j=1;j<M;j++)
			{
				now=std::min(std::max(s[j].first,0.0),1.0);
				if(!cov) sum+=now-pre;
				cov+=s[j].second;
				pre=now;
			}
			ret+=Cross(A,B)*sum;
		}	
	}
	return ret/2;
}
double Area(vector<point>p)
{
	double ans=0;
	int n=p.size();
	for(int i=1;i<n-1;i++)
	ans+=Cross(p[i]-p[0],p[i+1]-p[0]);
	return ans/2;
}

point a[5];
int main()  
{  
    int n,m,T=0,ca=1;  
        
        while(scanf("%d",&n)!=EOF)
        {
		 pp[0].clear();  
        pp[1].clear();  
        point p; 
        for(int i=0;i<4;i++){  
       // printf("%lf %lf\n",a[i].x,a[i].y);
       	scanf("%lf%lf",&p.x,&p.y);
            pp[0].push_back(p);  
        }  
      scanf("%d",&m);
        for(int i=0;i<4;i++){  
        //printf("%lf %lf\n",a[i].x,a[i].y);
            //cin>>p.x>>p.y;  
            scanf("%lf%lf",&p.x,&p.y);
            pp[1].push_back(p);  
        }  
        
        double t1=Area(pp[0])+Area(pp[1]); 
        double t2=PolyUnion(pp,2); 
		//printf("%.6lf\n",t1-t2);
		printf("Case %d: ",ca++); 
		if(t1-t2>0)
		printf("Yes\n");
		else
		printf("No\n");
		
		}
    
    
    return 0;  
}  
