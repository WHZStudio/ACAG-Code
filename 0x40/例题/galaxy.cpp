/*
Author: WHZ
Date: 2018-03-11 10:14:38
Status: Accpeted
*/
#include <cstdio>
#include <algorithm>
namespace DS {
	int fa[30005],d[30005],size[30005];
	inline void init(int n) {
		for(int i=0;i<=n;++i) {
			fa[i]=i;
			d[i]=0;
			size[i]=1;
		}
	}
	int find(int x) {
		if(fa[x]!=x) {
			int t=find(fa[x]);
			d[x]+=d[fa[x]];
			return fa[x]=t;
		}
		return x;
	}
	inline void merge(int x,int y) {
		int xx=find(x),yy=find(y);
		fa[xx]=yy;
		d[xx]=size[yy];
		size[yy]+=size[xx];
	}
	inline bool same(int x,int y) {
		return find(x)==find(y);
	}
	inline int solve(int x,int y) {
		find(x);find(y);
		return std::max(d[x],d[y])-std::min(d[x],d[y])-1;
	}
}
int main() {
	int t;
	scanf("%d",&t);
	DS::init(30000);
	char opt[2];int i,j;
	while(t--) {
		scanf("%s%d%d",opt,&i,&j);
		if(opt[0]=='M') {
			DS::merge(i,j);
		}
		else {
			if(DS::same(i,j)) {
				printf("%d\n",DS::solve(i,j));
			}
			else {
				printf("-1\n");
			}
		}
	}
	return 0;
}
