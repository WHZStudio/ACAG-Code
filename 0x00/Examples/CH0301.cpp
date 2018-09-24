#include <cstdio>
int n,arr[20],idx=0;
void search(int i) {
	if(i>n) {
		for(int i=0;i<idx;++i) printf("%d ",arr[i]);
		printf("\n");
		return;
	}
	search(i+1);
	arr[idx++]=i;
	search(i+1);
	arr[--idx]=0;
}
int main() {
	scanf("%d",&n);
	search(1);
	return 0;
}
