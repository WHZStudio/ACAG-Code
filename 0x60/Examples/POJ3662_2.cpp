#include <cstdio>
#include <cstring>
#include <deque>
const int maxn=1005;
const int maxm=1000005;
struct edge {int u,v,w;};
struct G {
	edge edges[2*maxm];
	int head[maxn],nxt[2*maxm],idx;
	inline void init() {idx=0;memset(head,-1,sizeof(head));}
	inline void addEdge(int u,int v,int w) {
		edges[idx]=(edge){u,v,w};
		nxt[idx]=head[u];head[u]=idx++;
	}
} g,h;
struct Node {int x,d;};int d[maxn];
int SP(int s,int t) {
	memset(d,0x3f,sizeof(d));d[s]=0;
	std::deque<Node> dq;dq.push_back((Node){s,0});
	while(dq.size()) {
		Node temp=dq.front();dq.pop_front();int u=temp.x;
		if(temp.d^d[u]) continue;
		for(int i=h.head[u];~i;i=h.nxt[i]) {
			edge &e=h.edges[i];
			if(d[e.v]>d[u]+e.w) {
				d[e.v]=d[u]+e.w;
				if(e.w) dq.push_back((Node){e.v,d[e.v]});
				else dq.push_back((Node){e.v,d[e.v]});
			}
		}
	}
	return d[t];
}
int n,p,k;
inline bool check(int num) {
	h.init();
	for(int i=0,end=g.idx;i<end;++i) {
		edge &e=g.edges[i];
		if(e.w<=num) h.addEdge(e.u,e.v,0);
		else h.addEdge(e.u,e.v,1);
	}
	return SP(1,n)<=k;
}
int main() {
	scanf("%d%d%d",&n,&p,&k);
	int a,b,c;g.init();
	while(p--) {
		scanf("%d%d%d",&a,&b,&c);
		g.addEdge(a,b,c);g.addEdge(b,a,c);
	}
	int l=0,r=1000000;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",check(l)?l:-1);
	return 0;
}
