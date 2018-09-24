#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long int ll;
const int maxn=200005;
int n,y[maxn],ls[maxn],rs[maxn];
namespace BIT {
	int bit[maxn];
	inline void clear() {memset(bit,0,sizeof(bit));}
	inline void add(int x,int d) {
		while(x<=n) {
			bit[x]+=d;
			x+=x&-x;
		}
	}
	inline int query(int x) {
		int ans=0;
		while(x>0) {
			ans+=bit[x];
			x-=x&-x;
		}
		return ans;
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&y[i]);
	BIT::clear();
	for(int i=1;i<=n;++i) {
		ls[i]=BIT::query(y[i]);
		BIT::add(y[i],1);
	}
	BIT::clear();
	for(int i=n;i>=1;--i) {
		rs[i]=BIT::query(y[i]);
		BIT::add(y[i],1);
	}
	ll ans1=0,ans2=0;
	for(int i=2;i<=n-1;++i) {
		ans1+=(i-1-ls[i])*1LL*(n-i-rs[i]);
		ans2+=ls[i]*1LL*rs[i];
	}
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}
