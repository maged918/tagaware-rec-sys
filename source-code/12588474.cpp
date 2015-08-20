//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

#define MAX_INT (int)0x7fffffff
#define MIN_INT (int)0x80000000
#define MAX_UINT (uint)0xffffffff

#define TTi template<typename T> inline
TTi T SQR(T x) { return x * x; }

#define CONCAT3_NX(x, y, z) x ## y ## z
#define CONCAT3(x, y, z) CONCAT3_NX(x, y, z)
#define VAR(name) CONCAT3(__tmpvar__, name, __LINE__)
#define TYPE(x) __typeof(x)

#define FOR(i, s, n)  for (TYPE(n) i=(s),   VAR(end)=(n);  i <  VAR(end);  i++)
#define RFOR(i, s, n) for (TYPE(n) i=(n)-1, VAR(end)=(s);  i >= VAR(end);  i--)
#define FORN(i, n)    FOR(i, 0, n)
#define RFORN(i, n)   RFOR(i, 0, n)
#define FOREACH(i, v) for (auto& i: v)

#define MP(a, b) make_pair(a, b)
#define WHOLE(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define POPST(stack) (stack).top();(stack).pop();
#define POPQ(queue) (queue).front();(queue).pop();
#define CONTAINS(v, x) (find(WHOLE(v), (x)) != v.end())
#define SORT(v) (sort(WHOLE(v)))

#define LIMIT(x, lim) {if (x > lim) x = lim;}
TTi T MIN(T x, T y) { return (x < y) ? x : y; }
TTi T MAX(T x, T y) { return (x > y) ? x : y; }
TTi T ABS(T x) { return (x > 0) ? x : -x; }
TTi void UPDATE_MIN(T &x, T y) {if (y < x) {x = y;}}
TTi void UPDATE_MAX(T &x, T y) {if (x < y) {x = y;}}
TTi int ARGMAX(T cont) { return max_element(cont.begin(), cont.end()) - cont.begin(); }
TTi int ARGMIN(T cont) { return min_element(cont.begin(), cont.end()) - cont.begin(); }

vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s;
    s << "[";
    FORN(i, n - 1) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}

#ifndef ONLINE_JUDGE
    #define EPR(args...)   if (DEBUG) {fprintf(stderr, args);}
    #define EARR(arr, n)   if (DEBUG) {FORN(i, n) fprintf(stderr, "%d, ", arr[i]);}
    #define EVEC(arr)      if (DEBUG) {FORN(i, arr.size()) fprintf(stderr, "%d, ", arr[i]);}
    #define EVARS(args...) if (DEBUG) { __evars_begin(__LINE__); __evars(split(#args, ',').begin(), args);}

    inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
    inline void __evars(vector<string>::iterator it) {cerr << endl;}

    TTi void __evars_out_var(vector<T> val) {
        cerr << arrStr(val, val.size());
    }
    TTi void __evars_out_var(T* val) {
        cerr << arrStr(val, 10);
    }
    TTi void __evars_out_var(T val) {
        cerr << val;
    }
    template<typename T, typename... Args>
    inline void __evars(vector<string>::iterator it, T a, Args... args) {
        cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
        __evars_out_var(a);
        cerr << "; ";
        __evars(++it, args...);
    }
#else
    #define EPR(args...) 1
    #define EARR(args...) 1
    #define EVEC(args...) 1
    #define EVARS(args...) 1
#endif

template<class T> inline string TOSTR(const T & x) { stringstream ss; ss << x; return ss.str(); }
#define DIE(args...) {printf(args);exit(0);}
#define PR(x) cout << (x) << endl
#define PRF(x) cout << fixed << setprecision(10) << x << endl

inline int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
inline LL gcd(LL a, LL b) { return a ? gcd(b % a, a) : b; }
inline LL powmod(LL a, LL p, LL m) { LL r = 1; while (p) { if (p & 1) r = r*a%m; p>>=1; a=a*a%m; } return r; }

struct pairhash {
    template <typename T, typename U>
    std::size_t operator() (const std::pair<T, U> &x) const {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

template <typename K, typename V>
V GetWithDef(const std::unordered_map <K,V> & m, const K & key, const V & defval ) {
    auto it = m.find(key);
    return (it == m.end()) ? defval : it->second;
}

template <typename K, typename V>
void SetDef(std::unordered_map <K,V> & m, const K & key, const V & defval ) {
    auto it = m.find(key);
    if (it == m.end()) m[key] = defval;
}

const int MOD = 1000 * 1000 * 1000 + 7;
const double PI = 3.1415926535897932384626433832795l;



// -----------------------------------------------------------------
// CODE
// -----------------------------------------------------------------

#define DEBUG 1
#define MAXN 505

inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

inline int mul(int a, int b) {
  return (long long)a * b % MOD;
}

int XS, YS;
int dp[2][MAXN][MAXN] = {}; // x1, rx2
char s[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);

    scanf("%d %d\n", &YS, &XS);
    FORN(i, YS) {
        scanf("%s\n", s[i]);
        // printf("%d: %s\n", i, s[i]);
    }

    if (s[0][0] != s[YS-1][XS-1])
        DIE("0\n");

    int dpi = 0;
    dp[dpi][0][0] = 1;

    #define ADD(x1, x2, xx1, xx2) add(dp[dpi ^ 1][xx1][xx2], dp[dpi][x1][x2]);
    #define IF(dx1, dy1, dx2, dy2) if (s[y1 + dy1][x1 + dx1] == s[YS-1-y2-dy2][XS-1-x2-dx2])
    #define CHECK(dx1, dy1, dx2, dy2) IF(dx1, dy1, dx2, dy2) ADD(x1, x2, x1 + dx1, x2 + dx2)

    FOR(curlen, 1, (XS + YS) / 2) {
        FORN(x1, curlen) {
            int y1 = curlen - 1 - x1;
            FORN(x2, curlen) {
                int y2 = curlen - 1 - x2;
                // EVARS(curlen, x1, y1, x2, y2, s[y1][x1], s[YS-1-y2][XS-1-x2]);
                if (dp[dpi][x1][x2]) {
                    assert(s[y1][x1] == s[YS-1-y2][XS-1-x2]);
                    CHECK(0, 1, 0, 1);
                    CHECK(0, 1, 1, 0);
                    CHECK(1, 0, 0, 1);
                    CHECK(1, 0, 1, 0);
                }
            }
        }
        FORN(x1, XS) FORN(x2, XS) dp[dpi][x1][x2] = 0;
        dpi ^= 1;
    }

    int maxdelta = (XS + YS) & 1;
    int ans = 0;
    FORN(x1, (XS + YS) / 2) {
        add(ans, dp[dpi][x1][XS-x1-1]);
        if (maxdelta)
            add(ans, dp[dpi][x1][XS-x1-2]);
    }

    printf("%d\n", ans);

    return 0;
}
