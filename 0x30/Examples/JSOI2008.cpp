#include <cstdio>
#include <cmath>
#include <algorithm>
const int maxn=15;
int n;double in[maxn][maxn],a[maxn][maxn];
inline void gauss() {
	for(int i=0;i<n;++i) {
		int r=i;for(int j=i+1;j<n;++j) if(fabs(a[j][i])>fabs(a[r][i])) r=j;
		for(int j=0;j<=n;++j) std::swap(a[i][j],a[r][j]);
		for(int j=n;j>=i;--j) for(int k=i+1;k<n;++k) a[k][j]-=a[k][i]/a[i][i]*a[i][j];
	}
	for(int i=n-1;i>=0;--i) {
		for(int j=i+1;j<n;++j) a[i][n]-=a[j][n]*a[i][j];
		a[i][n]/=a[i][i];
	}
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<=n;++i) for(int j=0;j<n;++j) scanf("%lf",&in[i][j]);
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) {
		a[i][j]=2*(in[i+1][j]-in[i][j]);
		a[i][n]+=in[i+1][j]*in[i+1][j]-in[i][j]*in[i][j];
	}
	gauss();
	for(int i=0;i<n;++i) printf("%.3lf ",a[i][n]);printf("\n");
	return 0;
}
