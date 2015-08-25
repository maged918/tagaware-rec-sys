//Language: GNU C++11


#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
template <class T>
inline bool rd(T &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0;
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template <class T>
inline void pt(T x) {
    if (x <0) {
        putchar('-');
        x = -x;
    }
    if (x>9) pt(x / 10);
    putchar(x % 10 + '0');
}
typedef long long ll;
typedef pair<ll, ll> pii;
const int N = 500005;
const int inf = 1e9 + 10;
int n, q;

ll L[55], R[55];
map<ll, int>mp;
int main() {
    L[1] = R[1] = 1;
    for (int i = 2; i <= 50; i++)L[i] = L[i - 1] << 1, R[i] = R[i - 1] << 1 | 1;
    rd(n); rd(q);
    if (q == 0) {
        if (n == 1)puts("1");
        else puts("Data not sufficient!");
        return 0;
    }
    for (int i = 0, dep, ok; i < q; i++) {
        ll l, r;
        rd(dep); rd(l); rd(r); rd(ok);
        while (dep < n) {
            l <<= 1;
            r = r << 1 | 1;
            dep++;
        }
        if (ok)mp[l]++, mp[r + 1]--;
        else {
            mp[L[n]]++; mp[l]--;
            mp[r + 1]++; mp[R[n]+1]--;
        }
    }
    int sum = 0;
    ll pre = -1, cnt = 0, ans = 0;
    for (auto i : mp) {
        sum += i.second;
        if (pre != -1) {
            cnt += i.first - pre;
            ans = pre;
        }
        if (sum == q)pre = i.first;
        else pre = -1;
    }
    if (cnt == 0)puts("Game cheated!");
    else if (cnt > 1)puts("Data not sufficient!");
    else pt(ans);
    return 0;
}