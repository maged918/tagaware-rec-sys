//Language: GNU C++


/*
Name: Mahir Asef Kabir
AUST CSE 28th Batch
Problem Name: B. Simple Game (HACKED)
*/
#include <bits/stdc++.h>
using namespace std;

#define FORab(i,a,b) for( __typeof(a)         i = (a);          i <= (b);        ++i )
#define FORba(i,a,b) for( __typeof(a)         i = (a);          i >= (b);        --i )
#define forstl(i, s) for( __typeof((s).end()) i = (s).begin (); i != (s).end (); i++ )
#define rep(i,n)     FORab(i,0,n-1)
#define II           ({int    a;scanf("%d",   &a);a;})
#define IL           ({int64  a;scanf("%lld", &a);a;})
#define ID           ({double a;scanf("%lf",  &a);a;}
#define all(a)       (a).begin(), (a).end()
#define MP           make_pair
#define PB           push_back
#define INF          1<<30
#define int64        long long
#define nl           puts("")
#define vi           vector<int>
#define pii          pair<int,int>
#define PI           3.141592653589793
#define EPS          2.718281828459045
#define memo(a,b)    memset(a,b,sizeof(a))

template < class T, class U > inline T max (T &a, U &b) { return a > b ? a : b; }
template < class T, class U > inline T min (T &a, U &b) { return a < b ? a : b; }
template < class T, class U > inline T swap (T &a, U &b){ T tmp = a;a = b;b = tmp;}
template < class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template < class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template < class X, class Y, class Z > X BigMod( X B, Y P, Z M ) {
    if( P == 0 ) return 1;
    if( P % 2 == 1 ) {
        return ((B%M)*BigMod(B,P-1,M))%M;
    }
    X P2 = BigMod(B,P/2,M);
    return (P2*P2)%M;
}

int main() {
    //freopen("input.txt", "r", stdin);
    int64 n, m;
    while( cin >> n >> m ) {
        if( n == 1 ) cout << 1 << endl;
        else {
            if( n % 2 == 1 ) {
                int64 mid = n/2 + 1;
                if( m == mid ) cout << mid-1 << endl;
                else if( m < mid ) cout << m+1 << endl;
                else cout << m-1 << endl;
            }
            else {
                int64 mid1 = n/2, mid2 = n/2 + 1;
                if( mid1 == m ) cout << mid2 << endl;
                else if( mid2 == m ) cout << mid1 << endl;
                else {
                    if( m < mid1 ) cout << m+1 << endl;
                    else if( m > mid2 ) cout << m-1 << endl;
                }
            }
        }
    }
    return 0;
}
