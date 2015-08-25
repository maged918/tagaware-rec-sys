//Language: GNU C++11


#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:66777216")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <deque>
#include <cassert>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <string>
#include <list>
#include <fstream>
#include <unordered_set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define forn(i, n) for (ll i = 0; i < (ll)n; i++)
#define fornn(i, q, n) for (ll i = q; i < (ll)n; i++)
#define mp make_pair
#define pk push_back
#define all(v) v.begin(), v.end()
#define times clock() * 1.0 / CLOCKS_PER_SEC

#define TASK "kthsubstr"

const double eps = 1e-7;
const double pi = acos(-1.0);

const int inf = (int)2e9 + 1;
const ll linf = (ll)9e18 + 7;

int solve();
void gen();

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
    //freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("test.txt", "w", stderr);
#endif
    solve();
    return 0;
}

const int MAXN = 3e5 + 7;
const ll MM = (ll)1e9 + 7;
ll fact[MAXN], tcaf[MAXN];
ll dp[2007];

ll fp(ll a, ll n) {
    n %= MM - 1;
    if (n < 0)
        n += MM - 1;

    ll res = 1;
    for (; n; n /= 2) {
        if (n & 1)
            res *= a, res %= MM;
        a *= a, a %= MM;
    }
    return res;
}

ll CNK(int n, int k) {
    return fact[n] * tcaf[k] % MM * tcaf[n - k] % MM;
}

int solve() {
    fact[0] = tcaf[0] = 1;
    fornn(i, 1, MAXN) 
        fact[i] = i * fact[i - 1] % MM, tcaf[i] = fp(fact[i], -1);

    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int> > p(n);
    forn(i, n) 
        cin >> p[i].first >> p[i].second;

    p.pk({h, w});
    sort(all(p));

    forn(i, n + 1) {
        dp[i] = CNK(p[i].first + p[i].second - 2, p[i].first - 1);
        forn(j, i) {
            if (p[j].first <= p[i].first && p[j].second <= p[i].second)
                dp[i] = (dp[i] + MM - dp[j] * CNK(p[i].first - p[j].first + p[i].second - p[j].second, p[i].first - p[j].first)) % MM;
        }
    }
    cout << (dp[n] + MM) % MM;
    return 0;
}