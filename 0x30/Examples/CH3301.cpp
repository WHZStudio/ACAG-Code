#include <cstdio>
typedef long long int ll;
void exgcd(ll a,ll b,ll &x,ll &y) {
	if(b==0) {x=1;y=0;}
	else {
		exgcd(b,a%b,y,x);
		y-=a/b*x;
	}
}
int main() {
	ll a,b;scanf("%lld%lld",&a,&b);
	ll x,y;exgcd(a,b,x,y);
	printf("%lld\n",(x%b+b)%b);
	return 0;
}
