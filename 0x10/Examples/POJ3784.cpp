#include <cstdio>
#include <stack>
#include <algorithm>
const int maxn=10005;
struct type {
	int id,val;
	bool operator < (const type &rhs) const {
		if(val==rhs.val) return id<rhs.id;
		return val<rhs.val;
	}
} a[maxn];
struct node {
	int id,val;
	node *lst,*nxt;
	node(int id,int val):id(id),val(val) {lst=nxt=NULL;}
} *list[maxn];
inline void remove(node* &o) {
	if(o->lst!=NULL) o->lst->nxt=o->nxt;
	if(o->nxt!=NULL) o->nxt->lst=o->lst;
	delete o;
}
int cmp(node* &a,node* &b) {
	if(a->val==b->val) {
		if(a->id==b->id) return 0;
		return (a->id<b->id)?1:-1;
	}
	return (a->val<b->val)?1:-1;
}
int main() {
	int t;scanf("%d",&t);
	while(t--) {
		int kase,n;scanf("%d%d",&kase,&n);printf("%d %d\n",kase,(n+1)/2);
		for(int i=0;i<n;++i) {
			a[i].id=i;
			scanf("%d",&a[i].val);
		}
		std::sort(a,a+n);
		for(int i=0;i<n;++i) list[a[i].id]=new node(a[i].id,a[i].val);
		for(int i=0;i<n;++i) {
			int id=a[i].id;
			if(i==0) list[id]->lst=NULL;
			else list[id]->lst=list[a[i-1].id];
			if(i==n-1) list[id]->nxt=NULL;
			else list[id]->nxt=list[a[i+1].id];
		}
		node *now=list[a[(n-1)/2].id];std::stack<int> ans;
		if(n%2==0) remove(list[n-1]);
		for(int i=n%2?n-1:n-2;i>=0;i-=2) {
			ans.push(now->val);
			if(i==0) break;
			int smaller=cmp(list[i],now)+cmp(list[i-1],now);
			if(smaller>0) {
				now=now->nxt;
				if(list[i]==now) now=list[i]->nxt;
				remove(list[i]);
				if(list[i-1]==now) now=list[i-1]->nxt;
				remove(list[i-1]);
			}
			else if(smaller<0) {
				now=now->lst;
				if(list[i]==now) now=list[i]->lst;
				remove(list[i]);
				if(list[i-1]==now) now=list[i-1]->lst;
				remove(list[i-1]);
			}
			else {
				remove(list[i]);
				remove(list[i-1]);
			}
		}
		for(int i=0,end=ans.size();i<end;++i) {
			if(i&&i%10==0) putchar('\n');
			if(i%10) putchar(' ');
			printf("%d",ans.top());ans.pop();
		}
		printf("\n");
	}
	return 0;
}
