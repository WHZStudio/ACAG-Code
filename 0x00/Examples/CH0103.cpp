#include <cstdio>
#include <cstring>
#include <algorithm>
int arr[20][20],f[1<<20][20];
int main() {
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i) {
		for(int j=0;j<n;++j) {
			scanf("%d",&arr[i][j]);
		}
	}
	memset(f,0x3f,sizeof(f));f[1][0]=0;
	for(int i=0;i<(1<<n);++i) {
		for(int j=0;j<n;++j) if(i>>j&1) {
			for(int k=0;k<n;++k) if(i>>k&1) {
				if(j!=k) f[i][j]=std::min(f[i][j],f[i&~(1<<j)][k]+arr[j][k]);
			}
		}
	}
	printf("%d\n",f[(1<<n)-1][n-1]);
	return 0;
}
