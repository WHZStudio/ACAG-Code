#include <cstdio>
#include <cstdlib>
int fa[30005],d[30005],size[30005];
int find(int x) {
	if(x==fa[x]) return x;
	int rt=find(fa[x]);
	if(fa[x]!=rt) d[x]+=d[fa[x]];
	return fa[x]=rt;
}
int main() {
	int t;scanf("%d",&t);
	for(int i=0;i<=30000;++i) {
		fa[i]=i;d[i]=0;size[i]=1;
	}
	char s[2];int x,y;
	while(t--) {
		scanf("%s%d%d",s,&x,&y);
		if(s[0]=='M') {
			int a=find(x),b=find(y);// here
			d[a]=size[b];
			size[b]+=size[a];
			fa[a]=b;
		}
		else if(s[0]=='C') {
			if(find(x)==find(y)) printf("%d\n",abs(d[x]-d[y])-1);
			else printf("-1\n");
		}
	}
	return 0;
}
