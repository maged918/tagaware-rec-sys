//Language: GNU C++11


#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define X first
#define Y second

using namespace std;

constexpr int MAX = 512;
constexpr int MOD = 1000000007;

char mat[MAX][MAX];
int dp[2][MAX][MAX];

inline void add(int& a, int b, int p = MOD) {
  if ((a += b) >= p) a -= p;
}

inline bool check(int x1, int y1, int x2, int y2) {
  if (x1 == x2 && y1 == y2) return true;
  return (x1 == x2 && y1 + 1 == y2) || (x1 + 1 == x2 && y1 == y2);
}

int solve(int n, int m) {
  memset(dp, 0, sizeof(dp));
  int ret = 0, w = (n + m - 1) / 2, x = 0;
  for (int s = 0; s <= w; ++s, x ^= 1) {
    memset(dp[x], 0, sizeof(dp[x]));
    for (int i = 0; i <= s && i < n; ++i) {
      for (int j = 0; j <= s && i + j < n; ++j) {
        int x1 = i, y1 = s - i, x2 = n - 1 - j, y2 = m - 1 - (s - j);
        if (x1 > x2 || y1 > y2 || mat[x1][y1] != mat[x2][y2]) {
          dp[x][i][j] = 0;
        } else if (!s) {
          dp[x][i][j] = 1;
        } else {
          if (x1 > 0) {
            if (x2 < n - 1) {
              add(dp[x][i][j], dp[x ^ 1][i - 1][j - 1]);
            }
            if (y2 < m - 1) {
              add(dp[x][i][j], dp[x ^ 1][i - 1][j]);
            }
          }
          if (y1 > 0) {
            if (x2 < n - 1) {
              add(dp[x][i][j], dp[x ^ 1][i][j - 1]);
            }
            if (y2 < m - 1) {
              add(dp[x][i][j], dp[x ^ 1][i][j]);
            }
          }
        }
        if (check(x1, y1, x2, y2)) {
          add(ret, dp[x][i][j]);
        }
      }
    }
  }
  return ret;
}

int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; ++i) {
      scanf("%s", mat[i]);
    }
    printf("%d\n", solve(n, m));
  }
  return 0;
}
