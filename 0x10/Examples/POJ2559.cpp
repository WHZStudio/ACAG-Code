#include <cstdio>
#include <algorithm>
typedef long long int ll;
const int maxn=100005;
int n,h[maxn],w[maxn],sta[maxn],top=0;
int main() {
	while(scanf("%d",&n)==1&&n) {
		for(int i=1;i<=n;++i) scanf("%d",&h[i]);
		ll ans=0;
		h[++n]=0;sta[top=0]=-1;
		for(int i=1;i<=n;++i) {
			if(h[i]>sta[top]) {
				sta[++top]=h[i];
				w[top]=1;
			}
			else {
				int width=0;
				while(sta[top]>=h[i]) {
					width+=w[top];
					ans=std::max(ans,(ll)sta[top]*width);
					--top;
				}
				sta[++top]=h[i];w[top]=width+1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
