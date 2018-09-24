/*
Note: 并查集扩展域做法
*/
#include <cstdio>
#include <algorithm>
const int maxm=5005;
struct opt {int l,r,t;} a[maxm];
int hash[2*maxm],idx=0;
inline int query(int x) {return std::lower_bound(hash,hash+idx,x)-hash;}
int fa[4*maxm];
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void unite(int x,int y) {
	int a=find(x),b=find(y);
	if(a!=b) fa[a]=b;
}
int main() {
	int n,m;scanf("%d%d",&n,&m);
	char s[10];idx=0;
	for(int i=0;i<m;++i) {
		scanf("%d%d%s",&a[i].l,&a[i].r,s);a[i].t=s[0]=='o';
		hash[idx++]=a[i].l-1;hash[idx++]=a[i].r;
	}
	std::sort(hash,hash+idx);idx=std::unique(hash,hash+idx)-hash;
	for(int i=0;i<2*idx;++i) fa[i]=i;
	for(int i=0;i<m;++i) {
		int l=query(a[i].l-1),r=query(a[i].r);
		int x=find(l),y=find(r);
		if(a[i].t==0) {
			if(find(l)==find(idx+r)||find(idx+l)==find(r)) {
				printf("%d\n",i);
				return 0;
			}
			else {unite(l,r);unite(idx+l,idx+r);}
		}
		else {
			if(find(l)==find(r)||find(idx+l)==find(idx+r)) {
				printf("%d\n",i);
				return 0;
			}
			else {unite(l,idx+r);unite(idx+l,r);}
		}
	}
	printf("%d\n",m);
	return 0;
}
