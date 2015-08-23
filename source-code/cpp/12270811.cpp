//Language: GNU C++


#include <bits/stdc++.h>
#define pb          push_back
#define mp          make_pair
#define MAX         105
#define read(a, n)  for ( int i = 0; i < n; ++i ) cin >> a[i]

using namespace std;

string x, y;
inline bool cmp ( int a, int b, int c, int d ) {
    for ( int i = a, j = c; i <= b; ++i, ++j )
        if ( x[i] != y[j] )
            return false;
    return true;
}

bool go ( int a, int b, int c, int d ) {
    if ( cmp(a, b, c, d) ) return true;
    if ( (b - a) % 2 == 0 ) return false;

    int m1 = (a + b) / 2;
    int m2 = (c + d) / 2;

    if ( cmp(a, m1, c, m2) ) return go(m1 + 1, b, m2 + 1, d);
    if ( cmp(m1 + 1, b, m2 + 1, d) ) return go(a, m1, c, m2);
    if ( cmp(a, m1, m2 + 1, d) ) return go(m1 + 1, b, c, m2);
    if ( cmp(m1 + 1, b, c, m2) ) return go(a, m1, m2 + 1, d);

    return ( go(a, m1, c, m2) && go(m1 + 1, b, m2 + 1, d) ) ||
           ( go(a, m1, m2 + 1, d) && go(m1 + 1, b, c, m2) );
}

int main ( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;

    cout << ( go(0, x.size() - 1, 0, y.size() - 1) ? "YES" : "NO" );
}
