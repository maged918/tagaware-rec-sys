//Language: GNU C++11


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int N = 100;

int n, k;
int a[N], b[N];
string sign[N];

long long dp[N][N];

int L, R, A, B;

enum {
  OLD,
  CUR,
  NEW,
};

bool valid_time(int ltime, int rtime, string sign) {
  if (sign == ">") {
    return ltime > rtime;
  }
  if (sign == "<") {
    return ltime < rtime;
  }
  if (sign == "=") {
    return ltime == rtime;
  }
  if (sign == ">=") {
    return ltime >= rtime;
  }
  if (sign == "<=") {
    return ltime <= rtime;
  }
}

int time(int idx) {
  if (idx < L || idx > R) {
    return OLD;
  }
  if (idx == A || idx == B) {
    return CUR;
  }
  return NEW;
}

bool valid(int l, int r, int lput, int rput) {
  L = l, R = r, A = lput, B = rput;
  for (int i = 0; i < k; i ++) {
    int ltime = time(a[i]);
    int rtime = time(b[i]);

    if (ltime == CUR || rtime == CUR) {
      if (!valid_time(ltime, rtime, sign[i])) {
        return false;
      }
    }
  }
  return true;
}

long long calcdp(int l, int r) {
  long long &res = dp[l][r];
  if (res != -1) {
    return res;
  }
  res = 0;
  if (l + 1 == r) {
    if (valid(l, r, l, r)) {
      res++;
    }
  } else {
    if (valid(l, r, l, l + 1)) {
      res += calcdp(l + 2, r);
    }
    if (valid(l, r, l, r)) {
      res += calcdp(l + 1, r - 1);
    }
    if (valid(l, r, r - 1, r)) {
      res += calcdp(l, r - 2);
    }
  }
  return res;
}

int main() {
  cin >> n >> k;
  n <<= 1;
  for (int i = 0; i < k; i ++) {
    cin >> a[i] >> sign[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  memset(dp, -1, sizeof(dp));
  cout << calcdp(0, n - 1);
}
