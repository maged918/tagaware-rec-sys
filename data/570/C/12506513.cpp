//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second

int n, m;
string s;
int sum = 0;

int main() {
        ios_base::sync_with_stdio(0);
        cin >> n >> m >> s;
        s += 'a';
        s = "a" + s;
        ++n;
        pii p = pii(-1, -1);
        for (int i = 1; i <= n; ++i) {
                if (s[i] == '.') {
                        if (p.fi == -1) {
                                p = pii(i, i + 1);
                        } else {
                                p.se = i + 1;
                        }
                } else {
                        if (p.fi != -1) {
                                sum += p.se - p.fi - 1;
                                p = pii(-1, -1);
                        }
                }
        }
        for (int i = 0; i < m; ++i) {
                int x;
                char c;
                cin >> x >> c;
                if (c == '.') {
                        if (s[x] == '.') {
                                cout << sum << '\n';
                                continue;
                        }
                        if (s[x - 1] == '.' && s[x + 1] == '.') {
                                sum += 2;
                        } else if (s[x - 1] == '.') {
                                sum += 1;
                        } else  if (s[x + 1] == '.') {
                                sum += 1;
                        }
                } else {
                        if (s[x] != '.') {
                                cout << sum << '\n';
                                continue;
                        }
                        if (s[x - 1] == '.' && s[x + 1] == '.') {
                                sum -= 2;
                        } else if (s[x - 1] == '.') {
                                sum -= 1;
                        } else  if (s[x + 1] == '.') {
                                sum -= 1;
                        }
                }
                cout << sum << '\n';
                s[x] = c;
        }
        return 0;
}
