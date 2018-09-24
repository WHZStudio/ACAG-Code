#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
const int maxn=100005;
const int maxm=500005;
const int INF=0x3f3f3f3f;
struct edge {int u,v;};
struct G {
	edge edges[2*maxm];
	int head[maxn],nxt[2*maxm],idx;
	inline void init() {idx=0;memset(head,-1,sizeof(head));}
	inline void addEdge(int u,int v) {
		edges[idx]=(edge){u,v};
		nxt[idx]=head[u];head[u]=idx++;
	}
} g,r;
int n,m,a[maxn],f[maxn],d[maxn];
struct Node {
	int x,d;
	bool operator < (const Node &rhs) const {return d>rhs.d;}
};
void dij1() {
	f[1]=a[1];for(int i=2;i<=n;++i) f[i]=INF;
	std::priority_queue<Node> pq;pq.push((Node){1,a[1]});
	while(pq.size()) {
		Node temp=pq.top();pq.pop();int u=temp.x;
		if(f[u]^temp.d) continue;
		for(int i=g.head[u];~i;i=g.nxt[i]) {
			edge &e=g.edges[i];
			if(f[e.v]>std::min(f[u],a[e.v])) {
				f[e.v]=std::min(f[u],a[e.v]);
				pq.push((Node){e.v,f[e.v]});
			}
		}
	}
}
void dij2() {
	for(int i=1;i<n;++i) d[i]=INF;d[n]=a[n];
	std::priority_queue<Node> pq;pq.push((Node){n,a[n]});
	while(pq.size()) {
		Node temp=pq.top();pq.pop();int u=temp.x;
		if(d[u]^temp.d) continue;
		for(int i=r.head[u];~i;i=r.nxt[i]) {
			edge &e=r.edges[i];
			if(d[e.v]>std::max(d[u],a[e.v])) {
				d[e.v]=std::max(d[u],a[e.v]);
				pq.push((Node){e.v,d[e.v]});
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	int x,y,z;g.init();r.init();
	while(m--) {
		scanf("%d%d%d",&x,&y,&z);
		if(z==1) {g.addEdge(x,y);r.addEdge(y,x);}
		else {g.addEdge(x,y);g.addEdge(y,x);r.addEdge(y,x);r.addEdge(x,y);}
	}
	dij1();dij2();
	int ans=0;
	for(int i=1;i<=n;++i) if((d[i]^INF)&&(f[i]^INF))ans=std::max(ans,d[i]-f[i]);
	printf("%d\n",ans);
	return 0;
}
