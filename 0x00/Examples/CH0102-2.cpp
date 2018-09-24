#include <cstdio>
typedef long long int ll;
ll mul(ll a,ll b,ll p) {
	a%=p;b%=p;
	ll c=(long double)a*b/p;
	ll ans=a*b-c*p;
	if(ans<0) ans+=p;
	else if(ans>=p) ans-=p;
	return ans;
}
int main() {
	ll a,b,p;
	scanf("%lld%lld%lld",&a,&b,&p);
	printf("%lld\n",mul(a,b,p));
	return 0;
}
