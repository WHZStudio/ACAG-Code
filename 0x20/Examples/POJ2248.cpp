#include <cstdio>
#include <cstring>
int n,depth,x[105];
bool search(int loc) {
	if(loc>depth) return x[depth]==n;
	int vis[105]={0};
	for(int i=loc-1;i>=0;--i) {
		for(int j=i;j>=0;--j) {
			if(x[i]+x[j]>n||vis[x[i]+x[j]]) continue;
			if(x[i]+x[j]<=x[loc-1]) return false;//here
			x[loc]=x[i]+x[j];
			if(search(loc+1)) return true;
			x[loc]=0;
			vis[x[i]+x[j]]=true;
		}
	}
	return false;
}
int main() {
	while(scanf("%d",&n)==1&&n) {
		depth=0;x[0]=1;
		while(!search(1)) ++depth;
		for(int i=0;i<=depth;++i) printf("%d ",x[i]);printf("\n");
	}
	return 0;
}
