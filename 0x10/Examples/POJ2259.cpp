/* 入门OJ AC */
/*
#include <cstdio>
#include <queue>
#include <map>
int main() {
	int t,kase=0;
	while(scanf("%d",&t)==1&&t) {
		std::map<int,int> bel;
		for(int i=0;i<t;++i) {
			int n;scanf("%d",&n);
			while(n--) {
				int x;scanf("%d",&x);
				bel[x]=i;
			}
		}
		if(kase) printf("\n");
		printf("Scenario #%d\n",++kase);
		char s[20];std::queue<int> qq,q[1005];
		while(scanf("%s",s)==1&&s[0]!='S') {
			if(s[0]=='E') {
				int x;scanf("%d",&x);
				if(q[bel[x]].empty()) qq.push(bel[x]);
				q[bel[x]].push(x);
			}
			else if(s[0]=='D') {
				printf("%d\n",q[qq.front()].front());
				q[qq.front()].pop();
				if(q[qq.front()].empty()) qq.pop();
			}
		}
	}
	return 0;
}
*/
/* POJ AC */
#include <cstdio>
#include <queue>
int bel[1000005];
int main() {
	int t,kase=0;
	while(scanf("%d",&t)==1&&t) {
		for(int i=0;i<t;++i) {
			int n;scanf("%d",&n);
			while(n--) {
				int x;scanf("%d",&x);
				bel[x]=i;
			}
		}
		if(kase) printf("\n");
		printf("Scenario #%d\n",++kase);
		char s[20];std::queue<int> qq,q[1005];
		while(scanf("%s",s)==1&&s[0]!='S') {
			if(s[0]=='E') {
				int x;scanf("%d",&x);
				if(q[bel[x]].empty()) qq.push(bel[x]);
				q[bel[x]].push(x);
			}
			else if(s[0]=='D') {
				printf("%d\n",q[qq.front()].front());
				q[qq.front()].pop();
				if(q[qq.front()].empty()) qq.pop();
			}
		}
	}
	return 0;
}
