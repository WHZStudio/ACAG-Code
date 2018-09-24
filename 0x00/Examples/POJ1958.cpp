#include <cstdio>
#include <algorithm>
int f[15],g[15];
int main() {
	f[1]=1;
	for(int i=2;i<=12;++i) f[i]=2*f[i-1]+1;
	g[1]=1;
	for(int i=2;i<=12;++i) {
		int cur=0x3f3f3f3f;
		for(int j=1;j<i;++j) cur=std::min(cur,2*g[i-j]+f[j]);
		g[i]=cur;
	}
	for(int i=1;i<=12;++i) printf("%d\n",g[i]);
	return 0;
}
