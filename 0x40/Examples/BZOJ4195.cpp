#include <cstdio>
#include <algorithm>
const int maxn=1000005;
struct opt {int t,x,y;} a[maxn];
int hash[2*maxn],idx=0;
inline int query(int x) {return std::lower_bound(hash,hash+idx,x)-hash;}
int fa[2*maxn];
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
int main() {
	int t;scanf("%d",&t);
	while(t--) {
		int n;scanf("%d",&n);
		idx=0;
		for(int i=0;i<n;++i) {
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].t);
			hash[idx++]=a[i].x;hash[idx++]=a[i].y;
		}
		std::sort(hash,hash+2*n);
		idx=std::unique(hash,hash+2*n)-hash;
		for(int i=0;i<idx;++i) fa[i]=i;
		for(int i=0;i<n;++i) if(a[i].t==1) {
			fa[find(query(a[i].x))]=find(query(a[i].y));
		}
		int ans=true;
		for(int i=0;i<n;++i) if(a[i].t==0) {
			if(find(query(a[i].x))==find(query(a[i].y))) ans=false;
		}
		printf("%s\n",ans?"YES":"NO");
	}
	return 0;
}
