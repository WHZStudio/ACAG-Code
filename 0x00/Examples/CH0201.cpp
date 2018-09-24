#include <cstdio>
#include <algorithm>
const int rnd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char s[10][10];int test[10];
int cur=0;
void press(int x,int y) {
	++cur;
	test[x]^=1<<(4-y);
	for(int i=0;i<4;++i) {
		int nx=x+rnd[i][0],ny=y+rnd[i][1];
		if(0<=nx&&nx<5&&0<=ny&&ny<5) {
			test[nx]^=1<<(4-ny);
		}
	}
}
int main() {
	int n;scanf("%d",&n);
	while(n--) {
		for(int i=0;i<5;++i) scanf("%s",s[i]);
		int ans=0x3f3f3f3f;
		for(int i=0;i<(1<<5);++i) {
			for(int j=0;j<5;++j) {
				test[j]=0;
				for(int k=0;k<5;++k) test[j]=test[j]<<1|(s[j][k]-'0');
			}
			cur=0;
			for(int j=0;j<5;++j) if(i>>(4-j)&1) press(0,j);
			for(int j=1;j<5;++j) for(int k=0;k<5;++k) if(!(test[j-1]>>(4-k)&1)) press(j,k);
			if(test[4]==(1<<5)-1) ans=std::min(ans,cur);
		}
		printf("%d\n",(ans==0x3f3f3f3f||ans>6)?-1:ans);
	}
	return 0;
}
