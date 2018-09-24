#include <cstdio>
int n,sta[25],top=0,print[25],now=0,ans=0;
void search(int x) {
	if(x==n) {
		for(int i=0;i<now;++i) printf("%d",print[i]);
		for(int i=top-1;i>=0;--i) printf("%d",sta[i]);
		printf("\n");
		++ans;
		return;
	}
	int temp[25],ttop=0;
	for(int i=0;i<top;++i) temp[ttop++]=sta[i];
	for(int i=top;i>=0;--i) {// 枚举弹出多少次后插入
		for(int j=0;j<i;++j) print[now++]=sta[--top];
		sta[top++]=x+1;
		search(x+1);
		if(ans==20) return;
		for(int j=0;j<i;++j) --now;
		top=0;for(int j=0;j<ttop;++j) sta[top++]=temp[j];
	}
}
int main() {
	scanf("%d",&n);
	search(0);
	return 0;
}
