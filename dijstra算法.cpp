#include <bits/stdc++.h>  
using namespace std;  
int n,m,Start,End;  
const int maxn = 510;  
const int INF = 0x3f3f3f3f;  
struct node{  
    int to,next,w;  
}edge[maxn*maxn+10];  
int tot, head[maxn];  
void init(){  
    tot = 0;memset(head, -1, sizeof(head));  
}  
void add_edge(int u, int v, int w){  
    edge[tot].to = v;  
    edge[tot].w = w;  
    edge[tot].next = head[u];  
    head[u] = tot++;  
}  
bool vis[maxn];  
int dis[maxn];  
int sum[maxn];  
int a[maxn];  
void dij(){  
   memset(dis, INF, sizeof(dis));   
   dis[Start] = 0;  
   sum[Start] = a[Start];  
   for(int i=0; i<n; i++){  
       int minn = INF; int flag;  
       for(int j=0; j<n; j++)  
           if(!vis[j]&&minn > dis[j])  
               minn = dis[j], flag = j;  
       vis[flag] = true;  
       int u = flag;  
       for(int j=head[u]; j!=-1; j=edge[j].next){  
           int v = edge[j].to;  
           if(dis[u] + edge[j].w < dis[v]){  
               dis[v] = dis[u] + edge[j].w;  
               sum[v] = sum[u] + a[v];  
           }  
           else if(dis[u] + edge[j].w == dis[v]){  
               sum[v] = max(sum[v], sum[u] + a[v]);  
           }  
       }  
   }  
}  
int main(){  
    cin>>n>>m>>Start>>End;  
    init();  
    for(int i=0; i<n; i++) scanf("%d", a+i);  
    for(int i=1; i<=m; i++){  
        int u,v,w;  
        scanf("%d %d %d", &u, &v, &w);  
        add_edge(u, v, w);
		//printf("%d %d %d %d\n",edge[tot-1].to,edge[tot-1].w,edge[tot-1].next,head[u]);  
        add_edge(v, u, w);  
        //printf("%d %d %d %d\n",edge[tot-1].to,edge[tot-1].w,edge[tot-1].next,head[u]);
    }  
    dij();  
    cout<<dis[End]<<" "<<sum[End]<<endl;  
    return 0;  
}  
