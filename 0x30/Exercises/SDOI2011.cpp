#include <cstdio>
#include <cmath>
#include <cstring>
typedef long long int ll;
ll qpow(ll n,ll k,ll p) {
	ll ans=1;
	while(k) {if(k&1) ans=ans*n%p;n=n*n%p;k>>=1;}
	return ans;
}
void exgcd(ll a,ll b,ll &d,ll &x,ll &y) {
	if(!b) {d=a;x=1;y=0;}
	else {exgcd(b,a%b,d,y,x);y-=a/b*x;}
}
inline ll solve(ll a,ll b,ll c) {
	ll d,x,y;exgcd(a,b,d,x,y);
	if(c%d) return -1;
	x=c/d*x;x=(x%(b/d)+(b/d))%(b/d);
	return x;
}
const int hashmod=100007;
struct Hash {
	struct edge {int x,y;} edges[1000000];
	int head[hashmod],nxt[1000000],idx;
	inline void clear() {idx=0;memset(head,-1,sizeof(head));}
	inline void insert(ll x,ll y) {
		int u=x%hashmod;
		edges[idx]=(edge){x,y};
		nxt[idx]=head[u];head[u]=idx++;
	}
	inline int query(ll x) {
		int u=x%hashmod;
		for(int i=head[u];~i;i=nxt[i]) {
			edge &e=edges[i];
			if(e.x==x) return e.y;
		}
		return -1;
	}
} hash;
ll BSGS(ll a,ll b,ll p) {
	if(a%p==0) return -1;
	a%=p;b%=p;
	if(b==0) return 0;
	int m=(int)ceil(sqrt(p));hash.clear();
	for(int i=0,t=b;i<m;++i,t=1LL*t*a%p) hash.insert(t,i);
	for(int i=1,tt=qpow(a,m,p),t=tt;i<=m;++i,t=1LL*t*tt%p) {
		int res=hash.query(t);
		if(~res) return i*m-res;
	}
	return -1;
}
int main() {
	int t,k;scanf("%d%d",&t,&k);
	ll y,z,p;
	if(k==1) while(t--) {
		scanf("%lld%lld%lld",&y,&z,&p);
		printf("%lld\n",qpow(y,z,p));
	}
	else if(k==2) while(t--) {
		scanf("%lld%lld%lld",&y,&z,&p);
		ll ans=solve(y,p,z);
		(ans==-1)?printf("Orz, I cannot find x!\n"):printf("%lld\n",ans);
	}
	else if(k==3) while(t--) {
		scanf("%lld%lld%lld",&y,&z,&p);
		ll ans=BSGS(y,z,p);
		(ans==-1)?printf("Orz, I cannot find x!\n"):printf("%lld\n",ans);
	}
	return 0;
}
