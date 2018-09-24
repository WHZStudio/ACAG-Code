#include <cstdio>
#include <cmath>
#include <algorithm>
int n,m,v=0,s=0,ans=0x3f3f3f3f;
int prev[25],pres[25];
void search(int now,int lh,int lr) {
	if(now==0) {
		if(v==n) ans=std::min(ans,s);
		return;
	}
	if(v+prev[now]>n) return;
	if(s+pres[now]>ans) return;
	for(int r=std::min(lr-1,(int)sqrt(n-v)+1);r>=now;--r) {
		for(int h=std::min(lh-1,(n-v)/r*r+1);h>=now;--h) {
			if(v+r*r*h>n) continue;
			if(2*(n-v)/r+s>ans) continue;
			v+=r*r*h;s+=2*r*h+(now==m?r*r:0);
			search(now-1,h,r);
			v-=r*r*h;s-=2*r*h+(now==m?r*r:0);
		}
	}
}
int main() {
	for(int i=1;i<=20;++i) prev[i]=prev[i-1]+i*i*1;
	for(int i=1;i<=20;++i) pres[i]=pres[i-1]+2*i*1;
	scanf("%d%d",&n,&m);
	search(m,n+1,sqrt(double(n))+1);
	printf("%d\n",ans==0x3f3f3f3f?0:ans);
	return 0;
}
