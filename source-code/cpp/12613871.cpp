//Language: GNU C++11


#include <stdio.h>
#include <map>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int maxn = 505;
const int mod = (int)1e9 + 7;
char g[maxn][maxn];
int dp[2][maxn][maxn];
int n, m;
int dx[2] = { 0, -1 }, dy[2] = { -1, 0 };

inline bool check(int a, int b, int c, int d) {
    return a <= c && b <= d;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", g[i]);
    }
    if (g[0][0] != g[n - 1][m - 1]) {
        puts("0");
        return 0;
    }
    int step = (n + m - 2) >> 1;
    int pre = 0, cur = 1;
    int result = 0;

    dp[0][0][n - 1] = 1;
    cur = 0, pre = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!(i == 0 && j == 0)) {
                memset(dp[cur][j], 0, sizeof(dp[cur][j]));
            }
            if (i + j > step) break;
            if (j > 0) {
                for (int k = 0; k < n; ++k) {
                    if (dp[cur][j - 1][k] == 0) continue;
                    int x = k, y = n + m - i - j - 1 - k;
                    for (int dk = 0; dk < 2; ++dk) {
                        int tx = x + dx[dk], ty = y + dy[dk];
                        if (!check(i, j, tx, ty)) continue;
                        if (g[i][j] != g[tx][ty]) continue;
                        dp[cur][j][tx] = (dp[cur][j - 1][k] + dp[cur][j][tx]) % mod;
                    }
                }
            }
            if (i > 0) {
                for (int k = 0; k < n; ++k) {
                    if (dp[pre][j][k] == 0) continue;
                    int x = k, y = n + m - i - j - 1 - k;
                    for (int dk = 0; dk < 2; ++dk) {
                        int tx = x + dx[dk], ty = y + dy[dk];
                        if (!check(i, j, tx, ty)) continue;
                        if (g[i][j] != g[tx][ty]) continue;
                        dp[cur][j][tx] = (dp[pre][j][k] + dp[cur][j][tx]) % mod;
                    }
                }
            }
            if (i + j == step) {
                for (int k = 0; k < n; ++k) {
                    result = (result + dp[cur][j][k]) % mod;
                }
            }
        }
        cur = 1 - cur;
        pre = 1 - pre;
    }

    printf("%d\n", result);

    return 0;
}