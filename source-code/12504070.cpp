//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int INF = 0x7fffffff;
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;

int n, m;
char s[N];

int main() {
#ifdef Tally_Ho
    freopen("in.txt", "r", stdin);
#endif // Tally_Ho
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i - 1] == '.' && s[i] == '.') cnt ++;
    }
    int p;
    char t[10];
    while(m--) {
        scanf("%d %s", &p, t);
        p--;
        char c = t[0];
        int dot = 0;
        if(p > 0) {
            if(s[p - 1] == '.') dot++;
        }
        if(p < n - 1) {
            if(s[p + 1] == '.') dot++;
        }
        if(s[p] == '.') {
            s[p] = c;
            if(c != '.') {
                cnt -= dot;
            }
        } else {
            s[p] = c;
            if(c == '.') {
                cnt += dot;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
