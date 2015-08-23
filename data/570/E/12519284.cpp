//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

#define fillchar(a, s) memset((a), (s), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define rep(it, v) for (auto it = (v).begin(); it != (v).end(); it++)

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 510, MOD = 1e9 + 7;

int add (int x, int y) {
	return (x + y) % MOD;
}

void addeq (int &x, int y) {
	x = add(x, y);
}

int N, M, K;
char S[MAXN][MAXN];
int dp[2][MAXN][MAXN];

bool bounded (int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
	}
	scanf("%d %d", &N, &M);
	K = N + M - 1;	//this is the # of squares goddamnit
	for (int i = 0; i < N; i++) {
		scanf("%s", S[i]);
	}
	//init the dp stuff
	int cur = 0, prv = 1;
	if (K % 2) {
		int m = K / 2;
		for (int i = 0; i < N; i++) {
			int j = m - i;
			if (0 <= j && j < M) {
				dp[cur][i][i] = 1;
			}
		}
	} else {
		//otherwise there are TWO spots, not one
		//i don't have time for calls; i need to work
		//ok there are TWO fucking middle spots
		int m1 = K / 2 - 1;
		//m1 and m1 + 1... right next to each other
		for (int i = 0; i < N; i++) {
			int j = m1 - i;
			//ok the point is i, j. that's the FIRST point
			if (bounded(i + 1, j)) {
				dp[cur][i][i + 1] = (S[i + 1][j] == S[i][j]);
			}
			if (bounded(i, j + 1)) {
				dp[cur][i][i] = (S[i][j + 1] == S[i][j]);
			}
		}
	}
	for (int t = (K - 1) / 2; t; t--) {
		swap(cur, prv);
		int t2 = K - 1 - t;
		fillchar(dp[cur], 0);
		for (int i = 0; i < N; i++) {
			int yi = t - i;
			if (0 <= yi && yi < M) {
				for (int j = 0; j < N; j++) {
					//i don't have time to answer your calls...
					int yj = t2 - j;
					if (0 <= yj && yj < M) {
						int pdp = dp[prv][i][j];
						for (int a1 = 0; a1 < 2; a1++) {
							//i, yi. j, yj. now to i - a1, yi - (1 - a1)
							int ax = i - a1, ay = yi - (1 - a1);
							if (bounded(ax, ay)) {
								for (int b1 = 0; b1 < 2; b1++) {
									int bx = j + b1, by = yj + (1 - b1);
									if (bounded(bx, by) && S[ax][ay] == S[bx][by]) {
										// printf("encinia %d %d %d %d\n", ax, ay, bx, by);
										addeq(dp[cur][ax][bx], pdp);
										// printf("dp[%d][%d][%d][%d] += dpprv[%d][%d][%d][%d] = %d\n", ax, ay, bx, by, i, yi, j, yj, dp[cur][ax][bx]);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", dp[cur][0][N - 1]);
}