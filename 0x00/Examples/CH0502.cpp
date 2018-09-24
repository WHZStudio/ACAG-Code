#include <cstdio>
#include <cstdlib>
#include <algorithm>
typedef long long int ll;
const int maxn=100005;
int temp[maxn];
ll solve(int arr[],int n) {
	int sum=0;
	for(int i=1;i<=n;++i) sum+=arr[i];
	if(sum/n*n!=sum) return -1;
	sum/=n;temp[0]=0;
	for(int i=2;i<=n;++i) {
		temp[i-1]=temp[i-2]+arr[i]-sum;
	}
	std::sort(temp,temp+n);
	ll ans=0;
	for(int i=0;i<n;++i) ans+=abs(temp[i]-temp[n/2]);
	return ans;
}
int a[maxn],b[maxn];
int main() {
	int n,m,t;scanf("%d%d%d",&n,&m,&t);
	int x,y;
	while(t--) {
		scanf("%d%d",&x,&y);
		++a[x];++b[y];
	}
	ll ansx=solve(a,n),ansy=solve(b,m);
	if(ansx==-1) {
		if(ansy==-1) printf("impossible\n");
		else printf("column %lld\n",ansy);
	}
	else {
		if(ansy==-1) printf("row %lld\n",ansx);
		else printf("both %lld\n",ansx+ansy);
	}
	return 0;
}
