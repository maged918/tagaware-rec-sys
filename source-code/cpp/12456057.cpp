//Language: GNU C++


#include <cstdio>
#define lch (k << 1)
#define rch (k << 1 | 1)
#define mid ((l+r) >> 1)

const int maxn = 100000;
char s[maxn];

struct segment_tree {
	int data[26][maxn << 2], lazy[26][maxn << 2];
	void push_up(int ch, int k) {
		data[ch][k]=data[ch][lch]+data[ch][rch];
	}
	void push_down(int ch, int k, int w) {
		lazy[ch][lch]=lazy[ch][rch]=lazy[ch][k];
		data[ch][lch]=(w-(w>>1))*lazy[ch][k];
		data[ch][rch]=   (w>>1) *lazy[ch][k];
		lazy[ch][k]=-1;
	}
	void update(int a, int b, int v, int ch, int k, int l, int r) {
		if(a <= l && r <= b) {
			lazy[ch][k]=v;
			data[ch][k]=(r-l+1)*v;
			return;
		}
		if(lazy[ch][k] != -1) push_down(ch, k, r-l+1);
		if(a <= mid) update(a, b, v, ch, lch, l, mid);
		if(b>mid) update(a, b, v, ch, rch, mid+1, r);
		push_up(ch, k);
	}
	int query(int a, int b, int ch, int k, int l, int r) {
		if(a <= l && r <= b) return data[ch][k];
		if(lazy[ch][k] != -1) push_down(ch, k, r-l+1);
		int res=0;
		if(a <= mid) res += query(a, b, ch, lch, l, mid);
		if(b>mid) res += query(a, b, ch, rch, mid+1, r);
		return res; 
	}
}solver;

int main() {
	int n, q;
	scanf("%d%d%s", &n, &q, s+1);
	for(int i=0; i<26; i++)
		for(int j=0; j<n<<1; j++)
			solver.lazy[i][j];
	for(int i=1; i <= n; i++) solver.update(i, i, 1, s[i]-'a', 1, 1, n);
	for(int x, y, z, cur, num; q-- && scanf("%d%d%d", &x, &y, &z);) {
		cur=x;
		if(z) {
			for(int i=0; num <= n && i<26; i++) {
				num=solver.query(x, y, i, 1, 1, n);				
				solver.update(x, y, 0, i, 1, 1, n);
				if(num) solver.update(cur, cur+num-1, 1, i, 1, 1, n);
				cur += num;
			}
		}
		else {
			for(int i=25; num <= n && i >= 0; i--) {
				num=solver.query(x, y, i, 1, 1, n);				
				solver.update(x, y, 0, i, 1, 1, n);								
				if(num) solver.update(cur, cur+num-1, 1, i, 1, 1, n);
				cur += num;
			}
		}
	}
	for(int i=1; i <= n; i++) 
		for(int j=0; j<26; j++)
			if(solver.query(i, i, j, 1, 1, n)) {
				putchar(j+'a');
				break;
			}
	puts("");		
	return 0;
}
		 		 		 	   	    				  	 			