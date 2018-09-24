#include <cstdio>
#include <climits>
#include <algorithm>
typedef long long int ll;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
inline ll eular(ll n) {
	ll ans=n;
	for(ll i=2;i*i<=n;++i) {
		if(n%i==0) {
			ans=ans/i*(i-1);
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans=ans/n*(n-1);
	return ans;
}
ll p;
ll mul(ll a,ll b) {
	ll temp=(long double)a*b/p;
	ll ans=a*b-temp*p;
	if(ans>=p) ans-=p;
	if(ans<0) ans+=p;
	return ans;
}
ll pow(ll n,ll k) {
	ll ans=1;
	while(k) {
		if(k&1) ans=mul(ans,n);
		n=mul(n,n);k>>=1;
	}
	return ans;
}
int main() {
	ll l;int kase=0;
	while(scanf("%lld",&l)==1&&l) {
		p=l*9/gcd(8,l);ll n=eular(p),ans=1LL<<60;
		for(ll i=1;i*i<=n;++i) {
			if(n%i==0) {
				if(pow(10,i)==1) {ans=i;break;}
				else if(i*i!=n&&pow(10,n/i)==1) ans=std::min(ans,n/i);
			}
		}
		printf("Case %d: %lld\n",++kase,ans==1LL<<60?0:ans);
	}
	return 0;
}
