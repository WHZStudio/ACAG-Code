#include <cstdio>
#include <cstdlib>
#include <algorithm>
typedef long long int ll;
int a[100005];
int main() {
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	std::sort(a,a+n);
	int cur=a[n/2];ll ans=0;
	for(int i=0;i<n;++i) ans+=abs(a[i]-cur);
	printf("%lld\n",ans);
	return 0;
}
