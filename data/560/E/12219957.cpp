//Language: GNU C++


#include <iostream>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>

#define mp make_pair
#define pb push_back
#define debug( x ) cout << #x << " = " << x << endl
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define f(i,a,b) for(int i = a ; i < b ; i++)
#define fst first
#define snd second
#define EPS 1E-9
#define INF 2000000000
#define MOD 1000000007
#define sqr(x) ((x)*(x))
using namespace std;

typedef pair<int,int> ii ;
typedef long long ll ;
typedef vector<int> vi;
typedef vector<ii> vii;


ll fact[200010];
ll inv[200010];
ll dp[3000];

ll fastExpo(int n, int pot){
    if(pot == 0) return 1;

    if(pot % 2){
        return (fastExpo(n,pot-1)*n)%MOD;
    }else{
        ll a = fastExpo(n,pot/2);
        return (a*a)%MOD;
    }
}

ll C(ll n, ll k){
    if(k > n) return 0;
    ll res = fact[n];
    res = (res*inv[n-k])%MOD;
    res = (res*inv[k])%MOD;
    return res;
}

int main()
{
    int h,w,n; cin >> h >> w >> n;

    vii puntos,puntos2;
    f(i,0,n){
        int a ,b; scanf("%d %d",&a,&b);
        puntos.pb(mp(b-1,a-1));
    }

    fact[0] = 1;
    inv[0] = 1;
    f(i, 1 ,200010){
        fact[i] = (fact[i-1]*i) % MOD;
        inv[i] = fastExpo(fact[i],MOD-2);
    }

    sort(all(puntos));
    puntos.pb(mp(w-1,h-1));
    for(int i = 0; i < n+1; i++){
        int row = puntos[i].snd;
        int col = puntos[i].fst;
        ll val = C(col+row,col);
        for(int j = 0; j < i; j++){
            int rr = puntos[j].snd;
            int cc = puntos[j].fst;
            ll invalid = dp[j];
            ll trans = C(row-rr+col-cc,col-cc);
            val = (val - (invalid*trans)%MOD + MOD)%MOD;
        }
        dp[i] = val;
    }

    cout<<dp[n]<<endl;

    return 0;
}
