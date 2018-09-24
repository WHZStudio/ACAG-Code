#include <cstdio>
#include <cstring>
const int maxn=1e6+5;
int trie[maxn][26],tag[maxn],idx=0;
inline void init() {idx=0;memset(trie[0],-1,sizeof(trie[0]));tag[0]=0;}
inline void insert(char s[]) {
	int n=strlen(s),rt=0;
	for(int i=0;i<n;++i) {
		int c=s[i]-'a';
		if(trie[rt][c]==-1) {
			trie[rt][c]=++idx;
			memset(trie[idx],-1,sizeof(trie[idx]));tag[idx]=0;
		}
		rt=trie[rt][c];
	}
	++tag[rt];
}
inline int search(char s[]) {
	int n=strlen(s),rt=0,ans=0;
	for(int i=0;i<n;++i) {
		int c=s[i]-'a';
		if(trie[rt][c]==-1) return ans;
		rt=trie[rt][c];
		ans+=tag[rt];
	}
	return ans;
}
char s[maxn];
int main() {
	int n,m;scanf("%d%d",&n,&m);
	init();
	while(n--) {
		scanf("%s",s);
		insert(s);
	}
	while(m--) {
		scanf("%s",s);
		printf("%d\n",search(s));
	}
	return 0;
}
