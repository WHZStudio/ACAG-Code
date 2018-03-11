/*
Author: WHZ
Date: 2018-03-11 09:39:42
Status: Accepted
*/
#include <cstdio>
#include <algorithm>
const int maxn=1000005;
namespace DS {
	int fa[2*maxn];
	inline void init(int n) {
		for(int i=0;i<n;++i) fa[i]=i;
	}
	inline int find(int x) {
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	inline void merge(int x,int y) {
		fa[find(x)]=find(y);
	}
	inline bool same(int x,int y) {
		return find(x)==find(y);
	}
}
struct message {
	int i,j,e;
} arr[maxn];
int n,ele[2*maxn],m;
inline void discrete() {
	std::sort(ele,ele+2*n);
	m=std::unique(ele,ele+2*n)-ele;
}
inline int query(int x) {
	return std::lower_bound(ele,ele+m,x)-ele;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=0;i<n;++i) {
			scanf("%d%d%d",&arr[i].i,&arr[i].j,&arr[i].e);
			ele[i]=arr[i].i;ele[i+n]=arr[i].j;
		}
		discrete();
		DS::init(m);
		for(int i=0;i<n;++i) {
			if(arr[i].e) DS::merge(query(arr[i].i),query(arr[i].j));
		}
		bool ans=true;
		for(int i=0;i<n;++i) {
			if(!arr[i].e) ans=ans&&!DS::same(query(arr[i].i),query(arr[i].j));
		}
		printf("%s\n",ans?"YES":"NO");
	}
	return 0;
}
