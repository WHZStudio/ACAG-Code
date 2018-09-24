#include <cstdio>
#include <cstring>
#include <queue>
#include <bitset>
const int maxn=30005;
const int maxm=30005;
struct edge {int u,v;} edges[maxm];
int head[maxn],nxt[maxm],in[maxn],idx=0;
inline void addEdge(int x,int y) {
	edges[idx]=(edge){x,y};++in[y];
	nxt[idx]=head[x];head[x]=idx++;
}
int topo[maxn],topoidx=0;
std::bitset<maxn> vis[maxn];
int main() {
	int n,m;scanf("%d%d",&n,&m);
	int x,y;idx=0;memset(head,-1,sizeof(head));
	while(m--) {
		scanf("%d%d",&x,&y);
		addEdge(x,y);
	}
	std::queue<int> q;
	for(int i=1;i<=n;++i) if(!in[i]) q.push(i);
	while(q.size()) {
		int u=q.front();q.pop();topo[topoidx++]=u;
		for(int i=head[u];i!=-1;i=nxt[i]) {
			int v=edges[i].v;
			if(--in[v]==0) q.push(v);
		}
	}
	for(int i=topoidx-1;i>=0;--i) {
		int u=topo[i];
		vis[u].set(topo[i]);
		for(int j=head[u];j!=-1;j=nxt[j]) {
			int v=edges[j].v;
			vis[u]|=vis[v];
		}
	}
	for(int i=1;i<=n;++i) printf("%lu\n",vis[i].count());
	return 0;
}
