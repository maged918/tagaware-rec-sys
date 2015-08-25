//Language: GNU C++11


#include <iostream>
#include <unordered_map>
#include <cstring>
#include <memory>
#include <utility>
#include <functional>
#include <vector>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;

const int maxn = 100;
lli dp[maxn][maxn];

vector<pii> signs[maxn];

/**
 * sign1: -2 'a < b', -1 'a <= b', 0 'a == b', 1 'a >= b', 2 'a > b'
 * sign2: 1 'a < b', 0 'b == a', -1 'a > b'
 */
bool valid_signs(int sign1, int sign2) {
  switch (sign1) {
    case -2: return sign2 == 1;
    case -1: return sign2 >= 0;
    case  0: return sign2 == 0;
    case  1: return sign2 <= 0;
    case  2: return sign2 == -1;
    default: return false;
  }
}

bool is_sign_valid(pii left_interval, pii right_interval, pii sign, int n) {
  int tmp = 1;

  if (sign.second >= 1 && sign.second < left_interval.first) {
    tmp = -1;
  }

  if (sign.second >= left_interval.first && sign.second < left_interval.second) {
    tmp = 0;
  }

  if (sign.second > right_interval.first && sign.second <= right_interval.second) {
    tmp = 0;
  }

  if (sign.second > right_interval.second && sign.second <= 2 * n) {
    tmp = -1;
  }

  return valid_signs(sign.first, tmp);
}

bool is_valid(int left, int right, int shift, int n) {
  // [1, left) < current.
  // [left, shifted left) == current.
  pii left_interval(left, left + shift);

  // (shifted right, right] == current.
  // (right, 2 * n] < current.
  pii right_interval(right - (2 - shift), right);

  for (int j = left_interval.first; j < left_interval.second; j++) {
    for (const auto& sign : signs[j]) {
      if (!is_sign_valid(left_interval, right_interval, sign, n)) {
        return false;
      }
    }
  }

  for (int j = right_interval.first + 1; j <= right_interval.second; j++) {
    for (const auto& sign : signs[j]) {
      if (!is_sign_valid(left_interval, right_interval, sign, n)) {
        return false;
      }
    }
  }

  return true;
}

lli go(int block, int left, int right, int n) {
  if (block == n) {
    return 1LL;
  }

  lli& ans = dp[left][right];
  if (ans != -1LL) {
    return ans;
  }

  ans = 0LL;
  for (int i = 0; i <= 2; i++) {
    if (is_valid(left, right, i, n)) {
      ans += go(block + 1, left + i, right - (2 - i), n);
    }
  }

  if (block == (n - 1)) {
    ans = ans > 0LL ? 1LL : 0LL;
  }

  return ans;
}

int get_int(string s) {
  if (s == "<") {
    return -2;
  } else if (s == "<=") {
    return -1;
  } else if (s == "=") {
    return 0;
  } else if (s == ">=") {
    return 1;
  } else {
    return 2;
  }
}

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < k; i++) {
    int a, b;
    string s;

    cin >> a >> s >> b;
    signs[a].push_back(make_pair(get_int(s), b));
    signs[b].push_back(make_pair(-get_int(s), a));
  }

  memset(dp, -1LL, sizeof dp);
  cout << go(0, 1, 2 * n, n) << endl;

  return 0;
}
