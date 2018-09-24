#include <cstdio>
const int maxn=1005;
int notprime[maxn],prime[maxn],phi[maxn],idx=0;
inline void eular(int n) {
	for(int i=2;i<=n;++i) {
		if(!notprime[i]) {
			prime[idx++]=i;
			phi[i]=i-1;
		}
		for(int j=0;j<idx&&i*prime[j]<=n;++j) {
			notprime[i*prime[j]]=true;
			if(i%prime[j]) phi[i*prime[j]]=phi[i]*(prime[j]-1);
			else {
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
		}
	}
}
int main() {
	eular(1000);
	int c;scanf("%d",&c);
	for(int kase=1;kase<=c;++kase) {
		int n;scanf("%d",&n);
		int ans=3;
		for(int i=2;i<=n;++i) ans+=2*phi[i];
		printf("%d %d %d\n",kase,n,ans);
	}
	return 0;
}
