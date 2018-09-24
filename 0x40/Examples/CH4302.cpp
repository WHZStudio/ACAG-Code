#include <cstdio>
#include <cstring>
#include <cstdlib>
typedef long long int ll;
const int maxn=(int)5e5+5;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
namespace BIT {
	int n;ll bit[maxn];
	inline void init(int N) {
		n=N;memset(bit,0,sizeof(bit));
	}
	inline void add(int x,ll d) {
		for(;x<=n;x+=x&-x) bit[x]+=d;
	}
	inline ll query(int x) {
		ll ans=0;
		for(;x;x-=x&-x) ans+=bit[x];
		return ans;
	}
}
namespace SGT {
	int n;ll ans[4*maxn];
	void build(int o,int l,int r,ll arr[]) {
		int mid=(l+r)>>1;
		if(l==r) ans[o]=arr[mid];
		else {
			build(o<<1,l,mid,arr);
			build(o<<1|1,mid+1,r,arr);
			ans[o]=gcd(ans[o<<1],ans[o<<1|1]);
		}
	}
	inline void init(int N,ll arr[]) {n=N;build(1,1,n,arr);}
	int q,ql,qr;
	void add(int o,int l,int r,ll d) {
		int mid=(l+r)>>1;
		if(l==r) ans[o]+=d;
		else {
			if(q<=mid) add(o<<1,l,mid,d);
			else if(mid+1<=q) add(o<<1|1,mid+1,r,d);
			ans[o]=gcd(ans[o<<1],ans[o<<1|1]);
		}
	}
	inline void add(int x,ll d) {q=x;add(1,1,n,d);}
	ll query(int o,int l,int r) {
		int mid=(l+r)>>1;
		if(ql<=l&&r<=qr) return ans[o];
		else {
			if(ql<=mid&&mid+1<=qr) return gcd(query(o<<1,l,mid),query(o<<1|1,mid+1,r));
			else if(ql<=mid) return query(o<<1,l,mid);
			else if(mid+1<=qr) return query(o<<1|1,mid+1,r);
		}
		return 0;
	}
	inline ll query(int l,int r) {ql=l;qr=r;return query(1,1,n);}
}
ll a[maxn];
int main() {
	int n,m;scanf("%d%d",&n,&m);
	ll last=0,x;BIT::init(n);
	for(int i=1;i<=n;++i) {
		scanf("%lld",&x);
		BIT::add(i,x-last);
		a[i]=x-last;last=x;
	}
	char s[2];int l,r;ll d;SGT::init(n,a);
	while(m--) {
		scanf("%s%d%d",s,&l,&r);
		if(s[0]=='C') {
			scanf("%lld",&d);
			BIT::add(l,d);SGT::add(l,d);
			if(r+1<=n) {BIT::add(r+1,-d);SGT::add(r+1,-d);}
		}
		else if(s[0]=='Q') {
			if(l+1<=r) printf("%lld\n",gcd(BIT::query(l),llabs(SGT::query(l+1,r))));
			else printf("%lld\n",BIT::query(l));
		}
	}
	return 0;
}
