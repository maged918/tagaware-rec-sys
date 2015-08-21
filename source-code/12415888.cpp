//Language: GNU C++11


#include<bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define rep(i,n) for(int i=0; i<n; i++)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const int N = 36, K = 101;
int n, k;
ll dp[N][2 * N];
int xs[K], ys[K];
string sign[K];

bool check(int l, int r) {
    bool good = true;
    rep(i, k) {
        int x = xs[i], y = ys[i];
        string s = sign[i];
        if (l <= x && x <= r && (y < l || r < y)) {
            good &= (s == ">=" || s == ">");
        }
        else if (l <= y && y <= r && (x < l || r < x)) {
            good &= (s == "<=" || s == "<");
        }
    }
    return good;
}

bool check2(int l, int r) {
    rep(i, k) {
        int x = xs[i], y = ys[i];
        string s = sign[i];
        if (x == l && y == r && (s == ">" || s == "<")) return false;
        if (y == l && x == r && (s == ">" || s == "<")) return false;
    }
    return true;
}

ll calcdp(int h, int l) {
    int len = 2 * n - 2 * (h - 1);
    int r = l + len - 1;
    if (r > 2 * n) return 0;
    if (h == n) {
        if (check(l, r) && check2(l, r)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (dp[h][l] == -1) {
        if (check(l, r)) {
            dp[h][l] = 0;
            if (check2(r - 1, r))
                dp[h][l] += calcdp(h+1, l);
            if (check2(l, r))
                dp[h][l] += calcdp(h+1, l+1);
            if (check2(l, l + 1))
                dp[h][l] += calcdp(h+1, l+2);
        }
        else {
            dp[h][l] = 0;
        }
    }
    return dp[h][l];
}

int main() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 2 * N; j++) {
            dp[i][j] = -1;
        }
    cin >> n >> k;
    rep(i, k) {
        cin >> xs[i] >> sign[i] >> ys[i];
    }
    cout << calcdp(1, 1) << endl;
	return 0;
}
