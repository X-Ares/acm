#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
char s[35][35][35];
bool hash[35][35][35];
struct pp{
	int x,y,z;
	int step;
};
int main()
{
	int n,m,l;
	while(cin>>n>>m>>l,n&&m&&l)
	{
	 int i,j,k;
	 pp ss;
	 memset(hash,false,sizeof hash);
	 for(i=0;i<n;i++)
	 {
	 	for(j=0;j<m;j++)
	 	{
	 		cin>>s[i][j];
	 		for(k=0;k<l;k++)
	 		{
	 			if(s[i][j][k]=='S')
	 			{
	 				ss.x=i;
	 				ss.y=j;
	 				ss.z=k;
	 				ss.step=0;
	 				hash[i][j][k]=true;
				 }
			 }
		 }
	 }
	 queue<pp>bfs;
	 bfs.push(ss);
	 bool find=false;
	 while(!bfs.empty())
	 {
	 	pp tmp=bfs.front();
	 	bfs.pop();
	 	if(s[tmp.x][tmp.y][tmp.z]=='E')
	 	{
	 		find=true;
	 		cout<<"Escaped in "<<tmp.step<<" minute(s)."<<endl;
	 		break;
		 }
		 tmp.step++;
		 pp tmp2;
		 if(tmp.x>0)
		 {
		 	tmp2=tmp;
		 	tmp2.x--;
		 	if(s[tmp2.x][tmp2.y][tmp2.z]!='#'&&hash[tmp2.x][tmp2.y][tmp2.z]==false)
		 	{
		 		hash[tmp2.x][tmp2.y][tmp2.z]==true;
		 		bfs.push(tmp2);
		 		
			 }
		 }
		  if(tmp.x<n-1)
		 {
		 	tmp2=tmp;
		 	tmp2.x++;
		 	if(s[tmp2.x][tmp2.y][tmp2.z]!='#'&&hash[tmp2.x][tmp2.y][tmp2.z]==false)
		 	{
		 		hash[tmp2.x][tmp2.y][tmp2.z]==true;
		 		bfs.push(tmp2);
		 		
			 }
		 }
		  if(tmp.y<m-1)
		 {
		 	tmp2=tmp;
		 	tmp2.y++;
		 	if(s[tmp2.x][tmp2.y][tmp2.z]!='#'&&hash[tmp2.x][tmp2.y][tmp2.z]==false)
		 	{
		 		hash[tmp2.x][tmp2.y][tmp2.z]==true;
		 		bfs.push(tmp2);
		 		
			 }
		 }
		  if(tmp.y>0)
		 {
		 	tmp2=tmp;
		 	tmp2.y--;
		 	if(s[tmp2.x][tmp2.y][tmp2.z]!='#'&&hash[tmp2.x][tmp2.y][tmp2.z]==false)
		 	{
		 		hash[tmp2.x][tmp2.y][tmp2.z]==true;
		 		bfs.push(tmp2);
		 		
			 }
		 }
		  if(tmp.z>0)
		 {
		 	tmp2=tmp;
		 	tmp2.z--;
		 	if(s[tmp2.x][tmp2.y][tmp2.z]!='#'&&hash[tmp2.x][tmp2.y][tmp2.z]==false)
		 	{
		 		hash[tmp2.x][tmp2.y][tmp2.z]==true;
		 		bfs.push(tmp2);
		 		
			 }
		 }
		  if(tmp.z<l-1)
		 {
		 	tmp2=tmp;
		 	tmp2.z++;
		 	if(s[tmp2.x][tmp2.y][tmp2.z]!='#'&&hash[tmp2.x][tmp2.y][tmp2.z]==false)
		 	{
		 		hash[tmp2.x][tmp2.y][tmp2.z]==true;
		 		bfs.push(tmp2);
		 		
			 }
		 }	 
	 }
	  if(!find)
		 {
		 	cout<<"Trapped!"<<endl;
		 }
	}
	return 0;
 } 
 
