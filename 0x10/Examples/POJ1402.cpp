#include <cstdio>
#include <cstring>
#include <algorithm>
typedef unsigned long long int ull;
const int maxn=3e5+5;
char s[maxn];int n;
ull hash[maxn],p[maxn];
inline void pre() {
	n=strlen(s);
	hash[0]=s[0]-'a'+1;p[0]=1;
	for(int i=1;i<n;++i) {
		hash[i]=hash[i-1]*131+s[i]-'a'+1;
		p[i]=p[i-1]*131;
	}
}
inline ull substr(int l,int r) {return hash[r]-(l?hash[l-1]:0)*p[r-l+1];}
inline int LCP(const int &x,const int &y) {
	int l=0,r=std::min(n-x,n-y);
	while(l<r) {
		int mid=(l+r+1)>>1;
		if(substr(x,x+mid-1)==substr(y,y+mid-1)) l=mid;
		else r=mid-1;
	}
	return l;
}
inline bool cmp(const int &x,const int &y) {
	int lcp=LCP(x,y);
	return s[x+lcp]<s[y+lcp];
}
int sa[maxn];
inline void build() {
	pre();
	for(int i=0;i<n;++i) sa[i]=i;
	std::sort(sa,sa+n,cmp);
}
int main() {
	scanf("%s",s);
	build();
	for(int i=0;i<n;++i) printf("%d ",sa[i]);printf("\n");
	printf("0");for(int i=1;i<n;++i) printf(" %d",LCP(sa[i-1],sa[i]));printf("\n");
	return 0;
}
