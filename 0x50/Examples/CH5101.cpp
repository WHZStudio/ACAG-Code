#include <cstdio>
#include <algorithm>
const int maxn=3005;
int n,a[maxn],b[maxn],f[maxn][maxn];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	for(int i=1;i<=n;++i) {
		int temp=0;
		for(int j=1;j<=n;++j) {
			if(a[i]==b[j]) f[i][j]=temp+1;
			else f[i][j]=f[i-1][j];
			if(b[j]<a[i]) temp=std::max(temp,f[i][j]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i) ans=std::max(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}
