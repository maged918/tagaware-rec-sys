//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
#define MAXVAL 2000000
bool prime[ MAXVAL + 1 ];
void criba(){
    memset( prime , 1 , sizeof( prime ) );
    prime[ 0 ] = 0;
    prime[ 1 ] = 0;
    for ( int i = 2 ; i * i <= MAXVAL ; i++ ){
        if ( prime[ i ] ){
            for ( int j = i*i ; j < MAXVAL ; j += i )
                prime[ j ] = 0;
        }
    }
}
int toi(string s){istringstream is(s);int x;is>>x;return x;}    
string tos( int t){stringstream st; st<<t;return st.str();}

vector< int > v ,r;
int p , q;
int reverse( int x ){
    int num = 0;
    while( x ){
        int t = x % 10;
        x /= 10;
        num = num*10 + t;
    }
    return num;
}

int main(){
    ios_base::sync_with_stdio( 0 );
    cin>>p>>q;
    criba();
    vector< int > PI( MAXVAL , 0 ) , RUB( MAXVAL , 0 );
    for ( int i = 1; i <= MAXVAL; i++ ){
        int u = reverse( i );
        if ( u == i ){
            r.push_back( u );                            
            RUB[ i ]++;
        }       
        RUB[ i ] = RUB[ i - 1 ] + RUB[ i ];
        if ( prime[ i ] ) PI[ i ]++;
        PI[ i ] = PI[ i - 1 ] + PI[ i ];
    }
    int maxi = -1;
    bool b1 = 0;
    for ( int i = 2000000; i >= 1 && !b1; i-- ){
        if ( (long long )q*(long long )PI[ i ] <= (long long )p*(long long )RUB[ i ] ){ b1 = 1;maxi = i; break;}
    }       
    if ( maxi == -1 ) cout<<"Palindromic tree is better than splay tree"<<'\n';
    else cout<<maxi<<'\n';
}