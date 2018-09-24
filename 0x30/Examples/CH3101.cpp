#include <cstdio>
#include <cstring>
int notprime[1000005],prime[1000005],idx=0;
inline void getPrime(int n) {
	idx=0;memset(notprime,0,sizeof(notprime));
	for(int i=2;i<=n;++i) {
		if(!notprime[i]) prime[idx++]=i;
		for(int j=0;j<idx&&i*prime[j]<=n;++j) {
			notprime[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}
int main() {
	int n;scanf("%d",&n);
	getPrime(n);
	for(int i=0;i<idx;++i) {
		int ans=0;
		for(long long int j=prime[i];j<=n;j=j*prime[i]) ans+=n/j;
		printf("%d %d\n",prime[i],ans);
	}
	return 0;
}
