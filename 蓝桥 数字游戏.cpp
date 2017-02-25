#include<iostream>
using namespace std;
int main()
{
	long long  n,k,t;

	while(cin>>n>>k>>t)
	{
		long long ans=1,num=0,nn=1,m1,m2;
		for(int i=1;i<t;i++)
		{
			m1=i*n+1;
			m2=i*n;
			 if(m1%2==0){  
            m1=m1/2;  
	        }  
	        else{  
	            m2=m2/2;  
	        } 
			num=(((m1%k)*(m2%k))%k+1)%k;

			ans+=num;
	
		}
		cout<<ans<<endl;
		
	}
 } 
