#include <cstdio>
#include <queue>
#include <functional>
#include <vector>
int main() {
	int t;scanf("%d",&t);
	while(t--) {
		int p,n;scanf("%d%d",&p,&n);
		printf("%d %d\n",p,(n+1)/2);
		std::vector<int> vec;
		int x;std::priority_queue<int> le;std::priority_queue<int,std::vector<int>,std::greater<int> > ri;
		for(int i=0;i<n;++i) {
			scanf("%d",&x);
			if(le.size()&&x<=le.top()) le.push(x);
			else ri.push(x);
			while(le.size()+1<ri.size()) {
				le.push(ri.top());ri.pop();
			}
			while(ri.size()+1<le.size()) {
				ri.push(le.top());le.pop();
			}
			if(le.size()>ri.size()) vec.push_back(le.top());
			else if(le.size()<ri.size()) vec.push_back(ri.top());
		}
		for(int i=0,end=vec.size();i<end;++i) {
			if(i&&i%10==0) printf("\n");
			printf("%d ",vec[i]);
		}
		if(vec.size()%10) printf("\n");
	}
	return 0;
}
