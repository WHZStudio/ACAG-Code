#include <cstdio>
#include <vector>
typedef long long int ll;
const ll mod=9901;
std::vector<ll> prime;
std::vector<ll> times;
inline void divide(ll n) {
	for(ll i=2;i*i<=n;++i) {
		if(n%i==0) {
			prime.push_back(i);ll cnt=0;
			while(n%i==0) {n/=i;++cnt;}
			times.push_back(cnt);
		}
	}
	if(n>1) {prime.push_back(n);times.push_back(1);}
}
inline ll qpow(ll n,ll k) {
	ll ans=1;
	while(k) {
		if(k&1) ans=ans*n%mod;
		n=n*n%mod;k>>=1;
	}
	return ans;
}
int main() {
	ll a,b;scanf("%lld%lld",&a,&b);
	divide(a);
	ll ans=1;
	for(int i=0,end=prime.size();i<end;++i) {
		times[i]*=b;
		if((prime[i]-1)%mod==0) ans=ans*(times[i]+1)%mod;
		else ans=ans*((qpow(prime[i],times[i]+1)-1+mod)*qpow(prime[i]-1,mod-2)%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
