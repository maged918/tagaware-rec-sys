//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

#define N 70
vector< int > menor[ N + 1 ], igual[ N + 1 ], menori[ N + 1 ];
bool val( int x, int y , int x2 , int y2 ){
    for ( int i = 0; i < (int)igual[ x2 ].size(); i++ ){
        int ind = igual[ x2 ][ i ]; 
        if( ind != x2 && ind != y2 ) return 0;  
    }
    
    for ( int i = 0; i < (int)igual[ y2 ].size(); i++ ){
        int ind = igual[ y2 ][ i ]; 
        if( ind != x2 && ind != y2 ) return 0;  
    }
    
    for ( int i = 0 ; i < (int)menor[ x2 ].size(); i++ ){
        int ind = menor[ x2 ][ i ];
        if( x <= ind && ind <= y ) return 0;
        if( ind == x2 || ind == y2 ) return 0;
    }
    for ( int i = 0 ; i < (int)menor[ y2 ].size(); i++ ){
        int ind = menor[ y2 ][ i ];
        if( x <= ind && ind <= y ) return 0;
        if( ind == x2 || ind == y2 ) return 0;
    }
    for ( int i = 0 ; i < (int)menori[ x2 ].size(); i++ ){
        int ind = menori[ x2 ][ i ];
        if( x <= ind && ind <= y ) return 0;
    }
    for ( int i = 0 ; i < (int)menori[ y2 ].size(); i++ ){
        int ind = menori[ y2 ][ i ];
        if( x <= ind && ind <= y ) return 0;
    }   
    return 1;
}
bool used[ N + 1 ][ N + 1 ];
long long memo[ N + 1 ][ N + 1 ];
int n;
long long dp( int x , int y ){
    if( x == 0 && y == n-1 ) return 1;
    if( used[ x ][ y ] ) return memo[ x ][ y ];
    used[ x ][ y ] = 1;
    long long &dev = memo[ x ][ y ] = 0;
    if( x - 2 >= 0  && val( x , y , x - 2 , x - 1  ) ){
        dev += dp( x - 2 , y );
    }
    if( y + 2 <= n - 1 && val( x , y , y + 1 , y + 2 ) ){
        dev += dp( x , y + 2 );
    }
    if( x - 1 >= 0 && y + 1 <= n - 1 && val( x , y , x - 1 , y + 1 ) ){
        dev += dp( x - 1 , y + 1 );
    }
    return dev;
}
int main(){
    int k;
    cin>>n>>k;
    n *= 2;
    for ( int i = 0; i < k; i++ ){
        int a ,b;
        string op;
        cin>>a>>op>>b;
        a-- , b--;
        if( op == "=" ) igual[ a ].push_back( b );
        else if( op == "<" ) menor[ b ].push_back( a ); 
        else if( op == "<=") menori[ b ].push_back( a );
        else if( op == ">" ) menor[ a ].push_back( b );
        else menori[ a ].push_back( b );
    }
    long long ans = 0;
    for ( int i = 0 ; i < n - 1 ; i++ ){
        if( val( i + 1 , i  , i , i + 1 ) ) ans += dp( i , i + 1 );
    }
    cout<<ans<<endl;
    
}   