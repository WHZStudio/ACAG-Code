#include <cstdio>
#include <cstdlib>
#include <climits>
#include <algorithm>
const int maxn=2005;
int n,a[maxn],b[maxn],f[maxn][maxn];
inline bool cmp(const int &x,const int &y) {return x>y;}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	std::sort(b+1,b+n+1);
	for(int i=1;i<=n;++i) {
		int temp=INT_MAX;
		for(int j=1;j<=n;++j) {
			temp=std::min(temp,f[i-1][j]);
			f[i][j]=temp+abs(b[j]-a[i]);
		}
	}
	int ans=INT_MAX;
	for(int i=1;i<=n;++i) ans=std::min(ans,f[n][i]);
	std::sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;++i) {
		int temp=INT_MAX;
		for(int j=1;j<=n;++j) {
			temp=std::min(temp,f[i-1][j]);
			f[i][j]=temp+abs(b[j]-a[i]);
		}
	}
	for(int i=1;i<=n;++i) ans=std::min(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}
