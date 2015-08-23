//Language: GNU C++11


# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll>pll;
typedef vector<ll>vll;
typedef set<ll>sll;

const ll MAXN = ll(5e6);
const ll INF = ll(1e17);
const ld EPS = ll(1e-9);
const ll MOD = ll(1e9) + 7;
const ll MILLION = ll(1e6);
const ll BILLION = ll(1e9);

ll n, a[MAXN], cnt[MAXN], z = -INF, last[MAXN], first[MAXN], y = INF;

int main(){

    cin >> n;
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(ll i = 1; i <= n; ++i){
        z = max(z, cnt[a[i]]);
        cnt[a[i]] = 0;
    }
    for(ll i = 1; i <= n; ++i){
        if(!cnt[a[i]]){
            first[a[i]] = i;
        }
        ++cnt[a[i]];
        last[a[i]] = i;
    }
    ll l, r;
    for(ll i = 1; i <= n; ++i){
        if(cnt[a[i]] == z){
            if(y > last[a[i]] - first[a[i]] + 1){
                y = last[a[i]] - first[a[i]] + 1;
                l = first[a[i]], r = last[a[i]];
            }
        }
    }
    cout << l << " " << r;
    return 0;
}
