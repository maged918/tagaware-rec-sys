//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

#define all(c) ((c).begin()), ((c).end())
#define dump(c) cerr << "> " << #c << " = " << (c) << endl;
#define iter(c) __typeof((c).begin())
#define tr(i, c) for (iter(c) i = (c).begin(); i != (c).end(); i++)
#define REP(i, a, b) for (int i = a; i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int INF = 1 << 29;
const double EPS = 1e-10;

double zero(double d) {
    return d < EPS ? 0.0 : d;
}

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << '(' << p.first << ',' << p.second << ')';
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    rep(i, a.size()) os << (i ? " " : "") << a[i];
    return os << ']';
}

// to avoid error on mingw
string toString(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

const int M = 1000000007;
// a^k
ll fpow(ll a, ll k) {
    ll res = 1ll;
    ll x = a;
    while (k != 0) {
        if ((k & 1) == 1)
            res = res * x;
        x = x * x;
        k >>= 1;
    }
    return res;
}


int pref(int a, int b){
    if(a == b)
        return a;
    if(a > b)
        a /= 2;
    else
        b /= 2;
    return pref(a, b);
}

int conv(int a, int b) {
    int count = 0;

    int p = pref(a,b);
    // a -> p
    while(a > p)
        count++, a/=2;

    // p -> b
    while(b > p)
        count++, p*=2;

    return count;
}

int main() {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(8);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int a[n];
    vi apref;
    rep(i,n) {
        cin >> a[i];
        int t = a[i];
        while(t % 2 == 0)
            t /= 2;
        apref.push_back(t);
    }

    int p = apref[0];
    REP(i, 1, apref.size()) {
        p = pref(p, apref[i]);
    }

    int bitlen = 1;
    int tmpp = p;
    while(tmpp > 1) {
        bitlen++;
        tmpp /= 2;
    }

    cerr << "bitlen: " << bitlen << endl;

    int res = INT_MAX;
    rep(i, 31-bitlen) {
        int target = p * fpow(2, i);
        int count = 0;
        rep(j, n) {
            count += conv(a[j], target);
        }
        res = min(res, count);
    }

    cout << res << endl;

    return 0;
}