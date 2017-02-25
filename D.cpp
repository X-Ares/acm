#include<stdio.h>
#include<queue>
#include<string.h>
#include<algorithm>
using std::queue;
using std::min;
const int M = 4005;
const int inf = ~0u>>2;
struct eg{
	int u, v, cap, cost;
	eg(){}
	eg(int a, int b, int c, int d){
		u = a, v = b, cap = c, cost = d;
	}
}edg[M*2];
int fir[M], nex[M*2];
int n, m, s, t, ecnt;
void add(int a, int b, int c, int d){
	edg[ecnt] = eg(a, b, c, d);
	nex[ecnt] = fir[a], fir[a] = ecnt++;
	edg[ecnt] = eg(b, a, 0, -d);
	nex[ecnt] = fir[b], fir[b] = ecnt++;
}
int pre[M], dis[M];
bool vis[M];
int spfa(int s, int t, int n){
	queue<int>q;
	memset(pre, -1, sizeof(pre));
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i <= t; ++i) dis[i] = inf;
	dis[s] = 0; vis[s] = 1;
	q.push(s);
	while(!q.empty()){
		int u = q.front(); q.pop(); vis[u] = 0;
		for(int k = fir[u]; k != -1; k = nex[k]){
			int v = edg[k].v;
			if( edg[k].cap && dis[u] + edg[k].cost < dis[v]){
				dis[v] = edg[k].cost + dis[u];
				pre[v] = k;
				if(!vis[v]){
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	return dis[t] != inf;
}
int mincostEK(int s, int t, int n){
	int res = 0, minflow;
	while( spfa(s, t, n) ){
		minflow = inf;
		for(int k = pre[t]; k != -1; k = pre[edg[k].u]){
			minflow = min(minflow, edg[k].cap);
		}
		for(int k = pre[t]; k != -1; k = pre[edg[k].u]){
			edg[k].cap -= minflow;
			edg[k^1].cap += minflow;
		}
		res += dis[t] * minflow;
	}
	return res;
} 
int main(){
	int n, m, ca = 1;
	while(scanf("%d%d", &n, &m) != EOF){
		ecnt = 0;
		memset(fir, -1, sizeof(fir));
		for(int i = 0; i < m; ++i){
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			add(a, b, 1, c);
			add(a, b, 1, c+d); 
		}
		s = 0;
		t = n+1;
		add(s, 1, 2, 0);
		add(n, t, 2, 0);
		printf("Case %d: %d\n", ca++, mincostEK(s, t, n+2));
	}
} 
