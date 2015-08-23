//Language: GNU C++11


#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
typedef long long ll;
using namespace std;
const double PI = 3.14159265;
const double E = 2.718281828459;
const double EPS = 1e-8;
const int M = 1179858+3;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

double p, q;
int a[M] = {0};
int b[M] = {0};
int digit[30];
bool prime[M];
bool pal[M];
double ret[M] = {0};

void getprime( )    {
    prime[1] = false;
    for( int i=2; i<M; i++ )    {
        if( !prime[i] )  continue;
        prime[i] = true;
        for( int j=2; j*i<M; j++ )
            prime[i*j] = false;
    }
}

bool palindromic( int n )   {
    int cnt = 0;
    do  {
        digit[cnt++] = n%10;
        n /= 10;
    }while( n );
    for( int i=0; i<cnt/2; i++ )
        if( digit[i] != digit[cnt-i-1] )    return false;
    return true;
}

int main()  {
    #ifdef ONLINE_JUDGE
    #else
        freopen( "in.txt", "r", stdin );
    #endif
    memset( prime, true, sizeof(prime) );
    getprime( );
    for( int i=1; i<M; i++ )   {
        a[i] = a[i-1];
        b[i] = b[i-1];
        if( prime[i] ) a[i]++;
        if( palindromic(i) ) b[i]++;
        ret[i] = (double)a[i]/(double)b[i];
    }
    // for( int i=1; i<100; i++ )  {
    //     printf("i = %d\t%.8f\n", i, ret[i] );
    // }
    // for( int i=M-100; i<M; i++ )    {
    //     printf("i = %d\t%.8f\n", i, ret[i] );
    // }
    while( ~scanf("%lf%lf", &p, &q ) )  {
        double A = p/q;
        // printf("A = %.8f\n", A );
        int ans;
        // int ans = upper_bound( ret, ret+M-1, A ) - ret;
        for( int i=M-2; i>=1; i-- )   {
            if( ret[i]-A < EPS )  {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans );
    }
    return 0;
}