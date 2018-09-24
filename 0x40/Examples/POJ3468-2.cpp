#include <cstdio>
typedef long long int ll;
const int maxn=100005;
template <typename T>
inline void read(T &num) {
	bool flag=false;char c=getchar();
	while(c<'0'||'9'<c) {
		if(c=='-') flag=true;
		c=getchar();
	}
	num=0;
	while('0'<=c&&c<='9') {
		num=num*10+c-'0';
		c=getchar();
	}
	if(flag) num=-num;
}
namespace SGT {
	int n;ll sum[4*maxn],tag[4*maxn];
	void build(int o,int l,int r,ll arr[]) {
		int mid=(l+r)>>1;
		if(l==r) {sum[o]=arr[mid];tag[o]=0;}
		else {
			build(o<<1,l,mid,arr);
			build(o<<1|1,mid+1,r,arr);
			sum[o]=sum[o<<1]+sum[o<<1|1];tag[o]=0;
		}
	}
	inline void init(int N,ll arr[]) {n=N;build(1,1,n,arr);}
	int ql,qr;
	inline void pd(int &o,int &l,int &r,int &mid) {
		if(tag[o]) {
			sum[o<<1]+=tag[o]*(mid-l+1);tag[o<<1]+=tag[o];
			sum[o<<1|1]+=tag[o]*(r-mid);tag[o<<1|1]+=tag[o];
			tag[o]=0;
		}
	}
	void add(int o,int l,int r,ll d) {
		if(ql<=l&&r<=qr) {sum[o]+=(r-l+1)*d;tag[o]+=d;}
		else {
			int mid=(l+r)>>1;
			pd(o,l,r,mid);
			if(ql<=mid) add(o<<1,l,mid,d);
			if(mid+1<=qr) add(o<<1|1,mid+1,r,d);
			sum[o]=sum[o<<1]+sum[o<<1|1];
		}
	}
	inline void add(int l,int r,ll d) {ql=l;qr=r;add(1,1,n,d);}
	ll query(int o,int l,int r) {
		if(ql<=l&&r<=qr) return sum[o];
		int mid=(l+r)>>1;
		pd(o,l,r,mid);
		ll ans=0;
		if(ql<=mid) ans+=query(o<<1,l,mid);
		if(mid+1<=qr) ans+=query(o<<1|1,mid+1,r);
		return ans;
	}
	inline ll query(int l,int r) {ql=l;qr=r;return query(1,1,n);}
}
ll a[maxn];
int main() {
	int n,q;read(n);read(q);
	for(int i=1;i<=n;++i) read(a[i]);
	SGT::init(n,a);
	char opt[2];int a,b;ll c;
	while(q--) {
		fgets(opt,2,stdin);read(a);read(b);
		if(opt[0]=='C') {
			read(c);
			SGT::add(a,b,c);
		}
		else printf("%lld\n",SGT::query(a,b));
	}
	return 0;
}
