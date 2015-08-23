//Language: GNU C++11


#include <iostream>

using namespace std;

const long long MAXN = 4005;
const long long MOD = 1e9 + 7;

long long d1[MAXN][MAXN];
long long d2[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        d2[i][0] = 0;
        d2[0][i] = 1;
    }
    d1[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            d1[i][j] = (d1[i - 1][j - 1] + d2[i - 1][j] - d2[i - 1][j - 1] + MOD) % MOD;
            d2[i][j] = (d2[i][j - 1] + (d1[i][j] * j) % MOD) % MOD;
        }
    }
    cout << d2[n][n] << '\n';
}
