/*
Author: WHZ
Date: 2018-03-11 14:40:21
Status: Accepted
*/
/*
Although this code has passed all the test datas, it is wrong.
You have to conversion type when you add up the final result to get the correct code.
To find out the reason, please visit my blog: https://whzstudio.coding.me/2018/03/11/tyvj_1432/.
*/
#include <cstdio>
#include <cstring>
typedef long long int ll;
const int maxn=2e5+5;
int y[maxn];
int leftsmaller[maxn],rightsmaller[maxn];
namespace BIT {
	int bit[maxn],n;
	static inline int lowbit(int x) {return x&-x;}
	inline void init(int nn) {
		n=nn;
		memset(bit,0,sizeof(bit));
	}
	inline void add(int x,int d) {
		while(x<=n) {
			bit[x]+=d;
			x+=lowbit(x);
		}
	}
	inline int query(int x) {
		int ans=0;
		while(x>0) {
			ans+=bit[x];
			x-=lowbit(x);
		}
		return ans;
	}
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&y[i]);
	BIT::init(n);
	for(int i=0;i<n;++i) {
		leftsmaller[i]=BIT::query(y[i]);
		BIT::add(y[i],1);
	}
	BIT::init(n);
	for(int i=n-1;i>=0;--i) {
		rightsmaller[i]=BIT::query(y[i]);
		BIT::add(y[i],1);
	}
	ll ans1=0,ans2=0;
	for(int i=0;i<n;++i) {
		ans1+=(i-leftsmaller[i])*(n-i-1-rightsmaller[i]);
		ans2+=leftsmaller[i]*rightsmaller[i];
	}
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}
