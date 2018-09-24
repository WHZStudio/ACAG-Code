#include <cstdio>
#include <climits>
char s[10][10];
int table[10][10],x[9],y[9],z[9];
inline int block(const int &x,const int &y) {
	if(x<=2) {
		if(y<=2) return 0;
		else if(y<=5) return 1;
		else if(y<=8) return 2;
	}
	else if(x<=5) {
		if(y<=2) return 3;
		else if(y<=5) return 4;
		else if(y<=8) return 5;
	}
	else {
		if(y<=2) return 6;
		else if(y<=5) return 7;
		else if(y<=8) return 8;
	}
	return -1;
}
int cnt=0;
int temp[40];
inline int calc(int num) {
	int out=0;
	while(num) {
		++out;
		num-=num&-num;
	}
	return out;
}
bool search(int now) {
	if(now==cnt) return true;
	int ans=INT_MAX,ansset=0,ansx=-1,ansy=-1;
	for(int i=0;i<9;++i) {
		for(int j=0;j<9;++j) {
			if(table[i][j]) continue;
			int set0=x[i]&y[j]&z[block(i,j)],c=calc(set0);
			if(set0&&c<ans) {
				ans=c;ansset=set0;ansx=i;ansy=j;
			}
		}
	}
	for(int i=ansset;i;i-=i&-i) {
		int loc=temp[(i&-i)%37];
		table[ansx][ansy]=loc+1;x[ansx]&=~(1<<loc);y[ansy]&=~(1<<loc);z[block(ansx,ansy)]&=~(1<<loc);
		if(search(now+1)) return true;
		table[ansx][ansy]=0;x[ansx]|=1<<loc;y[ansy]|=1<<loc;z[block(ansx,ansy)]|=1<<loc;
	}
	return false;
}
int main() {
	int t;scanf("%d",&t);
	for(int i=0;i<=35;++i) temp[(1LL<<i)%37]=i;
	while(t--) {
		cnt=0;
		for(int i=0;i<9;++i) x[i]=y[i]=z[i]=(1<<9)-1;
		for(int i=0;i<9;++i) {
			scanf("%s",s[i]);
			for(int j=0;j<9;++j) {
				table[i][j]=s[i][j]-'0';
				if(table[i][j]==0) {
					++cnt;
					continue;
				}
				x[i]&=~(1<<(table[i][j]-1));
				y[j]&=~(1<<(table[i][j]-1));
				z[block(i,j)]&=~(1<<(table[i][j]-1));
			}
		}
		search(0);
		for(int i=0;i<9;++i) {
			for(int j=0;j<9;++j) {
				printf("%d",table[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
