#include <cstdio>
#include <algorithm>
const int maxn=500005;
namespace SGT {
	int n,sum[4*maxn],lmx[4*maxn],rmx[4*maxn],ans[4*maxn];
	inline int max(int x,int y,int z) {return std::max(std::max(x,y),z);}
	inline void maintain(int o,int l,int r) {
		sum[o]=sum[o<<1]+sum[o<<1|1];
		lmx[o]=std::max(lmx[o<<1],sum[o<<1]+lmx[o<<1|1]);
		rmx[o]=std::max(rmx[o<<1]+sum[o<<1|1],rmx[o<<1|1]);
		ans[o]=max(ans[o<<1],ans[o<<1|1],rmx[o<<1]+lmx[o<<1|1]);
	}
	void build(int o,int l,int r,int a[]) {
		int mid=(l+r)>>1;
		if(l==r) sum[o]=lmx[o]=rmx[o]=ans[o]=a[mid];
		else {
			build(o<<1,l,mid,a);build(o<<1|1,mid+1,r,a);
			maintain(o,l,r);
		}
	}
	inline void init(int N,int a[]) {n=N;build(1,1,n,a);}
	int q,ql,qr;
	void modify(int o,int l,int r,int d) {
		if(l==r) sum[o]=lmx[o]=rmx[o]=ans[o]=d;
		else {
			int mid=(l+r)>>1;
			if(q<=mid) modify(o<<1,l,mid,d);
			else if(mid+1<=q) modify(o<<1|1,mid+1,r,d);
			maintain(o,l,r);
		}
	}
	inline void modify(int x,int d) {q=x;modify(1,1,n,d);}
	struct type {int sum,lmx,rmx,ans;};
	type query(int o,int l,int r) {
		if(ql<=l&&r<=qr) return (type){sum[o],lmx[o],rmx[o],ans[o]};
		int mid=(l+r)>>1;
		if(ql<=mid&&mid+1<=qr) {
			type x=query(o<<1,l,mid),y=query(o<<1|1,mid+1,r);
			return (type){x.sum+y.sum,std::max(x.lmx,x.sum+y.lmx),std::max(x.rmx+y.sum,y.rmx),max(x.ans,y.ans,x.rmx+y.lmx)};
		}
		else if(ql<=mid) return query(o<<1,l,mid);
		else if(mid+1<=qr) return query(o<<1|1,mid+1,r);
		return (type){0,0,0,0};
	}
	inline int query(int l,int r) {ql=l;qr=r;return query(1,1,n).ans;}
}
int a[maxn];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	SGT::init(n,a);
	int k,x,y;
	while(m--) {
		scanf("%d%d%d",&k,&x,&y);
		if(k==1) printf("%d\n",SGT::query(std::min(x,y),std::max(x,y)));
		else SGT::modify(x,y);
	}
	return 0;
}
