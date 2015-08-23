//Language: GNU C++11


#include <iostream>
#include <cstring>
using namespace std;
char a[200042], b[200042];
int len;
bool eq ( int s1, int f1, int s2, int f2) {
    int cLen = f1-s1;
    bool f = true;
    for( int i = 0 ; i < cLen ; i ++ ) {
        if ( a[s1+i] != b[s2+i] ) {
            f = 0;
            break;
        }
    }
    if ( f ) { return 1; }

    if ( cLen %2 ) { return 0; }

    return ( eq( s1, (s1+f1)/2, (s2+f2)/2, f2 ) && eq( (s1+f1)/2, f1, s2, (s2+f2)/2 ) ) ||
            ( eq( (s1+f1)/2, f1, (s2+f2)/2, f2 ) && eq( s1, (s1+f1)/2, s2, (s2+f2)/2 ) );
}

int main () {
//    ios::sync_with_stdio(false);
  //  cin.tie( NULL ):
    cin >> a >> b;
    len = strlen ( a );
    if ( eq( 0, len, 0, len ) ) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}