//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using ll = long long;
using llu = unsigned long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vll = vector<ll>;
using vvll = vector<vll>;
const int INF = numeric_limits<int>::max();
const double EPS = 1e-10;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n, k;
  while (cin >> n >> k) {
    ll answer = 0;
    map<ll, ll> count, s2;
    for (ll i = 0; i < n; i++) {
      ll v; cin >> v;
      if (v % k == 0) {
        answer += s2[v / k];
        s2[v] += count[v / k];
      }
      count[v]++;
    }
    cout << answer << endl;
  }
}
