//Language: GNU C++


#include <cstdio>
#include <algorithm>

#define MAXN 15000000

using namespace std;

typedef long long ll;

int P[ MAXN + 1 ], nprimes[ MAXN + 1 ], pal[ MAXN + 1 ];

bool ispal( int i ) {
  int A[ 10 ], len = 0;
  while( i > 0 ) {
    A[ len++ ] = i % 10;
    i /= 10;
  }
  for(  i = 0; i < len; i++ ) {
    if( A[ i ] != A[ len - i - 1 ] ) return 0;
  }
  return 1;
}

int main( void ) {
  for( int i = 2; i <= MAXN; i++ ) {
    for( int j = 2*i; j <= MAXN; j += i ) {
      nprimes[ j ] = true;
    }
  }
  nprimes[ 1 ] = 1;
  for( int i = 1; i <= MAXN; i++ ) {
    pal[ i ] = pal[ i - 1 ] + ispal( i );
    P[ i ] = P[ i - 1 ] + 1 - nprimes[ i ];
  }
  int p, q, ans = -1;
  scanf("%d%d", &p, &q );
  for( int i = 1; i <= MAXN; i++ ) {
    if( ( ll )q * ( ll )P[ i ] <= ( ll )p * ( ll )pal[ i ] ) ans = i;
  }
  if( ans == -1 ) printf("Palindromic tree is better than splay tree\n");
  else printf("%d\n", ans );
  return 0;
}
