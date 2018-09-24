#include <cstdio>
typedef long long int ll;
const int maxn=500005;
int n,a[maxn],temp[maxn],tempidx=0;ll ans=0;
void divide(int l,int r) {
	if(l==r) return;
	int mid=(l+r)>>1;
	divide(l,mid);divide(mid+1,r);
	for(int i=l,j=mid;i<=mid&&j<=r;++i) {
		while(j+1<=r&&a[i]>a[j+1]) ++j;
		ans+=j-mid;
	}
	for(int tempidx=0,i=l,j=mid+1;tempidx<r-l+1;++tempidx) {
		if(i<=mid&&j<=r) {
			if(a[i]<a[j]) temp[tempidx]=a[i++];
			else temp[tempidx]=a[j++];
		}
		else if(i<=mid) temp[tempidx]=a[i++];
		else if(j<=r) temp[tempidx]=a[j++];
	}
	for(int i=0;i<r-l+1;++i) a[l+i]=temp[i];
}
int main() {
	while(scanf("%d",&n)==1&&n) {
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		ans=0;divide(0,n-1);
		printf("%lld\n",ans);
	}
	return 0;
}
