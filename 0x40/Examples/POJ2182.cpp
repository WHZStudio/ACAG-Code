#include <cstdio>
const int maxn=8005;
int n,a[maxn];
namespace BIT {
	int bit[maxn];
	inline void init() {
		for(int i=1;i<=n;++i) bit[i]=i&-i;
	}
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
inline int search(int k) {
	int l=1,r=n;
	while(l<r) {
		int mid=(l+r)>>1;
		if(BIT::query(mid)>=k) r=mid;
		else l=mid+1;
	}
	return l;
}
int ans[maxn];
int main() {
	scanf("%d",&n);BIT::init();
	a[1]=0;for(int i=2;i<=n;++i) scanf("%d",&a[i]);
	for(int i=n;i>=1;--i) {
		ans[i]=search(a[i]+1);
		BIT::add(ans[i],-1);
	}
	for(int i=1;i<=n;++i) printf("%d\n",ans[i]);
	return 0;
}
