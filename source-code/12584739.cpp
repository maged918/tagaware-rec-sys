//Language: GNU C++11


#include <iostream>
#include <string>

using namespace std;

inline bool left(string &s, int x) {
  return 0 < x && s[x - 1] == '.';
}

inline bool right(string &s, int x) {
  return x + 1 < (int) s.length() && s[x + 1] == '.';
}

inline bool both(string &s, int x) {
  return left(s, x) && right(s, x);
}

inline bool any(string &s, int x) {
  return left(s, x) || right(s, x);
}

int main() {
  int n, m, f = 0;
  string s;
  cin >> n >> m >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.') {
      int len = 1;
      for (int j = i + 1; j < n && s[j] == '.'; ++j) {
        ++len;
      }
      i += len - 1;
      f += len - 1;
    }
  }
  for (int i = 0; i < m; ++i) {
    char c;
    int x;
    cin >> x >> c;
    --x;
    if (s[x] == '.' && c != '.') {
      if (both(s, x)) {
        f -= 2;
      } else if (any(s, x)) {
        --f;
      }
    }
    if (s[x] != '.' && c == '.') {
      if (both(s, x)) {
        f += 2;
      } else if (any(s, x)) {
        ++f;
      }
    }
    s[x] = c;
    cout << f << endl;
  }
  return 0;
}