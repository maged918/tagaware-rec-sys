//Language: GNU C++


#include <bits/stdc++.h>
typedef long long ll;
const ll MAXN = 200010;
const ll P = 1000000007;
using namespace std;

ll d[MAXN];
ll fact[MAXN];
ll rec_fact[MAXN];

ll minus1(ll a, ll b)
{
    return (a - b + P) % P;
}

ll mpow(ll a, ll b) {
    if(b == 0) return 1;
    ll res = mpow(a,b/2);
    res *= res;
    res %= P;
    if(b&1ll) {
        res *= a;
        res %= P;
    }
    return res;
}

ll recip (ll a)
{

    return mpow(a, P - 2);
}

ll binom(ll n, ll k)
{
    return ( ( ( (fact[n] * rec_fact[k]) % P) * rec_fact[n - k] ) % P + P) % P;
}


int main()
{
//    freopen("gchess.in", "r", stdin);
    ll i, j, h, w, n, x, y, x1, y1, p, z;
    vector <pair <ll, ll> > points;
    fact[0] = 1;
    for (i = 1; i < MAXN; ++i)
        fact[i] = (fact[i - 1] * i) % P;
    rec_fact[0] = 1;
    for (i = 1; i < MAXN; ++i)
        rec_fact[i] = (rec_fact[i - 1] * recip(i) ) % P;
    cin >> h >> w >> n;
    for (i = 0; i < n; ++i) {
        cin >> y >> x;
        points.push_back(make_pair(y, x));
    }
    points.push_back(make_pair(h, w));
    sort(points.begin(), points.end());
    for (i = 0; i <= n; ++i) {
        y = points[i].first;
        x = points[i].second;
        d[i] = binom(x + y - 2, x - 1);
        for (j = 0; j < i; ++j) {
            y1 = points[j].first;
            x1 = points[j].second;
            if (x >= x1 && y >= y1)
                d[i] = minus1(d[i], ((binom(x - x1 + y - y1, x - x1) * d[j]) % P + P) % P);
        }
//        cout << d[i] << endl;
    }
    cout << d[n];
    return 0;
}
