//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Fit(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-9
typedef pair<int, int> II;
typedef pair<ll, ll> LL;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI 2 * acos(0)

#define maxn 100005

int h, q;
vector<LL> V1, V2;

bool check(ll x){
    Rep(i, sz(V2)) if(V2[i].fi <= x && V2[i].se >= x) return false;
    return true;
}

int main(){
//  freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> q;
    Rep(run, q){
        ll id, l, r, ans;
        cin >> id >> l >> r >> ans;
        int u = (h - id);
        l <<= u;
        r = ((r + 1) << u) - 1;
        if(ans) V1.pb(mp(l, r));
        else V2.pb(mp(l, r));
    }

    sort(all(V1));
    sort(all(V2));

    ll l = (1ll << (h - 1)), r = (1ll << h) - 1;
    Rep(i, sz(V1)){
        if(r < V1[i].fi || l > V1[i].se){
            cout << "Game cheated!" << endl;
            return 0;
        }
        l = max(l, V1[i].fi);
        r = min(r, V1[i].se);
    }
//    cout << l << " " << r << endl;
    ll res = r - l + 1, run = l;
    Rep(i, sz(V2)){
        ll ll = V2[i].fi, rr = V2[i].se;
        if(ll > r || rr < l) continue;
        else {
            ll = max(ll, l);
            rr = min(rr, r);
        }
        if(run > rr) continue;
        else res = res - (rr - max(ll, run) + 1);
        run = max(run, rr + 1);
    }
    if(res == 0){
        cout << "Game cheated!" << endl;
    }
    else if(res > 1){
        cout << "Data not sufficient!" << endl;
    }
    else{
        if(r == l){
            cout << l << endl;
        } else{
            Rep(i, sz(V2)){
                ll x = V2[i].fi - 1;
                if(x >= l && x <= r && check(x)){
                    cout << x << endl;
                    return 0;
                }
                x = V2[i].se + 1;
                if(x >= l && x <= r && check(x)){
                    cout << x << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
