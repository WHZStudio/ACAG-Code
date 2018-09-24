#include <cstdio>
#include <algorithm>
const int maxn=105;
struct ask {
	double t,x,l,r;
	bool operator < (const ask &rhs) const {
		return x<rhs.x;
	}
} asks[2*maxn];
double hash[2*maxn];int idx=0;
inline int query(double x) {return std::lower_bound(hash,hash+idx,x)-hash;}
namespace SGT {
	int n,cnt[4*2*maxn];double ans[4*2*maxn];
	void build(int o,int l,int r) {
		if(l==r) ans[o]=cnt[o]=0;
		else {
			int mid=(l+r)>>1;
			build(o<<1,l,mid);build(o<<1|1,mid+1,r);
			ans[o]=cnt[o]=0;
		}
	}
	inline void init(int N) {n=N;build(1,1,n);}
	int ql,qr;
	void add(int o,int l,int r) {
		if(ql<=l&&r<=qr) {
			++cnt[o];
			ans[o]=hash[r]-hash[l-1];
		}
		else {
			int mid=(l+r)>>1;
			if(ql<=mid) add(o<<1,l,mid);
			if(mid+1<=qr) add(o<<1|1,mid+1,r);
			if(!cnt[o]) ans[o]=ans[o<<1]+ans[o<<1|1];
		}
	}
	inline void add(int l,int r) {ql=l;qr=r;add(1,1,n);}
	void clear(int o,int l,int r) {
		if(ql<=l&&r<=qr) {
			--cnt[o];
			if(!cnt[o]) ans[o]=ans[o<<1]+ans[o<<1|1];
		}
		else {
			int mid=(l+r)>>1;
			if(ql<=mid) clear(o<<1,l,mid);
			if(mid+1<=qr) clear(o<<1|1,mid+1,r);
			if(!cnt[o]) ans[o]=ans[o<<1]+ans[o<<1|1];
		}
	}
	inline void clear(int l,int r) {ql=l;qr=r;clear(1,1,n);}
	inline double query() {return ans[1];}
}
int main() {
	int n,kase=0;
	while(scanf("%d",&n)==1&&n) {
		idx=0;double x1,y1,x2,y2;
		for(int i=0;i<n;++i) {
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			asks[i]=(ask){1,x1,y1,y2};asks[n+i]=(ask){-1,x2,y1,y2};
			hash[idx++]=y1;hash[idx++]=y2;
		}
		std::sort(hash,hash+idx);idx=std::unique(hash,hash+idx)-hash;
		std::sort(asks,asks+2*n);
		SGT::init(idx);
		double ans=0,last=0;
		for(int i=0;i<2*n;++i) {
			int l=query(asks[i].l)+1,r=query(asks[i].r);
			ans+=SGT::query()*(asks[i].x-last);
			if(asks[i].t==1) SGT::add(l,r);
			else if(asks[i].t==-1) SGT::clear(l,r);
			last=asks[i].x;
		}
		if(kase) printf("\n");
		printf("Test case #%d\nTotal explored area: %.2f\n",++kase,ans);
	}
	return 0;
}
