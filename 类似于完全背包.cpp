#include<stdio.h>  
#include<string.h>  
#include<math.h>  
#include<stdlib.h>  
#include<map>  
#include<set>  
#include<stack>  
#include<queue>  
#include<vector>  
using namespace std;  
typedef long long ll;  
#define INF 1<<30  
#define F first  
#define S second  
const int N = 1e5+10;  
const int mod = 1e9+7;  
int main()  
{  
    int Q, n, m, k, T;  
    int a[110], b[110];  
    ll dp[10010]; //价值为i时的最小成本  
  
    while(~scanf("%d", &Q))  
    {  
        while(Q--)  
        {  
            ll res = 0;  
            scanf("%d%d%d%d", &n,&m,&k,&T);  
            for(int i=1; i<=m; i++) scanf("%d", a+i);  
            for(int i=1; i<=m; i++) scanf("%d", b+i);  
            for(int u=1; u<=n; u++)  
            {  
                for(int i=1; i<10010; i++) dp[i] = INF;  
                dp[0] = 0;  
                ll minn = INF;  
                for(int i=1; i<=m; i++)  
                {  
                    for(int j=0; j<=k; j++)  
                    {  
                       int nx=min(int(j+b[i]),k);
						dp[nx]=min(dp[nx],dp[j]+a[i]);
                    }  
                }  
                //for(int i=k; i<=2*k; i++) minn = min(minn,dp[i]);  
                //res += minn;  
                res += dp[k]; //将每级累加  
                for(int v=1; v<=m; v++)  
                    b[v] /= T;  
            }  
            if(res >= INF) puts("No Answer");  
            else printf("%lld\n", res);  
        }  
    }  
    return 0;  
}
