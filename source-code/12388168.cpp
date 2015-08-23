//Language: GNU C++


#include <iostream>
#include <set>
#include <algorithm>

using namespace std ;

set < int > s ;
set < int > :: iterator it ;
int x[200005] ;
int n , a ;

int check( int n )
{
  return ( n + 1 ) / ( a + 1 ) ;
}

int main()
{
  int k , m , i , tmp , flag , l , r ;
  cin >> n >> k >> a >> m ;

  for ( i = 1 ; i <= m ; ++ i )
        cin >> x[i] ;

  s.clear() ;
  tmp = check(n) ; flag = -1 ;

  s.insert(0) ; s.insert( n + 1 ) ;

  for ( i = 1 ;i <= m ; ++ i )
  {
    s.insert (x[i]) ;
    it = s.find(x[i]) ;
    -- it ;
    l = (*it) ;
    ++ it , ++ it ;

    r = (*it) ;

    tmp = tmp - check ( r - l - 1 ) + check ( x[i] - l - 1 ) + check ( r - x[i] - 1 ) ;
    if ( tmp < k )
    {
        flag = i ; break ;
    }

  }
  cout << flag ;
  return 0;
}
