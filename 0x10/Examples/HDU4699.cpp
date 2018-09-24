#include <cstdio>
#include <climits>
#include <algorithm>
const int maxn=(int)1e6+5;
int l[maxn],r[maxn],s[maxn],m[maxn],lt=0,rt=0;
inline void insert(int x) {l[++lt]=x;s[lt]=s[lt-1]+x;m[lt]=std::max(m[lt-1],s[lt]);}
inline void remove() {if(lt) --lt;}
inline void left() {if(lt) r[++rt]=l[lt--];}
inline void right() {if(!rt) return;l[++lt]=r[rt--];s[lt]=s[lt-1]+l[lt];m[lt]=std::max(m[lt-1],s[lt]);}
inline int query(int k) {return m[k];}
int main() {
	int q;
	while(scanf("%d",&q)==1) {
		lt=rt=0;s[0]=0;m[0]=INT_MIN;//Important
		while(q--) {
			char opt[2];scanf("%s",opt);
			if(opt[0]=='I') {int x;scanf("%d",&x);insert(x);}
			else if(opt[0]=='D') remove();
			else if(opt[0]=='L') left();
			else if(opt[0]=='R') right();
			else if(opt[0]=='Q') {int k;scanf("%d",&k);printf("%d\n",query(k));}
		}
	}
	return 0;
}
