//Language: GNU C++


//============================================================================//
//------------------------>Nguyen Quoc Nhan<----------------------------------//
//--------------------->quocnhan1843@gmail.com<-------------------------------//
//============================================================================//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i,n) for(int i=0; i<n; i++)
#define fr(i,a,b) for(int i=a; i<=b; i++)
#define debug(a) cout<< #a << " = " <<a<<endl;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define oo 2147483647
#define INF 12512523232344LL
#define pi 3.1415926535897932
#define MaxN 1000000

int GCD(int a, int b){return(b==0?a:GCD(b,a%b));}
int LCM(int a, int b){return a*(b/GCD(a,b));}

int n, vl;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("INPUT.INP", "r", stdin);
    freopen("OUTPUT.OUT", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;
    rep(i,n){
        cin  >> vl;
        if(vl == 1){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;


return 0;
}
