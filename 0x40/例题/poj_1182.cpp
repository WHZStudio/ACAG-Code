/*
Author: WHZ
Date: 2018-03-11 11:31:13
Status: Accepted
*/
#include <cstdio>
const int maxn=50005;
namespace DS {
	int fa[3*maxn];
	inline void init(int n) {
		for(int i=0;i<=n;++i) fa[i]=i;
	}
	int find(int x) {
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	inline bool same(int x,int y) {
		return find(x)==find(y);
	}
	inline void merge(int x,int y) {
		int i=find(x),j=find(y);
		if(i!=j) fa[i]=j;
	}
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	using namespace DS;
	init(3*n);
	int d,x,y,ans=0;
	while(k--) {
		scanf("%d%d%d",&d,&x,&y);
		if(x>n||y>n) {
			++ans;
			continue;
		}
		if(d==1) {
			if(same(x,y+n)||same(x,y+2*n)||same(x+n,y)||same(x+n,y+2*n)||same(x+2*n,y)||same(x+2*n,y+n)) {
				++ans;
				continue;
			}
			merge(x,y);
			merge(x+n,y+n);
			merge(x+2*n,y+2*n);
		}
		else if(d==2) {
			if(same(x,y)||same(x,y+2*n)||same(x+n,y)||same(x+n,y+n)||same(x+2*n,y+n)||same(x+2*n,y+2*n)) {
				++ans;
				continue;
			}
			merge(x,y+n);
			merge(x+n,y+2*n);
			merge(x+2*n,y);
		}
	}
	printf("%d\n",ans);
	return 0;
}
