//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>

typedef long long LL;
const int maxn = 505;
const LL mod = 1e9 + 7;
const int dx[] = {0, 1};
const int dy[] = {1, 0};
int n, m;
LL f[2][maxn][maxn];
char mp[maxn][maxn];

inline bool ok(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

inline void calc(int i, int j, int k, int l) {
    int ni, nj, nk, nl, ii = i & 1, nii;
    for(int d1 = 0; d1 < 2; d1++) {
        ni = i - dx[d1]; nj = j - dy[d1];
        if(i == ni) nii = ii;
        else nii = ii ^ 1;
        if(!ok(ni, nj)) continue;
        for(int d2 = 0; d2 < 2; d2++) {
            nk = k - dx[d2]; nl = l - dy[d2];
            if(!ok(nk, nl)) continue;
            if(mp[ni][nj] == mp[n - nk + 1][m - nl + 1]) {
                f[ii][j][k] += f[nii][nj][nk];
                while(f[ii][j][k] >= mod) f[ii][j][k] -= mod;
            }
        }
    }
}

void gao() {
    LL ans = 0;
    memset(f, 0, sizeof(f));
    f[1][1][1] = 1;
    int pcnt = n + m, mid = (n + m + 1) / 2 + 1;
    for(int i = 1; i <= n; i++) {
        int ii = i & 1;
        for(int j = 1; j <= m && i + j <= mid; j++) {
            if(i == 1 && j == 1) continue;
            for(int k = 1; k < i + j; k++) {
                f[ii][j][k] = 0;
                if(mp[i][j] == mp[n - k + 1][m - i - j + k + 1]) calc(i, j, k, i + j - k);
            }
            if(i + j == mid)  {
                if(pcnt % 2 == 0) ans += f[ii][j][n - i + 1];
                else {
                    if(j > 1) ans += f[ii][j - 1][n - i + 1];
                    if(i > 1) ans += f[ii ^ 1][j][n - i + 1];
                }
                while(ans >= mod) ans -= mod;
            }
        }
    }
    printf("%I64d\n", ans);
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
        gao();
    }
    return 0;
}