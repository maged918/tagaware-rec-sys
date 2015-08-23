//Language: GNU C++11


#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n, ans = 1e9, a[100001], maxi = 0, dis[100001], freq[100001];
vector<pair<int, int> > common[100001];

int main() { _
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    maxi = max(maxi, a[i]);
  }
  for (int i = 0; i < n; i++) {
    int b = a[i], d = 0;
    while (b > 0) {
      freq[b]++;
      dis[b] += d;
      if (b > 1 && b != ((b>>1)<<1)) {
        common[i].push_back(make_pair(b>>1, d+1));
      }
      b >>= 1;
      d++;
    }
    b = a[i]<<1, d = 1;
    while (b <= maxi) {
      freq[b]++;
      dis[b] += d;
      b <<= 1;
      d++;
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (auto p : common[i]) {
      int b = p.first, d = p.second;
      b <<= 1;
      d++;
      while (b <= maxi) {
        freq[b]++;
        dis[b] += d;
        b <<= 1;
        d++;
      }
    }
  }
  for (int i = 1; i <= maxi; i++) {
    if (freq[i] == n) {
      ans = min(ans, dis[i]);
    }
  }
  cout << ans << "\n";
  return 0;
}
