#include <cstdio>
#include <algorithm>
typedef long long int ll;
int main() {
	ll n,k;
	scanf("%lld%lld",&n,&k);
	ll ans=n*k;
	for(int i=1;i<=n;++i) {
		ll end=k/i==0?n:std::min(n,k/(k/i));
		ans-=(k/i)*(i+end)*(end-i+1)/2;
		i=end;
	}
	printf("%lld\n",ans);
	return 0;
}
