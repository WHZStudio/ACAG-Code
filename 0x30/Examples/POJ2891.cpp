#include <cstdio>
const int maxn=(int)1e5+5;
typedef long long int ll;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
void exgcd(ll a,ll b,ll &d,ll &x,ll &y) {
	if(!b) {d=a;x=1;y=0;}
	else {exgcd(b,a%b,d,y,x);y-=a/b*x;}
}
ll solve(ll a,ll b,ll c) {
	ll d,x,y;exgcd(a,b,d,x,y);
	if(c%d) return -1;
	x=c/d*x;return (x%(b/d)+(b/d))%(b/d);
}
ll a[maxn],r[maxn];
int main() {
	int k;
	while(scanf("%d",&k)==1) {
		for(int i=0;i<k;++i) scanf("%lld%lld",&a[i],&r[i]);
		ll x=r[0],mul=a[0];bool error=false;
		for(int i=1;i<k;++i) {
			ll t=solve(mul,a[i],(r[i]+a[i]-x%a[i])%a[i]);
			if(t==-1) {error=true;break;}
			x+=mul*t;
			mul=mul/gcd(mul,a[i])*a[i];
			x%=mul;
		}
		if(error) printf("-1\n");
		else printf("%lld\n",x);
	}
	return 0;
}
