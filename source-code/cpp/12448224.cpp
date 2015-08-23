//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int INF = 0x7fffffff;
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

int main() {
#ifdef Tally_Ho
    freopen("in.txt", "r", stdin);
#endif // Tally_Ho
    int t, s, q;
    cin >> t >> s >> q;
    int a = 0, b = s;
    int ans = 1;
    while(1) {
        int meet = (b - a) * q;
        s += meet - b;
        if(meet >= t) break;
        b = meet;
        a = 0;
        ans ++;
    }
    cout << ans << endl;
    return 0;
}
