#include <cstdio>
typedef long long int ll;
const int maxn=15;
void exgcd(ll a,ll b,ll &d,ll &x,ll &y) {
	if(!b) {d=a;x=1;y=0;}
	else {exgcd(b,a%b,d,y,x);y-=a/b*x;}
}
inline ll solve(ll a,ll b,ll c) {
	ll d,x,y;exgcd(a,b,d,x,y);
	if(c%d) return -1;
	x=c/d*x;x=(x%(b/d)+(b/d))%(b/d);
	return x;
}
ll m[maxn],a[maxn],t[maxn];
int main() {
	int n;scanf("%d",&n);
	ll M=1;
	for(int i=0;i<n;++i) {
		scanf("%lld%lld",&m[i],&a[i]);
		M*=m[i];
	}
	for(int i=0;i<n;++i) t[i]=solve(M/m[i],m[i],1);
	ll ans=0;
	for(int i=0;i<n;++i) ans+=a[i]*M/m[i]*t[i];
	printf("%lld\n",ans%M);
	return 0;
}
