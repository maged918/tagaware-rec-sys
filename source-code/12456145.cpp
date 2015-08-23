//Language: GNU C++11


#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <unordered_map>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb(x) push_back(x)
#define f(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define ones(x) __builtin_popcount(x)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define debug(x) cerr << #x << ": " << x << endl;
#define fst first
#define snd second
#define itm1 fst.fst
#define itm2 fst.snd
#define itm3 snd
#define mt(a,b,c) mp(mp(a,b),c)
#define oo 2000000000
#define EPS 1e-9


typedef vector<int> vi;
typedef long long int ll;
typedef pair<ll,ll> ill;
typedef pair<int,int> ii ;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ii, int> tri;
typedef unsigned int uint;
const double PI = 3.14159265359;
const double E = 2.718281828459;
const ll MOD = 1000000007;



ll comb[4002][4002] ;
ll pot2[4002] ;
ll DP[4002];


int main()
{
     int  n; cin >> n ;

     pot2[0] = 1 ;
     for(int i=1;i<4002;i++) pot2[i] = (pot2[i-1]*2)%MOD;
    ll ans = 1 ;


   //for(int i=1;i<10;i++) cout << DP[i] << endl ;
    for(int i=0;i<=n;i++)
        comb [i][0] = 1, comb[0][i] = 0 ;
    comb[0][0] = 1 ;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%MOD;

       /* for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
            cout <<" combi  de " << i << " en " << j <<": "<< comb[i][j] << endl;
        */

    DP[1] = 1 ;
    for(int N=2;N<=n;N++)
    {
        DP[N] = 1 ;
        for(int k=1;k<N;k++)
        {
            DP[N] = (DP[N] + (DP[k]*comb[N-1][k])%MOD) % MOD ;
        }
    }

    for(int k=1;k<n;k++)
    {
        ans = (ans + (comb[n][k]*DP[k])%MOD ) % MOD;
    }

    printf("%I64d",ans) ;

    return 0 ;

}
