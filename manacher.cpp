#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int p[222222],n;
char str[222222],s[222222];
void init()
{
	str[0]='#';
	
	for(int i=1,j=1;j<=2*n&&i<=n;i++)
	{
		str[j++]=s[i];
		//cout<<s[i]<<j<<endl;
		str[j++]='#';
		//cout<<str[j]<<endl;
	}
	//str[2*n]='#';
	str[2*n+1]='$';
}
void pk()
{
    int i;
    int mx = 0;
    int id;
    for(i=1; i<=2*n; i++)
    {
        if( mx > i )
            p[i] = min( p[2*id-i], mx-i );        
        else
            p[i] = 1;
        for(; str[i+p[i]] == str[i-p[i]]; p[i]++);
            
        if( p[i] + i > mx )
        {
            mx = p[i] + i;
            id = i;
        }
    }
}
int main()
{
	
	 std::ios::sync_with_stdio(false);
	while(cin>>s+1)
	{
		memset(str,0,sizeof str);
		memset(p,0,sizeof p);
		n=strlen(s+1);
		init();
		pk();
		int ma=0;
		for(int i=1;i<=2*n;i++)
		{
			cout<<p[i]<<endl;
			if(p[i]>ma)
			ma=p[i];
		}
		cout<<ma-1<<endl;
		
	}
	return 0;
 } 
