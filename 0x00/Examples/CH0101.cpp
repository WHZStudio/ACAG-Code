#include <cstdio>
typedef long long int ll;
ll p;
ll qpow(ll n,ll k) {
	ll ans=1;
	while(k) {
		if(k&1) ans=ans*n%p;
		n=n*n%p;k>>=1;
	}
	return ans%p;
}
int main() {
	ll a,b;
	scanf("%lld%lld%lld",&a,&b,&p);
	printf("%lld\n",qpow(a,b));
	return 0;
}
