#include <cstdio>
#include <cstring>
#include <algorithm>
int n,arr[100],used[100],sum=0,cur,cnt;
inline bool search(int stick,int len,int last) {
	if(stick==cnt) return true;
	int lastfail=0;
	for(int i=0;i<n;++i) {
		if(used[i]||len+arr[i]>cur||arr[i]==lastfail) continue;
		used[i]=true;
		if(len+arr[i]==cur) {if(search(stick+1,0,-1)) return true;}
		else if(search(stick,len+arr[i],i)) return true;
		used[i]=false;
		lastfail=arr[i];
		if(len==0||len+arr[i]==cur) return false;
	}
	return false;
}
inline int cmp(const int &x,const int &y) {return x>y;}
int main() {
	while(scanf("%d",&n)==1&&n) {
		sum=0;int mx=0;
		for(int i=0;i<n;++i) {
			scanf("%d",&arr[i]);
			sum+=arr[i];
			mx=std::max(mx,arr[i]);
		}
		std::sort(arr,arr+n,cmp);
		for(cur=mx;cur<=sum;++cur) {
			if(sum%cur) continue;
			cnt=sum/cur;
			memset(used,0,sizeof(used));
			if(search(0,0,-1)) break;
		}
		printf("%d\n",cur);
	}
	return 0;
}
