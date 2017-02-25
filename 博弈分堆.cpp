#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <algorithm>  
#include <stack>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <string>  
#include <math.h>  
#include <stdlib.h>  
#include <time.h>  
using namespace std;  
#define REP(i,k,n) for(int i=k;i<n;i++)  
#define REPP(i,k,n) for(int i=k;i<=n;i++)  
#define scan(d) scanf("%d",&d)  
#define scann(n,m) scanf("%d%d",&n,&m)  
#define mst(a,k)  memset(a,k,sizeof(a));  
#define LL long long  
#define maxn 1000005  
#define mod 100000007  
  
#define MAX 1000  
int sg[maxn],vst[maxn];  
  
void take_part(int n)  
{  
     for(int i = 1; i <= n/3; i++)  
     {  
         for(int j=1;j<=n/3; j++)  
        {  
             int yihuo = 0;  
             yihuo ^= sg[i] ^ sg[j] ^sg[n-i-j];  
             vst[yihuo] = true;  
        }  
     }  
}  
  
 void get_sg()  //´ò±í  
 {  
     memset(sg, 0, sizeof(sg));  
     for(int i = 0; i < MAX; i++)  
     {  
         memset(vst, false, sizeof(vst));  
         int j = 0;  
         while(j++ < i)  
         {  
             vst[sg[j]] = true;  
         }  
         take_part(i);  
         for(int j = 0; j < MAX; j++)  
         {  
             if(!vst[j])  
             {  
                 sg[i] = j;  
                 break;  
             }  
         }  
     }  
     return ;  
 }  
  
int main()  
{  
    //freopen("out.txt","w",stdout); 
    get_sg(); 
    for(int i=0;i<1000;i++) 
    { 
        if(sg[i]!=i) 
        printf("sg[%d]=%d\n",i,sg[i]); 
    } 
    return 0; 
}
