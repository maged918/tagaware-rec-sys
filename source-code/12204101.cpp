//Language: GNU C++


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> x_left;
  map<int, int> x_cnt;
  int max_count = 0, l = 0, r = 0;
  for (int ii = 0; ii < n; ii++) {
      int x;
      cin >> x;

      if (x_left[x] == 0) {
          x_cnt[x] = 1;
          x_left[x] = (ii+1);
      } else {
          x_cnt[x]++;
      }
      if (x_cnt[x] > max_count) {
          l = x_left[x];
          r = (ii+1);
          max_count = x_cnt[x];
      } else if (x_cnt[x] == max_count && (r-l) > (ii+1-x_left[x])) {
          r = (ii+1);
          l = x_left[x];
      }
  }
  printf("%d %d\n", l, r);

  return 0;
}