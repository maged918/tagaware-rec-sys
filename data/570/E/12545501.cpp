//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

const int p = 1000000007;

char a[505][505];
long long f[505][505], g[505][505];
int n, m, dx[] = {1, 0, 0, -1}, dy[] = {0, 1, -1, 0};

bool out(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  int mx = min(n, m), N = (m + n - 2) / 2;
  for (int i = 0; i <= n || i <= m; i++) {
    if ((m + n) % 2 == 0) g[i][i] = 1;
    else {
      if (!out(N - i, i) && !out(N - i, i + 1) && a[N - i][i] == a[N - i][i + 1]) {
        g[i][i + 1] = 1;
      }
      if (!out(N - i, i) && !out(N - i + 1, i) && a[N - i][i] == a[N - i + 1][i]) {
        g[i][i] = 1;
      }
    }
  }
  for (int k = N; k; k--) {
    for (int i = 0; i <= m || i <= n; i++) {
      for (int j = 0; j <= m || j <= n; j++) {
        f[i][j] = 0;
      }
    }
    for (int x0 = min(n, k) - 1, y0 = k - x0 - 1; x0 >= 0 && y0 < m; x0--, y0++) {
      for (int y1 = max(0, m - k), x1 = m + n - y1 - k - 1; x1 >= 0 && y1 < m; x1--, y1++) {
        for (int i = 0; i < 2; i++) {
          if (a[x0][y0] ^ a[x1][y1]) continue;
          for (int j = 2; j < 4; j++) {
            int _x0 = x0 + dx[i], _y0 = y0 + dy[i];
            int _x1 = x1 + dx[j], _y1 = y1 + dy[j];
            if (out(_x0, _y0) || out(_x1, _y1)) continue;
            f[y0][y1] += g[_y0][_y1];
            f[y0][y1] %= p;
          }
        }
      }
    }
    for (int i = 0; i <= m || i <= n; i++) {
      for (int j = 0; j <= m || j <= n; j++) {
        g[i][j] = f[i][j];
      }
    }
  }
  cout << f[0][m - 1];
}
