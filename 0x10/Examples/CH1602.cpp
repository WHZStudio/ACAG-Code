#include <cstdio>
#include <cstring>
#include <bitset>
const int maxn=1e5+5;
int ch[maxn*32][2],idx=0;
inline void init() {idx=0;memset(ch[0],-1,sizeof(ch[0]));}
inline void insert(std::bitset<31> &bs) {
	int rt=0;
	for(int i=0;i<31;++i) {
		int c=bs[i];
		if(ch[rt][c]==-1) {
			ch[rt][c]=++idx;
			memset(ch[idx],-1,sizeof(ch[idx]));
		}
		rt=ch[rt][c];
	}
}
inline int search(std::bitset<31> &bs) {
	int ans=0,rt=0;
	if(ch[rt][0]==-1&&ch[rt][1]==-1) return ans;
	for(int i=0;i<31;++i) {
		int c=bs[i];
		if(ch[rt][c^1]==-1) {
			rt=ch[rt][c];
			ans=ans<<1|0;
		}
		else {
			rt=ch[rt][c^1];
			ans=ans<<1|1;
		}
	}
	return ans;
}
std::bitset<31> cnt;
int main() {
	int n;scanf("%d",&n);
	int ans=0,x;init();
	while(n--) {
		scanf("%d",&x);
		for(int i=0;i<31;++i) {
			cnt[i]=((x>>(30-i))&1);
		}
		ans=std::max(ans,search(cnt));
		insert(cnt);
	}
	printf("%d\n",ans);
	return 0;
}
