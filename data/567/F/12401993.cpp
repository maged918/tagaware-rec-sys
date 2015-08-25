//Language: GNU C++


#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef long long LL;
typedef double db;
const int N = 40;

#define foi( i, x ) for ( typeof( x.begin() ) i=x.begin(); i!=x.end(); ++i )
#define fo( i, x, y ) for ( int i=x; i<( y ); ++i )
#define mkp( A, B ) make_pair( A, B )
#define pb( x ) push_back( x )
#define fi first
#define se second

vector < pair< int, string > > e[N];
LL f[N][ N<<1 ][ N<<1 ];
int a[ N<<2 ];
int n, m;

void preprocessing()
{
	string S;
	int x, y;
	cin >> n >> m;
	fo ( i, 0, m )
	{
		cin >> x >> S >> y; --x, --y;
		if ( S==">=" ) swap( x, y ), S = "<=";
		if ( S==">" ) swap( x, y ), S = "<";
		e[y].pb( mkp( x, S ) );
	}
	fo ( i, 0, n + 1 ) fo ( j, 0, n<<1|1 ) 
		fo ( k, 0, n<<1|1 ) f[i][j][k] = -1;
	fill( a, a + ( n<<1 ), N );
}

bool chk( int x )
{
	foi ( j, e[x] )
	{
		if ( j->se=="=" && a[x]!=a[ j->fi ] ) return 0;
		if ( j->se=="<" && a[x]<=a[ j->fi ] ) return 0;
		if ( j->se=="<=" && a[x]<a[ j->fi ] ) return 0;
	}
	return 1;
}

LL dfs( int x, int l, int r )
{
	if ( f[x][l][r]>=0 ) return f[x][l][r];
	if ( r==l ) return 1;
	LL Res = 0;

	a[l] = a[ l+1 ] = x;
	if ( chk( l ) && chk( l+1 ) ) Res += dfs( x+1, l+2, r );
	a[l] = a[ l+1 ] = N;

	a[ r-1 ] = a[ r-2 ] = x;
	if ( chk( r-1 ) && chk( r-2 ) ) Res += dfs( x+1, l, r-2 );
	a[ r-1 ] = a[ r-2 ] = N;

	a[l] = a[ r-1 ] = x;
	if ( chk( l ) && chk( r-1 ) ) Res += dfs( x+1, l+1, r-1 );
	a[l] = a[ r-1 ] = N;
	return f[x][l][r] = Res;
}

int main()
{
	preprocessing();
	LL Res = dfs( 0, 0, n<<1 );
	cout << ( Res / 3 ) << endl;
	return 0;
}
