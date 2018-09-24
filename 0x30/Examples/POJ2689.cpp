#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <algorithm>
int prime[1000005],notprime[1000005],idx;
inline void getPrime(int num) {
	idx=0;memset(notprime,0,sizeof(notprime));
	for(int i=2;i<=num;++i) {
		if(!notprime[i]) prime[idx++]=i;
		for(int j=0;j<idx&&i*prime[j]<=num;++j) {
			notprime[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
}
int isnotprime[1000005];
int main() {
	int l,u;
	while(scanf("%d%d",&l,&u)==2) {
		getPrime(floor(sqrt(u)));memset(isnotprime,0,sizeof(isnotprime));
		for(int i=0;i<idx;++i) {
			for(int j=std::max(2,(int)ceil((double)l/prime[i]));j<=(int)floor((double)u/prime[i]);++j) {
				isnotprime[prime[i]*j-l]=true;
			}
		}
		int last=0x3f3f3f3f,ans=0,ansc=INT_MAX,cx,cy,ansd=INT_MIN,dx,dy;
		for(int i=0;i<u-l+1;++i) {
			if(!isnotprime[i]&&i+l!=1) {
				if(i-last>0) {
					ans=true;
					if(i-last<ansc) {
						ansc=i-last;
						cx=last;cy=i;
					}
					if(i-last>ansd) {
						ansd=i-last;
						dx=last;dy=i;
					}
				}
				last=i;
			}
		}
		if(ans) printf("%d,%d are closest, %d,%d are most distant.\n",l+cx,l+cy,l+dx,l+dy);
		else printf("There are no adjacent primes.\n");
	}
	return 0;
}
