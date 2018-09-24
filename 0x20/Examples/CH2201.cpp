#include <cstdio>
#include <algorithm>
const int maxn=20;
int n,w,c[maxn];
int cnt=0,car[maxn],ans=0x3f3f3f3f;
void search(int id) {
	if(cnt>=ans) return;
	if(id==n) {
		ans=cnt;
		return;
	}
	for(int i=0;i<cnt;++i) {
		if(car[i]+c[id]<=w) {
			car[i]+=c[id];
			search(id+1);
			car[i]-=c[id];
		}
	}
	car[cnt++]=c[id];
	search(id+1);
	--cnt;
}
inline int cmp(const int &x,const int &y) {return x>y;}
int main() {
	scanf("%d%d",&n,&w);
	for(int i=0;i<n;++i) scanf("%d",&c[i]);
	std::sort(c,c+n,cmp);
	search(0);
	printf("%d\n",ans);
	return 0;
}
