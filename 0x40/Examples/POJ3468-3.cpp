#include <cstdio>
#include <cmath>
#include <algorithm>
typedef long long int ll;
const int maxn=100005;
int n,q,k;ll a[maxn],s[maxn],tg[maxn];
inline int bl(const int &x) {return (x-1)/k+1;}
inline int ls(const int &x) {return (bl(x)-1)*k+1;}
inline int rs(const int &x) {return std::min(n,bl(x)*k);}
inline void update(int l,int r,ll d) {
	int L=bl(l),R=bl(r);
	if(L==R) for(register int i=l;i<=r;++i) {a[i]+=d;s[bl(i)]+=d;}
	else {
		for(register int i=l;i<=rs(l);++i) {a[i]+=d;s[L]+=d;}
		for(register int i=L+1;i<=R-1;++i) {s[i]+=k*d;tg[i]+=d;}
		for(register int i=ls(r);i<=r;++i) {a[i]+=d;s[R]+=d;}
	}
}
inline ll query(int l,int r) {
	int L=bl(l),R=bl(r);ll ans=0;
	if(L==R) for(register int i=l;i<=r;++i) ans+=a[i]+tg[bl(i)];
	else {
		for(register int i=l;i<=rs(l);++i) ans+=a[i]+tg[L];
		for(register int i=L+1;i<=R-1;++i) ans+=s[i];
		for(register int i=ls(r);i<=r;++i) ans+=a[i]+tg[R];
	}
	return ans;
}
int main() {
	scanf("%d%d",&n,&q);
	k=sqrt(n);
	for(register int i=1;i<=n;++i) {
		scanf("%lld",&a[i]);
		s[bl(i)]+=a[i];
	}
	char opt[2];int l,r;
	while(q--) {
		scanf("%s%d%d",opt,&l,&r);
		if(opt[0]=='Q') printf("%lld\n",query(l,r));
		else if(opt[0]=='C') {
			ll c;scanf("%lld",&c);
			update(l,r,c);
		}
	}
	return 0;
}
