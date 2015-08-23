//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

#define N   200005
#define mp  make_pair
#define pb  push_back
#define ll  long long
#define INF 10000000
#define MOD 1000000007

int n, k, a, m;
int i, j, l, r, mid, rem, last;
int shot[N];
bool g[N];

bool check( int id )
{
    for( i=0; i < n; i++ )      g[i] = 0;
    for( i=0; i <= id; i++ )    g[ shot[i]-1 ] = 1;

    rem = k;
    last = -1;
    for( i=0; i < n; i++ )
    {
        if( g[i] == 1 )
        {
            last = i;
        }
        if( last == -1 && i >= a-1 )
        {
            last = i+1;
            rem--;
        }
        else if( i-last >= a )
        {
            last = i+1;
            rem--;
        }
    }

    return rem > 0;
}

int main()
{
    scanf( "%d %d %d %d", &n, &k, &a, &m );
    for( i=0; i < m; i++ )
        scanf( "%d", &shot[i] );

    l = 0;
    r = m-1;
    while( r-l > 1 )
    {
        mid = ( l+r )/2;
        if( check( mid ) )  r = mid;
        else                l = mid;
    }
    if( check( l ) )        printf( "%d", l+1 );
    else if( check( r ) )   printf( "%d", r+1 );
    else                    printf( "%d", -1 );

    return 0;
}
