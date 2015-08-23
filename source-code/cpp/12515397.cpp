//Language: GNU C++11


#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <memory.h>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 510;

char s[maxn][maxn];
int n, m;

const int p = (int)1e9 + 7;

long long f[maxn][2 * maxn][2];

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}

	int d = n + m - 2;
	int it = 0;

	for (int i = d % 2; i <= d; i += 2) {
		for (int t = 0; t < maxn; t++) {
			for (int j = 0; j < 2 * maxn; j++) {
				f[t][j][it] = 0;
			}
		}

		for (int x = 0; x < n; x++) {
			int y = d - 2 * x - i;

			if (y < 0) {
				continue;
			}

			y /= 2;

			if (i == 0) {
				f[x][0][it] = 1;
			} else {
				for (int dx = 0; dx <= i; dx++) {
					int x1 = x + dx;
					int y1 = y + i - dx;

					if (x1 < n && y1 < m && s[x][y] == s[x1][y1]) {
						if (i != 1) {
							f[x][dx][it] = f[x + 1][x1 - x - 2][it ^ 1] + f[x][x1 - x - 1][it ^ 1] + f[x + 1][x1 - x - 1][it ^ 1] + f[x][x1 - x][it ^ 1];
							f[x][dx][it] %= p;
						} else {
							f[x][dx][it] = 1;
						}
					}
				}
			}
		}

		it ^= 1;
	}

	cout << f[0][n - 1][it ^ 1] << endl;

	return 0;
}
