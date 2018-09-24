#include <cstdio>
int n,m,arr[30],idx=0;
void search(int i) {
	if(idx+n-i+1<m) return;
	if(i>n) {
		for(int i=0;i<idx;++i) printf("%d ",arr[i]);
		printf("\n");
		return;
	}
	if(idx+1<=m) {
		arr[idx++]=i;
		search(i+1);
		arr[--idx]=0;
	}
	search(i+1);
}
int main() {
	scanf("%d%d",&n,&m);
	search(1);
	return 0;
}
