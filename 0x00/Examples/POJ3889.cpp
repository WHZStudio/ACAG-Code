#include <cstdio>
#include <cmath>
#include <utility>
#define x first
#define y second
typedef long long int ll;
typedef std::pair<ll,ll> P;
ll power[20];
P calc(ll n,ll loc) {
	if(n==0) return P(1,1);
	P ret;
	if(loc<=power[n-1]) {
		P get=calc(n-1,power[n-1]+1-loc);
		ret.x=get.y;ret.y=(1<<(n-1))+1-get.x;
	}
	else if(loc<=2*power[n-1]) {
		P get=calc(n-1,loc-power[n-1]);
		ret.x=get.x;ret.y=(1<<(n-1))+get.y;
	}
	else if(loc<=3*power[n-1]) {
		P get=calc(n-1,loc-2*power[n-1]);
		ret.x=(1<<(n-1))+get.x;ret.y=(1<<(n-1))+get.y;
	}
	else if(loc<=4*power[n-1]) {
		P get=calc(n-1,power[n-1]+1-(loc-3*power[n-1]));
		ret.x=(1<<n)+1-get.y;ret.y=get.x;
	}
	return ret;
}
inline ll solve(ll n,ll h,ll o) {
	P a=calc(n,h),b=calc(n,o);
	return floor(sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y))*10+0.5);
}
int main() {
	int t;scanf("%d",&t);
	power[0]=1;for(int i=1;i<=16;++i) power[i]=power[i-1]*4; 
	ll n,h,o;
	while(t--) {
		scanf("%lld%lld%lld",&n,&h,&o);
		printf("%lld\n",solve(n,h,o));
	}
	return 0;
}
