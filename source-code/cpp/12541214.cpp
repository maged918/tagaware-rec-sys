//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
#define N 500
#define MOD 1000000007LL
char s[ N + 1 ][ N + 1 ];
int n ,m;
long long DP[ 2 ][ N + 4 ][ N + 4 ];
int main(){
    cin>>n>>m;
    for ( int i =0 ; i < n ; i++ ) cin>>s[ i ];
    
    for ( int r1 = n - 1; r1 >= 0 ; r1-- ){
        for ( int c1 = m - 1; c1 >= 0 ; c1-- ){
            for ( int r2 = 0 ; r2 < n ; r2++ ){
                int c2 = n - 1 + m - 1 - r1 - c1 - r2;  
                long long &dev = DP[ r1 & 1 ][ c1 ][ r2 ] = 0;
                if( (r1 == r2) && (c1 + 1 == c2) ){ 
                    dev = (s[ r1 ][ c1 ] == s[ r2 ][ c2 ]?1:0); 
                    continue;
                }
                if( (r1 + 1 == r2) && (c1 == c2) ){ 
                    dev = (s[ r1 ][ c1 ] == s[ r2 ][ c2 ]?1:0);
                    continue;
                }
                if( (r1 == r2) && (c1 == c2) ){ 
                    dev = 1;
                    continue;
                } 
                if( r1 > r2 || c1 > c2 ){ 
                    dev = 0; continue;
                }
                if( s[ r1 ][ c1 ] == s[ r2 ][ c2 ] ){
                    dev = (dev +DP[ r1 & 1 ][ c1 + 1][ r2 - 1 ]  ) %MOD;
                    dev = (dev + DP[ (r1 + 1) & 1 ][ c1 ][ r2 -1 ] )%MOD;
                    dev = (dev + DP[ r1 & 1 ][ c1 + 1 ][ r2 ] )%MOD;
                    dev = (dev + DP[ (r1 + 1)&1 ][ c1 ][ r2 ] )%MOD;
                }       
            }
        }
    }
    cout<<DP[ 0 & 1 ][ 0 ][ n - 1 ]<<'\n';  
}
