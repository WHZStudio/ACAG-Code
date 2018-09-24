#include <cstdio>
#include <vector>
const int mod=9901;
std::vector<int> prime;
std::vector<int> times;
void divide(int num) {
	for(int i=2,end=num;i*i<=end;++i) {
		if(num%i==0) {
			prime.push_back(i);
			int cnt=0;
			while(num%i==0) {
				++cnt;
				num/=i;
			}
			times.push_back(cnt);
		}
	}
	if(num>1) {
		prime.push_back(num);
		times.push_back(1);
	}
}
int pow(int n,int k) {
	int ans=1;
	while(k) {
		if(k&1) ans=ans*n%mod;
		n=(long long int)n*n%mod;k>>=1;
	}
	return ans;
}
int powsum(int n,int k) {
	if(k==0) return 1;
	int temp=powsum(n,(k-1)/2);
	int ans=(temp+temp*pow(n,(k-1)/2+1)%mod)%mod;
	if(!(k&1)) ans=(ans+pow(n,k))%mod;
	return ans;
}
int main() {
	int a,b;scanf("%d%d",&a,&b);
	divide(a);
	for(int i=0,end=times.size();i<end;++i) times[i]*=b;
	int ans=1;
	for(int i=0,end=prime.size();i<end;++i) ans=ans*powsum(prime[i],times[i])%mod;
	printf("%d\n",ans);
	return 0;
}
