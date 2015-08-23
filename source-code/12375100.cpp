//Language: GNU C++11


//by dezhonger
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <deque>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <iomanip>
#include <stack>
using namespace std;

#define rep(i, a, b) for( i = (a); i <= (b); i++)
#define reps(i, a, b) for( i = (a); i < (b); i++)
#define pb push_back
#define ps push
#define mp make_pair
#define CLR(x,t) memset(x,t,sizeof x)
#define LEN(X) strlen(X)
#define F first
#define S second
#define Debug(x) cout<<#x<<"="<<x<<endl;


const double euler_r = 0.57721566490153286060651209;
const double pi = 3.141592653589793238462643383279;
const double E = 2.7182818284590452353602874713526;
const int inf=~0U>>1;
const int MOD = int(1e9) + 7;
const double EPS=1e-6;
const int mod = int(1e9) + 7;
typedef long long ll;
typedef long long LL;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}


//dp[i] qianmian you duoshao ge i/k.
int a[200010];
map<LL, int> ma, mb;int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    LL n, k;
    cin >>n >> k;
    LL x;
    LL ans = 0;
    for(int i = 1; i <= n ;i++)
    {
        cin >> x;
        a[i] = x;
        ma[x]++;
    }

    ma[a[1]]--;
    mb[a[1]]++;
    for(int i = 2; i < n; i++)
    {
        x = a[i];
        ma[x]--;
        if(x % k == 0)
        {
            LL l =mb[x/k];
            LL r = ma[x*k];
            ans = ans + 1LL * l * r;
        }
        mb[x]++;

    }


    cout <<ans << endl;
    return 0;
}
