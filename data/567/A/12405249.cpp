//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define INF 1e12

int main() {
	int n, v[100005], minimo, maximo;

	scanf( "%d", &n );
	for( int i=0; i<n; i++ )
		scanf( "%d", &v[i] );

	for( int i=0; i<n; i++ ) {
		minimo = min( ( i+1 < n ? abs( v[i] - v[i+1] ) : INF ), ( i-1 >= 0 ? abs( v[i] - v[i-1] ) : INF ) );
		maximo = max( abs( v[i] - v[0] ), abs( v[i] - v[n-1] ) );
		printf( "%d %d\n", minimo, maximo );
	}

	return 0;
}