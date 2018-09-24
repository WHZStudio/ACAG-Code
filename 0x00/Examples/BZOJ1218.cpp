#include <cstdio>
#include <algorithm>
int s[5005][5005];
int main() {
	int n,r;scanf("%d%d",&n,&r);
	int x,y,v;
	while(n--) {
		scanf("%d%d%d",&x,&y,&v);
		s[x+1][y+1]+=v;
	}
	int ans=0;
	for(int i=1;i<=5001;++i) {
		for(int j=1;j<=5001;++j) {
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			if(i>=r&&j>=r) ans=std::max(ans,s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
