#include <cstdio>
int n,vis[15],arr[15];
void search(int idx) {
	if(idx>n) {
		for(int i=1;i<idx;++i) printf("%d ",arr[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;++i) {
		if(!vis[i]) {
			vis[i]=true;
			arr[idx]=i;
			search(idx+1);
			arr[idx]=0;
			vis[i]=false;
		}
	}
}
int main() {
	scanf("%d",&n);
	search(1);
	return 0;
}
