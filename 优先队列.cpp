#include<iostream>
#include<queue>
using namespace std;
struct cmp1{  
    bool operator ()(int &a,int &b){  
        return a>b;//最小值优先  
    }  
};
int main()
{
	priority_queue<int,vector<int>,cmp1>que;
	int n,m;
	while(cin>>n)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>m;
			que.push(m);
		}
		while(que.size()>1)
		{
			int x=que.top();
			que.pop();
			int y=que.top();
			que.pop();
			 
			que.push(x+y);
			sum+=x+y;
			
		}
		cout<<sum<<endl;
	}
}

