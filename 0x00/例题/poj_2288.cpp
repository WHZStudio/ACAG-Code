#include <cstdio>
#include <cstring>
#include <algorithm>
const int INF=0x7fffffff;
int n,m,v[20];
int g[15][15];
int d[1<<15][15][15],c[1<<15][15][15];
void dp(int now,int status) {
	d[now][status]=INF;
	c[now][status]=1;
	for(int i=0;i<g[now].size();++i) {
		int to=g[now][i];
		if((status>>to&1)==0) {
			dp(to,status|(1<<to));
			d[now][status]=std::min(d[now][status],d[to][status|(1<<to)]+v[to]);
			c[now][status]+=c[to][status|(1<<to)];
		}
	}
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i) {
			scanf("%d",&v[i]);
		}
		int u,v;
		memset(g,0,sizeof(g));
		for(int i=0;i<m;++i) {
			scanf("%d%d",&u,&v);
			g[u][v]=g[v][u]=true;
		}
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		dp(1,0,n);
		printf("%d %d\n",d[0][1],c[0][1]);
	}
	return 0;
}
