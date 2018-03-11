/*
Author: WHZ
Date: 2018-03-11 11:01:59
Status: Accepted
*/
#include <cstdio>
#include <algorithm>
const int maxn=10005;
struct message {
	int l,r;
	char s[5];
} ms[maxn];
int arr[2*maxn],cnt;
inline int query(int x) {
	return std::lower_bound(arr,arr+cnt,x)-arr;
}
namespace DS {
	int fa[4*maxn];
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
inline int solve() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i) {
		scanf("%d%d%s",&ms[i].l,&ms[i].r,ms[i].s);
		arr[i]=ms[i].l-1;arr[i+m]=ms[i].r;
	}
	std::sort(arr,arr+2*m);
	cnt=std::unique(arr,arr+2*m)-arr;
	DS::init(cnt*2);
	for(int i=0;i<m;++i) {
		int x=query(ms[i].l-1),y=query(ms[i].r);
		if(ms[i].s[0]=='e') {
			if(DS::same(x,y+cnt)||DS::same(x+cnt,y)) return i;
			DS::merge(x,y);
			DS::merge(x+cnt,y+cnt);
		}
		else if(ms[i].s[0]=='o') {
			if(DS::same(x,y)||DS::same(x+cnt,y+cnt)) return i;
			DS::merge(x,y+cnt);
			DS::merge(x+cnt,y);
		}
	}
	return m;
}
int main() {
	printf("%d\n",solve());
	return 0;
}
