#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxl=205;
const int maxn=1005;
int l,n,c[maxl][maxl],a[maxn],f[maxn][maxl][maxl];
int main() {
	scanf("%d%d",&l,&n);
	for(int i=1;i<=l;++i) {
		for(int j=1;j<=l;++j) {
			scanf("%d",&c[i][j]);
		}
	}
	a[0]=1;for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	memset(f,0x3f,sizeof(f));f[0][2][3]=0;
	for(int i=0;i<n;++i) {
		for(int x=1;x<=l;++x) if(a[i]!=x) {
			for(int y=1;y<=l;++y) if(a[i]!=y&&x!=y) {
				if(a[i+1]!=x&&a[i+1]!=y) f[i+1][x][y]=std::min(f[i+1][x][y],f[i][x][y]+c[a[i]][a[i+1]]);
				if(a[i+1]!=y&&a[i+1]!=a[i]) f[i+1][y][a[i]]=std::min(f[i+1][y][a[i]],f[i][x][y]+c[x][a[i+1]]);
				if(a[i+1]!=x&&a[i+1]!=a[i]) f[i+1][x][a[i]]=std::min(f[i+1][x][a[i]],f[i][x][y]+c[y][a[i+1]]);
			}
		}
	}
	int ans=0x3f3f3f3f;
	for(int x=1;x<=l;++x) {
		for(int y=1;y<=l;++y) {
			ans=std::min(ans,f[n][x][y]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
