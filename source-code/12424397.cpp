//Language: GNU C++11


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
typedef pair<int, int> IP;

const LL MOD = 1000000007LL;

LL fastpow(LL a, LL b) {
  if (!b) return 1;
  LL c = fastpow((a*a)%MOD, b>>1);
  if (b&1) c *= a;
  return c%MOD;
}

LL fac[200001];
LL inv[200001];

inline LL com(LL n, LL k) {
  return (fac[n] * ( (inv[k]*inv[n-k])%MOD ))%MOD;
}

int h, w, n;
IP a[100001];
LL tbl[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  memset(tbl, 0, sizeof tbl);
  fac[0] = inv[0] = 1;
  for (int i=1;i<200001; ++i) {
    fac[i] = (fac[i-1]*i)%MOD;
    inv[i] = (inv[i-1]*fastpow(i, MOD-2))%MOD;
  }
  cin >> h >> w >> n;
  for (int i=0; i<n; ++i) cin >> a[i].first >> a[i].second;
  a[n] = { h, w };
  sort(a, a+n+1);
  for (int i=0; i<=n; ++i) {
    // how many ways from previous black cells to this one
    LL sub = 0;
    for(int j=0; j<i; ++j) {
      int x = a[i].first-a[j].first;
      int y = a[i].second-a[j].second;
      if (y>=0) sub = (sub + tbl[j]*com(x+y, x))%MOD;
    }           
    // how many ways from initial cell to this one
    tbl[i] = ( com(a[i].second+a[i].first-2, a[i].first-1)-sub+MOD )%MOD;
  }
  cout << tbl[n] << endl;
  return 0;
}










