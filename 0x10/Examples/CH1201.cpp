#include <cstdio>
#include <climits>
#include <queue>
const int maxn=300005;
int arr[maxn],sum[maxn];
int main() {
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) {
		scanf("%d",&arr[i]);
		sum[i]=sum[i-1]+arr[i];
	}
	std::deque<int> q;q.push_back(0);int ans=INT_MIN;
	for(int i=1;i<=n;++i) {
		while(q.size()&&q.front()<i-m) q.pop_front();
		ans=std::max(ans,sum[i]-sum[q.front()]);
		while(q.size()&&sum[q.back()]>=sum[i]) q.pop_back();
		q.push_back(i);
	}
	printf("%d\n",ans);
	return 0;
}
