#include <cstdio>
#include <cstring>
int n,k,m;
struct M {
	int s[35][35];
	M() {memset(s,0,sizeof(s));}
	M operator + (const M &rhs) const {
		M ans;
		for(int i=0;i<n;++i) for(int j=0;j<n;++j) ans.s[i][j]=(s[i][j]+rhs.s[i][j])%m;
		return ans;
	}
	M operator += (const M &rhs) {return *this=*this+rhs;}
	M operator * (const M &rhs) const {
		M ans;
		for(int i=0;i<n;++i) {
			for(int j=0;j<n;++j) {
				for(int k=0;k<n;++k) {
					ans.s[i][k]=(ans.s[i][k]+s[i][j]*rhs.s[j][k]%m)%m;
				}
			}
		}
		return ans;
	}
	M operator *= (const M &rhs) {return *this=*this*rhs;}
} A,one;
struct Matrix {
	int n,m;M s[2][2];
	Matrix(int n=2,int m=2):n(n),m(m) {}
	Matrix operator * (const Matrix &rhs) const {
		Matrix ans;
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				for(int k=0;k<rhs.m;++k) {
					ans.s[i][k]+=s[i][j]*rhs.s[j][k];
				}
			}
		}
		return ans;
	}
};
inline Matrix qpow(Matrix n,int k) {
	Matrix ans;for(int i=0;i<2;++i) ans.s[i][i]=one;
	while(k) {if(k&1) ans=ans*n;n=n*n;k>>=1;}
	return ans;
}
int main() {
	scanf("%d%d%d",&n,&k,&m);
	for(int i=0;i<n;++i) {
		for(int j=0;j<n;++j) {
			scanf("%d",&A.s[i][j]);
			A.s[i][j]%=m;
		}
	}
	Matrix f(1,2);f.s[0][0]=one;f.s[0][1]=A;
	for(int i=0;i<n;++i) one.s[i][i]=1;
	Matrix d;
	d.s[0][0]=A;d.s[0][1]=M();
	d.s[1][0]=one;d.s[1][1]=one;
	f=f*qpow(d,k);
	for(int i=0;i<n;++i) {
		for(int j=0;j<n;++j) {
			printf("%d ",f.s[0][0].s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
