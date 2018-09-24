#include <cstdio>
typedef unsigned long long int ll;
ll p;
ll mul(ll a,ll b) {
	ll ans=0;
	while(b) {
		if(b&1) ans=(ans+a)%p;
		a=(a+a)%p;b>>=1;
	}
	return ans%p;
}
int main() {
	ll a,b;
	scanf("%lld%lld%lld",&a,&b,&p);
	printf("%lld\n",mul(a,b));
	return 0;
}
