//Language: GNU C++11


#include <bits/stdc++.h>

#define FILE    0
#define INPUT   "input"
#define OUTPUT  "output"

#define MP      make_pair
#define MT      make_tuple
#define PB      push_back
#define FI      first
#define SE      second

#define MAX     int( 2010 )
#define INF     INT_MAX
#define EPS     int(1e-7)
#define MOD     int(1e7+7)
#define PI      acos(-1)

typedef long long ll;

using namespace std;

int sz;
string a, b;

bool check( int fa, int ta, int fb, int tb, int s ) {
    bool can = true;
    for( int d = 0; d < s && can; d++ ) can &= ( a[ fa+d ] == b[ fb+d ] );
    if( can ) return true;
    if( s%2 == 1 ) return false;
    return ( check( fa, fa+s/2-1, fb+s/2, tb, s/2 ) && check( fa+s/2, ta, fb, fb+s/2-1, s/2 ) ) ||
           ( check( fa, fa+s/2-1, fb, fb+s/2-1, s/2 ) && check( fa+s/2, ta, fb+s/2, tb, s/2 ) );
}

int main( ) {

    cin.tie( 0 ); ios_base::sync_with_stdio( 0 );

    if( FILE & 1 ) freopen( INPUT , "r", stdin  );
    if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    cin >> a >> b;
    sz = int( a.size( ) );
    cout << ( check( 0, sz-1, 0, sz-1, sz ) ? "YES\n" : "NO\n" );

    return 0;
}
