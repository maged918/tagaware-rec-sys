//Language: GNU C++11


#include <bits/stdc++.h>
#ifndef M_PI
#define M_PI 3.14159265359
#endif // M_PI
#define endl "\n"
#define FOR(x, y, z) for (int x = (y); x < (z); ++x)
#define FORR(x, y, z) for (int x = (y); x > (z); --x)
#define GET(a, n) for (int __i = 0; __i < (n); ++__i) cin >> a[__i];
#define GETM(a, n, m) for (int __i = 0; __i < (n); ++__i) for (int __j = 0; __j < m; ++__j) cin >> a[__i][__j];
#define PRINTM(a, n, m) for (int __i = 0; __i < (n); ++__i) { for (int __j = 0; __j < m; ++__j) cout << a[__i][__j] << " ";  cout << endl; };
#define PRINT(a, n) for (int __i = 0; __i < (n); ++__i) cout << a[__i] << " ";
#define IT(a) a.begin(), a.end()
#define CASE(a, s) cout << "Case #" << a << ": " << s << endl;
#define DEB(a) cout << #a << " = " << (a) << endl; cout.flush();
#define DEBA(a) for (auto __i: a) cout << __i << " "; cout << endl;
#define IFDEB(b, a) if (b) { cout << #a << " = " << (a) << endl; cout.flush(); }
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <vector <int>> VVI;
typedef pair <int, int> PII;
const int MOD = 1000000007;
template <class T> typename T::value_type arr_sum(const T& v, int n) { typename T::value_type sum = 0; FOR(i, 0, n) sum += v[i]; return sum; }
struct Sync_stdio { Sync_stdio() { cin.tie(NULL); ios_base::sync_with_stdio(false); } } _sync_stdio;

struct Z
{
    int a;
    int b;
    string c;
};

vector <Z> v;
vector <vector <LL>> dp(100, vector <LL> (100, -1));

LL f(int l, int r)
{
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    if (l + 2 == r) {
        FOR (j, 0, v.size()) {
            if (v[j].a < l || v[j].a >= r) {
                continue;
            }
            if (v[j].c == "=" || v[j].c == "<=") {
                if (!(v[j].b < r)) {
                    return 0;
                }
            }
            if (v[j].c == "<") {
                return 0;
            }
            if (v[j].c == ">") {
                if (v[j].b < r) {
                    return 0;
                }
            }
        }
        return 1;
    }
    LL res = 0;
    FOR (i, 0, 3) {
        int k = 2 - i;
        int flag = 1;
        FOR (j, 0, v.size()) {
            if ((l <= v[j].a && v[j].a < l + i) || (r - k <= v[j].a && v[j].a < r)) {
                if (v[j].c == "=") {
                    if (!(r - k <= v[j].b && v[j].b < r) && !(l <= v[j].b && v[j].b < l + i)) {
                        flag = 0;
                    }
                }
                if (v[j].c == "<") {
                    if (!(l + i <= v[j].b && v[j].b < r - k)) {
                        flag = 0;
                    }
                }
                if (v[j].c == ">") {
                    if (l <= v[j].b && v[j].b < r) {
                        flag = 0;
                    }
                }
                if (v[j].c == "<=") {
                    if (!(l <= v[j].b && v[j].b < r)) {
                        flag = 0;
                    }
                }
                if (v[j].c == ">=") {
                    if (l + i <= v[j].b && v[j].b < r - k) {
                        flag = 0;
                    }
                }
            }
        }
        if (flag) {
            res += f(l + i, r - k);
        }
    }
    return dp[l][r] = res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    FOR (i, 0, k) {
        Z z;
        cin >> z.a >> z.c >> z.b;
        --z.a;
        --z.b;
        if (z.a == z.b) {
            if (z.c == ">" || z.c == "<") {
                cout << 0;
                return 0;
            }
            continue;
        }
        if (z.a > z.b) {
            swap(z.a, z.b);
            if (z.c == ">") {
                z.c = "<";
            } else if (z.c == "<") {
                z.c = ">";
            } else if (z.c == ">=") {
                z.c = "<=";
            } else if (z.c == "<=") {
                z.c = ">=";
            }
        }
        v.push_back(z);
    }
    cout << f(0, 2 * n);
}
