//Language: GNU C++11


#include<cstdio>

const int maxn = 200000;
int r[maxn], o[maxn];

int main() {
	int n, i, x, y;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", &x);
		for(int t=0; x; x >>= 1) {
			r[x]++;
			o[x] += t++;
		}
	}
	for(i=1e5; i>1 && r[i]-n; i--);
	x=o[i];
	for(;; i <<= 1) {
		y=r[i+i];
		if (n>y+y) break;
		x=x-y+n-y;
	}
	printf("%d\n", x);
	return 0;
}