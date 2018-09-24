#include <cstdio>
#include <set>
#include <utility>
#include <algorithm>
typedef std::pair<int,int> P;
int arr[10005];
std::set<P> s;
int main() {
	int n,i,h,r;
	scanf("%d%d%d%d",&n,&i,&h,&r);
	arr[1]+=h;arr[n+1]-=h;
	int a,b;
	while(r--) {
		scanf("%d%d",&a,&b);
		int x=std::min(a,b),y=std::max(a,b);
		if(s.count(P(x,y))) continue;
		s.insert(P(x,y));
		arr[x+1]+=-1;arr[y]-=-1;
	}
	int now=0;
	for(int i=1;i<=n;++i) printf("%d\n",now+=arr[i]);
	return 0;
}
