#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long int ll;
const int maxn=10005;
struct line {
	ll x,l,r;int c;
	bool operator < (const line &rhs) const {return x==rhs.x?c<rhs.c:x<rhs.x;}
} lines[2*maxn];
ll hash[2*maxn],idx=0;
inline int query(ll &x) {return std::lower_bound(hash,hash+idx,x)-hash;}
namespace SGT {
	int n,mx[4*2*maxn],tag[4*2*maxn];
	inline void init(int N) {n=N;memset(mx,0,sizeof(mx));memset(tag,0,sizeof(tag));}
	int ql,qr;
	inline void pushdown(int o) {
		if(tag[o]) {
			mx[o<<1]+=tag[o];tag[o<<1]+=tag[o];
			mx[o<<1|1]+=tag[o];tag[o<<1|1]+=tag[o];
			tag[o]=0;
		}
	}
	void update(int o,int l,int r,int d) {
		if(ql<=l&&r<=qr) {mx[o]+=d;tag[o]+=d;}
		else {
			pushdown(o);
			int mid=(l+r)>>1;
			if(ql<=mid) update(o<<1,l,mid,d);
			if(mid+1<=qr) update(o<<1|1,mid+1,r,d);
			mx[o]=std::max(mx[o<<1],mx[o<<1|1]);
		}
	}
	inline void update(int l,int r,int d) {ql=l;qr=r;update(1,1,n,d);}
	inline int query() {return mx[1];}
}
int main() {
	int n,w,h;
	while(scanf("%d%u%u",&n,&w,&h)==3) {
		ll x,y;int c;idx=0;
		for(int i=0;i<n;++i) {
			scanf("%lld%lld%d",&x,&y,&c);
			lines[i]=(line){x,y,y+h-1,c};
			lines[n+i]=(line){x+w,y,y+h-1,-c};
			hash[idx++]=y;hash[idx++]=y+h-1;
		}
		std::sort(lines,lines+2*n);
		std::sort(hash,hash+idx);idx=std::unique(hash,hash+idx)-hash;
		int ans=0;SGT::init(idx);
		for(int i=0;i<2*n;++i) {
			int l=query(lines[i].l)+1,r=query(lines[i].r)+1;
			ans=std::max(ans,SGT::query());
			SGT::update(l,r,lines[i].c);
		}
		printf("%d\n",ans);
	}
	return 0;
}
