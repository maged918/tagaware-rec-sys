//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

int n;
pii xa[101];
int res;

int main() {
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin >> n;
  xa[0] = mp(0, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> xa[i].first >> xa[i].second;
  }
  ++n;
  sort(xa, xa + n);
  for (int i = 0; i < n; ++i) {
    if (xa[i].first == 0) {
      int res1 = 0, res2 = 0;
      int len = min(i, n - i - 1);
      for (int j = max(0, i - len - 1); j <= min(n - 1, i + len); ++j) {
	res1 += xa[j].second;
      }
      for (int j = max(0, i - len); j <= min(n - 1, i + len + 1); ++j) {
	res2 += xa[j].second;
      }
      cout << max(res1, res2) << endl;
      return 0;
    }
  }
  assert(false);
  return 0;
}
