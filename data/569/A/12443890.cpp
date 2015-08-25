//Language: GNU C++


#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ll t, s, q;
  cin >> t >> s >> q;

  ll r = 1;
  ll c = s * q;
  while (t > c) {
    c *= q;
    ++r;
  }

  cout << r << endl;

  return 0;
}