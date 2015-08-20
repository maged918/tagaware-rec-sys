//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int INF = 0x7fffffff;
const int MOD = 1e9 + 7;
const int N = 500 + 10;

int dp[2][N][N]; // i&1, x0, x1
char str[N][N];

void add(int& x, int v) {
    x += v;
    if(x >= MOD) x -= MOD;
}
int main() {
#ifdef Tally_Ho
    freopen("in.txt", "r", stdin);
#endif // Tally_Ho
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", &str[i][1]);
    }
    dp[0][1][n] = str[1][1] == str[n][m];
    int cur = 0;
    for(int step = 1; step <= (m + n - 2) / 2; step++) {
        cur ^= 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dp[cur][i][j] = 0;
            }
        }
        for(int x1 = 1; x1 <= n && x1 - 1 <= step; x1++) {
            for(int x2 = n; x2 >= 1 && n - x2 <= step; x2--) {
                int y1 = 1 + step - (x1 - 1);
                int y2 = m - step + (n - x2);
                if(str[x1][y1] != str[x2][y2]) continue;
                add(dp[cur][x1][x2], dp[cur ^ 1][x1][x2]);
                add(dp[cur][x1][x2], dp[cur ^ 1][x1][x2 + 1]);
                add(dp[cur][x1][x2], dp[cur ^ 1][x1 - 1][x2 + 1]);
                add(dp[cur][x1][x2], dp[cur ^ 1][x1 - 1][x2]);
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        add(res, dp[cur][i][i]);
    }
    if((m + n) % 2 == 1) {
        for(int i = 1; i <= n - 1; i++) {
            add(res, dp[cur][i][i + 1]);
        }
    }
    printf("%d\n", res);
    return 0;
}