//Language: GNU C++11


#include <iostream>

using namespace std;

int main() {
  int t, s, q, count = 0;
  cin >> t >> s >> q;
  int i = 0, j = 0;
  while (s < t) {
    j++;
    s++;
    if (j == q) {
      s--;
      j = 0;
    }
    i++;
    if (i >= s) {
      count++;
      i = 0;
    }
  }
  cout << count + 1;
  return 0;
}
