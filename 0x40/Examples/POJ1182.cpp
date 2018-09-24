#include <cstdio>
const int maxn=50005;
int fa[3*maxn];
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
inline bool same(int x,int y) {return find(x)==find(y);}
inline void unite(int x,int y) {if(!same(x,y)) fa[find(x)]=find(y);}
int main() {
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=3*n;++i) fa[i]=i;
	int d,x,y,ans=0;
	while(k--) {
		scanf("%d%d%d",&d,&x,&y);
		if(x>n||y>n) {
			++ans;
			continue;
		}
		if(d==1) {
			if(same(x,n+y)||same(x,2*n+y)||same(n+x,y)||same(n+x,2*n+y)||same(2*n+x,y)||same(2*n+x,n+y)) {
				++ans;
				continue;
			}
			unite(x,y);unite(n+x,n+y);unite(2*n+x,2*n+y);
		}
		else {
			if(same(x,y)||same(x,2*n+y)||same(n+x,y)||same(n+x,n+y)||same(2*n+x,n+y)||same(2*n+x,2*n+y)) {
				++ans;
				continue;
			}
			unite(x,n+y);unite(n+x,2*n+y);unite(2*n+x,y);
		}
	}
	printf("%d\n",ans);
	return 0;
}
