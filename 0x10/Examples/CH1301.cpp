#include <cstdio>
#include <climits>
#include <cstdlib>
#include <stack>
#include <algorithm>
const int maxn=(int)1e5+5;
struct type {
	int id,val;
	type *lst,*nxt;
	bool operator < (const type &rhs) const {
		return val<rhs.val;
	}
} a[maxn];
struct node {
	int id,val;
	node *lst,*nxt;
	node(int id,int val):id(id),val(val) {lst=nxt=NULL;} 
} *link[maxn];
int main() {
	int n;scanf("%d",&n);
	for(int i=0;i<n;++i) {
		a[i].id=i;
		scanf("%d",&a[i].val);
	}
	std::sort(a,a+n);
	for(int i=0;i<n;++i) link[a[i].id]=new node(a[i].id,a[i].val);
	for(int i=0;i<n;++i) {
		int loc=a[i].id;
		if(i==0) link[loc]->lst=NULL;
		else link[loc]->lst=link[a[i-1].id];
		if(i==n-1) link[loc]->nxt=NULL;
		else link[loc]->nxt=link[a[i+1].id];
	}
	std::stack<int> ans,ansloc;
	for(int i=n-1;i>=1;--i) {
		int left,right;
		if(link[i]->lst==NULL) left=INT_MAX;
		else left=abs(link[i]->lst->val-link[i]->val);
		if(link[i]->nxt==NULL) right=INT_MAX;
		else right=abs(link[i]->nxt->val-link[i]->val);
		if(left<=right) {
			ans.push(left);
			ansloc.push(link[i]->lst->id+1);
		}
		else {
			ans.push(right);
			ansloc.push(link[i]->nxt->id+1);
		}
		if(link[i]->lst!=NULL) link[i]->lst->nxt=link[i]->nxt;
		if(link[i]->nxt!=NULL) link[i]->nxt->lst=link[i]->lst;
		delete link[i];
	}
	while(ans.size()) {
		printf("%d %d\n",ans.top(),ansloc.top());
		ans.pop();ansloc.pop();
	}
	return 0;
}
