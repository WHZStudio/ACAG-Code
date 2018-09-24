#include <cstdio>
#include <cstring>
#include <algorithm>
typedef unsigned long long int ull;
const int maxn=1000005;
char s[maxn];int n;
ull hash[maxn],hash2[maxn],p[maxn];
inline void pre() {
	hash[0]=s[0]-'a'+1;p[0]=1;
	for(int i=1;i<n;++i) {
		hash[i]=hash[i-1]*131+s[i]-'a'+1;
		p[i]=p[i-1]*131;
	}
	hash2[n-1]=s[n-1]-'a'+1;
	for(int i=n-2;i>=0;--i) hash2[i]=hash2[i+1]*131+s[i]-'a'+1;
}
inline ull substr(int l,int r) {return hash[r]-(l?hash[l-1]:0)*p[r-l+1];}
inline ull substr2(int l,int r) {return hash2[l]-(r!=n-1?hash2[r+1]:0)*p[r-l+1];}
inline bool check(int l1,int r1,int l2,int r2) {return substr(l1,r1)==substr2(l2,r2);}
inline int solve() {
	int ans=0;pre();
	for(int i=0;i<n;++i) {
		int l=1,r=std::min(i+1,n-i);
		while(l<r) {
			int mid=(l+r+1)>>1;
			if(check(i-mid+1,i,i,i+mid-1)) l=mid;
			else r=mid-1;
		}
		ans=std::max(ans,(l<<1)-1);
	}
	for(int i=0;i<n-1;++i) {
		int l=1,r=std::min(i+1,n-i-1);
		while(l<r) {
			int mid=(l+r+1)>>1;
			if(check(i-mid+1,i,i+1,i+mid)) l=mid;
			else r=mid-1;
		}
		ans=std::max(ans,l<<1);
	}
	return ans;
}
int main() {
	int kase=0;
	while(scanf("%s",s)&&s[0]!='E') {
		n=strlen(s);
		printf("Case %d: %d\n",++kase,solve());
	}
	return 0;
}
