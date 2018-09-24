#include <cstdio>
#include <cstdlib>
typedef long long int ll;
int n,arr[5],cnt;ll***** f;
ll dp(int a,int b,int c,int d,int e) {
	if(f[a][b][c][d][e]!=-1) return f[a][b][c][d][e];
	ll ans=0;
	if(a<arr[0]) ans+=dp(a+1,b,c,d,e);
	if(a>b&&b<arr[1]) ans+=dp(a,b+1,c,d,e);
	if(b>c&&c<arr[2]) ans+=dp(a,b,c+1,d,e);
	if(c>d&&d<arr[3]) ans+=dp(a,b,c,d+1,e);
	if(d>e&&e<arr[4]) ans+=dp(a,b,c,d,e+1);
	return f[a][b][c][d][e]=ans;
}
ll***** ask(int a,int b,int c,int d,int e) {
	ll***** p=(ll*****)malloc(sizeof(ll****)*a);
	for(int i=0;i<a;++i) {
		*(p+i)=(ll****)malloc(sizeof(ll***)*b);
		for(int j=0;j<b;++j) {
			*(*(p+i)+j)=(ll***)malloc(sizeof(ll**)*c);
			for(int k=0;k<c;++k) {
				*(*(*(p+i)+j)+k)=(ll**)malloc(sizeof(ll*)*d);
				for(int l=0;l<d;++l) {
					*(*(*(*(p+i)+j)+k)+l)=(ll*)malloc(sizeof(ll)*e);
				}
			}
		}
	}
	for(int i=0;i<a;++i)
		for(int j=0;j<b;++j)
			for(int k=0;k<c;++k)
				for(int l=0;l<d;++l)
					for(int m=0;m<e;++m)
						p[i][j][k][l][m]=-1;
	return p;
}
int main() {
	int n;
	while(scanf("%d",&n)==1&&n) {
		for(int i=0;i<5;++i) arr[i]=0;
		for(int i=0;i<n;++i) scanf("%d",&arr[i]);
		f=ask(arr[0]+1,arr[1]+1,arr[2]+1,arr[3]+1,arr[4]+1);
		f[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]]=1;
		printf("%lld\n",dp(0,0,0,0,0));
	}
	return 0;
}
