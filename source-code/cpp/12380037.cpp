//Language: GNU C++11


#include <iostream>
#include <algorithm>
#define MAXN 75
#define MAXK 105

using namespace std;

int n,k;
bool lt[MAXN][MAXN],eq[MAXN][MAXN],gt[MAXN][MAXN];
long long dp[MAXN][MAXN];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= 2*n; i++) {
        for (int j = i+1; j <= 2*n; j++) {
            lt[i][j] = eq[i][j] = gt[i][j] = 1;
        }
    }

    while (k--) {
        int x,y;
        string sign;
        cin >> x >> sign >> y;
        bool l = 0, e = 0, g = 0;
        for (char c : sign) {
            if (c == '<') l = 1;
            if (c == '=') e = 1;
            if (c == '>') g = 1;
        }
        if (x > y) {
            swap(x,y);
            swap(l,g);
        }
        lt[x][y] &= l;
        eq[x][y] &= e;
        gt[x][y] &= g;
    }

    for (int i = 1; i < 2*n; i++) {
        if (eq[i][i+1]) dp[i][i+1] = 1;
    }

    for (int a = 1; a < n; a++) {
        for (int i = 1; i + 2*a + 1 <= 2*n; i++) {
            int j = i + 2*a + 1;
            bool ok;

            ok = 1;
            if (!eq[i][i+1]) ok = 0;
            for (int x = i+2; x <= j; x++) {
                if (!lt[i][x]) ok = 0;
                if (!lt[i+1][x]) ok = 0;
            }
            if (ok) dp[i][j] += dp[i+2][j];

            ok = 1;
            if (!eq[i][j]) ok = 0;
            for (int x = i+1; x < j; x++) {
                if (!lt[i][x]) ok = 0;
                if (!gt[x][j]) ok = 0;
            }
            if (ok) dp[i][j] += dp[i+1][j-1];

            ok = 1;
            if (!eq[j-1][j]) ok = 0;
            for (int x = i; x < j-1; x++) {
                if (!gt[x][j-1]) ok = 0;
                if (!gt[x][j]) ok = 0;
            }
            if (ok) dp[i][j] += dp[i][j-2];
        }
    }

    cout << dp[1][2*n] << '\n';
}
