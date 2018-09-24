#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long int ll;
struct M {
	int n,m;ll s[65][65];
	M(int n=65,int m=65):n(n),m(m) {memset(s,0,sizeof(s));}
	M operator * (const M &rhs) const {
		M ans;
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				for(int k=0;k<rhs.m;++k) {
					ans.s[i][k]+=s[i][j]*rhs.s[j][k];
				}
			}
		}
		return ans;
	}
	void print() {
		printf("Matrix %d %d.\n",n,m);
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				printf("%lld ",s[i][j]);
			}
			printf("\n");
		}
	}
};
M qpow(M n,int k) {
	M ans;for(int i=0;i<65;++i) ans.s[i][i]=1;
	while(k) {if(k&1) ans=ans*n;n=n*n;k>>=1;}
	return ans;
}
int n,m,t,act;char optid[10][10];char opt[10][10];int len[10];
inline int id(const int &x,const int &y) {return (x-1)*m+y;}
M d[60];
inline ll calc() {
	M x,y;for(int i=0;i<=n*m;++i) x.s[i][i]=y.s[i][i]=1;
	for(int k=0;k<60;++k) {
		d[k].s[0][0]=1;
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=m;++j) {
				int idx=optid[i-1][j-1]-'0';
				char option=opt[idx][k%len[idx]];
				if('0'<=option&&option<='9') {
					d[k].s[0][id(i,j)]=option-'0';
					d[k].s[id(i,j)][id(i,j)]=1;
				}
				else if(option=='N'&&i-1>=1) d[k].s[id(i,j)][id(i-1,j)]=1;
				else if(option=='S'&&i+1<=n) d[k].s[id(i,j)][id(i+1,j)]=1;
				else if(option=='W'&&j-1>=1) d[k].s[id(i,j)][id(i,j-1)]=1;
				else if(option=='E'&&j+1<=m) d[k].s[id(i,j)][id(i,j+1)]=1;
			}
		}
		x=x*d[k];
		if(k<t%60) y=y*d[k]; 
	}
	M f(1,n*m+1);f.s[0][0]=1;f=f*qpow(x,t/60)*y;
	ll ans=0;for(int i=1;i<=n*m;++i) ans=std::max(ans,f.s[0][i]);return ans;
}
int main() {
	scanf("%d%d%d%d",&n,&m,&t,&act);
	for(int i=0;i<n;++i) scanf("%s",optid[i]);
	for(int i=0;i<act;++i) {
		scanf("%s",opt[i]);
		len[i]=strlen(opt[i]);
	}
	printf("%lld\n",calc());
	return 0;
}
