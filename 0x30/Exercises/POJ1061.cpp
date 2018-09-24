#include <cstdio>
typedef long long int ll;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
void exgcd(ll a,ll b,ll &d,ll &x,ll &y) {
	if(!b) {d=a;x=1;y=0;}
	else {exgcd(b,a%b,d,y,x);y-=a/b*x;}
}
int main() {
	ll x0,y0,m0,n0,l0;scanf("%lld%lld%lld%lld%lld",&x0,&y0,&m0,&n0,&l0);
	ll a,b,c;
	if(m0>=n0) {a=m0-n0;b=l0;c=y0-x0;}
	else {a=n0-m0;b=l0;c=x0-y0;}
	if(c%gcd(a,b)) printf("Impossible\n");
	else {
		ll d,x,y;exgcd(a,b,d,x,y);
		x=c/d*x;y=c/d*y;
		printf("%lld\n",(x%(b/d)+(b/d))%(b/d));
	}
	return 0;
}
