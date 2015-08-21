//Language: GNU C++


#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>

using namespace std;

const int maxn = 36;

int fan[5]={0,2,1,4,3};

long long f[maxn+1][maxn*2+1];
long long result;
int n, m;
vector<pair<int, int> > con[maxn*2+1];

void init() {
	int i, j, x, y, t;
	char s[10];
	scanf("%d%d", &n, &m);
	for (i=1; i<=m; ++i) {
		scanf("%d%s%d",&x,s,&y);
		if (strlen(s) == 1) {
			if (s[0] == '=') t = 0;
			if (s[0] == '<') t = 1;
			if (s[0] == '>') t = 2;
		} else {
			if (s[0] == '<') t = 3;
			if (s[0] == '>') t = 4;
		}
		con[x].push_back(pair<int, int>(t, y));
		con[y].push_back(pair<int, int>(fan[t], x));
	}
}

bool check(int t, int x, int y) {
	if (t == 0) return x == y;
	if (t == 1) return x < y;
	if (t == 2) return x > y;
	if (t == 3) return x <= y;
	if (t == 4) return x >= y;
}

void work() {
	int i, j, k, left, right, x, y, q, p, t, nleft;
	bool ky;
	f[0][0] = 1;
	for (i=0; i<n; ++i)
		for (j=0; j<=i+i; ++j)
			if (f[i][j]) {
				left = j;
				right = n + n - (i + i - j) + 1;
				for (q=1; q<=3; ++q) {
					if ((i==n-1)&&(q>1)) break;
					if (q==1) {
						x = left + 1;
						y = right - 1;
					} else {
						if (q==2) {
							x = left + 1;
							y = left + 2;
						} else {
							x = right - 2;
							y = right - 1;
						}
					}
					ky = true;
					// check constraint
					for (k=0; k<con[x].size(); ++k) {
						t = con[x][k].first;
						p = con[x][k].second;
						if ((p <= left) || (p >= right)) continue;
						if (p == x) ky = (ky && check(t, i, i));
						else if (p == y) ky = (ky && check(t, i, i));
						else ky = (ky && check(t, i, i + 1));
					}
					for (k=0; k<con[y].size(); ++k) {
						t = con[y][k].first;
						p = con[y][k].second;
						if ((p <= left) || (p >= right)) continue;
						if (p == x) ky = (ky && check(t, i, i));
						else if (p == y) ky = (ky && check(t, i, i));
						else ky = (ky && check(t, i, i + 1));
					}
					if (q==1) nleft = left + 1;
					else if (q==2) nleft = left + 2;
					else nleft = left;
					if (ky) {
						// printf("i+1=%d nleft=%d\n",i+1, nleft);
						f[i+1][nleft] += f[i][left];
					}
				}
			}
}

void output() {
	int i;
	result = 0;
	for (i=0; i<=n+n; ++i) result += f[n][i];
	printf("%lld\n", result);
}

int main() {
//	freopen("F.in", "r", stdin);
	init();
	work();
	output();
	return 0;
}