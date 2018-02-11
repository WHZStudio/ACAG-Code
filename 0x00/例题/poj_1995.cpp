/*
Author: WHZ
Status: Accepted
Date: 2018-02-11 14:06:47
*/
#include <cstdio>
typedef long long int ll;
ll pow_mod(ll n,ll k,ll mod) {
	ll ret=1,x=n;
	while(k>0) {
		if(k&1) ret=ret*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		ll m,h;
		scanf("%lld%lld",&m,&h);
		ll ans=0,a,b;
		while(h--) {
			scanf("%lld%lld",&a,&b);
			ans=(ans+pow_mod(a,b,m))%m;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
