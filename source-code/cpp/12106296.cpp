//Language: GNU C++


#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define PER(I, N) for (int I = (N); I >= 0; --I)
#define PERR(I, A, B) for (int I = (A); I >= B; --I)
#define ITR(I, A) for (__typeof((A).begin()) I=(A).begin(), _##i=(A).end(); I!=_##i; ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
#define LB(X) __builtin_ctz((X))
#define ONES(X) __builtin_popcount((X))
typedef long long LL;
using namespace std;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
const int MOD = 1e9+7;
const int SIZE = 1e5+10;
const int INF = 0x3f3f3f3f;
#define LOCALTEST 0 // change this to 1 to perform localtest on "in.txt"
int h,q;
vector<pair<LL,LL> > badranges;
pair<LL, LL> makerange(LL l, LL r, LL curh) {
    //printf("mr\n");
    LL lef, rig;
    lef = l, rig = r;
    while (curh < h) {
        lef *= 2LL;
        rig *= 2LL;
        rig++;
        curh++;
    }
    //printf("Finish mr\n");
    return MP(lef, rig);
}
bool badrangecovers(LL l, LL r, int idx) {
    LL rig = badranges[idx].S;
    idx++;
    while (idx < SZ(badranges) && rig < r) {
        LL curlef = badranges[idx].F;
        LL currig = badranges[idx].S;
        if (curlef > rig + 1)
            return false;
        rig = max(rig,currig);
        idx++;
    }
    return rig >= r;
}
int main(){
    if (LOCALTEST) {
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
    while (RII(h,q) == 2) {
        LL i, l, r, ans;
        bool stillok = true;
        badranges.clear();
        pair<LL, LL> p = makerange(1,1,1);
        while (q--) {
            scanf("%I64d %I64d %I64d %I64d", &i, &l, &r, &ans);
            if (!stillok)
                continue;
            //printf("%I64d %I64d %I64d %I64d", i, l, r, ans);
            if (ans == 0)
                badranges.PB(makerange(l,r,i));
            else {
                pair<LL, LL> goodrange = makerange(l,r,i);
                if (p.F == -1) {
                    p = goodrange;
                } else {
                    if (goodrange.S < p.F || goodrange.F > p.S) {
                        stillok = false;
                    } else {
                        // join into one good range
                        p.F = max(p.F, goodrange.F);
                        p.S = min(p.S, goodrange.S);
                    }
                }
            }

        }

        sort(ALL(badranges));
        // test against bad ranges
        REP(j,SZ(badranges)) {
            pair<LL, LL> badrange = badranges[j];
            //printf("badrange %I64d %I64d vs p %I64d %I64d\n",badrange.F,badrange.S,p.F,p.S);
            if (p.F >= badrange.F && p.S <= badrange.S) {
                stillok = false;
                break;
            } else if (badrange.S < p.F) {
                continue;
            } else if (badrange.F > p.S) {
                break;
            } else if (badrange.F > p.F) {
                if (badrangecovers(badrange.F, p.S, j))
                    p.S = badrange.F - 1;
                else
                    p.F = -1, p.S = 0;
            } else {
                p.F = badrange.S + 1;
            }
        }

        if (!stillok) {
            printf("Game cheated!\n");
        } else if (p.S == p.F) {
            printf("%I64d\n", p.F);
        } else {
            printf("Data not sufficient!\n");
        }
    }
    return 0;
}
