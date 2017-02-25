#include<iostream>  
#include<algorithm>  
#include<cstring>  
#include<string>  
#include<cstdio>  
using namespace std;  
int a,b,k;    
int dp[15][110][110];  
int pw[11]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};  
int dfs(int d,int m1,int m2)  
{  
    if(d==0) return (m1==0&&m2==0)?1:0;  
    if(dp[d][m1][m2]>=0) return dp[d][m1][m2];  
    dp[d][m1][m2]=0;  
    for(int i=0;i<10;i++)  
        dp[d][m1][m2]+=dfs(d-1,((m1-i)%k+k)%k,((m2-i*pw[d-1])%k+k)%k);  
    return dp[d][m1][m2];  
}   
int func(int n)  
{  
    int d=0,m1=0,m2=0,a[15];  
    if(n==0) a[d++]=0;  
    while(n!=0)  
    {  
        a[d]=n%10;  
        n/=10;  
        d++;  
    }  
    int ans=0;  
    for(int i=d-1;i>=0;i--)  
    {  
         
        for(int j=0;j<a[i];j++)  
        {  
            ans+=dfs(i,(k-(m1+j)%k)%k,(k-(m2+pw[i]*j)%k)%k);  
        }  
       
        m1+=a[i];  
        m2+=pw[i]*a[i];  
  
    }  
    return ans;  
}  
  
int main()  
{  
    int t;  
    cin>>t;  
    while(t--)  
    {  
        cin>>a>>b>>k;  
        if(k>100)  
            printf("0\n");  
        else{  
            memset(dp,-1,sizeof(dp));  
            printf("%d\n",func(b+1)-func(a));  
        }  
    }  
    return 0;  
}
