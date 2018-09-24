#include <cstdio>
#include <cstring>
const int mod=99991;
const int maxn=100005;
inline int hash(int a[]) {
	int sum=0,mul=1;
	for(int i=0;i<6;++i) {
		sum=(sum+a[i])%mod;
		mul=(long long int)mul*a[i]%mod;
	}
	return (sum+mul)%mod;
}
inline bool same(int a[],int b[]) {
	for(int i=0;i<6;++i) {
		for(int j=0;j<6;++j) {
			bool ok=true;
			for(int k=0;k<6;++k) {
				if(a[(i+k)%6]!=b[(j+k)%6]) {
					ok=false;
					break;
				}
			}
			if(ok) return true;
			ok=true;
			for(int k=0;k<6;++k) {
				if(a[(i+k)%6]!=b[(j+6-k)%6]) {
					ok=false;
					break;
				}
			}
			if(ok) return true;
		}
	}
	return false;
}
int snow[maxn][6],head[maxn],nxt[maxn],idx=0;
inline bool check(int a[]) {
	int val=hash(a);
	for(int i=head[val];i!=-1;i=nxt[i]) {
		if(same(snow[i],a)) return true;
	}
	for(int i=0;i<6;++i) snow[idx][i]=a[i];
	nxt[idx]=head[val];head[val]=idx++;
	return false;
}
int a[6];
int main() {
	int n;scanf("%d",&n);
	memset(head,-1,sizeof(head));
	bool ans=false;
	while(n--) {
		for(int i=0;i<6;++i) scanf("%d",&a[i]);
		if(check(a)) {
			ans=true;
			break;
		}
	}
	printf("%s\n",ans?"Twin snowflakes found.":"No two snowflakes are alike.");
	return 0;
}
