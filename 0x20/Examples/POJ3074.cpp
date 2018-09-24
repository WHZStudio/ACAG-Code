#include <cstdio>
#include <climits>
char s[100];
int table[10][10],x[9],y[9],z[9],block0[9][9];
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
int cnt=0,temp[40],calc0[1<<9];
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
			int set0=x[i]&y[j]&z[block0[i][j]],c=calc0[set0];
			if(!set0) return false; 
			if(c<ans) {ans=c;ansset=set0;ansx=i;ansy=j;}
		}
	}
	for(int i=ansset;i;i-=i&-i) {
		int loc=temp[(i&-i)%37];
		table[ansx][ansy]=loc+1;x[ansx]&=~(1<<loc);y[ansy]&=~(1<<loc);z[block0[ansx][ansy]]&=~(1<<loc);
		if(search(now+1)) return true;
		table[ansx][ansy]=0;x[ansx]|=1<<loc;y[ansy]|=1<<loc;z[block0[ansx][ansy]]|=1<<loc;
	}
	return false;
}
int main() {
	for(int i=0;i<=35;++i) temp[(1LL<<i)%37]=i;
	for(int i=0;i<(1<<9);++i) calc0[i]=calc(i);
	for(int i=0;i<9;++i) for(int j=0;j<9;++j) block0[i][j]=block(i,j);
	while(scanf("%s",s)==1&&s[0]!='e') {
		cnt=0;
		for(int i=0;i<9;++i) x[i]=y[i]=z[i]=(1<<9)-1;
		for(int i=0;i<9;++i) {
			for(int j=0;j<9;++j) {
				if(s[i*9+j]=='.') {
					table[i][j]=0;
					++cnt;
					continue;
				}
				table[i][j]=s[i*9+j]-'0';
				x[i]&=~(1<<(table[i][j]-1));
				y[j]&=~(1<<(table[i][j]-1));
				z[block0[i][j]]&=~(1<<(table[i][j]-1));
			}
		}
		search(0);
		for(int i=0;i<9;++i) for(int j=0;j<9;++j) printf("%d",table[i][j]);
		printf("\n");
	}
	return 0;
}
