#include <cstdio>
const int maxn=1000005;
char s[maxn];int n,f[maxn];
inline void KMP() {
	f[0]=f[1]=0;int j;
	for(int i=1;i<n;++i) {
		j=f[i];
		while(j&&s[i]!=s[j]) j=f[j];
		f[i+1]=(s[i]==s[j])?j+1:0;
	}
}
int main() {
	int kase=0;
	while(scanf("%d",&n)==1&&n) {
		scanf("%s",s);
		KMP();
		if(kase) printf("\n");
		printf("Test case #%d\n",++kase);
		for(int i=2;i<=n;++i) if(f[i]>0&&i%(i-f[i])==0) {
			printf("%d %d\n",i,i/(i-f[i]));
		}
	}
	return 0;
}
