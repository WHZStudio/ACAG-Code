#include <cstdio>
#include <algorithm>
const int maxm=5005;
struct opt {
	int l,r,t;
} a[maxm];
int hash[2*maxm],idx=0;
inline int query(int x) {return std::lower_bound(hash,hash+idx,x)-hash;}
int fa[2*maxm],d[2*maxm];
int find(int x) {
	if(x==fa[x]) return x;
	int rt=find(fa[x]);
	d[x]^=d[fa[x]];
	return fa[x]=rt;
}
int main() {
	int n,m;scanf("%d%d",&n,&m);
	char s[10];
	for(int i=0;i<m;++i) {
		scanf("%d%d%s",&a[i].l,&a[i].r,s);a[i].t=(s[0]=='o');
		hash[idx++]=a[i].l-1;hash[idx++]=a[i].r;
	}
	std::sort(hash,hash+idx);idx=std::unique(hash,hash+idx)-hash;
	for(int i=0;i<idx;++i) {
		fa[i]=i;d[i]=0;
	}
	for(int i=0;i<m;++i) {
		int l=query(a[i].l-1),r=query(a[i].r);
		int x=find(l),y=find(r);
		if(x==y) {
			if((d[l]^d[r])!=a[i].t) {
				printf("%d\n",i);
				return 0;
			}
		}
		else {
			d[x]=a[i].t^d[l]^d[r];
			fa[x]=y;
		}
	}
	printf("%d\n",m);
	return 0;
}
