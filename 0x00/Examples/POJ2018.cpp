#include <cstdio>
#include <climits>
#include <algorithm>
const int maxn=100005;
int n,f;double arr[maxn],temp[maxn],sum[maxn];
bool check(double num) {
	for(int i=1;i<=n;++i) {
		temp[i]=arr[i]-num;
		sum[i]=sum[i-1]+temp[i];
	}
	double mininum=1e10,ans=-1e10;
	for(int i=f;i<=n;++i) {
		mininum=std::min(mininum,sum[i-f]);
		ans=std::max(ans,sum[i]-mininum);
	}
	return ans>=0;
}
int main() {
	scanf("%d%d",&n,&f);
	double l=1e10,r=-1e10;
	for(int i=1;i<=n;++i) {
		scanf("%lf",&arr[i]);
		l=std::min(l,arr[i]);
		r=std::max(r,arr[i]);
	}
	while(r-l>1e-5) {
		double mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%d\n",int(r*1000));
	return 0;
}
