#include <cstdio>
#include <algorithm>
const int maxn=200005;
const int maxm=200005;
int a[maxn],b[maxn],c[maxn];
int h[maxn+2*maxm],idx=0;
inline int query(int x) {return std::lower_bound(h,h+idx,x)-h;}
int cnt[maxn+2*maxm];
int main() {
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i) {
		scanf("%d",&a[i]);
		h[idx++]=a[i];
	}
	int m;scanf("%d",&m);
	for(int i=0;i<m;++i) {
		scanf("%d",&b[i]);
		h[idx++]=b[i];
	}
	for(int i=0;i<m;++i) {
		scanf("%d",&c[i]);
		h[idx++]=c[i];
	}
	std::sort(h,h+idx);
	idx=std::unique(h,h+idx)-h;
	for(int i=0;i<n;++i) ++cnt[query(a[i])];
	int fav=-1,like=-1,id=0;
	for(int i=0;i<m;++i) {
		if(cnt[query(b[i])]>fav) {
			fav=cnt[query(b[i])];
			like=cnt[query(c[i])];
			id=i+1;
		}
		else if(cnt[query(b[i])]==fav) {
			if(cnt[query(c[i])]>like) {
				like=cnt[query(c[i])];
				id=i+1;
			}
		}
	}
	printf("%d\n",id);
	return 0;
}
