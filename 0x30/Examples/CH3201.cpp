#include <cstdio>
int prime[50005],notprime[50005],idx=0;
inline void getPrime(int n) {
	for(int i=2;i<=n;++i) {
		if(!notprime[i]) prime[idx++]=i;
		for(int j=0;j<idx&&i*prime[j]<=n;++j) {
			notprime[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}
inline int calc(int &num,int p) {
	int ans=0;
	while(num%p==0) {
		++ans;
		num/=p;
	}
	return ans;
}
int main() {
	getPrime(50000);
	int n;scanf("%d",&n);
	int a0,a1,b0,b1;
	while(n--) {
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		int ans=1;
		for(int i=0;i<idx&&b1>1;++i) {
			if(b1%prime[i]==0) {
				int ma0=calc(a0,prime[i]),ma1=calc(a1,prime[i]);
				int mb0=calc(b0,prime[i]),mb1=calc(b1,prime[i]);
				if(ma0>ma1&&mb0<mb1&&ma1==mb1) ans*=1;
				else if(ma0>ma1&&mb0==mb1&&ma1<=mb1) ans*=1;
				else if(ma0==ma1&&mb0<mb1&&mb1>=ma1) ans*=1;
				else if(ma0==ma1&&mb0==mb1&&ma1<=mb1) ans*=(mb1-ma1+1);
				else {ans=0;break;}
			}
		}
		if(ans&&b1>1) {
			int ma0=calc(a0,b1),ma1=calc(a1,b1);
			int mb0=calc(b0,b1),mb1=calc(b1,b1);
			if(ma0>ma1&&mb0<mb1&&ma1==mb1) ans*=1;
			else if(ma0>ma1&&mb0==mb1&&ma1<=mb1) ans*=1;
			else if(ma0==ma1&&mb0<mb1&&mb1>=ma1) ans*=1;
			else if(ma0==ma1&&mb0==mb1&&ma1<=mb1) ans*=(mb1-ma1+1);
			else ans=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}
