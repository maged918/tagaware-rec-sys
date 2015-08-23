//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

#ifdef SG
    #include "debug/debug.h"
#else
    #define debug(...)
#endif

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 500;

struct Input {
    int n, m;
    char a[N][N + 1];
        
    bool read () {
        if (!(cin >> n >> m)) {
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%s", a[i]);
        }
        return true;
    }

    void init (const Input &input) {
        *this = input;
    }
};

const int mod = 1e9 + 7;

struct Data: Input {
    int ans;

    void write () {
        cout << ans << "\n";
    }
    
    virtual void solve () {}
    
    virtual void clear () {
        *this = Data();
    }
};

struct Solution: Data {
    int dp[N][N * (N + 1) / 2 + 2];
                 
    bool ok (int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    int sol (int i, int j, int x, int y) {
        if (!ok(i, j) || !ok(x, y)) {
            return 0;
        }
        if (i > x || j > y) {
            return 0;
        }
        
        int & r = dp[i][((y * (y + 1)) >> 1) + j];
        if (r != -1) {
            return r;
        }
        if (i == x && j == y) {
            return r = 1;
        }
        if (a[i][j] != a[x][y]) {
            return r = 0;
        }
        if (x - i + y - j == 1) {
            return r = 1;
        }

        r = (ll(sol(i + 1, j, x - 1, y)) +
             ll(sol(i + 1, j, x, y - 1)) +
             ll(sol(i, j + 1, x - 1, y)) + 
             ll(sol(i, j + 1, x, y - 1))) % mod;
        return r;
    }

    void solve () {
        memset(dp, -1, sizeof dp);
        ans = sol(0, 0, n - 1, m - 1);
        /*
        ll cnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int x = i; x < n; ++x) {
                    for (int y = j; y < m; ++y) {
                        if (i + j == (n - x - 1) + (m - y - 1)) {
                            ++cnt;
                        }
                    }
                }
            }
        }
        */

    }
    
    void clear () {
        *this = Solution();
    }
};

Solution sol;

int main () {
    cout.setf(ios::showpoint | ios::fixed);
    cout.precision(20);
#ifdef SG
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
    while (sol.read()) {
        sol.solve();
        sol.write();
        sol.clear();
    }
#else
    sol.read();
    sol.solve();
    sol.write();
#endif
    return 0;
}
