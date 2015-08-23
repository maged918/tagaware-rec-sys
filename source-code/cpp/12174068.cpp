//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

# define pb push_back
# define mp make_pair
# define FORN( a , b , c ) for ( int a = b ; a <= c ; ++ a )
# define FORNBACK( a , b , c ) for ( int a = b ; a >= c ; -- a )
int uz [ 7 ] ;int a1,b1 ;
    int a2,b2 ;
    int a3,b3 ;
inline void back ( int k )
{
    if ( k == 4 ){
        if ( a1 >= a2 + a3 ){
            if ( b1 >= b2 and b1 >= b3 )
            {
                cout << "YES\n" ;
                exit ( 0 ) ;
            }
        }
        if ( a1 >= a2 and a1 >= a3 ){
            if ( b1 >= b1 + b3 ) {
                cout << "YES\n" ;
                exit ( 0 ) ;
            }
        }
        return ;
    }
    FORN ( i , 1 , 3 )
    {
        if ( uz [ i ] ) continue ;
        uz [ i ] = 1 ;
        if ( i == 1 ){
            swap ( a1 , b1 ) ;
        }
        else if ( i == 2 ){
            swap ( a2 , b2 ) ;
        }
        else swap ( a3 , b3 ) ;
        back ( k + 1 ) ;

        uz [ i ] = 0 ;
        if ( i == 1 ){
            swap ( a1 , b1 ) ;
        }
        else if ( i == 2 ){
            swap ( a2 , b2 ) ;
        }
        else swap ( a3 , b3 ) ;

        back ( k + 1 ) ;
    }
}
int main()
{
    ios :: sync_with_stdio ( false ) ;

    //freopen( "input" , "r" , stdin ) ;
    //freopen( "output" , "w" , stdout ) ;
    cin >> a1 >> b1 ;
    cin >> a2 >> b2 ;
    cin >> a3 >> b3 ;
    if ( a1 * b1 < a2 * b2 + a3 * b3 ){
        cout << "NO\n" ;
        return 0 ;
    }
    back ( 1 ) ;
    cout << "NO\n"  ;
    return 0 ;
}
