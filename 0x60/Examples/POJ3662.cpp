#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
const int maxn=1005;
const int maxm=10005;
const int maxk=1005;
struct edge {int u,v,w;} edges[2*maxm];
int head[maxn],nxt[2*maxm],idx=0;
inline void addEdge(int u,int v,int w) {
	edges[idx]=(edge){u,v,w};
	nxt[idx]=head[u];head[u]=idx++;
}
struct Node {
	int x,y,d;
	inline bool operator < (const Node &rhs) const {return d>rhs.d;}
};
int N,P,K,d[maxn][maxk];
inline void dijkstra() {
	memset(d,0x3f,sizeof(d));d[1][0]=0;
	std::priority_queue<Node> pq;pq.push((Node){1,0,0});
	while(pq.size()) {
		Node temp=pq.top();pq.pop();int x=temp.x,k=temp.y;
		if(temp.d>d[x][k]) continue;
		for(int i=head[x];~i;i=nxt[i]) {
			edge &e=edges[i];
			if(k+1<=K&&d[e.v][k+1]>d[x][k]) {
				d[e.v][k+1]=d[x][k];
				pq.push((Node){e.v,k+1,d[e.v][k+1]});
			}
			if(d[e.v][k]>std::max(d[x][k],e.w)) {
				d[e.v][k]=std::max(d[x][k],e.w);
				pq.push((Node){e.v,k,d[e.v][k]});
			}
		}
	}
}
int main() {
	scanf("%d%d%d",&N,&P,&K);
	int a,b,c;idx=0;memset(head,-1,sizeof(head));
	while(P--) {
		scanf("%d%d%d",&a,&b,&c);
		addEdge(a,b,c);addEdge(b,a,c);
	}
	dijkstra();
	printf("%d\n",d[N][K]==0x3f3f3f3f?-1:d[N][K]);
	return 0;
}
