//Language: GNU C++11


#include <iostream>

using namespace std ;

const int N = 1e7 + 10 ;
typedef long long ll ;
typedef pair<int,int> pii;
typedef long double ld;

int n ;
int a , o[N] , x , f[N] , l[N] ;

int main(int argc, const char * argv[]) {
    
    cin >> n ;
    
    for (int i = 0 ; i < N ; i++)
    {
        f[i] = -1 ; l[i] = n + 1 ;
    }
    for (int i = 0 ; i < n ; i++)
    {
        cin >> x ;
        if ( f[x] == -1)
            f[x] = i ;
        l[x] = i ;
        
        o[x] ++ ;
    }
    int mm = 0 ;
    for (int i = 0 ; i < N ; i++)
    {
        if ( o[i] > 0 ){
            if ( o[i] > o[mm] ){
                mm = i ;
            }else if ( (o[i] == o[mm]) && ((l[mm] - f[mm]) > (l[i] - f[i])) ){
                mm = i;
            }
        }
    }
    
    cout << f[mm]+1 << " " << l[mm]+1 ;
    
    return 0;
}