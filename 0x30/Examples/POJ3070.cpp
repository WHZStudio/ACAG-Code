#include <cstdio>
#include <cstring>
const int mod=10000;
struct M {
	int n,m,s[2][2];
	M(int n=2,int m=2):n(n),m(m) {memset(s,0,sizeof(s));}
	M operator * (const M &rhs) const {
		M ans;
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				for(int k=0;k<rhs.m;++k) {
					ans.s[i][k]=(ans.s[i][k]+s[i][j]*rhs.s[j][k])%mod;
				}
			}
		}
		return ans;
	}
};
M qpow(M n,int k) {
	M ans;for(int i=0;i<2;++i) ans.s[i][i]=1;
	while(k) {if(k&1) ans=ans*n;n=n*n;k>>=1;}
	return ans;
}
inline int f(int n) {
	if(n==0) return 0;
	if(n==1) return 1;
	M d;d.s[0][0]=d.s[0][1]=d.s[1][0]=1;
	M ans(2,1);ans.s[0][0]=1;
	ans=qpow(d,n-1)*ans;
	return ans.s[0][0];
}
int main() {
	int n;
	while(scanf("%d",&n)==1&&(~n)) printf("%d\n",f(n));
	return 0;
}
