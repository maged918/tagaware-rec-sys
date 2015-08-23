//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define DBG(x) cerr<<">> "<<#x<<" = "<<x<<endl;
#define REP(x,n) for (int x = 0; x < (n); ++ x)
#define FOR(x,a,b) for (int x = (a); x <= (b); ++ x)
#define FORD(x,a,b) for (int x = (a); x >= (b); -- x)
#define FOREACH(it, v) for (decltype((v).begin())it=(v).begin();it!=(v).end(); ++it)
#define ALL(v) (v).begin(),(v).end()
#define SIZE(v) ((int)(v).size())
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
const int MX = 105;
const int INF = 1e9 + 7;
const LL MOD = 1e9 + 7;

LL fastPow(LL a, LL b){if(!b)return 1LL;LL x=fastPow(a,b/2LL);x=(x*x)%MOD;if(b&1LL)x*=a;return x%MOD;}
LL revMod(LL x){return fastPow(x,MOD-2);}

/* kod */

string s;
int n, m, LICZBA, SUMA;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> s;

    FORD(i,n-1,0)
    {
        if (s[i] == '.' && (i == n-1 || s[i+1] != '.'))
            ++ LICZBA;
    
        if (s[i] == '.')
            ++ SUMA;
    }

    while (m--)
    {
        int x; string y;
        cin >> x >> y;
        x --;

        if (s[x] == '.' && y[0] == '.')
            goto ans;
        if (s[x] != '.' && y[0] != '.')
            goto ans;

        if (s[x] != '.')
            ++ SUMA;
        else
            -- SUMA;

        if (x > 0 && x < n-1 && s[x-1] == '.' && s[x+1] == '.')
        {
            if (s[x] == '.')
                LICZBA++;
            else
                LICZBA--;
            
            goto ans;
        }

        if ((x == 0 || s[x-1] != '.') && (x == n-1 || s[x+1] != '.'))
        {
            if (s[x] == '.')
                LICZBA--;
            else
                LICZBA++;

            goto ans;
        }

        ans:

        s[x] = y[0];

        cout << SUMA - LICZBA << endl;
    }

    return 0;
}