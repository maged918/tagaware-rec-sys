//Language: GNU C++11


#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <memory.h>
#include <cstdio>
#include <assert.h>

using namespace std;

#define pb push_back
#define INF 1011111111
#define FOR(i, a, b) for (int _n(b), i(a); i < _n; i++)
#define rep(i, n) FOR(i, 0, n)
#define CL(a, v) memset((a), (v), sizeof(a))
#define mp make_pair
#define X first
#define Y second
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;

/*** TEMPLATE CODE ENDS HERE */

char a[512][512];
char b[512][512];
ll dp[512][512][2];

int dist(int a, int b, int c, int d) { return abs(a - c) + abs(b - d); }

int main() {
#ifdef LOCAL_HOST
  freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
#endif

  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  rep(i, n) rep(j, m) cin >> a[i + 1][j + 1];
  rep(i, n) rep(j, m) b[n - i][m - j] = a[i + 1][j + 1];

  if (n == 1 && m == 1) {
    cout << 1 << endl;
    return 0;
  }

  if (b[1][1] != a[1][1]) {
    cout << 0 << endl;
    return 0;
  }

  dp[1][1][1] = 1;
  int k = n - 1 + m - 1;
  k /= 2;
  ll ans = 0;
  const int MOD = 1e9 + 7;

  for (int z = 1; z - 1 <= k; z++) {
    for (int i = 1; i - 1 <= k; i++) {
      for (int j = 1; i + j - 2 <= k && j <= m; j++) {
        if (i == 1 && j == 1 && z == 1) continue;
        if (!(i + j - z >= 1 && i + j - z <= m)) {
          dp[i][j][z & 1] = 0;
          continue;
        }
        if (a[i][j] != b[z][i + j - z]) {
          dp[i][j][z & 1] = 0;
        } else {
          dp[i][j][z & 1] = 0;
          if (i > 1) {
            dp[i][j][z & 1] += dp[i - 1][j][z & 1];
            if (z > 1) dp[i][j][z & 1] += dp[i - 1][j][(z & 1) ^ 1];
          }
          if (j > 1) {
            dp[i][j][z & 1] += dp[i][j - 1][z & 1];
            if (z > 1) dp[i][j][z & 1] += dp[i][j - 1][(z & 1) ^ 1];
          }
          dp[i][j][z & 1] %= MOD;
        }
        if (dist(i, j, n - z + 1, m - (i + j - z) + 1) <= 1) {
          ans += dp[i][j][z & 1];
        }
      }
    }
  }

  cout << ans % MOD << endl;

#ifdef LOCAL_HOST
  printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
#endif

  return 0;
}
