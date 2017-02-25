#include<iostream>
#include<algorithm>
using namespace std;
int a[10];
int main()
{
	int kk=0;
	while(1)
	{
		int count=0;
	for(int i=0;i<4;i++)
	{
	cin>>a[i];
	if(a[i]==0)
	count++;
	}
	

	if(count==4)
	break;
	if(kk!=0)
	{
	cout<<endl;
	}
	kk++;
	sort(a,a+4);
	int j=0,tmp=0;
	while(a[j]==0)
	{
		j++;
	}
	tmp=a[0];
	a[0]=a[j];
	a[j]=tmp;
	int k=-1;
	do
	{
		
		if(a[0]==k)
		{
			cout<<" ";
			for(int i=0;i<4;i++)
			cout<<a[i]; 
				
		}
		else
		{
			if(k!=-1)
			{
			cout<<endl;
			}
			
			k=a[0];
			for(int i=0;i<4;i++)
			cout<<a[i];
		}
		
	}while(next_permutation(a,a+4));
	cout<<endl;
	}
	
	return 0;
	
}
