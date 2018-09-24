#include <cstdio>
#include <cstring>
typedef unsigned long long int ull;
const int maxn=1000005;
char s[maxn];int n;ull hash[maxn],p[maxn];
inline void pre() {
	n=strlen(s);
	hash[0]=s[0]-'a'+1;p[0]=1;
	for(int i=1;i<n;++i) {
		hash[i]=hash[i-1]*131+s[i]-'a'+1;
		p[i]=p[i-1]*131;
	}
}
inline ull substr(int l,int r) {return hash[r]-(l?hash[l-1]:0)*p[r-l+1];}
int main() {
	scanf("%s",s);pre();
	int m;scanf("%d",&m);
	int l1,r1,l2,r2;
	while(m--) {
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);--l1;--r1;--l2;--r2;
		if(substr(l1,r1)==substr(l2,r2)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
