#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>
const int maxn=100005;
struct edge {int u,v,w;} edges[2*maxn];
int head[maxn],nxt[2*maxn],idx0=0;
inline void add(int u,int v,int w) {
	edges[idx0]=(edge){u,v,w};
	nxt[idx0]=head[u];head[u]=idx0++;
}
int d[maxn];
void dfs(int x,int fa) {
	for(register int i=head[x];~i;i=nxt[i]) {
		int v=edges[i].v;if(v==fa) continue;
		d[v]=d[x]^edges[i].w;
		dfs(v,x);
	}
}
int ch[maxn*31][2],idx=0;
inline void init() {idx=0;memset(ch[0],-1,sizeof(ch[0]));}
inline void insert(std::bitset<31> &bs) {
	int rt=0;
	for(register int i=0;i<31;++i) {
		int c=bs[i];
		if(ch[rt][c]==-1) {
			ch[rt][c]=++idx;
			memset(ch[idx],-1,sizeof(ch[idx]));
		}
		rt=ch[rt][c];
	}
}
inline int search(std::bitset<31> &bs) {
	int ans=0,rt=0;
	for(register int i=0;i<31;++i) {
		int c=bs[i];
		if(ch[rt][c^1]==-1) {
			rt=ch[rt][c];
			ans=ans<<1|0;
		}
		else {
			rt=ch[rt][c^1];
			ans=ans<<1|1;
		}
	}
	return ans;
}
int main() {
	int n;
	while(scanf("%d",&n)==1) {
		int m=n-1,u,v,w;idx0=0;memset(head,-1,sizeof(head));
		while(m--) {
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);add(v,u,w);
		}
		d[1]=0;dfs(1,-1);init();
		int ans=0;std::bitset<31> bs;
		for(register int i=1;i<=n;++i) {
			for(register int j=0;j<31;++j) bs[j]=(d[i]>>(30-j)&1);
			insert(bs);ans=std::max(ans,search(bs));
		}
		printf("%d\n",ans);
	}
	return 0;
}
