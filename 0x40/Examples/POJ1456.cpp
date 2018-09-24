#include <cstdio>
#include <algorithm>
const int maxn=10005;
struct product {
	int p,d;
	bool operator < (const product &rhs) const {
		return p>rhs.p;
	}
} a[maxn];
int fa[10005];
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
int main() {
	int n;
	while(scanf("%d",&n)==1) {
		for(int i=0;i<n;++i) scanf("%d%d",&a[i].p,&a[i].d);
		std::sort(a,a+n);
		for(int i=0;i<=10000;++i) fa[i]=i;
		int ans=0;
		for(int i=0;i<n;++i) {
			int x=find(a[i].d);
			if(x==0) continue;
			ans+=a[i].p;
			fa[x]=find(x-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
