#include<iostream>
using namespace std;
typedef long long  ll;

int main()
{
	ll n;
	while(cin>>n)
	{
		
		ll i=1,count=0,after=0,before=0,cur=0;
		while((n/i)!=0)
		{
			cur=(n/i)%10;
			before=(n)/(i*10);
			after=n-(n/i)*i;
		
		if(cur>1)
		count=count+(before+1)*i;
		else if(cur==0)
		count=count+before*i;
		else if(cur==1)
		count=count+before*i+after+1;
		i=i*10;
		}
		cout<<count<<endl;
	}
	
}
