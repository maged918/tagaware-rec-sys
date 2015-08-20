//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
#define modn 1000000007
#define mod(x) ((x)%(1000000007))

using namespace std;

struct point{
    ll x, y, v;
} d[2005];
ll h, w, n, i, j, f[200005], r[200005];

ll binpow(ll n, ll k){
    ll res = 1;
    while(k){
        if(k & 1)
            res = mod(res*n);
        n = mod(n*n);
        k >>= 1;
    }
    return res;
}

ll reversed_element(ll n){
    return binpow(n, modn-2);
}

ll combinations(ll n, ll k){
    ll v = mod( f[n]*r[k] );
    return mod( v * r[n-k] );
}

bool by_coords(point a, point b){
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

int main(){
    // remove this
    //freopen("input.txt", "r", stdin);

    f[0] = 1;
    r[0] = 1;
    for(i=1; i<200005; i++)
        f[i] = mod(f[i-1]*i),
        r[i] = binpow(f[i], modn-2);

    cin >> h >> w >> n;
    for(i=0; i<n; i++)
        cin >> d[i].y >> d[i].x, d[i].v = 0;

    d[n].y = h;
    d[n].x = w;
    d[n++].v = 0;

    sort(d, d+n, by_coords);

    for(i=0; i<n; i++){
        d[i].v = combinations(d[i].x+d[i].y-2, d[i].x-1);

        for(j=0; j<i; j++){
            if(d[j].x <= d[i].x && d[j].y <= d[i].y)
                d[i].v = mod( d[i].v - mod(d[j].v * combinations(d[i].x+d[i].y-d[j].x-d[j].y, d[i].x-d[j].x)) );
            while(d[i].v < 0)
                d[i].v += modn;
        }
    }

    cout << d[n-1].v;
    return 0;
}
