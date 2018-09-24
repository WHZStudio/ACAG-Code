#include <cstdio>
#include <algorithm>
const int arr[]={2,3,5,7,11,13,17,19,23,29,31};
int n;long long int ans=0,ansnum=0,now=1,cnt=1;
inline int pow(int n,int k) {
	int ans=1;
	while(k) {
		if(k&1) ans*=n;
		n*=n;k>>=1;
	}
	return ans;
}
void search(int idx,int up) {
	if(idx>10) {
		if(cnt>ans) {
			ans=cnt;
			ansnum=now;
		}
		else if(cnt==ans) ansnum=std::min(ansnum,now);
		return;
	}
	search(idx+1,0);
	for(int i=1;i<=up;++i) {
		int power=pow(arr[idx],i);
		if((long long int)now*power>n) break;
		now*=power;cnt*=i+1;
		search(idx+1,i);
		now/=power;cnt/=i+1;
	}
}
int main() {
	scanf("%d",&n);
	search(0,30);
	printf("%lld\n",ansnum);
	return 0;
}
