//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

typedef ostringstream OSS;
typedef istringstream ISS;

typedef long long LL;
typedef pair<int, int> PII;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<PII> VPII;

#define fst first
#define snd second
// #define Y first
// #define X second
#define MP make_pair
#define PB push_back
#define EB emplace_back 
#define ALL(x) (x).begin(),(x).end()
#define RANGE(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define REP(i, init, N) for (int i = (init); i < (int)(N); i++)

template < typename T > inline T fromString(const string &s) { T res; ISS iss(s); iss >> res; return res; };
template < typename T > inline string toString(const T &a) { OSS oss; oss << a; return oss.str(); };

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const double DINF = 0x3f3f3f3f;
const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};
const double EPS = 1e-12;
//const double PI = acos(-1.0);

int main(void) {
    int n;
    cin >> n;
    VI xs(n);
    for (auto &x : xs) cin >> x;

    const int M = 1000005;
    VI cnts(M);
    VI ls(M);
    VI rs(M);

    rep(i, n) {
        int x = xs[i];

        cnts[x]++;
        if (cnts[x] == 1) {
            ls[x] = i;
        }
        rs[x] = i;
    }

    int max_cnt = 0;
    int max_l = 0, max_r = 0, max_len = INF;

    rep(x, M) {
        int len = rs[x] - ls[x];

        if (cnts[x]) {
//            printf("%d %d %d %d\n", cnts[x], ls[x], rs[x], len);
        }

        if (max_cnt < cnts[x] || 
                (max_cnt == cnts[x] && max_len > len)) {
            max_cnt = cnts[x];
            max_l = ls[x] + 1;
            max_r = rs[x] + 1;
            max_len = len;
        }
    }

    cout << max_l << " " << max_r << endl;

	return 0;
}
